#pragma once
#include "Prerequisites.h"
#include "Ticket.h"

class TicketGestor {

	public:
	TicketGestor() = default;
	~TicketGestor() = default;
	void agregarTicket(const Ticket& ticket);
	bool eliminarTicket(int ticketId);


	Ticket* getTicket(int ticketId);// obtener un ticket por su id
	std::vector<Ticket> getAllTickets() const;// listar todos los tickets

private:
	std::vector<Ticket> tickets; // vector para almacenar los tickets
	int nextId = 1; // id autoincremental para los tickets

};

// Implementación de los métodos
void TicketGestor::agregarTicket(const Ticket& ticket) {
    // Crear una copia del ticket para poder modificar su ID
    Ticket nuevoTicket = ticket;
    // Asignar el ID automático
    nuevoTicket.setId(nextId);
    // Agregar el ticket al vector
    tickets.push_back(nuevoTicket);
    // Incrementar el ID para el próximo ticket
    nextId++;

    std::cout << "Ticket creado exitosamente con ID: " << nuevoTicket.getId() << std::endl;
}

bool TicketGestor::eliminarTicket(int ticketId) {//buscamos para eliminar con el id
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i].getId() == ticketId) {
            // Eliminar el ticket del vector
            tickets.erase(tickets.begin() + i);
            std::cout << "Ticket con ID " << ticketId << " eliminado exitosamente." << std::endl;
            return true; // Ticket encontrado y eliminado
        }
    }

	std::cout << "No se encontró un ticket con ID: " << ticketId << std::endl;// o no se encoqntró y pues ya nada
    return false;
}

Ticket* TicketGestor::getTicket(int ticketId) {//obtener un ticket por su id
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i].getId() == ticketId) {
            return &tickets[i]; // Devolver la referencia (osea mi puntero)c al ticket encontrado
        }
    }
    return nullptr; // No se encontró el ticket 
}

std::vector<Ticket> TicketGestor::getAllTickets() const {
    return tickets; // Devolver una copia del vector completo
}