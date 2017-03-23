#include <fstream>
#include <iostream>
#include "shape_atd.h"

using namespace std;

namespace simple_shapes {
	// ��������� ��������� ������� �������
	ball* InBall(ifstream &ist);
	parallelepiped* InParallelepiped(ifstream &ist);
	tetrahedron* InTetrahedron(ifstream &ist);
	// ���� ���������� ���������� ������ �� �����
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
				return NULL;
		}
		ifst >> sp->temperature;
		return sp;
	}

	// ��������� ��������� ������� �������.
	void OutBall(ball &b, ofstream &ofst);
	void OutParallelepiped(parallelepiped &p, ofstream &ofst);
	void OutTetrahedron(tetrahedron &t, ofstream &ofst);
	// ����� ���������� ������� ������ � �����
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
		ofst << "temperature = " << s.temperature << endl;
	}

	double Volume(ball &b);
	double Volume(parallelepiped &p);
	
	double Volume(shape &s) {
		switch (s.key) {
		case shape::type::BALL:
			return Volume(*(ball *)s.obj);
		case shape::type::PARALLELEPIPED:
			return Volume(*(parallelepiped *)s.obj);
		default:
			return -1;
		}
	}

	//-----------------------------------------------------
	// C�������� ������ ���� ����������� ��������
	bool Compare(shape *first, shape *second) {
		return Volume(*first) < Volume(*second);
	}

} // end simple_shapes namespace