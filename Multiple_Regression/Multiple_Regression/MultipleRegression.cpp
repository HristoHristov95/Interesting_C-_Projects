#include<iostream>
#include "MultipleRegressionHeader.h"

int main() 
{
	vector<vector<double>> tableWithNumbers = { { 1142,1060,325,201 },
												{ 863,995,98,98 },
												{ 1065,3205,23,162 },
												{ 554,120,0,54 },
												{ 983,2896,120,138 },
												{ 256,485,88,61 },
	};
	Calculation object(tableWithNumbers);
	vector<double>results=object.CalculateResults();
	for (int count = 0; count < results.size(); count++) 
	{
		cout << results[count] << endl;
	}
	return 0;
}