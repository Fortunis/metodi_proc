#ifndef __container_atd__
#define __container_atd__

namespace simple_shapes {
	// ������ �� �������� �������������� ������.
	// ������ ��������� ����� ������ ��� ��������������
	// ���������� ���������� �� ���������
	struct shape;
	// ���������� ��������� �� ������ ����������� �������
	struct container{
		int size = 0;

		shape *cont = nullptr;
		container* next = nullptr;
		container *head = nullptr, *tail = nullptr, *current = nullptr;
	};
} // end simple_shapes namespace
#endif