/********************************************************************************
 *     FILENAME           :    main.cpp
 *
 *     DESCRIPTION        :    ==========
 *
 *     REVISION HISTORY   :
 *
 *     DATE                NAME              REFERENCE               REASON
 *     --------------------------------------------------------------------
 *     ==========        ==========          main.cpp             ==========
 *
 *     Copyright © 2022 Capgemini Group  All Rights Reserved
 *
 ********************************************************************************/

/********************************************************************************
 *                               HEADER FILES
 ********************************************************************************/
#include <utility.h>
#include <Employee.h>
#include <Project.h>
#include <Ticket.h>
#include <Trail.h>

/********************************************************************************
 *     FUNCTION NAME    :   main
 *
 *     DESCRIPTION      :   Driver function for the the program
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   None
 *******************************************************************************/
int main()
{
    /* Local variable */
    int main_loop_cond = true, /* Loop control condition for main menu */
        bug_loop_cond = true;  /* Loop control condition for bug tracker menu */

    int main_menu_choice = -1, /* Integer variable to store main menu choice */
        bug_menu_choice = -1;  /* Integer variable to store bug tracker menu choice */

    /* Logtrace */
    logtrace(INFO, "BugTracker: main() started");

    /* Keep track of logged in employee */
    string empId = "";

    /* Read employee data*/
    vector<Employee *> emp_vector = read_employees();

    /* Read project data */
    vector<Project *> project_vector = read_project();

    /* Read Ticket data */
    vector<Ticket *> ticket_vector = read_tickets();
    ticket_vector.shrink_to_fit();

    /* Read Trail data */
    vector<Trail *> trail_vector = read_trail();
    trail_vector.shrink_to_fit();

    /****************************** Program starts here ***************************/
    while (main_loop_cond)
    {
        /* Main menu */
        cout << "\n***************** Main Menu *****************\n";
        cout << "\n1. Login";
        cout << "\n2. Register Employee";
        cout << "\n0. Exit\n";

        /* Take user input */
        main_menu_choice = choice_input();

        /* Start condition */
        switch (main_menu_choice)
        {
        case 0: /* Exit */
        {
            cout << "\nThanks for using the appliction!\n";
            main_loop_cond = false;
        }
        break;

        case 1: /* Login */
        {
            /***************** Employee login ********************/
            empId = employee_login(emp_vector);

            if (empId == EMPTY_STRING)
            {
                bug_loop_cond = false;
                cout << "\nLogin Failed!\n";
            }
            else
            {
                bug_loop_cond = true;
                cout << "\nLogin Successful!\n";
            }

            /* If login successful */
            while (bug_loop_cond)
            {
                /***************** Bug Tracker Menu ******************/
                cout << "\n***************** Bug Tracker Menu *****************\n";
                cout << "\n1. Manage Projects";
                cout << "\n2. Manage Tickets";
                cout << "\n3. Reports";
                cout << "\n0. Back\n";

                /* Take user input */
                bug_menu_choice = choice_input();

                /* Start condition */
                switch (bug_menu_choice)
                {

                case 0: /* Back to previous menu */
                {
                    bug_loop_cond = false;
                }
                break;

                case 1: /* Manage projects */
                {
                    manage_projects(project_vector, ticket_vector, empId);
                }
                break; /* end Manage projects */

                case 2: /* Manage tickets */
                {
                    manage_tickets(ticket_vector, trail_vector);
                }
                break; /* end Manage tickets */

                case 3: /* Manage Reports */
                {
                    manage_reports(ticket_vector, empId);
                }
                break; /* end Manage Reports*/

                default:
                {
                    invalid_choice();
                }
                }
            }
        } /* end Login */
        break;

        case 2: /*Register */
        {
            register_employee(emp_vector);
        }
        break; /* end Register */

        default:
        {
            invalid_choice();
        }
        }
    }

    /* Delete all the memory */
    for (auto val : emp_vector)
        delete val;

    for (auto val : ticket_vector)
        delete val;

    for (auto val : trail_vector)
        delete val;

    for (auto val : project_vector)
        delete val;

    /* Logtrace */
    logtrace(INFO, "BugTracker: main() finished");
}