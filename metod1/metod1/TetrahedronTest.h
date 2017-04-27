#include <iostream>
#include <fstream>
#include "tetrahedron_atd.h"
#include "FilesCmp.h"
#include "gtest/gtest.h"

using namespace std;
using namespace simple_shapes;

namespace simple_shapes {
	double Volume(tetrahedron &t);
	tetrahedron* InTetrahedron(ifstream &ifst);
	void OutTetrahedron(tetrahedron &t, ofstream &ofst);
}

class TetrahedronTest : public ::testing::Test {
};

TEST_F(TetrahedronTest, CheckVolume){
	tetrahedron t;
	t.l = 6;
	t.d = 0;
	double expected = 25.4558;
	ASSERT_NEAR(expected, Volume(t), 0.01);
}

TEST_F(TetrahedronTest, CheckInput){
	ifstream ifst("InTetrahedron.txt");
	tetrahedron* actual = InTetrahedron(ifst);
	tetrahedron t;
	t.l = 2;
	t.d = 3;

	ASSERT_EQ(actual->l, t.l);
	ASSERT_NEAR(actual->d, t.d, 0.01);
}

TEST_F(TetrahedronTest, CheckOutput){
	ofstream ofst("OutTest.txt");
	tetrahedron t;
	t.l = 2;
	t.d = 3;
	OutTetrahedron(t, ofst);
	ofst.close();

	ifstream expected("OutTetrahedron.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}
