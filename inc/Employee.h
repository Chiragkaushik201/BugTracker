/********************************************************************************
 *     FILENAME           :    Employee.h
 *
 *     DESCRIPTION        :    ==========
 *
 *     REVISION HISTORY   :
 *
 *     DATE                NAME              REFERENCE               REASON
 *     --------------------------------------------------------------------
 *     ==========        ==========          Employee.h             ==========
 *
 *     Copyright © 2022 Capgemini Group  All Rights Reserved
 *
 ********************************************************************************/

/********************************************************************************
 *                             INCLUDE GUARDS
 ********************************************************************************/
#ifndef __EMPLOYEE_H_
#define __EMPLOYEE_H_

/********************************************************************************
 *                               HEADER FILES
 ********************************************************************************/
#include <utility.h>
using namespace std;

/********************************************************************************
 *     CLASS NAME       :   Employee
 *
 *     DESCRIPTION      :   ==========
 *
 *     DATA             :   None
 *
 *     FUNCTIONS        :   None
 *******************************************************************************/
class Employee
{
public:
    /* Friend function */
    friend string getEmployeeData(Employee);

    /* Constructors */
    Employee();
    Employee(string, string, string, string, string, string, string);
    Employee(const Employee &);

    /* Destructor */
    ~Employee();

    /* Functions */
    void printEmployeeDetails();
    string getEmpId();

private:
    string empId;         /* Employee Id */
    string empPassword;   /* Employee Password */
    string empName;       /* Employee Name */
    string empDepartment; /* Employee Department */
    string empMobileNum;  /* Employee Mobile Number */
    string empEmailId;    /* Employee Email Id */
    string empSkypeId;    /* Employee Skype Id */
};

#endif
