#include <fstream>
#include <iostream>
#include "tetrahedron_atd.h"

using namespace std;

namespace simple_shapes {
	// Ввод параметров прямоугольника из файла
	tetrahedron* InTetrahedron(ifstream &ifst) {
		tetrahedron *t;
		t = new tetrahedron;
		ifst >> t->l >> t->d;
		return t;
	}

	// Вывод параметров прямоугольника в поток
	void OutTetrahedron(tetrahedron &t, ofstream &ofst) {
		ofst << "It is Tetrahedron: t = " << t.l << ", Density = " << t.d << endl;
	}
} // end simple_shapes namespace