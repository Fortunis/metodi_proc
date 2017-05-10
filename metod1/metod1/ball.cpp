#include <fstream>
#include <iostream>
#include "ball_atd.h"

using namespace std;

namespace simple_shapes {
	// Ввод параметров прямоугольника из файла
	ball* InBall(ifstream &ifst) {
		ball *b;
		b = new ball;
		if (!ifst) {
			cerr << "Error: no input file!" << endl;
			exit(1);
		}
		ifst >> b->r;
		if (ifst.fail()) {
			cout << "Wrong input!" << endl;
			exit(1);
		}
		if (b->r <= 0) {
			cerr << "Error: Incorrect values in ball input" << endl;
			exit(1);
		}
		return b;
	}

	// Вывод параметров прямоугольника в поток
	void OutBall(ball &b, ostream &ofst) {
		if (!ofst) {
			cerr << "Error: no output file!" << endl;
			exit(1);
		}
		ofst << "It is Ball: r = " << b.r << endl;
	}

	double Volume(ball &b) {
		double v = 4 * 3.14*b.r*b.r*b.r / 3;
		if (abs((v * 3 / (4 * 3.14 *b.r*b.r)) -  b.r) >= 0.00001) {
			cerr << "ERROR VOLUME OVERFLOW" << endl;
			return 0;
		}
		return 4*3.14*b.r*b.r*b.r/3;
	}

} // end simple_shapes namespace