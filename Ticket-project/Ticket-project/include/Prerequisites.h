#pragma once

#include <iostream>
#include <vector>
#include <string>
#include<time.h>

/**
* Enum oara el estado del ticekt
* este lo voy a usar en la clase ticket con un metodo publico para validar y cambiar el estado del ticket
*/
enum Estado {

	ABIERTO,
	EN_PROGRESO,
	COMPLETADO,
};