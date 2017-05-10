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
	if (!(1 <= num && num <= 3)) 
	{
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
			ifst.getline(ws->text, 256);
			CheckWrongInput(ifst);
			ws->k = AFORYSM;
			ws->someType = (void*)Inn(ifst);
			break;
		}
		case 2:
		{
			ws = new WisdomItem;
			ifst.getline(ws->text, 256);
			CheckWrongInput(ifst);
			ws->k = POSLOVICA;
			ws->someType = (void*)Inc(ifst);
			break;
		}
		case 3:
		{
			ws = new WisdomItem;
			ifst.getline(ws->text, 256);
			CheckWrongInput(ifst);
			ws->k = RIDDLE;
			ws->someType = (void*)Inr(ifst);
			break;
		}
		default:
			break;
	}

	ws->quantityOfSpecialSymbols = ws->CountSighns(ws->text);
	ifst >> ws->grade;
	CheckWrongInput(ifst);
	Checkgrade(ws->grade);
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
		List::node *temp = l.head->next;
		delete l.head;
		l.head = temp;
		--l.size;
	}

	l.head = nullptr;
	l.tail = nullptr;
	l.current = nullptr;
}

void Add(List &l, WisdomItem &el)
{
	++l.size;
	List::node* temp = new List::node;
	temp->item = &el;
	temp->next = l.head;
	l.current = temp;

	if (l.head != nullptr)
	{
		l.tail->next = temp;
		l.tail = temp;
	}
	else
	{
		l.head = l.tail = temp;
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
			ofst << wisd.text << endl;
			OutA(*((Aforysm*)wisd.someType), cout);
			cout << wisd.text << endl;
			ofst << "The grade of the following statement is: " << wisd.grade << endl;
			cout << "The grade of the following statement is: " << wisd.grade << endl;
			ofst << "Quantity of special symbols in the folowing wisdom item: " << wisd.CountSighns(wisd.text) << endl;
			cout << "Quantity of special symbols in the folowing wisdom item: " << wisd.CountSighns(wisd.text) << endl;
		}
	}
	if (des == 2)
	{
		if (wisd.k == POSLOVICA)
		{
			OutP(*((Poslovica*)wisd.someType), ofst);
			ofst << wisd.text << endl;
			
			OutP(*((Poslovica*)wisd.someType), cout);
			cout << wisd.text << endl;
			ofst << "The grade of the following statement is: " << wisd.grade << endl;
			cout << "The grade of the following statement is: " << wisd.grade << endl;
			ofst << "Quantity of special symbols in the folowing wisdom item: " << wisd.CountSighns(wisd.text) << endl;
			cout << "Quantity of special symbols in the folowing wisdom item: " << wisd.CountSighns(wisd.text) << endl;
		}

	}
	if (des == 3)
	{
		if (wisd.k == RIDDLE)
		{
			OutR(*((Riddle*)wisd.someType), ofst);
			ofst << wisd.text << endl;
			OutR(*((Riddle*)wisd.someType), cout);
			cout << wisd.text << endl;
			ofst << "The grade of the following statement is: " << wisd.grade << endl;
			cout << "The grade of the following statement is: " << wisd.grade << endl;
			ofst << "Quantity of special symbols in the folowing wisdom item: " << wisd.CountSighns(wisd.text) << endl;
			cout << "Quantity of special symbols in the folowing wisdom item: " << wisd.CountSighns(wisd.text) << endl;
		}
		
	}
	if (des == 0)
	{
		if (wisd.k == AFORYSM)
		{
			OutA(*((Aforysm*)wisd.someType), ofst);
			ofst << wisd.text << endl;
			OutA(*((Aforysm*)wisd.someType), cout);
			cout << wisd.text << endl;

		}
		if (wisd.k == POSLOVICA)
		{
			OutP(*((Poslovica*)wisd.someType), ofst);
			ofst << wisd.text << endl;
			OutP(*((Poslovica*)wisd.someType), cout);
			cout << wisd.text << endl;

		}
		if (wisd.k == RIDDLE)
		{
			OutR(*((Riddle*)wisd.someType), ofst);
			ofst << wisd.text << endl;
			OutR(*((Riddle*)wisd.someType), cout);
			cout << wisd.text << endl;

		}
		ofst << "The grade of the following statement is: " << wisd.grade << endl;
		cout << "The grade of the following statement is: " << wisd.grade << endl;
		ofst << "Quantity of special symbols in the folowing wisdom item: " << wisd.CountSighns(wisd.text) << endl;
		cout << "Quantity of special symbols in the folowing wisdom item: " << wisd.CountSighns(wisd.text) << endl;
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

	WisdomItem* tmp = new WisdomItem;
	for (int i = 0; i < l.size; i++)
	{
		l.current = l.current->next;
		tmp = (WisdomItem*)l.current->item;

		Writeinfo(*tmp, ofst, des);
		tmp = nullptr;
		delete tmp;

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
	if (l.tail == nullptr)
	{
		return;
	}
	s = l.tail->next;

	while (s != l.tail)
	{
		ptr = s->next;
		while (ptr != l.tail->next)
		{
			if (ptr != l.tail->next)
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
			ptr = ptr->next;
		}
		s = s->next;
	}
}


bool Compare(WisdomItem item1, WisdomItem item2)
{
	return item1.quantityOfSpecialSymbols < item2.quantityOfSpecialSymbols;
}

void Multimethod(List &l, ofstream &ofst)
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
			ofst << "Multimethods:\n";
			cout << "Multimethods:\n";
		}
		else
		{
			ofst << "Container is empty:\n";
			cout << "Container is empty:\n";
		}

		List::node* currentNode = nullptr;
		for (int i = 0; i < l.size; i++)
		{
			l.current = l.current->next;
			currentNode = l.current;
			for (int j = 0; j < l.size; j++)
			{
				switch (l.current->item->k)
				{
				case AFORYSM:
				{
					switch (currentNode->item->k)
					{
					case AFORYSM:
					{
						ofst << "Aforysm and Aforysm:\n";
						cout << "Aforysm and Aforysm:\n";
						break;
					}
					case POSLOVICA:
					{
						ofst << "Aforysm and Poslovica:\n";
						cout << "Aforysm and Posovica:\n";
						break;
					}
					case RIDDLE:
					{
						ofst << "Aforysm and Riddle:\n";
						cout << "Aforysm and Riddle:\n";
						break;
					}
					default:
						break;
					}
					break;
				}
				case POSLOVICA:
				{
					switch (currentNode->item->k)
					{
					case AFORYSM:
					{
						ofst << "Poslovica and Aforysm:\n";
						cout << "Poslovica and Aforysm:\n";
						break;
					}
					case POSLOVICA:
					{
						ofst << "Poslovica and Poslovica:\n";
						cout << "Poslovica and Poslovica:\n";
						break;
					}
					case RIDDLE:
					{
						ofst << "Poslovica and Riddle:\n";
						cout << "Poslovica and Riddle:\n";
						break;
					}
					default:
						break;
					}
					break;
				}
				case RIDDLE:
				{
					switch (currentNode->item->k)
					{
					case AFORYSM:
					{
						ofst << "Riddle and Aforysm:\n";
						cout << "Riddle and Aforysm:\n";
						break;
					}
					case POSLOVICA:
					{
						ofst << "Riddle and Poslovica:\n";
						cout << "Riddle and Poslovica:\n";
						break;
					}
					case RIDDLE:
					{
						ofst << "Riddle and Riddle:\n";
						cout << "Riddle and Riddle:\n";
						break;
					}
					default:
						break;
					}
					break;
				}
				default:
					break;
				}

				Writeinfo(*l.current->item, ofst, 0);
				Writeinfo(*currentNode->item, ofst, 0);
				ofst << endl;
				cout << endl;
				currentNode = currentNode->next;
			}
		}
		ofst.close();
	}
}