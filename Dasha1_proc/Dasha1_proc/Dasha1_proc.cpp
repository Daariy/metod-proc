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
	setlocale(LC_ALL, "Rus");
	if (argc != 3)
	{
		cout << "Ошибка: входной и/или выходной файл отсутствует!" << endl;
		return 0;
	}
	else
	{

		List l;
		ifstream ifst(argv[1]);
		//ifstream ifst("in.txt");
		In(l, ifst);
		ofstream outputFile(argv[2]);
		//ofstream outputFile("out.txt");
		Out(l, outputFile);
		Clear(l);
		Out(l, outputFile);
	}
	system("pause");
	return 0;


}