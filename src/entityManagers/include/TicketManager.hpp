#pragma once
#include <map>
#include <vector>
#include "../../entities/include/Ticket.hpp"

using namespace std;

class TicketManager {
    private:
    map<int,Ticket> tickets;

    public:
    TicketManager();

    int createTicket(int customerId, int slotId);
    bool removeTicket(int slotId);

    vector<Ticket> getAllTickets();
};