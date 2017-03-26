#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<fstream>
#include<sstream>
using namespace std;
const int MIN_DIST = 10000;

const int DOT_PRODUCT = 0;
const int JACCARD = 1;

const int SINGLE_LINKAGE = 0;
const int COMPLETE_LINKAGE = 1;
const int AVG_LINKAGE = 2;
struct title
{
	int day;
	string title_string;
	set<string> words;
};
struct distances
{
	double dist;
	int index;
};
// za sortiraneto
struct Cmp {
	bool operator()(const distances d1, const distances d2) const
	{
		if (d1.dist == d2.dist)
		{
			return d1.index < d2.index;
		}
		return d1.dist < d2.dist;
	}
};
class classifier
{
	// iz4islqvane na razstoqniqta
	double dot_distance(set<string> &v1, set<string> &v2);
	double jaccard_distance(set<string> &v1, set<string> &v2);

	// 2d sortirani razstoqniq: O(log N)
	vector<multiset<distances, Cmp>> P;
	// 2d ne sortirani razstoqniq
	vector<vector<distances>> C;
	// markirani aktivni klusteri
	vector<int> II;
	// 2d pozicii s vsi4ki elementi
	vector<vector<int>> A;

	void classification(const int linkage_criteria, const int distance_function);
	void print_classes(string file);

public:
	// на колко клъстера да се раздели информацията
	int K;
	// броя на всички структури в titles тоест отделните изречения
	int N;

	// vsi4ki redove s info
	vector<title> titles;

	// kriteriite
	bool run_classification(void);

	// constructor
	classifier(vector<string> allInfo, int k);
	// destructor
	~classifier(void);
};
classifier::classifier(vector<string> allInfo, int k)
{
	K = k;

	titles.clear();

	vector<string>::iterator it = allInfo.begin();
	vector<string>::iterator const end=allInfo.end();
	while (it != end)
	{
		title t;
		t.words.clear();
		string s = it->data();
		string::iterator s_it = find(s.begin(), s.end(), '|');
		string curr_day(s.begin(), s_it);
		t.day = atoi(curr_day.c_str());

		s_it = s_it + 2;
		string curr_title(s_it, s.end());
		t.title_string = curr_title;

		//words 
		string::iterator s_beg(s_it);
		while (s_it != s.end())
		{
			if ((*s_it) == ' ')
			{
				//next word
				string word(s_beg, s_it);
				t.words.insert(word);
				s_beg = s_it;
				++s_beg;
			}
			++s_it;
		}

		titles.push_back(t);
		++it;
	}
	N = titles.size();
}

classifier::~classifier(void)
{
}

double classifier::dot_distance(set<string> &v1, set<string> &v2)
{
	double d_distance = 0;
	set<string>::iterator v1_it = v1.begin();
	while (v1_it != v1.end())
	{
		string str_cmp = v1_it->data();
		if (v2.find(str_cmp) != v2.end())
		{
			d_distance += 1;
		}
		++v1_it;
	}
	return d_distance;
}
double classifier::jaccard_distance(set<string> &v1, set<string> &v2)
{
	double d_distance = 0;
	set<string>::iterator v1_it = v1.begin();
	int different_words_cnt = v2.size();
	int mutual_words_cnt = 0;
	while (v1_it != v1.end())
	{
		++different_words_cnt;
		string str_cmp = v1_it->data();
		if (v2.find(str_cmp) != v2.end())
		{
			++mutual_words_cnt;
			--different_words_cnt;
		}
		++v1_it;
	}
	d_distance = 1 - ((double)mutual_words_cnt) / ((double)different_words_cnt);
	return d_distance;
}


void classifier::classification(const int linkage_criteria, const int distance_function)
{
	A.clear();
	C.clear();
	II.clear();
	P.clear();
	C.resize(N);
	P.resize(N);
	II.resize(N);
	A.resize(N);
	for (int i = 0; i < N; ++i)
	{
		vector<distances> V_temp;
		distances D_temp;
		V_temp.clear();
		multiset<distances, Cmp> Q_temp;
		Q_temp.clear();
		V_temp.resize(N);
		for (int j = 0; j < N; ++j)
		{
			if (distance_function == JACCARD)
			{
				D_temp.dist = -jaccard_distance(titles[i].words, titles[j].words);
			}
			else
			{
				D_temp.dist = -dot_distance(titles[i].words, titles[j].words); // sus minus e za6toto se tursi nai malkoto razstoqnie  poneje posle se sortirat
			}
			D_temp.index = j;
			V_temp[j] = D_temp;
			if (j != i)
			{
				Q_temp.insert(D_temp); // sortirani sa v narastva6t red NE SA OGLEDALNI SAMO GLAVNIQ DIAGONAL ELEMENTITE SA EDNAKVI !!!
			}
		}
		C[i] = V_temp; // ne sortirani vsi4ki razstoqniq + tiq deto se povtarqt
		II[i] = 1; // aktivni klusteri
		P[i] = Q_temp; // vsi4ki razstoqniq sortirani 1-vo po razstoqnie posle po indeks

		vector<int> A_i;
		A_i.push_back(i);
		A[i] = A_i; // pazi koi e nomera na title strukturite koito sa kum teku6tiq kluster dobaveni
	}

	// next: build clusters until K clusters left
	for (int n = 0; n < N - K; ++n)
	{
		double min_dist = MIN_DIST;
		int min_index = 0;
		for (int k = 0; k < N - 1; ++k)
		{
			if (II[k] == 1)
			{
				if (P[k].begin()->dist < min_dist)
				{
					// sortirani sa 1-vo po razstoqnie i posle po indeks zatova min_index se zima ot razstoqnieto
					// purvi klustar s minimalno razstoqnie
					min_dist = P[k].begin()->dist;
					/*minimalniq indeks pokazva kude e drugoto razstoqnie koeto otgovarq na tova razstoqnie oba4e minimalen indeks poneje sa sortirani po razstoqnie i sled tova po indeks
					razstoqniqta sa ednakvi oba4e pokazva kude to4no e drugoto s nai malkiq indeks*/
					/*ukazva kude e su6toto tova razstoqnie oba4e sus minimalen indeks !!!*/
					/*vuv P na vsqka 4ast p[k] vutre elementite sa edni i su6ti prosto sa svurzani vsqko sus vsqko*/
					min_index = P[k].begin()->index; // purvi klustar s indeks pokazva6t kude e su6toto tova razstoqnie oba4e sus minimalen indeks
				}
			}
		}
		// we have minimum distance
		// k1, k2 - indexes of most nearest clusters
		// ogledalen e vektora (EDNOMEREN MASIV razdelen posredata ogledalni elementi !!!) 1-niq put vzimame 1-viq klustar 2-riq put vzimame 2-riq klustar
		int k1 = min_index; // purvi klustar
		int k2 = P[k1].begin()->index; // vtori klustar

		int N_k1 = A[k1].size(); // goleminata na grupi4ka klustari
		int N_k2 = A[k2].size();

		P[k1].clear(); //iz4istva informaciqta za 1-viq kluster 
		// add cluster k2 to A[k1]
		for (int q = 0; q < A[k2].size(); ++q)
		{
			A[k1].push_back(A[k2][q]); // kum teku6tata grupa kustari se pribavq novata
		}
		// clear the second cluster
		II[k2] = 0; // iz4istva 2-riq kustar ve4e ne e aktiven 
		// O(N*log(N))
		// elementite sa ednakvi samo 4e 4ast ot tqh polovinata
		for (int m = 0; m < N; ++m)
		{
			// O(log(N)): insert, erase operations
			if ((II[m] != 0) && (m != k1))
			{
				// vector<vector<distances>> C !!! sudurja razstoqniqta na vseki sus vseki title element NE sortiran

				P[m].erase(C[m][k1]); // triim na vseki red vuv P vsi4ki elementite koito sa klustera K1 i propuskame samo tam kudeto e istinskiq kluster K1 tam kudeto 6te pribavqme K2
				P[m].erase(C[m][k2]); // triim navsqkade klustera k2
				if (linkage_criteria == SINGLE_LINKAGE)
				{
					// C  - NE e sortiran vektor i sudurja vsi4ki rastoqniq svurzani vseki sus vseki element !!!
					/*proverqva na vseki red dali na tezi indeksi kudeto sa bili klustarite ima po malko razstoqnie ako ima go prisvoqva na tozi klustar kudeto sme v momenta i 
					e aktiven v A[k1]*/
					//proverqva ot vseki edin red tam kudeto ne se povtarqt elementite k1 kum koi i sledva6tiq nai blizuk kluster
					C[m][k1].dist = C[m][k1].dist < C[m][k2].dist ? C[m][k1].dist : C[m][k2].dist; // tursime kum noviq kuster k1 kum koito sme pribavili k2 koe mu e sledva6toto nai 
					// blizko razstoqnie poneje ve4e sme pribavili k2 i se nujdaem ot drugo nai blizo razstoqnie
					C[k1][m].dist = C[m][k1].dist; //sled kato sme namerili nai blizkoto razstoqnie ot K1 kum noviq kluster promenqme noviq kluster da e s tova razstoqnie na K1 poneje 6te gi
					//sglobqvame pri sledva6ti cikli
				}
				if (linkage_criteria == COMPLETE_LINKAGE)
				{
					C[m][k1].dist = C[m][k1].dist > C[m][k2].dist ? C[m][k1].dist : C[m][k2].dist; // poneje sme sglobili noviq kluster k1 kum koito sme pribavili k2 tursim koe mu e nai
					// otdali4eniq kluster na k1 
					C[k1][m].dist = C[m][k1].dist;
				}
				if (linkage_criteria == AVG_LINKAGE)
				{
					int N_m = A[m].size();
					// N_k1 goleminata na 1-viq kluster* razstoqnieto mejdu 1-viq kluster i N_k2 goleminata na 2-riq kluster * razstoqnieto na 2-riq kluster / goleminata na ob6tiq broi 
					// klusteri
					C[m][k1].dist = (N_k1*C[m][k1].dist + N_k2*C[m][k2].dist) / N_m;
				}
				P[m].insert(C[m][k1]); // vuv vseki red ot vectori slagame novoto razstoqnie na nai blizkiq/otdali4eniq/sredniq kluster na k1 klustera smetnato
				// po formulite gore -kum koito sme bili pribavili drug kluster
				P[k1].insert(C[k1][m]); //na mqstoto na klustera k1 (toq kum koito sme pribavili k2) pribavqme informaciqta na K2 ( nai blizuk kluster )
			}
		}
	}
}

void classifier::print_classes(string file)
{
	ofstream outfile(file.c_str(), ios_base::out);
	int class_num = 0;
	for (int i = 0; i < N; ++i)
	{
		if (II[i] == 1)
		{
			++class_num;
			outfile << endl << "Class number: " << class_num << endl << endl;
			vector<int>::iterator it_a(A[i].begin());
			while (it_a != A[i].end())
			{
				int num_of_title = (*it_a);
				outfile << titles[num_of_title].day << "| " << titles[num_of_title].title_string << endl;
				++it_a;
			}
		}
	}
	outfile.close();
}

bool classifier::run_classification(void)
{
	if ((K < 1) || (K > N))
	{
		cout << "Wrong K (number of clusters). Should be in [1, N]" << endl;
		return false;
	}
	ostringstream os;
	os << K;
	string s = os.str();
	string s1;

	classification(SINGLE_LINKAGE, JACCARD);
	s1 = s + " classes single_linkage jaccard.txt";
	print_classes(s1);

	cout << "single_linkage jaccard completed" << endl;

	classification(SINGLE_LINKAGE, DOT_PRODUCT);
	s1 = s + " classes single_linkage dot_product.txt";
	print_classes(s1);

	cout << "single_linkage dot_product completed" << endl;

	classification(COMPLETE_LINKAGE, JACCARD);
	s1 = s + " classes complete_linkage jaccard.txt";
	print_classes(s1);

	cout << "complete_linkage jaccard completed" << endl;

	classification(COMPLETE_LINKAGE, DOT_PRODUCT);
	s1 = s + " classes complete_linkage dot_product.txt";
	print_classes(s1);

	cout << "complete_linkage dot_product completed" << endl;

	classification(AVG_LINKAGE, JACCARD);
	s1 = s + " classes average_linkage jaccard.txt";
	print_classes(s1);

	cout << "average_linkage jaccard completed" << endl;

	classification(AVG_LINKAGE, DOT_PRODUCT);
	s1 = s + " classes average_linkage dot_product.txt";
	print_classes(s1);

	cout << "average_linkage dot_product completed" << endl;
	return true;
}

int main(int argc, const char *argv[])
{
	string filename;
	int numberK;
	cout << "Enter filename: \n";
	getline(cin, filename);
	cout << "Enter K: \n";
	cin >> numberK;
	vector<string> allInfo;
	string line;
	allInfo.clear();
	ifstream infile(filename, ios::in);
	if (infile.is_open()) {
		while (getline(infile, line, '\n'))
		{
			allInfo.push_back(line);
		}
		infile.close();
	}
	else {
		cout << "No file found!\n";
		exit(1);
	}
	classifier classf(allInfo, numberK);
	classf.run_classification();
	cout << "Completed...!\n " << endl;
	return 0;
}