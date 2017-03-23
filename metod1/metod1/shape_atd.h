#ifndef __shape_atd__
#define __shape_atd__
// Подключение необходимых типов данных
#include "ball_atd.h"
#include "parallelepiped_atd.h"
#include "tetrahedron_atd.h"

namespace simple_shapes {
	// структура, обобщающая все имеющиеся фигуры
	
	struct shape {
		// значения ключей для каждой из фигур

		enum type { BALL, PARALLELEPIPED, TETRAHEDRON };

		type key; // ключ
		// используемые альтернативы
		void* obj;

		int temperature;
	};
} // end simple_shapes namespace
#endif