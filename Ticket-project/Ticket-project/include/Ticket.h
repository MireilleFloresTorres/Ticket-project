#pragma once
/**
 * @file Ticket.h
 * @brief Definicion de la clase Ticket para el sistema de gestion
 *
 * Contiene la clase principal Ticket que representa un ticket individual
 * con sus atributos y metodos para su manejo
 */

#include "Prerequisites.h"
std::string getFechaActual();
class Ticket
{
public:
	/**
	 * @brief Constructor de la clase Ticket
	 *
	 * Inicializo el constructor de la clase Ticket y sus atributos
	 * El ticket se crea con estado abierto por defecto y le asign0
	 * automaticamente la fecha y hora de creacion
	 *
	 * @param titulo Titulo del ticket
	 * @param descripcion Descripcion detallada del ticket
	 */

	Ticket(const std::string& titulo, const std::string& descripcion) :
		m_titulo(titulo), m_descripcion(descripcion), m_estado(Estado::ABIERTO), m_id(0) {
		m_fecha = getFechaActual();
	}
	/**
	 * @brief Destructor por defecto
	 */
	~Ticket() = default;

	// getters y setters de los atributos de la clase Ticket

	/**
	 * @brief Obtiene el titulo del ticket
	 * @return Titulo del ticket
	 */
	std::string getTitulo() const { return m_titulo; }

	/**
	 * @brief Obtiene la descripcion del ticket
	 * @return Descripcion del ticket
	 */
	std::string getDescripcion() const { return m_descripcion; }

	/**
	 * @brief Obtiene el estado actual del ticket
	 * @return Estado del ticket
	 */
	Estado getEstado() const { return m_estado; }

	/**
	 * @brief Obtiene el ID unico del ticket
	 * @return ID del ticket
	 */
	int getId() const { return m_id; }

	/**
	 * @brief Obtiene la fecha de creacion del ticket
	 * @return Fecha de creacion del ticket
	 */
	std::string getFecha() const { return m_fecha; }

	/**
	* @brief Asigna un ID al ticket
	* @param id Numero de identificacion unico
	*/
	void setId(int id) { m_id = id; }//el id se asigna automaticamente al crear el ticke
	/**
	 * @brief Cambia el estado del ticket
	 * @param nuevoEstado Nuevo estado a asignar (ABIERTO, EN_PROGRESO o COMPLETADO)
	 */
	void setEstado(Estado nuevoEstado) { m_estado = nuevoEstado; }
	
	/**
	 * @brief Muestra el estado del ticket por pantalla
	 *
	 * Nota: el switch no se usa con el tipo std::string.
	 * Hacemos un switch para convertir el enum en string y poder mostrarlo por pantalla.
	 * Ademas el switch nos permite controlar los estados del ticket.
	 * Accedemos a un valor del enum Estado (ABIERTO) a lo que accedemos con ::
	 */
	void mostrarEstado() const {
		switch (m_estado) {
		case Estado::ABIERTO:// accedemos a un valor del enum Estado
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

	/**
	 * @brief Muestra toda la informacion del ticket por pantalla
	 *
	 * Imprime ID, titulo, descripcion, estado y fecha de creacion
	 */
	void mostrarInfo() const;
	
	//ponemos los atributos en privado para que no se puedan modificar desde fuera de la clase
private:

	std::string m_titulo;
	std::string m_descripcion;
	Estado m_estado;// tiene mucho que ver con la logica de verificacion de estados
	std::string m_fecha;
	int m_id;

};

/**
 * @brief Implementacion del metodo mostrarInfo
 *
 * Muestra toda la informacion del ticket de forma estructurada
 */
void Ticket::mostrarInfo() const {

	std::cout << "Ticket Information:" << std::endl;
	std::cout << "ID: " << m_id << std::endl;
	std::cout << "Titulo: " << m_titulo << std::endl;
	std::cout << "Descripcion: " << m_descripcion << std::endl;
	std::cout << "Estado: ";
	mostrarEstado();
	std::cout << "Fecha de Creacion: " << m_fecha << std::endl;
}