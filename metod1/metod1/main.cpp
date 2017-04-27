#include <iostream>
#include <fstream>
#include "container_atd.h"
#include "ContainerTest.h"
#include "ShapeTest.h"
#include "BallTest.h"
#include "ParallelepipedTest.h"
#include "TetrahedronTest.h"
#include "gtest/gtest.h"

using namespace std;

namespace simple_shapes {
	// Сигнатуры требуемых внешних функций
	void Clear(container &c);
	void In(container &c, ifstream &ifst);
	void Out(container &c, ofstream &ofst);
	void OutBall(container &c, ofstream &ofst);
	void Sort(container &c);
}


using namespace simple_shapes;

int main(int argc, char* argv[]) {
	/*if(argc !=3) {
		cout << "incorrect command line! "
		"Waited: command infile outfile" << endl;
		exit(1);
	}

	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);

	cout << "Start"<< endl;
	container c;
	In(c, ifst);
	ofst << "Filled container. " << endl;
	Out(c, ofst);
	OutBall(c, ofst);
	Sort(c);
	ofst << "Sorted container. " << endl;
	Out(c, ofst);
	Clear(c);
	ofst << "Empty container. " << endl;
	Out(c, ofst);
	cout << "Stop"<< endl;*/

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}