#include "container_atd.h"
#include <fstream>
#include <iostream>
#include "shape_atd.h"

using namespace std;

namespace simple_shapes {
	// Очистка контейнера от элементов
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
	//Добавление элемента в список
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

	// Сигнатуры требуемых внешних функций
	shape *In(ifstream &ifdt);
	// Ввод содержимого контейнера из указанного потока
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

	// Сигнатуры требуемых внешних функций
	void Out(shape &s, ostream &ofst);

	double Volume(shape &s);
	
	// Вывод содержимого контейнера в указанный поток
	void Out(container &c, ostream &ofst) {
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

	//Вывод только шаров
	void OutBall(container &c, ostream &ofst) {
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

	//Вывод только параллелепипедов
	void OutParallelepiped(container &c, ostream &ofst) {
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

	//Вывод только тетраэдров
	void OutTetrahedron(container &c, ostream &ofst) {
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

	// Сигнатуры требуемых функций
	bool Compare(shape *first, shape *second);
	
	//Сортировка элементов списка
	void Sort(container &l,int des)	{
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
					switch (des)
					{
						case 0:
							if (Compare(s->cont, ptr->cont)) {
								temp = s->cont;
								s->cont = ptr->cont;
								ptr->cont = temp;
							}
							break;
						case 1:
							if (!Compare(s->cont, ptr->cont)) {
								temp = s->cont;
								s->cont = ptr->cont;
								ptr->cont = temp;
							}
							break;
						default:
							cerr << "Inknown des" << endl;
							exit(1);
					}
				}
				ptr = ptr->next;
			}
			s = s->next;
		}
	}

	//-----------------------------------------------------
	// Мультиметод
	void MultiMethod(container &c, ostream &ofst) {
		if (ofst.fail()) {
			cerr << "Error: Unable to open output file" << endl;
			return;
		}
		else {
			if (c.size) {
				ofst << "Multimethods:\n";
			}
			else {
				ofst << "Container is empty:\n";
			}
			container* temp = nullptr;
			for (int i = 0; i < c.size; i++) {
				c.current = c.current->next;
				temp = c.current;
				for (int j = 0; j < c.size; j++) {
					switch (c.current->cont->key) {
					case shape::BALL:
						switch (temp->cont->key) {
						case shape::BALL:
							ofst << "Ball and Ball." << endl;
							break;
						case shape::PARALLELEPIPED:
							ofst << "Ball and Parallelepiped." << endl;
							break;
						case shape::TETRAHEDRON:
							ofst << "Ball and Tetrahedron." << endl;
							break;
						default:
							ofst << "Unknown type" << endl;
						}
						break;
					case shape::PARALLELEPIPED:
						switch (temp->cont->key) {
						case shape::BALL:
							ofst << "Parallelepiped and Ball." << endl;
							break;
						case shape::PARALLELEPIPED:
							ofst << "Parallelepiped and Parallelepiped." << endl;
							break;
						case shape::TETRAHEDRON:
							ofst << "Parallelepiped and Tetrahedron." << endl;
							break;
						default:
							ofst << "Unknown type" << endl;
						}
						break;
					case shape::TETRAHEDRON:
						switch (temp->cont->key) {
						case shape::BALL:
							ofst << "Tetrahedron and Ball." << endl;
							break;
						case shape::PARALLELEPIPED:
							ofst << "Tetrahedron and Parallelepiped." << endl;
							break;
						case shape::TETRAHEDRON:
							ofst << "Tetrahedron and Tetrahedron." << endl;
							break;
						default:
							ofst << "Unknown type" << endl;
						}
						break;
					default:
						ofst << "Unknown type" << endl;
					}
					Out(*c.current->cont, ofst);
					Out(*temp->cont, ofst);
					temp = temp->next;
				}
			}
		}
	}

} // end simple_shapes namespace