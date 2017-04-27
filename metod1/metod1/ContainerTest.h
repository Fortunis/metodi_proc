#include <iostream>
#include <fstream>
#include "container_atd.h"
#include "shape_atd.h"
#include "FilesCmp.h"
#include "gtest/gtest.h"

using namespace std;
using namespace simple_shapes;

namespace simple_shapes {
	// Сигнатуры требуемых внешних функций
	void Clear(container &c);
	void In(container &c, ifstream &ifst);
	void Out(container &c, ofstream &ofst);
	void OutBall(container &c, ofstream &ofst);
	void OutParallelepiped(container &c, ofstream &ofst);
	void OutTetrahedron(container &c, ofstream &ofst);
	void Sort(container &c);
}

class ContainerTest : public ::testing::Test {
};

TEST_F(ContainerTest, CheckClear){
	ifstream ifst("ContainerInput.txt");
	ofstream ofst("ContainerTest.txt");

	container c;
	In(c, ifst);
	Clear(c);
	Out(c, ofst);
	ifst.close();
	ofst.close();

	ifstream actual("ContainerTest.txt");
	ifstream expected("ContainerClear.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckOutBall){
	ifstream ifst("ContainerInput.txt");
	ofstream ofst("ContainerTest.txt");

	container c;
	In(c, ifst);
	OutBall(c,ofst);
	ifst.close();
	ofst.close();

	ifstream actual("ContainerTest.txt");
	ifstream expected("ContainerOutBall.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckOutParallelepiped){
	ifstream ifst("ContainerInput.txt");
	ofstream ofst("ContainerTest.txt");

	container c;
	In(c, ifst);
	OutParallelepiped(c, ofst);
	ifst.close();
	ofst.close();

	ifstream actual("ContainerTest.txt");
	ifstream expected("ContainerOutParallelepiped.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckOutTetrahedron){
	ifstream ifst("ContainerInput.txt");
	ofstream ofst("ContainerTest.txt");

	container c;
	In(c, ifst);
	OutTetrahedron(c, ofst);
	ifst.close();
	ofst.close();

	ifstream actual("ContainerTest.txt");
	ifstream expected("ContainerOutTetrahedron.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckSort){
	ifstream ifst("ContainerInput.txt");
	ofstream ofst("ContainerTest.txt");

	container c;
	In(c, ifst);
	Sort(c);
	Out(c, ofst);
	ifst.close();
	ofst.close();

	ifstream actual("ContainerTest.txt");
	ifstream expected("ContainerSorted.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckSortEmpty){
	ifstream ifst("Empty.txt");
	ofstream ofst("ContainerTest.txt");

	container c;
	In(c, ifst);
	Sort(c);
	Out(c, ofst);
	ifst.close();
	ofst.close();

	ifstream actual("ContainerTest.txt");
	ifstream expected("ContainerSortEmpty.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckSortEqual){
	ifstream ifst("ContainerEqual.txt");
	ofstream ofst("ContainerTest.txt");

	container c;
	In(c, ifst);
	Sort(c);
	Out(c, ofst);
	ifst.close();
	ofst.close();

	ifstream actual("ContainerTest.txt");
	ifstream expected("ContainerSortEqual.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}