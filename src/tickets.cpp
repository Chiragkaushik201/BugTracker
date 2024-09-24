/********************************************************************************
 *     FILENAME           :    tickets.cpp
 *
 *     DESCRIPTION        :    ==========
 *
 *     REVISION HISTORY   :
 *
 *     DATE                NAME              REFERENCE               REASON
 *     --------------------------------------------------------------------
 *     ==========        ==========          tickets.cpp             ==========
 *
 *     Copyright © 2022 Capgemini Group  All Rights Reserved
 *
 ********************************************************************************/

/********************************************************************************
 *                               HEADER FILES
 ********************************************************************************/
#include <utility.h>
#include <Ticket.h>
#include <Trail.h>

/********************************************************************************
 *                             LOCAL FUNCTIONS
 ********************************************************************************/
void add_ticket_note(vector<Ticket *> &);
void add_ticket_code_snipp(vector<Ticket *> &);

/**********************************************************************************
 *     FUNCTION NAME    :   Ticket
 *
 *     DESCRIPTION      :   Non parameterized constructor for Ticket class  
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   None
 *********************************************************************************/
Ticket::Ticket()
{
    this->projectId = "";          /* Project Id */
    this->ticketId = "";           /* Ticket Id */
    this->bugPriority = "";        /* Bug priority: 'L' 'M' 'H' 'S'*/
    this->ticketCreatedBy = "";    /* Created By: <Employee Id> */
    this->bugDescription = "";     /* Description of bug */
    this->ticketCreationDate = ""; /* Date of ticket creation */
    this->ticketAssignedTo = "";   /* Assigned to: <Employee Id> */
    this->closedOn = "";           /* Date when ticket closed */
    this->ticketStatus = "";       /* Status: 'O' 'A' 'F' 'S' */
    this->estimatedFixtime = "";   /* Number of hours required to fix bug */
    this->ticketNote = "";         /* Any note related to ticket */
    this->codeSnippet = "";
}
/**********************************************************************************
 *     FUNCTION NAME    :   Ticket
 *
 *     DESCRIPTION      :   Parameterized constructor for Ticket class
 *
 *     PARAMETERS       :   string projectId,string ticketId,string BugPriority,
 *                          string ticketCreatedBy,string bugDescription,
 *                          string ticketCreationDate,string ticketAssignedTo,
                            string closedOn,string ticketStatus,string estimatedFixtime,
                            string ticketNote,string codeSnippet,

 *     RETURNS          :   None
 *********************************************************************************/
Ticket::Ticket(
    string projectId,
    string ticketId,
    string BugPriority,
    string ticketCreatedBy,
    string bugDescription,
    string ticketCreationDate,
    string ticketAssignedTo,
    string closedOn,
    string ticketStatus,
    string estimatedFixtime,
    string ticketNote,
    string codeSnippet)
{
    this->projectId = projectId;
    this->ticketId = ticketId;
    this->bugPriority = BugPriority;
    this->ticketCreatedBy = ticketCreatedBy;
    this->bugDescription = bugDescription;
    this->ticketCreationDate = ticketCreationDate;
    this->ticketAssignedTo = ticketAssignedTo;
    this->closedOn = closedOn;
    this->ticketStatus = ticketStatus;
    this->estimatedFixtime = estimatedFixtime;
    this->ticketNote = ticketNote;
    this->codeSnippet = codeSnippet;
}

/**********************************************************************************
 *     FUNCTION NAME    :   Project
 *
 *     DESCRIPTION      :   Copy constructor for Project class
 *
 *     PARAMETERS       :   Employee &obj
 *
 *     RETURNS          :   None
 *********************************************************************************/
Ticket::Ticket(const Ticket &ob)
{
    this->projectId = ob.projectId;
    this->ticketId = ob.ticketId;
    this->bugPriority = ob.bugPriority;
    this->ticketCreatedBy = ob.ticketCreatedBy;
    this->bugDescription = ob.bugDescription;
    this->ticketCreationDate = ob.ticketCreationDate;
    this->ticketAssignedTo = ob.ticketAssignedTo;
    this->closedOn = ob.closedOn;
    this->ticketStatus = ob.ticketStatus;
    this->estimatedFixtime = ob.estimatedFixtime;
    this->ticketNote = ob.ticketNote;
    this->codeSnippet = ob.codeSnippet;
}

/**********************************************************************************
 *     FUNCTION NAME    :   Ticket
 *
 *     DESCRIPTION      :   Destructor for Ticket class
 *
 *     PARAMETERS       :   Ticket obj
 *
 *     RETURNS          :   None
 *********************************************************************************/
Ticket::~Ticket()
{
}

/**********************************************************************************
 *     FUNCTION NAME    :   getTicketData
 *
 *     DESCRIPTION      :   Function to access all private data member of object,
 *                          concat them with ',' (format of employee.txt) and return
 *                          the final string
 *
 *     PARAMETERS       :   Ticket obj
 *
 *     RETURNS          :   string
 *********************************************************************************/
string getTicketData(Ticket obj)
{
    return obj.projectId + "," +
           obj.ticketId + "," +
           obj.bugPriority + "," +
           obj.ticketCreatedBy + "," +
           obj.bugDescription + "," +
           obj.ticketCreationDate + "," +
           obj.ticketAssignedTo + "," +
           obj.closedOn + "," +
           obj.ticketStatus + "," +
           obj.estimatedFixtime + "," +
           obj.ticketNote + "," +
           obj.codeSnippet;
}

/**********************************************************************************
 *     FUNCTION NAME    :   printTicketDetails()
 *
 *     DESCRIPTION      :   Function to print details of ticket
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   None
 *********************************************************************************/
void Ticket::printTicketDetails()
{
    cout << "\n**************** Ticket Details ****************\n";
    cout << "Project Id: " << this->projectId << endl
         << "Ticket ID: " << this->ticketId << endl
         << "BugPriority: " << this->bugPriority << endl
         << "Ticket Created By: " << this->ticketCreatedBy << endl
         << "Bug Description: " << this->bugDescription << endl
         << "Ticket Creation Date: " << this->ticketCreationDate << endl
         << "Ticket Assigned To: " << this->ticketAssignedTo << endl
         << "Ticket Closed on: " << this->closedOn << endl
         << "Ticket Status : " << this->ticketStatus << endl
         << "Estimated Fix Time: " << this->estimatedFixtime << endl
         << "Note: " << this->ticketNote << endl
         << "Code Snippet: " << this->codeSnippet << endl;
}

/**********************************************************************************
 *     FUNCTION NAME    :   getProjId()
 *
 *     DESCRIPTION      :   Function to return project id of ticket
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   string project
 *********************************************************************************/
string Ticket::getProjId()
{
    return this->projectId;
}

/**********************************************************************************
 *     FUNCTION NAME    :   getTicketId()
 *
 *     DESCRIPTION      :   Function to return ticket id of caller object
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   string ticketId
 *********************************************************************************/
string Ticket::getTicketId()
{
    return this->ticketId;
}

/**********************************************************************************
 *     FUNCTION NAME    :   getBugPriority()
 *
 *     DESCRIPTION      :   Function to return bug priority of caller object
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   string ticketId
 *********************************************************************************/
string Ticket::getBugPriority()
{
    return this->bugPriority;
}

/**********************************************************************************
 *     FUNCTION NAME    :   getTicketStatus()
 *
 *     DESCRIPTION      :   Function to return ticket status of caller object
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   string ticketStatus
 *********************************************************************************/
string Ticket::getTicketStatus()
{
    return this->ticketStatus;
}

/**********************************************************************************
 *     FUNCTION NAME    :   getTicketCreatedBy()
 *
 *     DESCRIPTION      :   Function to return employee id of person who created ticket
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   string ticketCreatedBy
 *********************************************************************************/
string Ticket::getTicketCreatedBy()
{
    return this->ticketCreatedBy;
}

/**********************************************************************************
 *     FUNCTION NAME    :   getTicketAssignedTo()
 *
 *     DESCRIPTION      :   Function to return employee id of person to whom ticket
 *                          is assigned
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   string ticketAssignedTo
 *********************************************************************************/
string Ticket::getTicketAssignedTo()
{
    return this->ticketAssignedTo;
}

/**********************************************************************************
 *     FUNCTION NAME    :   getCreationDate()
 *
 *     DESCRIPTION      :   Function to date of ticket creation
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   string ticketCreationDate
 *********************************************************************************/
string Ticket::getCreationDate()
{
    return this->ticketCreationDate;
}

/**********************************************************************************
 *     FUNCTION NAME    :   addNote()
 *
 *     DESCRIPTION      :   Adds a note to the caller object's 'ticketNode' data
 *
 *     PARAMETERS       :   string note
 *
 *     RETURNS          :   None
 *********************************************************************************/
void Ticket::addNote(string note)
{
    this->ticketNote = note;
}

/**********************************************************************************
 *     FUNCTION NAME    :   addCodeSnipp()
 *
 *     DESCRIPTION      :   Adds code snippet to caller object's 'codeSnippet' data
 *
 *     PARAMETERS       :   string codeSnippet
 *
 *     RETURNS          :   None
 *********************************************************************************/
void Ticket::addCodeSnipp(string codeSnippet)
{
    this->codeSnippet = codeSnippet;
}

/**********************************************************************************
 *     FUNCTION NAME    :   getTicketDataArray
 *
 *     DESCRIPTION      :   returns the data of object in array format
 *
 *     PARAMETERS       :   object of ticket type
 *
 *     RETURNS          :   returns array of string
 *********************************************************************************/
string *getTicketDataArray(Ticket obj)
{
    string *arr = new string[12];
    arr[0] = obj.projectId;          /* Project Id */
    arr[1] = obj.ticketId;           /* Ticket Id */
    arr[2] = obj.bugPriority;        /* Bug priority: 'L' 'M' 'H' 'S'*/
    arr[3] = obj.ticketCreatedBy;    /* Created By: <Employee Id> */
    arr[4] = obj.bugDescription;     /* Description of bug */
    arr[5] = obj.ticketCreationDate; /* Date of ticket creation */
    arr[6] = obj.ticketAssignedTo;   /* Assigned to: <Employee Id> */
    arr[7] = obj.closedOn;           /* Date when ticket closed */
    arr[8] = obj.ticketStatus;       /* Status: 'O' 'A' 'F' 'S' */
    arr[9] = obj.estimatedFixtime;   /* Number of hours required to fix bug */
    arr[10] = obj.ticketNote;        /* Any note related to ticket */
    arr[11] = obj.codeSnippet;

    return arr;
}

/**********************************************************************************
 *     FUNCTION NAME    :   getTicketId
 *
 *     DESCRIPTION      :   Function to return ticket id for given Ticket object
 *
 *     PARAMETERS       :   Ticket obj
 *
 *     RETURNS          :   string
 *********************************************************************************/
string getTicketID(Ticket obj)
{
    string retval = obj.ticketId;
    return retval;
}

/**********************************************************************************
 *     FUNCTION NAME    :   userEnteredTicket
 *
 *     DESCRIPTION      :   Function to enter the details of ticket from user
 *
 *     PARAMETERS       :   Ticket Id
 *
 *     RETURNS          :   array of strings containing all the ticket fields
 *********************************************************************************/
string *userEnteredTicket(string ticket_id)
{
    string *arr = new string[12];
    arr[10] = "";
    arr[11] = "";
    arr[1] = ticket_id;

    cout << "\nEnter Project Id:";
    getline(cin, arr[0]);
    cout << "\nPriority(L/M/H/S):";
    getline(cin, arr[2]);
    cout << "\nCreated By(Employee Id):";
    getline(cin, arr[3]);
    cout << "\nEnter Description:";
    getline(cin, arr[4]);
    cout << "\nCreated Date(DD/MM/YYYY):";
    getline(cin, arr[5]);
    cout << "\nAssigned To:";
    getline(cin, arr[6]);
    cout << "\nClosed On(DD/MM/YYYY):";
    getline(cin, arr[7]);
    cout << "\nStatus(O/A/F/S/Q/C):";
    getline(cin, arr[8]);
    cout << "\nEstimated Time:";
    getline(cin, arr[9]);

    return arr;
}
/**********************************************************************************
 *     FUNCTION NAME    :   add_Trail_Ticket
 *
 *     DESCRIPTION      :   Updates the trail.txt file with modification done with tickets.txt
 *
 *     PARAMETERS       :   vector of Trail* , ticketid,old employee ,new employee , old status and new status of ticket
 *
 *     RETURNS          :   VOID
 *********************************************************************************/
void add_Trail_Ticket(vector<Trail *> &trail_vector, string ticket, string oldEmployee, string NewEmployee, string oldStatus, string newStatus)
{
    string Date;
    cout << "\nEnter todays date:";
    getline(cin, Date);
    Trail *obj;
    obj = new Trail(ticket, Date, oldEmployee, NewEmployee, oldStatus, newStatus);
    trail_vector.push_back(obj);
    save_Trail(trail_vector);
    cout << "\nTrail File Updated\n";
}
/**********************************************************************************
 *     FUNCTION NAME    :   add_Ticket
 *
 *     DESCRIPTION      :   Function to enter the details of ticket from user
 *
 *     PARAMETERS       :   vector containing the Tickets extracted from database
 *
 *     RETURNS          :   VOID
 *********************************************************************************/
void add_Ticket(vector<Ticket *> &ticket_vector)
{
    // cin.ignore();
    // iterator - for last of vector
    vector<Ticket *>::iterator itr;
    string string_ticket_id; // last ticket id
    int int_ticket_id;
    string *arr = new string[12];
    string updated_ticket_id;

    // generating ticket id
    itr = ticket_vector.end() - 1;
    string_ticket_id = getTicketID(**itr);
    stringstream ss(string_ticket_id);
    ss >> int_ticket_id;
    int_ticket_id++;
    updated_ticket_id = to_string(int_ticket_id);

    // getting values from user and creating object
    arr = userEnteredTicket(updated_ticket_id);
    Ticket *obj = new Ticket(arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9], arr[10], arr[11]);

    // pushing object pointer into ticket_vector
    if (obj != NULL)
    {
        ticket_vector.push_back(obj);

        save_Ticket(ticket_vector);
        cout << "------------------------------------\nTicket Added!\n------------------------------------\n";
    }

    // deallocating memory
    delete[] arr;
}

/**********************************************************************************
 *     FUNCTION NAME    :   modify_Ticket
 *
 *     DESCRIPTION      :   Function to modify data for user provided ticket ID
 *
 *     PARAMETERS       :   vector containing the Tickets extracted from database
 *
 *     RETURNS          :   VOID
 *********************************************************************************/
void modify_Ticket(vector<Ticket *> &ticket_vector, vector<Trail *> &trail_vector)
{
    string ticket_id,
        old_emp,
        new_emp,
        old_status,
        new_status;
    Ticket *found_Obj = NULL;
    int i = 0;

    cout << "\n-------------------------Modify Ticket-----------------\n";
    cout << "Enter Ticket ID to be modified:";
    getline(cin, ticket_id);

    // traversing to  check for valid ticket id
    for (auto val : ticket_vector)
    {
        if (getTicketID(*val) == ticket_id)
        {
            found_Obj = val;

            break;
        }
        i++;
    }
    if (found_Obj == NULL)
    {
        cout << "INVALID TICKET ID.";

        // cin.ignore();
    }
    else
    {
        // trail content
        old_status = found_Obj->getTicketStatus();
        old_emp = found_Obj->getTicketAssignedTo();

        string *arr = new string[12]; // stores entries for tickets.txt
        if (arr != NULL)
        {
            // cin.ignore();
            arr = userEnteredTicket(ticket_id);
            Ticket *obj = new Ticket(arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9], arr[10], arr[11]);

            // trails content
            new_emp = arr[6];
            new_status = arr[8];
            add_Trail_Ticket(trail_vector, ticket_id, old_emp, new_emp, old_status, new_status);

            // ticket saving into vector
            if (obj != NULL)
            {
                ticket_vector[i] = obj;
                save_Ticket(ticket_vector);
                cout << "----------------------------------\nTicket modified!\n----------------------------------\n";
            }

        }
        delete[] arr;
    }
}

/**********************************************************************************
 *     FUNCTION NAME    :   close_status
 *
 *     DESCRIPTION      :   changes the status of ticket to close of object passed
 *
 *     PARAMETERS       :   object of Ticket type
 *
 *     RETURNS          :   VOID
 *********************************************************************************/
void close_status(Ticket obj)
{

    obj.ticketStatus = 'C';
}

/**********************************************************************************
 *     FUNCTION NAME    :   close_Ticket
 *
 *     DESCRIPTION      :   Function to close the ticket
 *
 *     PARAMETERS       :   vector containing the Tickets data extracted from database
 *
 *     RETURNS          :   VOID
 *********************************************************************************/
void close_Ticket(vector<Ticket *> &ticket_vector, vector<Trail *> &trail_vector)
{
    // local variables
    string ticket_id,
        old_emp,
        new_emp,
        old_status,
        new_status;
    Ticket *found_Obj = NULL;
    int i = 0;
    string *arrayed_data = new string[12];
    Ticket *obj;

    cout << "\n-------------------------Close Ticket-----------------\n";
    cout << "Enter Ticket ID to be closed:";
    getline(cin, ticket_id);

    for (auto val : ticket_vector)
    {
        if (getTicketID(*val) == ticket_id)
        {
            found_Obj = val;

            break;
        }
        i++;
    }
    if (found_Obj == NULL)
    {
        cout << "INVALID TICKET ID.";
        // cin.ignore();
    }
    else
    {
        // storing data for trail
        old_status = found_Obj->getTicketStatus();
        old_emp = found_Obj->getTicketAssignedTo();

        if (arrayed_data != NULL)
        {
            // storing data for tickets
            arrayed_data = getTicketDataArray(*found_Obj);
            arrayed_data[8] = CLOSED;

            // storing data for trail
            new_emp = arrayed_data[6];
            new_status = arrayed_data[8];
            add_Trail_Ticket(trail_vector, ticket_id, old_emp, new_emp, old_status, new_status);

            obj = new Ticket(arrayed_data[0], arrayed_data[1], arrayed_data[2], arrayed_data[3], arrayed_data[4], arrayed_data[5], arrayed_data[6], arrayed_data[7], arrayed_data[8], arrayed_data[9], arrayed_data[10], arrayed_data[11]);
            if (obj != NULL)
            {
                ticket_vector[i] = obj;
                save_Ticket(ticket_vector);
                cout << "--------------------------------------------\nTicket closed\n--------------------------------------------\n";
                // cin.ignore();
            }

        }
    }

    delete[] arrayed_data;
}

/**********************************************************************************
 *     FUNCTION NAME    :   read_tickets
 *
 *     DESCRIPTION      :   Function to read ticket from file and return a
 *                          ticket vector *
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   vector<Ticket *>
 *********************************************************************************/
vector<Ticket *> read_tickets()
{
    /* Local variables */
    ifstream fin;
    string ticket_data;
    string ticket_fields[12];

    vector<Ticket *> ticket_vector;

    /* Try opening file and handle error */
    try
    {
        fin.open("../data/tickets.txt", ios::in);

        if (fin.fail())
        {
            throw "\nCould not open tickets.txt\n";
        }
    }
    catch (const string *err)
    {
        cerr << err;
        exit(EXIT_FAILURE);
    }

    /* Read each line and store in obj */
    while (getline(fin, ticket_data))
    {
        for (int i = 0; i < 12; i++)
        {
            ticket_fields[i] = "";
        }

        /* For each line tokenize the string */
        istringstream ticket_obj(ticket_data);
        string word;
        int i = 0;

        while (getline(ticket_obj, word, DELIMITER))
        {
            ticket_fields[i] = word;
            i++;
        }

        /* Initialize Employee object with vecotor elements */
        Ticket *obj = new Ticket(
            ticket_fields[0],
            ticket_fields[1],
            ticket_fields[2],
            ticket_fields[3],
            ticket_fields[4],
            ticket_fields[5],
            ticket_fields[6],
            ticket_fields[7],
            ticket_fields[8],
            ticket_fields[9],
            ticket_fields[10],
            ticket_fields[11]);

        /* Push employee in employee vector */
        ticket_vector.push_back(obj);
    }

    fin.close();
    return ticket_vector;
}

/**********************************************************************************
 *     FUNCTION NAME    :   save_Ticket
 *
 *     DESCRIPTION      :   Function to save each element of vector into database
 *
 *     PARAMETERS       :   vector<Ticket *>
 *
 *     RETURNS          :   None
 *********************************************************************************/
void save_Ticket(vector<Ticket *> &ticket_vector)
{
    fstream fout;

    /* Try opening file and handle error */
    try
    {
        fout.open("../data/tickets.txt", ios::out);

        if (fout.fail())
        {
            throw "\nCould not open Tickets.txt\n";
        }
    }
    catch (const string *err)
    {
        logtrace(FATAL, *err);
        cerr << err;
        exit(EXIT_FAILURE);
    }

    /* Save data in tickets.txt */
    for (auto val : ticket_vector)
    {
        fout << getTicketData(*val) << "\n";
        fout.seekp(0, ios::end); /* to ensure the put pointer is at the end */
    }

    /* Clear previous vector */
    for (auto tkt : ticket_vector)
        delete tkt;

    /* Update new vector */
    ticket_vector = read_tickets();

    fout.close();
}

/**********************************************************************************
 *     FUNCTION NAME    :   manage_tickets
 *
 *     DESCRIPTION      :   Add / modify / delete tickets
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   None
 *********************************************************************************/
void manage_tickets(vector<Ticket *> &ticket_vector, vector<Trail *> &trail_vector)
{
    logtrace(INFO, "manage_tickets() started");

    int ch;
    int loop_check = 1;
    do
    {
        cout << "\n-------------- Tickets Menu --------------\n";
        cout << "\n1. Add Ticket";
        cout << "\n2. Modify Ticket";
        cout << "\n3. Close Ticket";
        cout << "\n4. Add Note to ticket";
        cout << "\n5. Add Code snippet to ticket";
        cout << "\n0. Back\n";

        ch = choice_input();

        switch (ch)
        {
        case 0:
        {
            cout << PREVIOUS_MENU;
            loop_check = 0;
        }
        break;
        case 1:
        {
            add_Ticket(ticket_vector);
        }
        break;
        case 2:
        {
            modify_Ticket(ticket_vector, trail_vector);
        }
        break;
        case 3:
        {
            close_Ticket(ticket_vector, trail_vector);
        }
        break;
        case 4:
        {
            add_ticket_note(ticket_vector);
        }
        break;
        case 5:
        {
            add_ticket_code_snipp(ticket_vector);
        }
        break;
        default:
        {
            invalid_choice();
            // cin.ignore();
        }
        }
    } while (loop_check);

    logtrace(INFO, "manage_tickets() finished");
}

/**********************************************************************************
 *     FUNCTION NAME    :   add_ticket_note
 *
 *     DESCRIPTION      :   Searches the ticket id in ticket_vector if found, add's
 *                          user entered note to the object's 'ticketNode' data
 *
 *     PARAMETERS       :   vector<Ticket *> ticket_vector
 *
 *     RETURNS          :   None
 *********************************************************************************/
void add_ticket_note(vector<Ticket *> &ticket_vector)
{
    logtrace(INFO, "add_ticket_note() started");

    /* Local variable */
    string ticket_id;
    string note;

    /* Input ticket id from user */
    cout << "\nEnter ticket id: ";
    getline(cin, ticket_id);

    /* Search for existing ticket id */
    for (auto val : ticket_vector)
    {
        /* If ticket is found */
        if (val->getTicketId() == ticket_id)
        {
            cout << "\nEnter note to ticket: ";
            getline(cin, note);

            val->addNote(note);
            save_Ticket(ticket_vector);

            cout << "\nTicket note added!\n";
            return;
        }
    }

    /* If ticket id does not exist */
    cout << "\nTicket not found!\n";

    logtrace(INFO, "add_ticket_note() finished");
    return;
}

/**********************************************************************************
 *     FUNCTION NAME    :   add_ticket_code_snipp
 *
 *     DESCRIPTION      :   Searches ticket id in ticket_vector if found, add's user
 *                          entered code snippet to the object's 'codeSnippet' data
 *
 *     PARAMETERS       :   vector<Ticket *> ticket_vector
 *
 *     RETURNS          :   None
 *********************************************************************************/
void add_ticket_code_snipp(vector<Ticket *> &ticket_vector)
{
    logtrace(INFO, "add_ticket_note() started");

    /* Local variable */
    string ticket_id;
    string code_snipp;

    /* Input ticket id from user */
    cout << "\nEnter ticket id: ";
    getline(cin, ticket_id);

    /* Search for existing ticket id */
    for (auto val : ticket_vector)
    {
        /* If ticket is found */
        if (val->getTicketId() == ticket_id)
        {
            cout << "\nEnter code snippet for ticket: ";
            getline(cin, code_snipp);

            val->addCodeSnipp(code_snipp);
            save_Ticket(ticket_vector);

            cout << "\nCode snippet added!\n";
            return;
        }
    }

    /* If ticket id does not exist */
    cout << "\nTicket not found!\n";

    logtrace(INFO, "add_ticket_note() finished");

    return;
}