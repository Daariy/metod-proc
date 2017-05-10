#include <fstream>
#include <string>
using namespace std;

enum key { AFORYSM, POSLOVICA, RIDDLE};
struct Aforysm
{
	char Author[256];
};

struct Poslovica
{
	char Country[256];
};
struct Riddle
{
	char Answer[256];
};
struct  WisdomItem // структура, обобщающа¤ все имеющиес¤ составл¤ющие кладезь мудрости элементы
{
	char text[256];

	int grade = 0;

	key k; // ключ

	void* someType;
	int CountSighns(char* text)
	{
		char c;
		int count = 0;
		for (int i = 0; i < strlen(text); i++)
		{
			c = text[i];
			if (c == ',' || c == '.' || c == '?' || c == '!')
			{
				count++;
			}
		}

		return count;
	}
	int quantityOfSpecialSymbols = 0;
};

struct List
{
	struct node
	{
		WisdomItem* item = nullptr;
		node* next = nullptr;
	};

	node *head = nullptr, *tail = nullptr, *current = nullptr; //ѕервый элемент,текущий и тот что последний
	int size = 0; //„исло элементов в списке	
};

WisdomItem* In(ifstream &ifst);
Aforysm* Inn(ifstream &ifst);
Poslovica* Inc(ifstream &ifst);
Riddle* Inr(ifstream &ifst);
void Writeinfo(WisdomItem &wisd, ofstream &ofst, int des);

void OutA(Aforysm &af, ostream &ofst);
void OutP(Poslovica &ps, ostream &ofst);
void OutR(Riddle &ps, ostream &ofst);

void Clear(List &l);
void Add(List &l, WisdomItem &el);
void In(List &l, ifstream &ifst);

void Out(List &l, ofstream &ofst, int des);

void Sort(List &l,int des);
bool Compare(WisdomItem item1, WisdomItem item2);
void Multimethod(List &l, ofstream &ofst);
