#include<iostream>
using namespace std;
class Film {
	char* name;
	int year;
public:
	Film(char* ="", int=1);
	~Film();
	Film(const Film&);
	char& operator[](int);
	Film& operator=(Film&);
	void print();
};
Film::Film(char* name, int year) {
	int lenght = strlen(name);
	this->name = new char[lenght+1];
	if (!this->name) {
		cout << "Error while allocating memory!\n";
		exit(1);
	}
	this->year = year;
	strcpy(this->name, name);
}
Film::~Film() {
	delete[] name;
	cout << "Useing destructor !\n";
}
Film::Film(const Film& object) {
	year = object.year;
	int lenght = strlen(object.name)+1;
	delete[] this->name;
	name = new char[lenght];
	if (!name) {
		cout << "Error while allocating memory !\n";
		exit(1);
	}
	strcpy(name, object.name);
}
char& Film::operator[](int position) {
	if ((position > (strlen(name) - 1)) || position < 0) {
		cout << "Error - out of bound!\n";
		exit(1);
	}
	return name[position];
}
Film& Film::operator=(Film& object) {
	year = object.year;
	int lenght = strlen(object.name);
	delete[] this->name;
	name = new char[lenght+1];
	if (!name) {
		cout << "Error while allocating memory !\n";
		exit(1);
	}
	strcpy(name, object.name);
	return *this;
}
void Film::print() {
	cout << "Author name: " << name << endl;
	cout << "Year of production: " << year << endl;
}


class CriminalFilm : virtual public Film {
	int victimCount;
public:
	CriminalFilm(int, char*, int);
	CriminalFilm(const CriminalFilm&);
	CriminalFilm& operator=(CriminalFilm&);
	char& operator[](int);
	void print();
	int getVictimCount();
};
CriminalFilm::CriminalFilm(int victimCount, char* name, int year): Film(name,year) {
	this->victimCount = victimCount;
}
CriminalFilm::CriminalFilm(const CriminalFilm& object) : Film(object) {
	victimCount = object.victimCount;
}
CriminalFilm& CriminalFilm::operator=(CriminalFilm& object) {
	Film::operator=((dynamic_cast<Film&>(object)));
	this->victimCount = object.victimCount;
	return *this;
}
char& CriminalFilm::operator[](int position) {
	return Film::operator[](position);
}
void CriminalFilm::print() {
	Film::print();
	cout << "Victims number: " << victimCount << endl;
}
int CriminalFilm::getVictimCount() {
	return victimCount;
}

class AnimationFilm : public Film {
	char* animatorName;
public:
	AnimationFilm(char*, char*, int);
	~AnimationFilm();
	AnimationFilm(const AnimationFilm&);
	AnimationFilm& operator=(AnimationFilm&);
	char& operator[](int);
	void print();
	char* getAnimatorName();
};
AnimationFilm::AnimationFilm(char* animName, char* name, int years) : Film(name, years) {
	int lenght = strlen(animName);
	animatorName = new char[lenght+1];
	if (!animatorName) {
		cout << "error!\n";
		exit(1);
	}
	strcpy(animatorName, animName);
}
AnimationFilm::~AnimationFilm() {
	delete[] animatorName;
}
AnimationFilm::AnimationFilm(const AnimationFilm& object): Film(object) {
	int lenght = strlen(object.animatorName);
	delete[] animatorName;
	animatorName = new char[lenght+1];
	if (!animatorName) {
		cout << "Allocation memory error!\n";
		exit(1);
	}
	strcpy(animatorName, object.animatorName);
}
AnimationFilm& AnimationFilm::operator=(AnimationFilm& object) {
	delete[] animatorName;
	animatorName = new char[strlen(object.animatorName)+1];
	if (!animatorName) {
		cout << "Error!\n";
		exit(1);
	}
	strcpy(animatorName, object.animatorName);
	Film::operator=((dynamic_cast<Film&>(object)));
	return *this;
}
char& AnimationFilm::operator[](int pos) {
	if (pos<0 || pos>strlen(animatorName)) {
		cout << "Error out of bounds !\n";
		exit(1);
	}
	return animatorName[pos];
}
void AnimationFilm::print() {
	Film::print();
	cout << "Animator's name: " << animatorName << endl;
}
char* AnimationFilm::getAnimatorName() {
	return animatorName;
}


class CriminalAnimationFilm : public CriminalFilm, public AnimationFilm {
public:
	CriminalAnimationFilm(int, char*, char*, int);
	CriminalAnimationFilm(const CriminalAnimationFilm&);
	CriminalAnimationFilm& operator=(CriminalAnimationFilm&);
	void print();
};
CriminalAnimationFilm::CriminalAnimationFilm(int victims, char* animatorsName, char* name, int year) : AnimationFilm(animatorsName, name, year), CriminalFilm(victims,name,year) {
}
CriminalAnimationFilm::CriminalAnimationFilm(const CriminalAnimationFilm& object): AnimationFilm(object), CriminalFilm(object) {
}
CriminalAnimationFilm& CriminalAnimationFilm::operator=(CriminalAnimationFilm& object) {
	CriminalFilm::operator=(dynamic_cast<CriminalFilm&>(object));
	AnimationFilm::operator=(dynamic_cast<AnimationFilm&>(object));
	return *this;
}
void CriminalAnimationFilm::print() {
	AnimationFilm::print();
	cout <<"Victim's count: " << CriminalFilm::getVictimCount() << endl;
}
int main() {
	CriminalFilm object(11, "George Miller", 1999);
	CriminalFilm object1(12, "Some1", 2000);
	object1 = object;
	object1.print();
	CriminalAnimationFilm temporary(22, "will smith", " J.J. Abrams A.K.A THE GEM", 2003);
	temporary.print();
	return 0;
}