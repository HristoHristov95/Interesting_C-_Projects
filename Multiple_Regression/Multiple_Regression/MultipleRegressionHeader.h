#pragma once
#include<vector>
#include<algorithm>
#include "Calculation.h"
using namespace std;
//default конструктор
Calculation::Calculation() {
	tableWithNumbers.resize(1);
	results.resize(1);
}
// Конструктор
Calculation::Calculation(vector<vector<double>> copy)
{
	tableWithNumbers = copy;
}
//Конструктор за копие
Calculation::Calculation(const Calculation& object)
{
	tableWithNumbers = object.tableWithNumbers;
	results = object.results;
}
//Предефиниране на оператор =
Calculation& Calculation::operator=(const Calculation& object)
{
	tableWithNumbers = object.tableWithNumbers;
	results = object.results;
	return *this;
}
//Предефиниране на оператор []
vector<double>& Calculation::operator[](int position)
{
	if (position >= 0 && position < tableWithNumbers.size())
	{
		return tableWithNumbers[position];
	}
	cout << "Incorrect position number";
	exit(1);
}
// Предефиниране на оператор ==
bool Calculation::operator==(vector<vector<double>> elements) 
{
	for (int count = 0; count < this->tableWithNumbers.size(); count++) 
	{
		for (int countTwo = 0; countTwo < this->tableWithNumbers[count].size(); countTwo++) 
		{
			if (elements[count][countTwo] != this->tableWithNumbers[count][countTwo]) 
			{
				return false;
			}
		}
	}
	return true;
}
//Изчисляване на сумата необходима за изчисленията
vector<double> Calculation::GetSum(vector<vector<double>> allElements)
{
	vector<double> sum;
	sum.resize(5);
	sum[0] = allElements.size();
	for (int count = 0; count < allElements.size(); count++) 
	{
		for (int countTwo = 0; countTwo < allElements[count].size(); countTwo++)
		{
			sum[countTwo + 1] += allElements[count][countTwo];
		}
	}
	return sum;
}
// Умножаване на сумата получена от GetSum за да се направят необходимите 4 на брой уравнения
vector<vector<double>> Calculation::GetElementsReadyForCalculation(vector<double> multiply)
{
	vector<vector<double>> allFour;
	allFour.resize(multiply.size()-1);
	allFour[0] = multiply;
	for (int count = 1; count < allFour.size(); count++)
	{
		for (int countTwo = 0; countTwo < allFour[0].size(); countTwo++)
		{
			if (countTwo == 0) 
			{
				allFour[count].push_back(allFour[0][count]);
				continue;
			}
			double temporary = 0;
			if (count == countTwo) 
			{
				for (int countThree = 0; countThree < tableWithNumbers.size(); countThree++) 
				{
					temporary += pow(tableWithNumbers[countThree][countTwo - 1],2);
				}
				allFour[count].push_back(temporary);
			}
			else 
			{
				for (int countThree = 0; countThree < tableWithNumbers.size(); countThree++) 
				{
					temporary += tableWithNumbers[countThree][count-1] * tableWithNumbers[countThree][countTwo-1];
				}
				allFour[count].push_back(temporary);
			}
		}
	}
	return allFour;
}
// делене на всички елементи в реда в който е Pivot елемента , на Pivot
vector<double> Calculation::GetPivotDivised(int row, int col, vector<vector<double>> swapAndReturn)
{
	vector<double> temporary;
	int temporaryCol = col;
	while (temporaryCol) 
	{
		temporary.push_back(0);
		temporaryCol--;
	}
	for (int currentCol = col; currentCol < swapAndReturn[row].size(); currentCol++)
	{
		temporary.push_back(swapAndReturn[row][currentCol] / swapAndReturn[row][col]);
	}
	return temporary;
}
//Премахване на числата които не са нужни за изчислението на крайния резултат (междинните сметки)
void Calculation::CalculateGaussMethod()
{
	vector<double> temporaryFirst;
	results = GetSum(tableWithNumbers);
	tableWithNumbers = GetElementsReadyForCalculation(results);
	temporaryFirst = GetPivotDivised(0, 0, tableWithNumbers);
	for (int count = 0; count < tableWithNumbers.size() - 1; count++)
	{ // pazi pivot-skiq red
		for (int countTwo = count + 1; countTwo < tableWithNumbers.size(); countTwo++)
		{ // pazi poredniq red sled pivot
			vector<double> temporarySecond;
			for (int countThree = 0; countThree < tableWithNumbers[count].size(); countThree++)
			{
				temporarySecond.push_back((-tableWithNumbers[countTwo][count])*(temporaryFirst[countThree]));
			}
			for (int countThree = 0; countThree < tableWithNumbers[count].size(); countThree++)
			{
				temporarySecond[countThree] = tableWithNumbers[countTwo][countThree] + temporarySecond[countThree];
			}
			tableWithNumbers[countTwo] = temporarySecond;
		}
		temporaryFirst = GetPivotDivised(count + 1, count + 1, tableWithNumbers);
	}
}
//изчисляване на самото BETA числа като отговор на поставената задача
vector<double> Calculation::CalculateResults()
{
	CalculateGaussMethod();
	int currentBeta = tableWithNumbers[tableWithNumbers.size()-1].size() - 2;
	results.erase(results.begin(), results.end());
	for (int count = tableWithNumbers.size() - 1; count >= 0; count--)
	{
		for (int countTwo = tableWithNumbers[count].size() - 2; countTwo >= 0; countTwo--)
		{
			if (countTwo != currentBeta) 
			{
				tableWithNumbers[count][tableWithNumbers[count].size() - 1] -= tableWithNumbers[count][countTwo];
				tableWithNumbers[count][countTwo] = 0;
			}
		}
		results.push_back(tableWithNumbers[count][tableWithNumbers[count].size() - 1] / tableWithNumbers[count][currentBeta]);
		for (int countTwo = tableWithNumbers.size() - 1; countTwo >= 0; countTwo--)
		{
			tableWithNumbers[countTwo][currentBeta] *= results[results.size() - 1];
		}
		currentBeta--;
	}
	reverse(results.begin(), results.end());
	for (int count = 0; count < results.size(); count++) 
	{
		results[count] = round(results[count] * 10000) / 10000;
	}
	return results;
}
