/********************************************************************************
 *     FILENAME           :    utility.h
 *
 *     DESCRIPTION        :    ==========
 *
 *     REVISION HISTORY   :
 *
 *     DATE                NAME              REFERENCE               REASON
 *     --------------------------------------------------------------------
 *     ==========        ==========          utility.h             ==========
 *
 *     Copyright © 2022 Capgemini Group  All Rights Reserved
 *
 ********************************************************************************/

/********************************************************************************
 *                             INCLUDE GUARDS
 ********************************************************************************/
#ifndef __UTILITY_H_
#define __UTILITY_H_

/********************************************************************************
 *                               HEADER FILES
 ********************************************************************************/
#include <bits/stdc++.h>
#include <Employee.h>
#include <Project.h>
#include <Ticket.h>
#include <Trail.h>

/********************************************************************************
 *                                 NAMESPACE
 ********************************************************************************/
using namespace std;

/********************************************************************************
 *                                  MACROS
 ********************************************************************************/
/* Custom messages*/
#define ENTER_CHOICE "\nPlease enter your choice: "
#define INVALID_CHOICE "\nInvalid choice!"
#define ENTER_TO_CONTINUE "\nPress enter to continue... "
#define PREVIOUS_MENU "\nGoing back to previous menu...\n"

/* Misc */
#define DELIMITER ','
#define EMPTY_STRING ""
#define CLOSED 'C'
#define LOG_FILENAME "../logs/trace.log"

/* file read/ write modes */
#define READMODE "r"
#define APPENDMODE "a"
#define WRITEMODE "w"

/* Labels for log trace */
#define FATAL "FATAL"
#define WARN "WARNING"
#define INFO "INFO"

/* file access errors */
#define ERR_FILE_READ "[-] Error: File doesn't exist or insufficient permissions!"
#define ERR_FILE_WRITE "[-] Error: Can't create output file. Insufficient permissions!"

/* other errors */
#define ERR_MEM_ALLOC "[-] Error: Memory allocation failed!\n"
#define ERR_MEM_DEALLOC2 "[-] Error: Memory de-allocation of array type failed!\n"
#define ERR_MEM_DEALLOC1 "[-] Error: Memory de-allocation of variable failed!\n"
#define ERR_ARG_COUNT "[-] Error: Minimum 2 arguments required!\n"
#define ERR_UNDERFLOW "[-] Error: List empty - Underflow!\n"
#define ERR_DATA_STORE "[!] Can't store data of allocation(s)/de-allocation(s) %s\n"

/********************************************************************************
 *                                 FUNCTIONS
 ********************************************************************************/

/* utility.cpp */
extern vector<Employee *> read_employees(void);
extern void save_employees(vector<Employee *> &);
extern int register_employee(vector<Employee *> &);
extern string employee_login(vector<Employee *>);
extern int choice_input(void);
extern void invalid_choice(void);
extern void logtrace(string, string);

/* projects.cpp */
extern vector<Project *> read_project(void);
extern void save_project(vector<Project *> &);
extern void manage_projects(vector<Project *> &, vector<Ticket *> &, string);
extern int add_project(vector<Project *> &);

/* tickets.cpp */
extern vector<Ticket *> read_tickets(void);
extern void save_Ticket(vector<Ticket *> &);
extern void manage_tickets(vector<Ticket *> &, vector<Trail *> &);
extern void add_Ticket(vector<Ticket *> &);
extern void modify_Ticket(vector<Ticket *> &, vector<Trail *> &);
extern void close_Ticket(vector<Ticket *> &, vector<Trail *> &);
extern string *userEnteredTicket(string);

/* reports.cpp */
extern void manage_reports(vector<Ticket *>, string);

// trail.cpp
extern vector<Trail *> read_trail(void);
extern void save_Trail(vector<Trail *> &);

#endif // end __UTILITY_H_