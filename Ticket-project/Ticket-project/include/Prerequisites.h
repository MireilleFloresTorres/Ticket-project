#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

struct Fecha {
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;
    int segundo;

    void getFecha() {
        time_t t = time(0); // Obtener el tiempo actual
        tm now; // Crear una estructura tm local
        if (localtime_s(&now, &t) == 0) { // Usar localtime_s función que convierte el tiempo en formato
            // guradamos en now con & 
            //&t direccipon dle tiepo
			// si es igual a 0 es que se ejecuto bien
            dia = now.tm_mday;
            mes = now.tm_mon + 1;
            anio = now.tm_year + 1900;
            hora = now.tm_hour;
            minuto = now.tm_min;
            segundo = now.tm_sec;
			std::cout << "Fecha y Hora: " << toString() << std::endl;// devolvemos un string con la fecha y hora
        }
        else {
            std::cerr << "Error al obtener la fecha actual" << std::endl;
			// cerr como cout pero para errores
			// es una salida de errores pero en la consola 
        }
    }

    std::string toString() const {
        return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio) +
            " " + std::to_string(hora) + ":" + std::to_string(minuto) + ":";
    }
};

std::string getFechaActual() {
	time_t t = time(0);// Obtener el tiempo actual, time 0 obtien el tiempo actual 
    //el 0 es el tiempo en segundos desde 1970
	tm now;// Crear una estructura tm local, tm variable para fechas y horas
    if (localtime_s(&now, &t) == 0) {
        int dia = now.tm_mday;
        int mes = now.tm_mon + 1;
        int anio = now.tm_year + 1900;
        int hora = now.tm_hour;
        int minuto = now.tm_min;
        int segundo = now.tm_sec;

        return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio) +
            " " + std::to_string(hora) + ":" + std::to_string(minuto) + ":";
    }
    return "Error al obtener fecha";
	// retonamos un string con la fecha y hora actual unimos estos con +
}
/**
* Enum oara el estado del ticekt
* este lo voy a usar en la clase ticket con un metodo publico para validar y cambiar el estado del ticket
*/
enum Estado {

	ABIERTO,
	EN_PROGRESO,
	COMPLETADO,
};