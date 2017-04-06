#include "stdafx.h"
#include "func.h"
#include <iostream>
#include <cstring>
using namespace std;

Aforysm* Inn(ifstream &ifst)
{
	Aforysm* af = new Aforysm;
	ifst.getline(af->Author, 256);
	return af;

}

Poslovica* Inc(ifstream &ifst)
{
	Poslovica* ps = new Poslovica;
	ifst.getline(ps->Country, 256);
	return ps;
}

WisdomItem* In(ifstream &ifst)
{
	WisdomItem *ws;
	int num = 0;
	ifst >> num;
	char t[256];
	ifst.getline(t, 256);
	
	switch (num)
	{
	case 1:
	{	
		ws = new WisdomItem;
		ifst.getline(ws->Text, 256);
		ws->k = AFORYSM;
		ws->someType = (void*)Inn(ifst);
		return ws;
	}
	case 2:
	{
		ws = new WisdomItem;
		ifst.getline(ws->Text, 256);
		ws->k = POSLOVICA;
		ws->someType = (void*)Inc(ifst);
		return ws;
	}
	default:
		break;
	}
}
void OutA(Aforysm &af, ostream &ofst)
{
	ofst << "Это Афоризм. Его автор: ";
	ofst << af.Author << endl;
	ofst << "Афоризм: ";
}

void OutP(Poslovica &ps, ostream &ofst)
{
	ofst << "Это Пословица. Страна: ";
	ofst << ps.Country << endl;
	ofst << "Пословица: ";
}

void Clear(List &l)
{
	while (l.size != 0)
	{
		List::node *temp = l.Head->Next;
		delete l.Head;
		l.Head = temp;
		--l.size;
	}

	l.Head = nullptr;
	l.Tail = nullptr;
	l.Current = nullptr;
}

void Add(List &l, WisdomItem &el)
{
	++l.size;
	List::node* temp = new List::node;
	temp->item = &el;
	temp->Next = l.Head;
	l.Current = temp;

	if (l.Head != nullptr)
	{
		l.Tail->Next = temp;
		l.Tail = temp;
	}
	else
	{
		l.Head = l.Tail = temp;
	}
}

void In(List &l, ifstream &ifst)
{
	if (ifst.fail())
	{
		cout << "Ошибка: не удается открыть входной файл!" << endl;
		return;
	}
	else
	{
		int tmp = 0;
		while (!ifst.eof())
		{
			Add(l, *(In(ifst)));
		}
	}
	ifst.close();
}
void Writeinfo(WisdomItem &wisd, ofstream &ofst)
{
	if (wisd.k == AFORYSM)
	{

		OutA(*((Aforysm*)wisd.someType), ofst);
		ofst << wisd.Text << endl;
		OutA(*((Aforysm*)wisd.someType), cout);
		cout << wisd.Text << endl;

	}
	if (wisd.k == POSLOVICA)
	{

		OutP(*((Poslovica*)wisd.someType), ofst);
		ofst << wisd.Text << endl;
		OutP(*((Poslovica*)wisd.someType), cout);
		cout << wisd.Text << endl;

	}
}

void Out(List &l, ofstream &ofst)
{
	if (ofst.fail())
	{
		cout << "Ошибка: не удается открыть выходной файл!" << endl;
		return;
	}
	else
	{
		if (l.size)
		{
			ofst << "Контейнер заполнен:\n";
			cout << "Контейнер заполнен:\n";
		}
		else
		{
			ofst << "Контейнер пуст:\n";
			cout << "Контейнер пуст:\n";
		}

		WisdomItem* current = new WisdomItem;
		for (int i = 0; i < l.size; i++)
		{

			l.Current = l.Current->Next;

			current = (WisdomItem*)l.Current->item;
			Writeinfo(*current, ofst);

			current = nullptr;
			delete current;
		}
		string result = "----------------------------- \nИмеется " + to_string(l.size) + " объектов(а).\n";
		cout << result;
		ofst << result;
		ofst.close();
	}
}


