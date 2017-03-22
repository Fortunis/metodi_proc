#ifndef __shape_atd__
#define __shape_atd__
// ����������� ����������� ����� ������
#include "ball_atd.h"
#include "parallelepiped_atd.h"

namespace simple_shapes {
	// ���������, ���������� ��� ��������� ������
	
	struct shape {
		// �������� ������ ��� ������ �� �����
		enum type { BALL, PARALLELEPIPED};
		type key; // ����
		// ������������ ������������
		void* obj;

		int temperature;
	};
} // end simple_shapes namespace
#endif