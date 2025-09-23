#pragma once
#include "Prerequisites.h"
#include "Ticket.h"

class TicketGestor {

	public:
	TicketGestor() = default;
	~TicketGestor() = default;
	void agregarTicket(const Ticket& ticket);
	bool elimnarTicket(int ticketId);

	Ticket* getTicket(int ticketId);// obtener un ticket por su id
	std::vector<Ticket> getAllTickets() const;// listar todos los tickets
};
