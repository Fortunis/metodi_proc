#include <fstream>
#include <iostream>
#include "tetrahedron_atd.h"

using namespace std;

namespace simple_shapes {
	// ���� ���������� �������������� �� �����
	tetrahedron* InTetrahedron(ifstream &ifst) {
		tetrahedron *t;
		t = new tetrahedron;
		ifst >> t->l >> t->d;
		return t;
	}

	// ����� ���������� �������������� � �����
	void OutTetrahedron(tetrahedron &t, ofstream &ofst) {
		ofst << "It is Tetrahedron: t = " << t.l << ", Density = " << t.d << endl;
	}

	double Volume(tetrahedron &b) {
		return sqrt(2)*b.l*b.l*b.l/12;
	}
} // end simple_shapes namespace