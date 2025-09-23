#pragma once
#include "Prerequisites.h"

class Ticket
{
public://Inicializo el constructor de la clase Ticket y sus atributos
	Ticket(const std::string titulo, const std::string descripción, Estado estado, const std::string fecha, int id);
	// destructor por defecto
	~Ticket() = default;

	// getters y setters de los atributos de la clase Ticket

	std::string getTitulo() const { return m_titulo; }
	void setTitulo(const std::string titulo) { m_titulo = titulo; }

	std::string getDescripción() const { return m_descripción; }
	void setDescripción(const std::string descripción) { m_descripción = descripción; }

	Estado getEstado() const { return m_estado; }
	void setEstado(Estado estado) { m_estado = estado; }

	/**
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
	
	//ponemos los atributos en privado para que no se puedan modificar desde fuera de la clase
private:

	std::string m_titulo;
	std::string m_descripción;
	Estado m_estado;
	std::string m_fecha;
	int m_id;

};