#pragma once
#include<vector>
using namespace std;
class Calculation
{
	vector<vector<double>> tableWithNumbers;
	vector<double> results;
public:
	Calculation();
	Calculation(vector<vector<double>>);
	Calculation(const Calculation&);
	vector<double>& operator[](int);
	Calculation& operator=(const Calculation&);
	bool operator==(vector <vector<double>>);
	vector<double> GetSum(vector<vector<double>>);
	vector<vector<double>> GetElementsReadyForCalculation(vector<double>);
	vector<double> GetPivotDivised(int, int, vector<vector<double>>);
	void CalculateGaussMethod();
	vector<double> CalculateResults();
};
