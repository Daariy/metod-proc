#include "stdafx.h"
#include "func.h"
#include <cstring>
#include "Protect.h"

using namespace std;

Aforysm* Inn(ifstream &ifst)
{
	CheckInputFile(ifst);
	Aforysm* af = new Aforysm;
	ifst.getline(af->Author, 256);
	CheckWrongInput(ifst);
	return af;
}

Poslovica* Inc(ifstream &ifst)
{
	CheckInputFile(ifst);
	Poslovica* ps = new Poslovica;
	ifst.getline(ps->Country, 256);
	CheckWrongInput(ifst);
	return ps;
}

Riddle* Inr(ifstream &ifst)
{
	CheckInputFile(ifst);
	Riddle* r = new Riddle;
	ifst.getline(r->Answer, 256);
	CheckWrongInput(ifst);
	return r;
}

WisdomItem* In(ifstream &ifst)
{
	CheckInputFile(ifst);
	int num = 0;
	WisdomItem *ws;
	ifst >> num;
	CheckWrongInput(ifst);
	if (!(1 <= num && num <= 3)) {
		cerr << "Error: unknown type" << endl;
		exit(1);
	}
	char t[256];
	ifst.getline(t, 256);
	CheckWrongInput(ifst);
	switch (num)
	{
	case 1:
	{		  
		ws = new WisdomItem;
		ifst.getline(ws->Text, 256);
		CheckWrongInput(ifst);
		ws->k = AFORYSM;
		ws->someType = (void*)Inn(ifst);
		break;
	}
	case 2:
	{
		ws = new WisdomItem;
		ifst.getline(ws->Text, 256);
		CheckWrongInput(ifst);
		ws->k = POSLOVICA;
		ws->someType = (void*)Inc(ifst);
		break;
	}
	case 3:
	{
		ws = new WisdomItem;
		ifst.getline(ws->Text, 256);
		CheckWrongInput(ifst);
		ws->k = RIDDLE;
		ws->someType = (void*)Inr(ifst);
		break;
	}
	default:
		break;
	}

	ws->quantityOfSpecialSymbols = ws->CountSighns(ws->Text);
	ifst >> ws->Grade;
	CheckWrongInput(ifst);
	CheckGrade(ws->Grade);
	return ws;
}

void OutA(Aforysm &af, ostream &ofst)
{
	CheckOutputFile(ofst);
	ofst << "Following statement is an Aforysm. Its Author is: ";
	ofst << af.Author << endl;
	ofst << "Its content: ";
}

void OutP(Poslovica &ps, ostream &ofst)
{
	CheckOutputFile(ofst);
	ofst << "Folowing statement is Poslovica. Its Country is: ";
	ofst << ps.Country << endl;
	ofst << "Its content: ";
}

void OutR(Riddle &r, ostream &ofst)
{
	CheckOutputFile(ofst);
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
	CheckInputFile(ifst);
	
	int tmp = 0;

	while (!ifst.eof())
	{
		Add(l, *(In(ifst)));
	}
	ifst.close();
}

void Writeinfo(WisdomItem &wisd, ofstream &ofst, int des)
{
	CheckOutputFile(ofst);
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
			ofst << "Quantity of special symbols in the folowing wisdom item: " << wisd.CountSighns(wisd.Text) << endl;
			cout << "Quantity of special symbols in the folowing wisdom item: " << wisd.CountSighns(wisd.Text) << endl;
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
			ofst << "Quantity of special symbols in the folowing wisdom item: " << wisd.CountSighns(wisd.Text) << endl;
			cout << "Quantity of special symbols in the folowing wisdom item: " << wisd.CountSighns(wisd.Text) << endl;
		}

	}
	if (des == 3)
	{
		if (wisd.k == RIDDLE)
		{
			OutR(*((Riddle*)wisd.someType), ofst);
			ofst << wisd.Text << endl;
			OutR(*((Riddle*)wisd.someType), cout);
			cout << wisd.Text << endl;
			ofst << "The grade of the following statement is: " << wisd.Grade << endl;
			cout << "The grade of the following statement is: " << wisd.Grade << endl;
			ofst << "Quantity of special symbols in the folowing wisdom item: " << wisd.CountSighns(wisd.Text) << endl;
			cout << "Quantity of special symbols in the folowing wisdom item: " << wisd.CountSighns(wisd.Text) << endl;
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

		}
		if (wisd.k == POSLOVICA)
		{
			OutP(*((Poslovica*)wisd.someType), ofst);
			ofst << wisd.Text << endl;
			OutP(*((Poslovica*)wisd.someType), cout);
			cout << wisd.Text << endl;

		}
		if (wisd.k == RIDDLE)
		{
			OutR(*((Riddle*)wisd.someType), ofst);
			ofst << wisd.Text << endl;
			OutR(*((Riddle*)wisd.someType), cout);
			cout << wisd.Text << endl;

		}
		ofst << "The grade of the following statement is: " << wisd.Grade << endl;
		cout << "The grade of the following statement is: " << wisd.Grade << endl;
		ofst << "Quantity of special symbols in the folowing wisdom item: " << wisd.CountSighns(wisd.Text) << endl;
		cout << "Quantity of special symbols in the folowing wisdom item: " << wisd.CountSighns(wisd.Text) << endl;
	}
	
}

void Out(List &l, ofstream &ofst, int des)
{
	CheckOutputFile(ofst);
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
		current = nullptr;
		delete current;

	}
	string result = "----------------------------- \nThere are " + to_string(l.size) + " objects involving.\n";
	cout << result;
	ofst << result;
	ofst.close();
	
}

void Sort(List &l, int des)
{
	List::node *s, *ptr;
	WisdomItem *temp;
	if (l.Tail == nullptr)
	{
		return;
	}
	s = l.Tail->Next;

	while (s != l.Tail)
	{
		ptr = s->Next;
		while (ptr != l.Tail->Next)
		{
			if (ptr != l.Tail->Next)
			{
				switch (des)
				{
				case 0:
				{
					if (!Compare(*s->item, *ptr->item))
					{
						temp = s->item;
						s->item = ptr->item;
						ptr->item = temp;
					}
				}
				case 1:
				{
					if (Compare(*s->item, *ptr->item))
					{
						temp = s->item;
						s->item = ptr->item;
						ptr->item = temp;
					}
				}
				default:
					cout << "Wrong des in Sort function" << endl;
					break;
				}

			}
			else
			{
				break;
			}
			ptr = ptr->Next;
		}
		s = s->Next;
	}
}


bool Compare(WisdomItem item1, WisdomItem item2)
{
	return item1.quantityOfSpecialSymbols < item2.quantityOfSpecialSymbols;
}