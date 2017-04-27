#ifndef __container_atd__
#define __container_atd__

namespace simple_shapes {
	// Ссылка на описание геометрической фигуры.
	// Знание структуры самой фигуры для представленной
	// реализации контейнера не требуется
	struct shape;
	// Простейший контейнер на основе одномерного массива
	struct container{
		int size = 0;

		shape *cont = nullptr;
		container* next = nullptr;
		container *head = nullptr, *tail = nullptr, *current = nullptr;
	};
} // end simple_shapes namespace
#endif