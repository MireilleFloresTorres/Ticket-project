#pragma once

#include <iostream>
#include <vector>
#include <string>
#include<time.h>

struct Fecha {
    int dia;
    int mes;
    int anio;

    void getFecha() {
        time_t t = time(0); // Obtener el tiempo actual
        tm now; // Crear una estructura tm local
        if (localtime_s(&now, &t) == 0) { // Usar localtime_s para inicializar de forma segura
            dia = now.tm_mday;
            mes = now.tm_mon + 1;
            anio = now.tm_year + 1900;

            std::cout << "Fecha actual: " << toString() << std::endl;
        }
        else {
            std::cerr << "Error al obtener la fecha actual." << std::endl;
        }
    }
    std::string toString() const {
        return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio);
    }
};


/**
* Enum oara el estado del ticekt
* este lo voy a usar en la clase ticket con un metodo publico para validar y cambiar el estado del ticket
*/
enum Estado {

	ABIERTO,
	EN_PROGRESO,
	COMPLETADO,
};