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
		ifstream ifst(argv[1], ios::in | ios::_Nocreate);
		In(l, ifst);
		ofstream outputFile(argv[2], ios::out | ios::trunc);
		int des = 0;
		cout << "What you want?" << endl << "0-All!" << endl << "1-OnlyAforism!" << endl << "2-OnlyPoslovica!" << endl;
		cout << "Please, Enter number: ";
		cin >> des;
		system("cls");
		Out(l, outputFile, des);
		Clear(l);
		outputFile.open(argv[2], ios::out | ios::app);
		Out(l, outputFile, des);
	}
	system("Pause");
	return 0;
}