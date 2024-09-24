/********************************************************************************
 *     FILENAME           :    Ticket.h
 *
 *     DESCRIPTION        :    ==========
 *
 *     REVISION HISTORY   :
 *
 *     DATE                NAME              REFERENCE               REASON
 *     --------------------------------------------------------------------
 *     ==========        ==========          Ticket.h             ==========
 *
 *     Copyright © 2022 Capgemini Group  All Rights Reserved
 *
 ********************************************************************************/

/********************************************************************************
 *                             INCLUDE GUARDS
 ********************************************************************************/
#ifndef __TICKET_H_
#define __TICKET_H_

/********************************************************************************
 *                               HEADER FILES
 ********************************************************************************/
#include <utility.h>
using namespace std;

/********************************************************************************
 *     CLASS NAME       :   Ticket
 *
 *     DESCRIPTION      :   ==========
 *
 *     DATA             :   None
 *
 *     FUNCTIONS        :   None
 *******************************************************************************/
class Ticket
{
public:
    /* Friend function */
    friend string getTicketData(Ticket);
    friend string *getTicketDataArray(Ticket);
    friend string getTicketID(Ticket);
    friend void close_status(Ticket);

    /* Constructors */
    Ticket();
    Ticket(string, string, string, string, string, string, string, string, string, string, string, string);
    Ticket(const Ticket &);

    /* Destructor */
    ~Ticket();

    /* Functions */
    void printTicketDetails();
    string getProjId();
    string getTicketId();
    string getBugPriority();
    string getTicketStatus();
    string getTicketCreatedBy();
    string getTicketAssignedTo();
    string getCreationDate();
    void addNote(string);
    void addCodeSnipp(string);

private:
    string projectId;          /* Project Id */
    string ticketId;           /* Ticket Id */
    string bugPriority;        /* Bug priority: 'L' 'M' 'H' 'S'*/
    string ticketCreatedBy;    /* Created By: <Employee Id> */
    string bugDescription;     /* Description of bug */
    string ticketCreationDate; /* Date of ticket creation */
    string ticketAssignedTo;   /* Assigned to: <Employee Id> */
    string closedOn;           /* Date when ticket closed */
    string ticketStatus;       /* Status: 'O' 'A' 'F' 'S' */
    string estimatedFixtime;   /* Number of hours required to fix bug */
    string ticketNote;         /* Any note related to ticket */
    string codeSnippet;        /* Code snippet for bug */
};

#endif
