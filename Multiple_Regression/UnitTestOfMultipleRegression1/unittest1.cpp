#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Multiple_Regression\MultipleRegression.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestOfMultipleRegression1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1GetSum)
		{
			// TODO: Your test code here
			vector<vector<double>> testTable = { {1142,1060,325,201},
												 {863,995,98,98},
												 {1065,3205,23,162},
												 {554,120,0,54},
												 {983,2896,120,138},
												 {256,485,88,61},
			};
			Calculation object;
			vector<double> results = { 6,4863,8761,654,714 };
			Assert::IsTrue(results == object.GetSum(testTable));
		}
		TEST_METHOD(TestMethod2GetElementsReadyForCalculation)
		{
			vector<double> testVector = { 6,4863,8761,654,714 };

			vector<vector<double>> results = { { 6,4863,8761,654,714 },
											   {4863,4521899,8519938,620707,667832},
											   {8761,8519938,21022091,905925,1265493},
											   {654,620707,905925,137902,100583} };

			vector<vector<double>> testTable = {	{ 1142,1060,325,201 },
													{ 863,995,98,98 },
													{ 1065,3205,23,162 },
													{ 554,120,0,54 },
													{ 983,2896,120,138 },
													{ 256,485,88,61 }, };
			Calculation object(testTable);
			Assert::IsTrue(results == object.GetElementsReadyForCalculation(testVector));
		}
		TEST_METHOD(TestMethod3GetPivotDivised)
		{
			vector<vector<double>> testTable = { { 6,4863,8761,654,714 },
												{ 4863,4521899,8519938,620707,667832 },
												{ 8761,8519938,21022091,905925,1265493 },
												{ 654,620707,905925,137902,100583 } };
			vector<double> results = {1,(double)4863/6,(double)8761/6,(double)654/6,(double)714/6};
			Calculation object;
			Assert::IsTrue(results == object.GetPivotDivised(0, 0, testTable));
		}
		/*TEST_METHOD(TestMethod4CalculateGaussMethod)
		{
			vector<vector<double>> testTable = { { 1142,1060,325,201 },
												{ 863,995,98,98 },
												{ 1065,3205,23,162 },
												{ 554,120,0,54 },
												{ 983,2896,120,138 },
												{ 256,485,88,61 },
																	};
			vector<vector<double>> results = {	{6,4863,8761,654,714},
												{0,580437.5,1419148,90640,89135},
												{0,0,4759809,-270635,5002.332},
												{0,0,0,37073.93,9122.275} };
			Calculation object(testTable);
			object.CalculateGaussMethod();
			Assert::IsTrue(object == results);
		}*/
		TEST_METHOD(TestMethod5CalculateResults) 
		{
			vector<vector<double>> testTable = { { 1142,1060,325,201 },
													{ 863,995,98,98 },
													{ 1065,3205,23,162 },
													{ 554,120,0,54 },
													{ 983,2896,120,138 },
													{ 256,485,88,61 },
																		};
			Calculation object(testTable);
			vector<double> results = { 6.7013,0.0784,0.0150,0.2461 };
			Assert::IsTrue(results == object.CalculateResults());
		}
		TEST_METHOD(TestMethod6CalculateResults2) 
		{
			vector<vector<double>> testTable = {	{ 345,65,23,31.4 },
													{ 168,18,18,14.6 },
													{ 94,0,0,6.4 },
													{ 187,185,98,28.3 },
													{ 621,87,10,42.1 },
													{ 255,0,0,15.3 },
																		};
			Calculation object(testTable);
			vector<double> results = { 0.5665,0.0653,0.0087,0.1510};
			Assert::IsTrue(results == object.CalculateResults());
		}
	};
}