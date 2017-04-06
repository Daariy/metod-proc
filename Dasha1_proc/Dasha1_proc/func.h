#include <fstream>
#include <string>
using namespace std;

enum key { AFORYSM, POSLOVICA };
struct Aforysm
{
	char Author[256];
};

struct Poslovica
{
	char Country[256];

};

struct  WisdomItem
{
	char Text[256];

	key k;

	void* someType;
	int CountSighns(char* Text)
	{
		char c;
		int count = 0;
		for (int i = 0; i < strlen(Text); i++)
		{
			c = Text[i];
			if (c == ',' || c == '.' || c == '?' || c == '!')
			{
				count++;
			}
		}
		/*cout << "Quantity of special symbols : " << count << endl;
		ofst << "Quantity of special symbols : " << count << endl;*/
		return count;
	}
	int quantityOfSpecialSymbols = 0;
};

struct List
{
	struct node
	{
		WisdomItem* item = nullptr;
		node* Next = nullptr;
	};

	node *Head = nullptr, *Tail = nullptr, *Current = nullptr;
	int size = 0;
};

WisdomItem* In(ifstream &ifst);
Aforysm* Inn(ifstream &ifst);
Poslovica* Inc(ifstream &ifst);

void OutA(Aforysm &af, ostream &ofst);
void OutP(Poslovica &ps, ostream &ofst);

void Clear(List &l);
void Add(List &l, WisdomItem &el);
void In(List &l, ifstream &ifst);
void Out(List &l, ofstream &ofst);

