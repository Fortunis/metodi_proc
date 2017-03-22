#include <fstream>
#include "parallelepiped_atd.h"

using namespace std;

namespace simple_shapes {
	// ���� ���������� ������������ �� ������
	parallelepiped* InParallelepiped(ifstream &ifst)
	{
		parallelepiped *p;
		p = new parallelepiped;
		ifst >> p->a >> p->b >> p->c >> p->d;
		return p;
	}

	// ����� ���������� ������������ � �����
	void OutParallelepiped(parallelepiped &p, ofstream &ofst)
	{
		ofst << "It is Parallelepiped: a = "
		<< p.a << ", b = " << p.b
		<< ", c = " << p.c 
		<< ", Density = " << p.d << endl;
	}

} // end simple_shapes namespace