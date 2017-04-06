// Dasha1_proc.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include "func.h"
using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Error: Input and/or output filenames are missing" << endl;
		return 0;
	}
	else
	{
		List l;
		ifstream ifst(argv[1], ios::in | ios::_Nocreate);
		In(l, ifst);
		ofstream outputFile(argv[2], ios::out | ios::trunc);
		Out(l, outputFile);
		Clear(l);
		outputFile.open(argv[2], ios::out | ios::app);
		Out(l, outputFile);
	}
	system("Pause");
	return 0;
}