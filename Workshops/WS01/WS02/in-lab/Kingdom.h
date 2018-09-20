/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
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

// TODO: header safeguards
#ifndef _244_Kingdom_H_
#define _244_Kingom_H_
// TODO: sict namespace
namespace sict
	// TODO: define the structure Kingdom in the sict namespace
{
	struct Kingdom
	{
		char m_name[32];
		int m_population;
	};


	// TODO: declare the function display(...),
	//         also in the sict namespace
	void display(const Kingdom &pKingdom);
}
#endif //_244_Kingdom_H_
