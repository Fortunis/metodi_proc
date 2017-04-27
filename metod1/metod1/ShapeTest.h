#include <iostream>
#include <fstream>
#include "ball_atd.h"
#include "parallelepiped_atd.h"
#include "tetrahedron_atd.h"
#include "shape_atd.h"
#include "FilesCmp.h"
#include "gtest/gtest.h"

using namespace std;
using namespace simple_shapes;

namespace simple_shapes {
	
	shape* In(ifstream &ifst);
	bool Compare(shape *first, shape *second);
	void Out(shape &s, ofstream &ofst);
}

class ShapeTest : public ::testing::Test {
};

TEST_F(ShapeTest, CheckInputBall)
{
	ifstream ifst("ShapeInBall.txt");
	shape* actual = In(ifst);

	shape* expected;
	expected = new shape;
	expected->key = shape::type::BALL;
	expected->temperature = 4;

	ASSERT_TRUE(expected->key == actual->key);
	ASSERT_EQ(expected->temperature, actual->temperature);
}

TEST_F(ShapeTest, CheckInputParallelepiped)
{
	ifstream ifst("ShapeInParallelepiped.txt");
	shape* actual = In(ifst);

	shape* expected;
	expected = new shape;
	expected->key = shape::type::PARALLELEPIPED;
	expected->temperature = 4;

	ASSERT_TRUE(expected->key == actual->key);
	ASSERT_EQ(expected->temperature, actual->temperature);
}

TEST_F(ShapeTest, CheckInputTetrahedron)
{
	ifstream ifst("ShapeInTetrahedron.txt");
	shape* actual = In(ifst);

	shape* expected;
	expected = new shape;
	expected->key = shape::type::TETRAHEDRON;
	expected->temperature = 4;

	ASSERT_TRUE(expected->key == actual->key);
	ASSERT_EQ(expected->temperature, actual->temperature);
}

TEST_F(ShapeTest, CheckOutputBall)
{
	ofstream ofst("ShapeOutTest.txt");

	shape* s;
	s = new shape;
	s->key = shape::type::BALL;
	ball *b;
	b = new ball;
	b->r = 2;
	b->d = 3;
	s->obj = (void*)b;
	s->temperature = 4;

	Out(*s, ofst);
	ofst.close();

	ifstream expected("ShapeOutBall.txt");
	ifstream actual("ShapeOutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ShapeTest, CheckOutputParallelepiped)
{
	ofstream ofst("ShapeOutTest.txt");

	shape* s;
	s = new shape;
	s->key = shape::type::PARALLELEPIPED;
	parallelepiped *p;
	p = new parallelepiped;
	p->a = 2;
	p->b = 2;
	p->c = 2;
	p->d = 3;
	s->obj = (void*)p;
	s->temperature = 4;

	Out(*s, ofst);
	ofst.close();

	ifstream expected("ShapeOutParallelepiped.txt");
	ifstream actual("ShapeOutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ShapeTest, CheckOutputTetrahedron)
{
	ofstream ofst("ShapeOutTest.txt");

	shape* s;
	s = new shape;
	s->key = shape::type::TETRAHEDRON;
	tetrahedron *t;
	t = new tetrahedron;
	t->l = 2;
	t->d = 3;
	s->obj = (void*)t;
	s->temperature = 4;

	Out(*s, ofst);
	ofst.close();

	ifstream expected("ShapeOutTetrahedron.txt");
	ifstream actual("ShapeOutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}


TEST_F(ShapeTest, CheckCompare)
{
	shape* s1;
	s1 = new shape;
	s1->key = shape::type::TETRAHEDRON;
	tetrahedron *t1;
	t1 = new tetrahedron;
	t1->l = 2;
	t1->d = 3;
	s1->obj = (void*)t1;
	s1->temperature = 4;

	shape* s2;
	s2 = new shape;
	s2->key = shape::type::TETRAHEDRON;
	tetrahedron *t2;
	t2 = new tetrahedron;
	t2->l = 3;
	t2->d = 3;
	s2->obj = (void*)t2;
	s2->temperature = 4;

	ASSERT_TRUE(Compare(s1, s2));
}