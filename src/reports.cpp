/********************************************************************************
 *     FILENAME           :    reports.cpp
 *
 *     DESCRIPTION        :    ==========
 *
 *     REVISION HISTORY   :
 *
 *     DATE                NAME              REFERENCE               REASON
 *     --------------------------------------------------------------------
 *     ==========        ==========          reports.cpp             ==========
 *
 *     Copyright © 2022 Capgemini Group  All Rights Reserved
 *
 ********************************************************************************/

/********************************************************************************
 *                               HEADER FILES
 ********************************************************************************/
#include <utility.h>
#include <Ticket.h>

/********************************************************************************
 *                               LOCAL FUNCTIONS
 ********************************************************************************/
void ticket_list_open_for_given_project(vector<Ticket *>, string);
void ticket_list_of_all_tickets(vector<Ticket *>, string);
void ticket_list_created_by_login_emp(vector<Ticket *>, string);
void ticket_list_assigned_to_login_emp(vector<Ticket *>, string);
void ticket_list_submitted_by_login_emp(vector<Ticket *>, string);
void ticket_list_created_on_given_date(vector<Ticket *>, string);
void ticket_list_closed_for_given_project(vector<Ticket *>, string);
void ticket_list_opened_by_login_emp(vector<Ticket *>, string);
void ticket_list_fixed_for_given_project(vector<Ticket *>, string);
void ticket_list_for_given_project(vector<Ticket *>, string);

/* Custom sort function for vector */
inline bool compare(Ticket *t1, Ticket *t2)
{
    if (t1->getBugPriority() == "H" && (t2->getBugPriority() == "L" ||
                                        t2->getBugPriority() == "M"))
    {
        return t1->getBugPriority() < t2->getBugPriority();
    }

    return t1->getBugPriority() > t2->getBugPriority();
}

/**********************************************************************************
 *     FUNCTION NAME    :   manage_reports()
 *
 *     DESCRIPTION      :   Details about reprots based on different parameters
 *
 *     PARAMETERS       :    vector<Ticket *>, string
 *
 *     RETURNS          :   None
 *********************************************************************************/
void manage_reports(
    vector<Ticket *> ticket_vector,
    string logged_in_emp_id)
{
    logtrace(INFO, "manage_reports() started");

    /* Sort ticket vector priority wise S > H > M > L */
    sort(begin(ticket_vector), end(ticket_vector), compare);

    logtrace(INFO, "ticket_vector sorted");

    /* Proceed with menu */
    int ch;
    int loop_check = 1;
    do
    {
        cout << "\n-------------- Reports Menu --------------\n";
        cout << "\n01. Prioritywise list of tickets which are open for given project";
        cout << "\n02. Prioritywise list of all tickets";
        cout << "\n03. Prioritywise list of tickets created by logged in employee";
        cout << "\n04. Prioritywise list of tickets assigned to logged in employee";
        cout << "\n05. Prioritywise list of tickets submitted by logged in employee";
        cout << "\n06. Prioritywise list of tickets which are created on given date";
        cout << "\n07. Prioritywise list of tickets which are closed for given project";
        cout << "\n08. Prioritywise list of tickets which are opened by logged in employee";
        cout << "\n09. Prioritywise list of tickets which are fixed for given project";
        cout << "\n10. Prioritywise list of tickets for given project";
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
            ticket_list_open_for_given_project(ticket_vector, logged_in_emp_id);
        }
        break;

        case 2:
        {
            ticket_list_of_all_tickets(ticket_vector, logged_in_emp_id);
        }
        break;

        case 3:
        {
            ticket_list_created_by_login_emp(ticket_vector, logged_in_emp_id);
        }
        break;

        case 4:
        {
            ticket_list_assigned_to_login_emp(ticket_vector, logged_in_emp_id);
        }
        break;

        case 5:
        {
            ticket_list_submitted_by_login_emp(ticket_vector, logged_in_emp_id);
        }
        break;

        case 6:
        {
            ticket_list_created_on_given_date(ticket_vector, logged_in_emp_id);
        }
        break;

        case 7:
        {
            ticket_list_closed_for_given_project(ticket_vector, logged_in_emp_id);
        }
        break;

        case 8:
        {
            ticket_list_opened_by_login_emp(ticket_vector, logged_in_emp_id);
        }
        break;

        case 9:
        {
            ticket_list_fixed_for_given_project(ticket_vector, logged_in_emp_id);
        }
        break;

        case 10:
        {
            ticket_list_for_given_project(ticket_vector, logged_in_emp_id);
        }
        break;

        default:
        {
            invalid_choice();
        }
        }
    } while (loop_check);

    logtrace(INFO, "manage_reports() finished");
}

/**********************************************************************************
 *     FUNCTION NAME    :   ticket_list_open_for_given_project()
 *
 *     DESCRIPTION      :   Prioritywise list of tickets that are open for given
 *                          project (prj id entered by user)
 *
 *     PARAMETERS       :   vector<Ticket *>, string
 *
 *     RETURNS          :   None
 *********************************************************************************/
void ticket_list_open_for_given_project(
    vector<Ticket *> ticket_vector,
    string logged_in_emp_id)
{
    /* Local variables */
    string proj_id;
    bool doesPidExist = false;

    /* Input project id */
    cout << "\nEnter project id: ";
    getline(cin, proj_id);

    /* Output list of tickets with ticket status 'open' */
    cout << "\n******** Ticket list open for given project ********\n";

    /* Search ticket vector */
    for (auto tkt : ticket_vector)
    {
        /* If project id found */
        if (tkt->getProjId() == proj_id)
        {
            doesPidExist = true;

            if (tkt->getTicketStatus() == "O")
            {
                tkt->printTicketDetails();
            }
        }
    }

    if (doesPidExist == false)
    {
        cout << "\nProject id not found!\n";
        return;
    }

    return;
}

/**********************************************************************************
 *     FUNCTION NAME    :   ticket_list_of_all_tickets()
 *
 *     DESCRIPTION      :   Prioritywise list of all tickets
 *
 *     PARAMETERS       :   vector<Ticket *>, string
 *
 *     RETURNS          :   None
 *********************************************************************************/
void ticket_list_of_all_tickets(
    vector<Ticket *> ticket_vector,
    string logged_in_emp_id)
{
    cout << "\n******** List of all tickets ********\n";

    for (auto tkt : ticket_vector)
    {
        tkt->printTicketDetails();
    }
}

/**********************************************************************************
 *     FUNCTION NAME    :   ticket_list_created_by_login_emp()
 *
 *     DESCRIPTION      :   Prioritywise list of tickets that are created by the
 *                          currently logged in employee
 *
 *     PARAMETERS       :   vector<Ticket *>, string
 *
 *     RETURNS          :   None
 *********************************************************************************/
void ticket_list_created_by_login_emp(
    vector<Ticket *> ticket_vector,
    string logged_in_emp_id)
{
    cout << "\n******** Tickets created by you ********\n";

    for (auto tkt : ticket_vector)
    {
        if (tkt->getTicketCreatedBy() == logged_in_emp_id)
        {
            tkt->printTicketDetails();
        }
    }
}

/**********************************************************************************
 *     FUNCTION NAME    :   ticket_list_assigned_to_login_emp()
 *
 *     DESCRIPTION      :   Prioritywise list of tickets that are assigned to the
 *                          currently logged in employee
 *
 *     PARAMETERS       :   vector<Ticket *>, string
 *
 *     RETURNS          :   None
 *********************************************************************************/
void ticket_list_assigned_to_login_emp(
    vector<Ticket *> ticket_vector,
    string logged_in_emp_id)
{
    cout << "\n******** Tickets assigned to you ********\n";

    for (auto tkt : ticket_vector)
    {
        if (tkt->getTicketAssignedTo() == logged_in_emp_id)
        {
            tkt->printTicketDetails();
        }
    }
}

/**********************************************************************************
 *     FUNCTION NAME    :   ticket_list_submitted_by_login_emp()
 *
 *     DESCRIPTION      :   Prioritywise list of tickets that are submitted by the
 *                          currently logged in employee
 *
 *     PARAMETERS       :   vector<Ticket *>, string
 *
 *     RETURNS          :   None
 *********************************************************************************/
void ticket_list_submitted_by_login_emp(
    vector<Ticket *> ticket_vector,
    string logged_in_emp_id)
{
    cout << "\n******** Tickets submitted by you ********\n";

    for (auto tkt : ticket_vector)
    {
        if (tkt->getTicketCreatedBy() == logged_in_emp_id)
        {
            if (tkt->getTicketStatus() == "S")
            {
                tkt->printTicketDetails();
            }
        }
    }
}

/**********************************************************************************
 *     FUNCTION NAME    :   ticket_list_created_on_given_date()
 *
 *     DESCRIPTION      :   Prioritywise list of tickets that are created on a given
 *                          date
 *
 *     PARAMETERS       :   vector<Ticket *>, string
 *
 *     RETURNS          :   None
 *********************************************************************************/
void ticket_list_created_on_given_date(
    vector<Ticket *> ticket_vector,
    string logged_in_emp_id)
{
    /* Input date */
    string search_date = "";
    cout << "\nEnter date: ";
    getline(cin, search_date);

    cout << "\n******** Tickets created on given date ********\n";

    for (auto tkt : ticket_vector)
    {
        if (tkt->getCreationDate() == search_date)
        {
            tkt->printTicketDetails();
        }
    }
}

/**********************************************************************************
 *     FUNCTION NAME    :   ticket_list_closed_for_given_project()
 *
 *     DESCRIPTION      :   Prioritywise list of tickets that are closed for the given
 *                          project (prj id entered by user)
 *
 *     PARAMETERS       :   vector<Ticket *>, string
 *
 *     RETURNS          :   None
 *********************************************************************************/
void ticket_list_closed_for_given_project(
    vector<Ticket *> ticket_vector,
    string logged_in_emp_id)
{
    /* Local variables */
    string proj_id;
    bool doesPidExist = false;

    /* Input project id */
    cout << "\nEnter project id: ";
    getline(cin, proj_id);

    /* Output list of tickets with ticket status 'close' */
    cout << "\n******** Ticket list close for given project ********\n";

    /* Search ticket vector */
    for (auto tkt : ticket_vector)
    {
        /* If project id found */
        if (tkt->getProjId() == proj_id)
        {
            doesPidExist = true;
            if (tkt->getTicketStatus() == "C")
            {
                tkt->printTicketDetails();
            }
        }
    }

    if (doesPidExist == false)
    {
        cout << "\nProject id not found!\n";
        return;
    }

    return;
}

/**********************************************************************************
 *     FUNCTION NAME    :   ticket_list_opened_by_login_emp()
 *
 *     DESCRIPTION      :   Prioritywise list of tickets that are opened by the
 *                          currently logged in employee
 *
 *     PARAMETERS       :   vector<Ticket *>, string
 *
 *     RETURNS          :   None
 *********************************************************************************/
void ticket_list_opened_by_login_emp(
    vector<Ticket *> ticket_vector,
    string logged_in_emp_id)
{

    cout << "\n******** Ticket list opened by you ********\n";

    for (auto tkt : ticket_vector)
    {
        if (tkt->getTicketCreatedBy() == logged_in_emp_id)
        {
            if (tkt->getTicketStatus() == "O")
            {
                tkt->printTicketDetails();
            }
        }
    }
}

/**********************************************************************************
 *     FUNCTION NAME    :   ticket_list_fixed_for_given_project()
 *
 *     DESCRIPTION      :   Prioritywise list of tickets that are fixed for the given
 *                          project (prj id entered by user)
 *
 *     PARAMETERS       :   vector<Ticket *>, string
 *
 *     RETURNS          :   None
 *********************************************************************************/
void ticket_list_fixed_for_given_project(
    vector<Ticket *> ticket_vector,
    string logged_in_emp_id)
{
    /* Local variables */
    string proj_id;
    bool doesPidExist = false;

    /* Input project id */
    cout << "\nEnter project id: ";
    getline(cin, proj_id);

    /* Output list of tickets with ticket status 'fixed' */
    cout << "\n******** Ticket list fixed for given project ********\n";

    /* Search ticket vector */
    for (auto tkt : ticket_vector)
    {
        /* If project id found */
        if (tkt->getProjId() == proj_id)
        {
            doesPidExist = true;

            if (tkt->getTicketStatus() == "F")
            {
                tkt->printTicketDetails();
            }
        }
    }

    if (doesPidExist == false)
    {
        cout << "\nProject id not found!\n";
        return;
    }

    return;
}

/**********************************************************************************
 *     FUNCTION NAME    :   ticket_list_for_given_project()
 *
 *     DESCRIPTION      :   Prioritywise list of tickets that for given project
 *
 *     PARAMETERS       :   vector<Ticket *>, string
 *
 *     RETURNS          :   None
 *********************************************************************************/
void ticket_list_for_given_project(
    vector<Ticket *> ticket_vector,
    string logged_in_emp_id)
{
    /* Local variables */
    string proj_id;
    bool doesPidExist = false;

    /* Input project id */
    cout << "\nEnter project id: ";
    getline(cin, proj_id);

    /* Output list of tickets for current project id */
    cout << "\n******** Ticket list for given project ********\n";

    /* Search ticket vector */
    for (auto tkt : ticket_vector)
    {
        /* If project id found */
        if (tkt->getProjId() == proj_id)
        {
            doesPidExist = true;
            tkt->printTicketDetails();
        }
    }

    if (doesPidExist == false)
    {
        cout << "\nProject id not found!\n";
        return;
    }

    return;
}
