#include "container_atd.h"
#include <fstream>
#include <iostream>
#include "shape_atd.h"

using namespace std;

namespace simple_shapes {
	// ������� ���������� �� ���������
	void Clear(container &c) {
		while (c.size != 0) {
			container *temp = c.head->next;
			delete c.head;
			c.head = temp;
			--c.size;
		}

		c.head = nullptr;
		c.tail = nullptr;
		c.current = nullptr;
	}
	//���������� �������� � ������
	void Add(container &c, shape &s){
		++c.size;
		container* temp = new container;
		temp->cont = &s;
		temp->next = c.head;
		c.current = temp;

		if (c.head != nullptr) {
			c.tail->next = temp;
			c.tail = temp;
		}
		else {
			c.head = c.tail = temp;
		}
	}

	// ��������� ��������� ������� �������
	shape *In(ifstream &ifdt);
	// ���� ����������� ���������� �� ���������� ������
	void In(container &c, ifstream &ifst) {
		if (!ifst) {
			cerr << "Error: Unable to open input file" << endl;
			exit(1);
		}
		else {
			int tmp = 0;
			if (ifst.eof()) {
				cerr << "Empty File!" << endl;
				exit(1);
			}
			while (!ifst.eof())	{
				Add(c, *(In(ifst)));
			}
		}
	}

	// ��������� ��������� ������� �������
	void Out(shape &s, ofstream &ofst);

	double Volume(shape &s);
	
	// ����� ����������� ���������� � ��������� �����
	void Out(container &c, ofstream &ofst) {
		if (!ofst) {
			cerr << "Error: Unable to open output file" << endl;
			return;
		}
		else {
			if (c.size) {
				ofst << "Container is filled:\n";
			}
			else {
				ofst << "Container is empty:\n";
			}
			shape* current = new shape;

			for (int i = 0; i < c.size; i++) {

				c.current = c.current->next;

				current = c.current->cont;
				Out(*current, ofst);
				ofst << "volume = " << Volume(*current) << endl;

				current = nullptr;
				delete current;
			}
		}
	}

	//����� ������ �����
	void OutBall(container &c, ofstream &ofst) {
		if (!ofst) {
			cerr << "Error: Unable to open output file" << endl;
			exit(1);
		}
		else {
			if (!c.size) {
				ofst << "Container is empty:\n";
			}
			ofst << "Only balls." << endl;
			shape* current = new shape;

			for (int i = 0; i < c.size; i++) {

				c.current = c.current->next;

				current = c.current->cont;
				if (current->key == shape::type::BALL) {
					Out(*current, ofst);
				}

				current = nullptr;
				delete current;
			}
		}
	}

	//����� ������ ����������������
	void OutParallelepiped(container &c, ofstream &ofst) {
		if (!ofst) {
			cerr << "Error: Unable to open output file" << endl;
			exit(1);
		}
		else {
			if (!c.size) {
				ofst << "Container is empty:\n";
			}
			ofst << "Only parallelepipeds." << endl;
			shape* current = new shape;

			for (int i = 0; i < c.size; i++) {

				c.current = c.current->next;

				current = c.current->cont;
				if (current->key == shape::type::PARALLELEPIPED) {
					Out(*current, ofst);
				}

				current = nullptr;
				delete current;
			}
		}
	}

	//����� ������ ����������
	void OutTetrahedron(container &c, ofstream &ofst) {
		if (!ofst) {
			cerr << "Error: Unable to open output file" << endl;
			exit(1);
		}
		else {
			if (!c.size) {
				ofst << "Container is empty:\n";
			}
			ofst << "Only tetrahedrons." << endl;
			shape* current = new shape;

			for (int i = 0; i < c.size; i++) {

				c.current = c.current->next;

				current = c.current->cont;
				if (current->key == shape::type::TETRAHEDRON) {
					Out(*current, ofst);
				}

				current = nullptr;
				delete current;
			}
		}
	}

	// ��������� ��������� �������
	bool Compare(shape *first, shape *second);
	
	//���������� ��������� ������
	void Sort(container &l)	{
		container *s, *ptr;
		shape *temp;
		if (l.tail == nullptr) {
			return;
		}
		s = l.tail->next;

		while (s != l.tail) {		
			ptr = s->next;
			while (ptr != l.tail->next) {			
				if (ptr != l.tail->next) {				
						if (Compare(s->cont, ptr->cont)) {						
							temp = s->cont;
							s->cont = ptr->cont;
							ptr->cont = temp;
						}
				}
				ptr = ptr->next;
			}
			s = s->next;
		}
	}

} // end simple_shapes namespace