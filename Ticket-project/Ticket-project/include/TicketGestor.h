/**
 * @file TicketGestor.h
 * @brief Gestor principal del sistema de tickets
 *
 * Contiene la clase TicketGestor que maneja la coleccion de tickets
 * y proporciona metodos para su administracion
 */
#pragma once
#include "Prerequisites.h"
#include "Ticket.h"

 /**
  * @class TicketGestor
  * @brief Clase gestora para administrar multiples tickets
  *
  * Gestiona un vector de tickets y proporciona funcionalidad para
  * agregar, eliminar, buscar y listar tickets
  */
class TicketGestor {

	public:
     /**
     * @brief Constructor por defecto
     */
	TicketGestor() = default;
    /**
     * @brief Destructor por defecto
	 */
	~TicketGestor() = default;

	// Metodos para gestionar los tickets
    /**
     * @brief Agrega un nuevo ticket al sistema
     * @param ticket Ticket a agregar (se crea una copia)
     */
	void agregarTicket(const Ticket& ticket);

    /**
     * @brief Elimina un ticket especifico por su ID
     * @param ticketId ID del ticket a eliminar
     * @return true si el ticket fue encontrado y eliminado, false si no existe
     */
	bool eliminarTicket(int ticketId);
    /**
     * @brief Elimina todos los tickets del sistema
     * Vacia completamente el vector de tickets y reinicia el contador de IDs
	 */
    void eliminarTodosLosTickets();
    /**
     * @brief Obtiene un ticket por su ID
     * @param ticketId ID del ticket a buscar
     * @return Puntero al ticket si existe, nullptr si no se encuentra
     */
	Ticket* getTicket(int ticketId);

    /**
     * @brief Lista todos los tickets del sistema
     * @return Vector con copia de todos los tickets
     */
	std::vector<Ticket> getAllTickets() const;// listar todos los tickets

private:
	std::vector<Ticket> tickets; // vector para almacenar los tickets
	int nextId = 1367; // id autoincremental para los tickets

};

/**
 * @brief Implementacion del metodo agregarTicket
 *
 * Crea una copia del ticket para poder modificar su ID.
 * Asigna el ID automatico.
 * Agrega el ticket al vector.
 * Incrementa el ID para el proximo ticket.
 *
 * @param ticket Ticket a agregar al sistema
 */
void TicketGestor::agregarTicket(const Ticket& ticket) {
    // Crear una copia del ticket para poder modificar su ID
    Ticket nuevoTicket = ticket;
    // Asignar el ID automático
    nuevoTicket.setId(nextId);
    // Agregar el ticket al vector
    tickets.push_back(nuevoTicket);
    // Incrementar el ID para el próximo ticket
    nextId++;

    std::cout << "Ticket creado con ID: " << nuevoTicket.getId() << std::endl;
}

/**
 * @brief Implementacion del metodo eliminarTicket
 *
 * Busca el ticket con el ID especificado en el vector.
 * Si lo encuentra, lo elimina del vector.
 * Si no se encuentra, retorna false.
 *
 * @param ticketId ID del ticket a eliminar
 * @return true si fue eliminado, false si no se encontro
 */
bool TicketGestor::eliminarTicket(int ticketId) {//buscamos para eliminar con el id
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i].getId() == ticketId) {
            // Eliminar el ticket del vector
            tickets.erase(tickets.begin() + i);
            std::cout << "Ticket con ID " << ticketId << " ha sido eliminado " << std::endl;
            return true; // Ticket encontrado y eliminado
        }
    }

	std::cout << "No se encontró un ticket con ID: " << ticketId << std::endl;// o no se encoqntró y pues ya nada
    return false;
}

/**
 * @brief Implementacion del metodo getTicket
 *
 * Busca un ticket por su ID en el vector.
 * Devuelve la referencia (osea el puntero) al ticket encontrado.
 * Si no se encuentra, devuelve nullptr.
 *
 * @param ticketId ID del ticket a buscar
 * @return Puntero al ticket o nullptr si no existe
 */
Ticket* TicketGestor::getTicket(int ticketId) {//obtener un ticket por su id
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i].getId() == ticketId) {
            return &tickets[i]; // Devolver la referencia (osea mi puntero)c al ticket encontrado
        }
    }
    return nullptr; // No se encontró el ticket 
}

/**
 * @brief Implementacion del metodo getAllTickets
 *
 * Devuelve una copia del vector completo de tickets.
 *
 * @return Vector con copia de todos los tickets
 */
std::vector<Ticket> TicketGestor::getAllTickets() const {
    return tickets; // Devolver una copia del vector completo
}

/**
 * @brief Implementacion del metodo eliminarTodosLosTickets
 *
 * Vacía completamente el vector de tickets.
 * Reinicia el contador de IDs a 1.
 */
void TicketGestor::eliminarTodosLosTickets() {
    tickets.clear(); // Vacía el vector completamente
    nextId = 1; // Reinicia el contador de los id
    std::cout << "Todos los tickets han sdo eliminados" << std::endl;
}