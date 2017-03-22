#include <fstream>
#include <iostream>
#include "shape_atd.h"

using namespace std;

namespace simple_shapes {
	// Сигнатуры требуемых внешних функций
	ball* InBall(ifstream &ist);
	parallelepiped* InParallelepiped(ifstream &ist);
	tetrahedron* InTetrahedron(ifstream &ist);
	// Ввод параметров обобщенной фигуры из файла
	shape* In(ifstream &ifst)
	{
		shape *sp;
		int k;
		ifst >> k;
		switch(k) {
			case 1:
				sp = new shape;
				sp->key = shape::type::BALL;
				sp->obj = (void*)InBall(ifst);
				return sp;
			case 2:
				sp = new shape;
				sp->key = shape::type::PARALLELEPIPED;
				sp->obj = (void*)InParallelepiped(ifst);
				return sp;
			case 3:
				sp = new shape;
				sp->key = shape::type::TETRAHEDRON;
				sp->obj = (void*)InTetrahedron(ifst);
				return sp;
			default:
				return NULL;
		}
	}

	// Сигнатуры требуемых внешних функций.
	void OutBall(ball &b, ofstream &ofst);
	void OutParallelepiped(parallelepiped &p, ofstream &ofst);
	void OutTetrahedron(tetrahedron &t, ofstream &ofst);
	// Вывод параметров текущей фигуры в поток
	void Out(shape &s, ofstream &ofst) {
		switch (s.key) {
		case shape::type::BALL:
			OutBall(*(ball *)s.obj, ofst);
			break;
		case shape::type::PARALLELEPIPED:
			OutParallelepiped(*(parallelepiped *)s.obj, ofst);
			break;
		case shape::type::TETRAHEDRON:
			OutTetrahedron(*(tetrahedron *)s.obj, ofst);
			break;
		default:
			ofst << "Incorrect figure!" << endl;
		}
	}
} // end simple_shapes namespace