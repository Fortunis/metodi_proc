#include <fstream>
#include <iostream>
#include "parallelepiped_atd.h"

using namespace std;

namespace simple_shapes {
	// Ввод параметров треугольника из потока
	parallelepiped* InParallelepiped(ifstream &ifst) {
		parallelepiped *p;
		p = new parallelepiped;
		if (!ifst) {
			cerr << "Error: no input file!" << endl;
			exit(1);
		}
		ifst >> p->a >> p->b >> p->c >> p->d;
		if (ifst.fail()) {
			cout << "Wrong input!" << endl;
			exit(1);
		}
		if (p->a <= 0 || p->b <= 0 || p->c <= 0 || p->d <= 0) {
			cerr << "Error: Incorrect values in parallelepiped input" << endl;
			exit(1);
		}
		return p;
	}

	// Вывод параметров треугольника в поток
	void OutParallelepiped(parallelepiped &p, ofstream &ofst) {
		if (!ofst) {
			cerr << "Error: no output file!" << endl;
			exit(1);
		}
		ofst << "It is Parallelepiped: a = "
		<< p.a << ", b = " << p.b
		<< ", c = " << p.c 
		<< ", Density = " << p.d << endl;
	}

	double Volume(parallelepiped &p) {
		double v = p.a * p.b * p.c;
		if (abs(v / (p.a* p.b) - p.c) >= 0.00001) {
			cerr << "ERROR VOLUME OVERFLOW" << endl;
			return 0;
		}
		return p.a*p.b*p.c;
	}

} // end simple_shapes namespace