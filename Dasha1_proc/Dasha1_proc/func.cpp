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

Riddle* Inr(ifstream &ifst)
{
	Riddle* r = new Riddle;
	ifst.getline(r->Answer, 256);
	return r;
}

WisdomItem* In(ifstream &ifst)
{
	int num = 0;
	WisdomItem *ws;
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
		ifst >> ws->Grade;
		return ws;
	}
	case 2:
	{
		ws = new WisdomItem;
		ifst.getline(ws->Text, 256);
		ws->k = POSLOVICA;
		ws->someType = (void*)Inc(ifst);
		ifst >> ws->Grade;
		return ws;
	}
	case 3:
	{
		ws = new WisdomItem;
		ifst.getline(ws->Text, 256);
		ws->k = RIDDLE;
		ws->someType = (void*)Inr(ifst);
		ifst >> ws->Grade;
		return ws;
	}
	default:
		break;
	}
}

void OutA(Aforysm &af, ostream &ofst)
{
	ofst << "Following statement is an Aforysm. Its Author is: ";
	ofst << af.Author << endl;
	ofst << "Its content: ";
}

void OutP(Poslovica &ps, ostream &ofst)
{
	ofst << "Folowing statement is Poslovica. Its Country is: ";
	ofst << ps.Country << endl;
	ofst << "Its content: ";
}

void OutR(Riddle &r, ostream &ofst)
{
	ofst << "Folowing statement is Riddle. Its Answer is: ";
	ofst << r.Answer << endl;
	ofst << "Its question: ";
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
		cerr << "Error: Unable to open input file" << endl;
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

void Writeinfo(WisdomItem &wisd, ofstream &ofst, int des)
{
	if (des == 1)
	{	
		if (wisd.k == AFORYSM)
		{
			OutA(*((Aforysm*)wisd.someType), ofst);
			ofst << wisd.Text << endl;
			OutA(*((Aforysm*)wisd.someType), cout);
			cout << wisd.Text << endl;
			ofst << "The grade of the following statement is: " << wisd.Grade << endl;
			cout << "The grade of the following statement is: " << wisd.Grade << endl;
		}
	}
	if (des == 2)
	{
		if (wisd.k == POSLOVICA)
		{
			OutP(*((Poslovica*)wisd.someType), ofst);
			ofst << wisd.Text << endl;
			OutP(*((Poslovica*)wisd.someType), cout);
			cout << wisd.Text << endl;
			ofst << "The grade of the following statement is: " << wisd.Grade << endl;
			cout << "The grade of the following statement is: " << wisd.Grade << endl;
		}
	}
	if (des == 0)
	{
		if (wisd.k == AFORYSM)
		{
			OutA(*((Aforysm*)wisd.someType), ofst);
			ofst << wisd.Text << endl;
			OutA(*((Aforysm*)wisd.someType), cout);
			cout << wisd.Text << endl;
			ofst << "The grade of the following statement is: " << wisd.Grade << endl;
			cout << "The grade of the following statement is: " << wisd.Grade << endl;
		}
		if (wisd.k == POSLOVICA)
		{
			OutP(*((Poslovica*)wisd.someType), ofst);
			ofst << wisd.Text << endl;
			OutP(*((Poslovica*)wisd.someType), cout);
			cout << wisd.Text << endl;
			ofst << "The grade of the following statement is: " << wisd.Grade << endl;
			cout << "The grade of the following statement is: " << wisd.Grade << endl;
		}
		if (wisd.k == RIDDLE)
		{
			OutP(*((Riddle*)wisd.someType), ofst);
			ofst << wisd.Text << endl;
			OutP(*((Riddle*)wisd.someType), cout);
			cout << wisd.Text << endl;
			ofst << "The grade of the following statement is: " << wisd.Grade << endl;
			cout << "The grade of the following statement is: " << wisd.Grade << endl;
		}
	}
}
void Out(List &l, ofstream &ofst, int des)
{
	if (ofst.fail())
	{
		cerr << "Error: Unable to open output file" << endl;
		return;
	}
	else
	{
		if (l.size)
		{
			ofst << "Container is filled:\n";
			cout << "Container is filled:\n";
		}
		else
		{
			ofst << "Container is empty:\n";
			cout << "Container is empty:\n";
		}

		WisdomItem* current = new WisdomItem;
		for (int i = 0; i < l.size; i++)
		{
			l.Current = l.Current->Next;
			current = (WisdomItem*)l.Current->item;
			Writeinfo(*current, ofst, des);
		}

		current = nullptr;
		delete current;

		string result = "----------------------------- \nThere are " + to_string(l.size) + " objects involving.\n";
		cout << result;
		ofst << result;
		ofst.close();
	}
}