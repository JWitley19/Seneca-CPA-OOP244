/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 05/29/2018
// Author Jordan Witley
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/

#include <iostream>
using namespace std;
// TODO: include the necessary headers
#include "Kingdom.h"
// TODO: the sict namespace
namespace sict
{
	// TODO:definition for display(...) 
	void display(const Kingdom &pKingdom)
	{
		cout << pKingdom.m_name << ", " << "population " << pKingdom.m_population << endl;
	}

	void display(const Kingdom kArr[], int kSize)
	{
		int totalPopulation = 0;

		for (int i = 0; i < kSize; i++)
		{
			totalPopulation += kArr[i].m_population;
		}

		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;

		for (int i = 0; i < kSize; i++)
		{
			cout << i + 1 << ". " << kArr[i].m_name << ", population " << kArr[i].m_population << endl;
		}
		
		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << totalPopulation << endl;
		cout << "------------------------------" << endl;
	}
}