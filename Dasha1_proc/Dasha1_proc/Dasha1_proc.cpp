// Dasha1_proc.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include "func.h"
#include "gtest/gtest.h"
#include "Test.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cerr << "Error: Input and/or output filenames are missing" << endl;
		return 0;
	}
	else
	{
		List l;
		ifstream ifst(argv[1], ios::in | ios::_Nocreate);
		In(l, ifst);
		ofstream ofst(argv[2], ios::out | ios::trunc);
		Multimethod(l, ofst);
	}
	system("pause");
	return 0;
	//::testing::InitGoogleTest(&argc, argv);
	//return RUN_ALL_TESTS();
}