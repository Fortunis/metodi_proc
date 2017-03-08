#include "container_atd.h"
#include <fstream>
#include "shape_atd.h"

using namespace std;

namespace simple_shapes {
	// ������� ���������� �� ���������
	// (������������ ������)
	void Clear(container &c) {
		while (c.size != 0)
		{
			container *temp = c.Head->Next;
			delete c.Head;
			c.Head = temp;
			--c.size;
		}

		c.Head = nullptr;
		c.Tail = nullptr;
		c.Current = nullptr;
	}

	void Add(container &c, shape &s)
	{
		++c.size;
		container* temp = new container;
		temp->cont = &s;
		temp->Next = c.Head;
		c.Current = temp;

		if (c.Head != nullptr)
		{
			c.Tail->Next = temp;
			c.Tail = temp;
		}
		else
		{
			c.Head = c.Tail = temp;
		}
	}

	// ��������� ��������� ������� �������
	shape *In(ifstream &ifdt);
	// ���� ����������� ���������� �� ���������� ������
	void In(container &c, ifstream &ifst) {
		int tmp = 0;
		while (!ifst.eof())
		{
			Add(c, *(In(ifst)));
		}
	}

	// ��������� ��������� ������� �������
	void Out(shape &s, ofstream &ofst);
	// ����� ����������� ���������� � ��������� �����
	void Out(container &c, ofstream &ofst) {
		ofst << "Container contains " << c.size
		<< " elements." << endl;
	
		shape* current = new shape;

		for (int i = 0; i < c.size; i++)
		{

			c.Current = c.Current->Next;

			current = c.Current->cont;
			Out(*current, ofst);

			current = nullptr;
			delete current;
		}
	}
} // end simple_shapes namespace