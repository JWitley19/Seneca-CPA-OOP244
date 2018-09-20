/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 09/18/2018
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

}