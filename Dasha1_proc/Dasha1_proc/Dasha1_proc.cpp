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
		cerr << "Error: Input and/or output filenames are missing" << endl;
		return 0;
	}
	else
	{
		List l;
		ifstream ifst(argv[1]);
		In(l, ifst);
		Sort(l);
		ofstream outputFile(argv[2]);
		Out(l, outputFile);
		Clear(l);
		Out(l, outputFile);
	}
	system("Pause");
	return 0;

}