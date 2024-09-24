/********************************************************************************
 *     FILENAME           :    Project.h
 *
 *     DESCRIPTION        :    ==========
 *
 *     REVISION HISTORY   :
 *
 *     DATE                NAME              REFERENCE               REASON
 *     --------------------------------------------------------------------
 *     ==========        ==========          Project.h             ==========
 *
 *     Copyright © 2022 Capgemini Group  All Rights Reserved
 *
 ********************************************************************************/

/********************************************************************************
 *                             INCLUDE GUARDS
 ********************************************************************************/
#ifndef __PROJECT_H_
#define __PROJECT_H_

/********************************************************************************
 *                               HEADER FILES
 ********************************************************************************/
#include <utility.h>
using namespace std;

/********************************************************************************
 *     CLASS NAME       :   Project
 *
 *     DESCRIPTION      :   ==========
 *
 *     DATA             :   None
 *
 *     FUNCTIONS        :   None
 *******************************************************************************/
class Project
{
public:
    /* Friend function */
    friend string getProjectData(Project);

    /* Constructors */
    Project();
    Project(string, string, string, string, string, string, string);
    Project(const Project &);

    /* Destructor */
    ~Project();

    /* Functions */
    void printProjectDetails();
    string getProjId();
    string getProjCreatedBy();
    void addProjDetails(string, string, string, string, string, string);

private:
    string projectId;           /* Project Id of project */
    string projectCreatedBy;    /* Project Created By: <Employe Id> */
    string projectDescription;  /* Project Description */
    string projectCreationDate; /* Project Creation Date */
    string projectDuration;     /* Project Duration: <In months> */
    string projectDepartment;   /* Project Department */
    string projectGroup;        /* Project Group */
};

#endif
