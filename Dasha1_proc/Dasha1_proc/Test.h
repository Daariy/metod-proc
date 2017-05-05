#include <iostream>
#include <fstream>
//#include "func.h"
#include "FilesCmp.h"
#include "gtest/gtest.h"

using namespace std;

class ListTest : public ::testing::Test {
};

TEST_F(ListTest, CheckClear)
{
	ifstream ifst("ListInput.txt");
	ofstream ofst("ListTest.txt");

	List c;
	In(c, ifst);
	Clear(c);
	Out(c, ofst, 0);
	ifst.close();
	ofst.close();

	ifstream actual("ListTest.txt");
	ifstream expected("ListClear.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ListTest, CheckOutAforysm)
{
	ifstream ifst("ListInput.txt");
	ofstream ofst("ListTest.txt");

	List c;
	In(c, ifst);
	Out(c, ofst,1);
	ifst.close();
	ofst.close();

	ifstream actual("ListTest.txt");
	ifstream expected("ListOutAforysm.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ListTest, CheckOutPoslovica)
{
	ifstream ifst("ListInput.txt");
	ofstream ofst("ListTest.txt");

	List c;
	In(c, ifst);
	Out(c, ofst,2);
	ifst.close();
	ofst.close();

	ifstream actual("ListTest.txt");
	ifstream expected("ListOutPoslovica.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ListTest, CheckOutRiddle)
{
	ifstream ifst("ListInput.txt");
	ofstream ofst("ListTest.txt");

	List c;
	In(c, ifst);
	Out(c, ofst,3);
	ifst.close();
	ofst.close();

	ifstream actual("ListTest.txt");
	ifstream expected("ListOutRiddle.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ListTest, CheckSort1)
{
	ifstream ifst("ListInput.txt");
	ofstream ofst("ListTest.txt");

	List c;
	In(c, ifst);
	Sort(c,1);
	Out(c, ofst,0);
	ifst.close();
	ofst.close();

	ifstream actual("ListTest.txt");
	ifstream expected("ListSorted1.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ListTest, CheckSort0)
{
	ifstream ifst("ListInput.txt");
	ofstream ofst("ListTest.txt");

	List c;
	In(c, ifst);
	Sort(c, 0);
	Out(c, ofst, 0);
	ifst.close();
	ofst.close();

	ifstream actual("ListTest.txt");
	ifstream expected("ListSorted0.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ListTest, CheckSortEqual)
{
	ifstream ifst("ListEqual.txt");
	ofstream ofst("ListTest.txt");

	List c;
	In(c, ifst);
	Sort(c,1);
	Out(c, ofst,0);
	ifst.close();
	ofst.close();

	ifstream actual("ListTest.txt");
	ifstream expected("ListSortEqual.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

class WisdomItemTest : public ::testing::Test {
};

TEST_F(WisdomItemTest, CheckCountSighns)
{
	WisdomItem a;
	strcpy_s(a.text,"...");
	int expected = 3;
	ASSERT_EQ(expected, a.CountSighns(a.text));
}

TEST_F(WisdomItemTest, CheckCountSighnsZero)
{
	WisdomItem a;
	strcpy_s(a.text, "");
	int expected = 0;
	ASSERT_EQ(expected, a.CountSighns(a.text));
}

TEST_F(WisdomItemTest, CheckCompare)
{
	WisdomItem s1;
	strcpy_s(s1.text, "..");
	s1.quantityOfSpecialSymbols = s1.CountSighns(s1.text);

	WisdomItem s2;
	strcpy_s(s2.text, "...");
	s2.quantityOfSpecialSymbols = s2.CountSighns(s2.text);

	ASSERT_TRUE(Compare(s1, s2));
}

TEST_F(WisdomItemTest, CheckInputAforysm)
{
	ifstream ifst("WisdomItemInAforysm.txt");
	WisdomItem* actual = In(ifst);

	WisdomItem* expected;
	expected = new WisdomItem;
	expected->k = AFORYSM;
	strcpy_s(expected->text,"qwerty..");
	expected->grade = 7;

	ASSERT_TRUE(expected->k == actual->k);
	ASSERT_STREQ(expected->text, actual->text);
	ASSERT_EQ(expected->grade, actual->grade);
}

TEST_F(WisdomItemTest, CheckInputPoslovica)
{
	ifstream ifst("WisdomItemInPoslovica.txt");
	WisdomItem* actual = In(ifst);

	WisdomItem* expected;
	expected = new WisdomItem;
	expected->k = POSLOVICA;
	strcpy_s(expected->text, "qwerty..");
	expected->grade = 7;

	ASSERT_TRUE(expected->k == actual->k);
	ASSERT_STREQ(expected->text, actual->text);
	ASSERT_EQ(expected->grade, actual->grade);
}

TEST_F(WisdomItemTest, CheckInputRiddle)
{
	ifstream ifst("WisdomItemInRiddle.txt");
	WisdomItem* actual = In(ifst);

	WisdomItem* expected;
	expected = new WisdomItem;
	expected->k = RIDDLE;
	strcpy_s(expected->text, "qwerty..");
	expected->grade = 7;

	ASSERT_TRUE(expected->k == actual->k);
	ASSERT_STREQ(expected->text, actual->text);
	ASSERT_EQ(expected->grade, actual->grade);
}

TEST_F(WisdomItemTest, CheckOutputAforysm)
{
	ofstream ofst("WisdomItemOutTest.txt");

	WisdomItem* s;
	s = new WisdomItem;
	s->k = AFORYSM;
	Aforysm *a;
	a = new Aforysm;
	strcpy_s(a->Author, "Dasha");
	s->someType = (void*)a;
	s->grade = 7;
	strcpy_s(s->text, "qwerty..");

	Writeinfo(*s, ofst,0);
	ofst.close();

	ifstream expected("WisdomItemOutAforysm.txt");
	ifstream actual("WisdomItemOutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(WisdomItemTest, CheckOutputPoslovica)
{
	ofstream ofst("WisdomItemOutTest.txt");

	WisdomItem* s;
	s = new WisdomItem;
	s->k = POSLOVICA;
	Poslovica *a;
	a = new Poslovica;
	strcpy_s(a->Country, "Russia");
	s->someType = (void*)a;
	s->grade = 7;
	strcpy_s(s->text, "qwerty..");

	Writeinfo(*s, ofst, 0);
	ofst.close();

	ifstream expected("WisdomItemOutPoslovica.txt");
	ifstream actual("WisdomItemOutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(WisdomItemTest, CheckOutputRiddle)
{
	ofstream ofst("WisdomItemOutTest.txt");

	WisdomItem* s;
	s = new WisdomItem;
	s->k = RIDDLE;
	Riddle *a;
	a = new Riddle;
	strcpy_s(a->Answer, "Dasha");
	s->someType = (void*)a;
	s->grade = 7;
	strcpy_s(s->text, "qwerty..");

	Writeinfo(*s, ofst, 0);
	ofst.close();

	ifstream expected("WisdomItemOutRiddle.txt");
	ifstream actual("WisdomItemOutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

class AforysmTest : public ::testing::Test {
};

TEST_F(AforysmTest, CheckInput)
{
	ifstream ifst("InAforysm.txt");
	Aforysm* actual = Inn(ifst);
	Aforysm b;
	strcpy_s(b.Author,"Dasha");

	ASSERT_STREQ(actual->Author, b.Author);
}

TEST_F(AforysmTest, CheckOutput)
{
	ofstream ofst("OutTest.txt");
	Aforysm b;
	strcpy_s(b.Author,"Dasha");
	OutA(b, ofst);
	ofst.close();

	ifstream expected("OutAforysm.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}


class PoslovicaTest : public ::testing::Test {
};

TEST_F(PoslovicaTest, CheckInput)
{
	ifstream ifst("InPoslovica.txt");
	Poslovica* actual = Inc(ifst);
	Poslovica b;
	strcpy_s(b.Country, "Russia");

	ASSERT_STREQ(actual->Country, b.Country);
}

TEST_F(PoslovicaTest, CheckOutput)
{
	ofstream ofst("OutTest.txt");
	Poslovica b;
	strcpy_s(b.Country, "Russia");
	OutP(b, ofst);
	ofst.close();

	ifstream expected("OutPoslovica.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

class RiddleTest : public ::testing::Test {
};

TEST_F(RiddleTest, CheckInput)
{
	ifstream ifst("InRiddle.txt");
	Riddle* actual = Inr(ifst);
	Riddle b;
	strcpy_s(b.Answer, "Dasha");

	ASSERT_STREQ(actual->Answer, b.Answer);
}

TEST_F(RiddleTest, CheckOutput)
{
	ofstream ofst("OutTest.txt");
	Riddle b;
	strcpy_s(b.Answer, "Dasha");
	OutR(b, ofst);
	ofst.close();

	ifstream expected("OutRiddle.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}
