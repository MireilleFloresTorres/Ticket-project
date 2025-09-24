#pragma once
#include "Prerequisites.h"
std::string getFechaActual();
// Definicion de la clase Ticket
class Ticket
{
public://Inicializo el constructor de la clase Ticket y sus atributos
	Ticket(const std::string& titulo, const std::string& descripcion) :
		m_titulo(titulo), m_descripcion(descripcion), m_estado(Estado::ABIERTO), m_id(0) {
		m_fecha = getFechaActual();
	}
	// destructor por defecto
	~Ticket() = default;

	// getters y setters de los atributos de la clase Ticket
	std::string getTitulo() const { return m_titulo; }
	std::string getDescripcion() const { return m_descripcion; }
	Estado getEstado() const { return m_estado; }
	int getId() const { return m_id; }
	std::string getFecha() const { return m_fecha; }

	void setId(int id) { m_id = id; }//el id se asigna automaticamente al crear el ticket y no se puede modificar

	/**
	* nota: el switch no se usa con eltipo std::string
	* Hacemos un switch para covertir el enum en string y poder mostrarlo por pantalla
	* ademas el switch nos permite controlar los estados del ticket
	*/
	void mostrarEstado() const {
		switch (m_estado) {
		case Estado::ABIERTO:// accedemos a un valor del enum Estado
			//ABIERTO a lo que accedo con ::
			std::cout << "Abierto" << std::endl;
			break;
		case Estado::EN_PROGRESO:
			std::cout << "En Progreso" << std::endl;
			break;
		case Estado::COMPLETADO:
			std::cout << "Completado" << std::endl;
			break;
		default:
			std::cout << "Estado Desconocido" << std::endl;
			break;
		}
	}

	void mostrarInfo() const;
	
	//ponemos los atributos en privado para que no se puedan modificar desde fuera de la clase
private:

	std::string m_titulo;
	std::string m_descripcion;
	Estado m_estado;// tiene mucho que ver con la logica de verificacion de estados
	std::string m_fecha;
	int m_id;

};

void Ticket::mostrarInfo() const {

	std::cout << "Ticket Information:" << std::endl;
	std::cout << "ID: " << m_id << std::endl;
	std::cout << "Titulo: " << m_titulo << std::endl;
	std::cout << "Descripcion: " << m_descripcion << std::endl;
	std::cout << "Estado: ";
	mostrarEstado();
	std::cout << "Fecha de Creacion: " << m_fecha << std::endl;
}