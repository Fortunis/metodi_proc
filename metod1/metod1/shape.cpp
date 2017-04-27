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
		if (!ifst) {
			cerr << "Error: no input file!" << endl;
			exit(1);
		}
		ifst >> k;
		if (ifst.fail()){
			cout << "Wrong input!" << endl;
			exit(1);
		}
		if (!(1 <= k && k <= 3)) {
			cerr << "Error: unknown type" << endl;
			exit(1);
		}
		if (ifst.eof()) {
			cerr << "Error: no data after type!" << endl;
			exit(1);
		}
		
		switch(k) {
			case 1:
				sp = new shape;
				sp->key = shape::type::BALL;
				sp->obj = (void*)InBall(ifst);
				break;
			case 2:
				sp = new shape;
				sp->key = shape::type::PARALLELEPIPED;
				sp->obj = (void*)InParallelepiped(ifst);
				break;
			case 3:
				sp = new shape;
				sp->key = shape::type::TETRAHEDRON;
				sp->obj = (void*)InTetrahedron(ifst);
				break;
			default:
				cerr << "Incorrect figure!" << endl;
				return NULL;
		}
		ifst >> sp->temperature;
		if (ifst.fail()){
			cout << "Wrong input!" << endl;
			exit(1);
		}
		return sp;
	}

	// Сигнатуры требуемых внешних функций.
	void OutBall(ball &b, ofstream &ofst);
	void OutParallelepiped(parallelepiped &p, ofstream &ofst);
	void OutTetrahedron(tetrahedron &t, ofstream &ofst);
	// Вывод параметров текущей фигуры в поток
	void Out(shape &s, ofstream &ofst) {
		if (!ofst) {
			cerr << "Error: no output file!" << endl;
			exit(1);
		}
		
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
		ofst << "temperature = " << s.temperature << endl;
	}

	double Volume(ball &b);
	double Volume(parallelepiped &p);
	double Volume(tetrahedron &p);

	double Volume(shape &s) {
		switch (s.key) {
		case shape::type::BALL:
			return Volume(*(ball *)s.obj);
		case shape::type::PARALLELEPIPED:
			return Volume(*(parallelepiped *)s.obj);
		case shape::type::TETRAHEDRON:
			return Volume(*(tetrahedron *)s.obj);
		default:
			return 0;
		}
	}

	//-----------------------------------------------------
	// Cравнение ключей двух программных объектов
	bool Compare(shape *first, shape *second) {
		return Volume(*first) < Volume(*second);
	}

} // end simple_shapes namespace