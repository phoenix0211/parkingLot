#include "include/Ticket.hpp"

int Ticket::ticketCount = 101;

Ticket::Ticket(int customerId, int slotId) {
    this->ticketId = ticketCount++;
    this->customerId = customerId;
    this->slotId = slotId;
}

int Ticket::getTicketId() {
    return ticketId;
}

int Ticket::getCustomerId() {
    return customerId;
}

int Ticket::getSlotId() {
    return slotId;
}