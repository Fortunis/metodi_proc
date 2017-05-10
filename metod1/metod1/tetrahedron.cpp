#include <fstream>
#include <iostream>
#include "tetrahedron_atd.h"

using namespace std;

namespace simple_shapes {
	// Ввод параметров прямоугольника из файла
	tetrahedron* InTetrahedron(ifstream &ifst) {
		tetrahedron *t;
		t = new tetrahedron;
		if (!ifst) {
			cerr << "Error: no input file!" << endl;
			exit(1);
		}
		ifst >> t->l;
		if (ifst.fail()) {
			cout << "Wrong input!" << endl;
			exit(1);
		}
		if (t->l <= 0) {
			cerr << "Error: Incorrect values in tetrahedron input" << endl;
			exit(1);
		}
		return t;
	}

	// Вывод параметров прямоугольника в поток
	void OutTetrahedron(tetrahedron &t, ostream &ofst) {
		if (!ofst) {
			cerr << "Error: no output file!" << endl;
			exit(1);
		}
		ofst << "It is Tetrahedron: t = " << t.l << endl;
	}

	double Volume(tetrahedron &b) {
		double v = sqrt(2)*b.l*b.l*b.l / 12;
		if (abs((v * 12 / (sqrt(2)*b.l*b.l)) - b.l) >= 0.00001) {
			cerr << "ERROR VOLUME OVERFLOW" << endl;
			return 0;
		}
		return sqrt(2)*b.l*b.l*b.l/12;
	}
} // end simple_shapes namespace