#include "include/TicketManager.hpp"

TicketManager::TicketManager() {}

int TicketManager::createTicket(int customerId, int slotId) {
    Ticket t(customerId, slotId);
    tickets.insert({slotId, t});
    // TODO: add check to see if ticket with same customerId already exists
    return t.getTicketId();
}

bool TicketManager::removeTicket(int slotId) {
    tickets.erase(slotId);
    // TODO: add check to see if any ticket with slotId exists or not
    return true;
}

Ticket TicketManager::getTicket(int slotId) {
    return tickets.find(slotId)->second;
}

Ticket TicketManager::getTicketByCustomerId(int customerId) {
    for(auto it = tickets.begin(); it != tickets.end(); ++it) {
        if(it->second.getCustomerId() == customerId) {
            return it->second;
        }
    }
    Ticket dummyTicket(-1, -1);
    return dummyTicket;
}

vector<Ticket> TicketManager::getAllTickets() {
    vector<Ticket> vec;
    for(auto it = tickets.begin(); it != tickets.end(); ++it) {
        vec.push_back(it->second);
    }
    return vec;
}
