#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<cstdint>
#include<ctgmath>
using namespace std;

class Suite
{
public:
	static double going(int n) {
		double res = 1.0, inter = 1.0;
		for (int i = n; i >= 2; i--)
		{
			inter = inter * (1.0 / i);
			res += inter;
		}
		return res;
	}
};
int main() {
	vector<vector<int>> a;
	//Suite::factiorial_function(a, 50,0);
	cout<<Suite::going(20)<<endl;
	return 0;
}














/*	long double a = (long double)(((long double)1 / factorial_Of_number(n))*secondPart);
double current = pow(10, 6);
long double result = ((unsigned long long int)(a*current)) / current;
ostringstream stream;
stream << fixed << setprecision(15) << a;
string s = stream.str();
string s1;
for (int i = 0; i < s.length(); i++) {
if (i<8) {
s1.append(1, s[i]);
}
if (i >= 8) {
break;
}
}
double endPLS = atof(s1.c_str());
double temp1 = pow(10, 6);
double ress = ((long long int)(endPLS*temp1) / temp1);
return ress;*/

/*static long double factorial_Of_number(int n) {
long double result = 1;
if (n == 1) {
return 1;
}
if (n >= 2) {
result *= factorial_Of_number(n - 1);
return result*n;
}
return n;
}
static long double going(int n) {
vector<long double> s;
long double s1=factorial_Of_number(n);
long double secondPart = 0;
for (int i = 1; i <= n; i++) {
if(i==n){
s.push_back(1);
continue;
}
s.push_back(factorial_Of_number(i));
}
for (int i = 0; i < s.size(); i++) {
if (i == s.size() - 1) {
secondPart += 1;
break;
}
secondPart += s[i] / s1;
}
return trunc(secondPart*1000000)/1000000;
}*/