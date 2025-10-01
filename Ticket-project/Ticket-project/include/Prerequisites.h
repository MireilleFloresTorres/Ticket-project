#pragma once
/**
 * @brief Archivo de prerequisitos y dependencias del sistema de gestion de tickets
 *
 * Contiene las estructuras, enums y funciones basicas necesarias para el sistema
 */

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
 /**
  * @struct Fecha
  * @brief Estructura para manejar fecha y hora del sistema
  *
  * Almacena informacion de fecha (dia, mes, anio), y hora y minuto
  */
struct Fecha {
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;
    int segundo;

    /**
     * @brief Obtiene la fecha y hora actual del sistema y la muestra en consola
     *
     * Usa localtime_s para convertir el tiempo en formato legible.
     * Guarda los datos en now con &.
     * &t es la direccion del tiempo.
     * Si es igual a 0 es que se ejecuto bien.
     */
    void getFecha() {
        time_t t = time(0); // Obtener el tiempo actual
        tm now; // Crear una estructura tm local
        if (localtime_s(&now, &t) == 0) { 
            
            dia = now.tm_mday;
            mes = now.tm_mon + 1;
            anio = now.tm_year + 1900;
            hora = now.tm_hour;
            minuto = now.tm_min;
            segundo = now.tm_sec;
			std::cout << "Fecha y Hora: " << toString() << std::endl;// devolvemos un string con la fecha y hora
        }
        else {
            // cerr como cout pero para errores
            // es una salida de errores pero en la consola 
            std::cerr << "Error al obtener la fecha actual" << std::endl;
        }
    }
    /**
     * @brief Convierte la fecha y hora a formato string
     */

    std::string toString() const {
        return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio) +
            " " + std::to_string(hora) + ":" + std::to_string(minuto) + ":";
    }
};

/**
 * @brief Funcion global para obtener la fecha y hora actual como string
 *
 * Obtiene el tiempo actual usando time(0).
 * El 0 es el tiempo en segundos desde 1970.
 * tm es una variable para fechas y horas.
 *
 * @return String con la fecha y hora o mensaje de error
 */
std::string getFechaActual() {
	time_t t = time(0); // Obtener el tiempo actual
	tm now;// Crear una estructura tm local
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
    // retonamos un string con la fecha y hora actual unimos estos con +
    return "Error al obtener fecha";
}
/**
 * @enum Estado
 * @brief Enum para el estado del ticket
 *
 * Este se usa en la clase Ticket con un metodo publico para validar y cambiar el estado del ticket
 */
enum Estado {

	ABIERTO,
	EN_PROGRESO,
	COMPLETADO,
};