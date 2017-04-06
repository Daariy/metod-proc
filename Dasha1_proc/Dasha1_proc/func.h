
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
	char Text[256];

	int Grade = 0;

	key k; // ключ

	void* someType;
};

struct List
{
	struct node
	{
		WisdomItem* item = nullptr;
		node* Next = nullptr;
	};

	node *Head = nullptr, *Tail = nullptr, *Current = nullptr; //ѕервый элемент,текущий и тот что последний
	int size = 0; //„исло элементов в списке	
};

WisdomItem* In(ifstream &ifst);
Aforysm* Inn(ifstream &ifst);
Poslovica* Inc(ifstream &ifst);
Riddle* Inr(ifstream &ifst);

void OutA(Aforysm &af, ostream &ofst);
void OutP(Poslovica &ps, ostream &ofst);
void OutR(Riddle &ps, ostream &ofst);

void Clear(List &l);
void Add(List &l, WisdomItem &el);
void In(List &l, ifstream &ifst);
void Out(List &l, ofstream &ofst, int des);