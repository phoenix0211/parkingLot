#pragma once

class Ticket {
    private:
    int ticketId;
    int customerId;
    int slotId;

    public:
    static int ticketCount;

    Ticket(int customerId, int slotId);

    int getTicketId();
    int getCustomerId();
    int getSlotId();
};