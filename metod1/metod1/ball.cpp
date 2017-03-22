#include <fstream>
#include <iostream>
#include "ball_atd.h"

using namespace std;

namespace simple_shapes {
	// Ввод параметров прямоугольника из файла
	ball* InBall(ifstream &ifst) {
		ball *b;
		b = new ball;
		ifst >> b->r >> b->d;
		return b;
	}

	// Вывод параметров прямоугольника в поток
	void OutBall(ball &b, ofstream &ofst) {
		ofst << "It is Ball: r = " << b.r << ", Density = "<< b.d << endl;
	}

} // end simple_shapes namespace