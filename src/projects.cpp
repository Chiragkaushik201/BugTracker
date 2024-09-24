/********************************************************************************
 *     FILENAME           :    projects.cpp
 *
 *     DESCRIPTION        :    ==========
 *
 *     REVISION HISTORY   :
 *
 *     DATE                NAME              REFERENCE               REASON
 *     --------------------------------------------------------------------
 *     ==========        ==========          projects.cpp             ==========
 *
 *     Copyright © 2022 Capgemini Group  All Rights Reserved
 *
 ********************************************************************************/

/********************************************************************************
 *                               HEADER FILES
 ********************************************************************************/
#include <utility.h>
#include <Project.h>

/********************************************************************************
 *                               LOCAL FUNCTIONS
 ********************************************************************************/
int add_project(vector<Project *> &);
int modify_project(vector<Project *> &, string empId);
int delete_project(vector<Project *> &, vector<Ticket *> &);

/**********************************************************************************
 *     FUNCTION NAME    :   Project
 *
 *     DESCRIPTION      :   Non parameterized constructor for Employee class
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   None
 *********************************************************************************/
Project::Project()
{
    this->projectId = "";
    this->projectCreatedBy = "";
    this->projectDescription = "";
    this->projectCreationDate = "";
    this->projectDuration = "";
    this->projectDepartment = "";
    this->projectGroup = "";
}

/**********************************************************************************
 *     FUNCTION NAME    :   Project
 *
 *     DESCRIPTION      :   Parameterized constructor for Project class
 *
 *     PARAMETERS       :   createdBy,projectDescription,createdDate,projectDuration,
 *                          department,group
 *
 *     RETURNS          :   None
 *********************************************************************************/
Project::Project(
    string projectId,
    string projectCreatedBy,
    string projectDescription,
    string projectCreationDate,
    string projectDuration,
    string projectDepartment,
    string projectGroup)
{
    this->projectId = projectId;
    this->projectCreatedBy = projectCreatedBy;
    this->projectDescription = projectDescription;
    this->projectCreationDate = projectCreationDate;
    this->projectDuration = projectDuration;
    this->projectDepartment = projectDepartment;
    this->projectGroup = projectGroup;
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
Project::Project(const Project &ob)
{
    this->projectId = ob.projectId;
    this->projectCreatedBy = ob.projectCreatedBy;
    this->projectDescription = ob.projectDescription;
    this->projectCreationDate = ob.projectCreationDate;
    this->projectDuration = ob.projectDuration;
    this->projectDepartment = ob.projectDepartment;
    this->projectGroup = ob.projectGroup;
}

/**********************************************************************************
 *     FUNCTION NAME    :   Project
 *
 *     DESCRIPTION      :   Destructor for Project class
 *
 *     PARAMETERS       :   Project obj
 *
 *     RETURNS          :   None
 *********************************************************************************/
Project::~Project()
{
}

/**********************************************************************************
 *     FUNCTION NAME    :   getProjId()
 *
 *     DESCRIPTION      :   Returns the project id of project
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   string
 *********************************************************************************/
string Project::getProjId()
{
    return this->projectId;
}

/**********************************************************************************
 *     FUNCTION NAME    :   getProjCreatedBy()
 *
 *     DESCRIPTION      :   Returns the employee id of project creator
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   string
 *********************************************************************************/
string Project::getProjCreatedBy()
{
    return this->projectCreatedBy;
}

/**********************************************************************************
 *     FUNCTION NAME    :   addDeatils()
 *
 *     DESCRIPTION      :   Adds a new details to
 *
 *     PARAMETERS       :   string note
 *
 *     RETURNS          :   None
 *********************************************************************************/
void Project::addProjDetails(
    string projectCreatedBy,
    string projectDescription,
    string projectCreationDate,
    string projectDuration,
    string projectDepartment,
    string projectGroup)
{
    this->projectCreatedBy = projectCreatedBy;
    this->projectDescription = projectDescription;
    this->projectCreationDate = projectCreationDate;
    this->projectDuration = projectDuration;
    this->projectDepartment = projectDepartment;
    this->projectGroup = projectGroup;
}

/**********************************************************************************
 *     FUNCTION NAME    :   printProjectDetails()
 *
 *     DESCRIPTION      :   Function to print details of project
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   None
 *********************************************************************************/
void Project::printProjectDetails()
{
    cout << "\n**************** Project Details ****************\n";
    cout << "Project Id: " << this->projectId << endl
         << "Created by(Employee ID): " << this->projectCreatedBy << endl
         << "Project description: " << this->projectDescription << endl
         << "Created Date: " << this->projectCreationDate << endl
         << "Project Duration: " << this->projectDuration << endl
         << "Department: " << this->projectDepartment << endl
         << "Group: " << this->projectGroup << endl;
}

/**********************************************************************************
 *     FUNCTION NAME    :   read_project
 *
 *     DESCRIPTION      :   Function to read project from file and return an
 *                          project vector *
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   vector<project *>
 *********************************************************************************/
vector<Project *> read_project()
{
    /* Local variables */
    ifstream fin;
    string project_data;
    string proj_fields[7];
    vector<Project *> project_vector;

    /* Try opening file and handle error */
    try
    {
        fin.open("../data/projects.txt", ios::in);

        if (fin.fail())
        {
            throw "\nCould not open projects.txt\n";
        }
    }
    catch (const string *err)
    {
        logtrace(FATAL, *err);
        cerr << err;
        exit(EXIT_FAILURE);
    }

    /* Read each line and store in obj */
    while (getline(fin, project_data))
    {
        /* For each line tokenize the string */
        istringstream proj_obj(project_data);
        string word;
        int i = 0;

        while (getline(proj_obj, word, DELIMITER))
        {
            proj_fields[i] = word;
            i++;
        }

        /* Initialize Employee object with vecotor elements */
        Project *obj = new Project(
            proj_fields[0],  /* Project Id */
            proj_fields[1],  /* Employee Id */
            proj_fields[2],  /* Project Description */
            proj_fields[3],  /* Creation Date */
            proj_fields[4],  /* project Duration */
            proj_fields[5],  /* Department */
            proj_fields[6]); /* Group*/

        if (obj == NULL)
        {
            logtrace(FATAL, ERR_MEM_ALLOC);
            cerr << ERR_MEM_ALLOC;
            exit(EXIT_FAILURE);
        }

        /* Push employee in employee vector */
        project_vector.push_back(obj);
    }

    fin.close();
    return project_vector;
}

/**********************************************************************************
 *     FUNCTION NAME    :   getProjectData
 *
 *     DESCRIPTION      :   Function to access all private data member of object,
 *                          concat them with ',' (format of employee.txt) and return
 *                          the final string
 *
 *     PARAMETERS       :   Project obj
 *
 *     RETURNS          :   string
 *********************************************************************************/
string getProjectData(Project obj)
{
    return obj.projectId + "," +
           obj.projectCreatedBy + "," +
           obj.projectDescription + "," +
           obj.projectCreationDate + "," +
           obj.projectDuration + "," +
           obj.projectDepartment + "," +
           obj.projectGroup;
}

/**********************************************************************************
 *     FUNCTION NAME    :   save_project
 *
 *     DESCRIPTION      :   Function to save each element of vector into database
 *
 *     PARAMETERS       :   vector<Project *>
 *
 *     RETURNS          :   None
 *********************************************************************************/
void save_project(vector<Project *> &proj_vector)
{
    fstream fout;

    /* Try opening file and handle error */
    try
    {
        fout.open("../data/projects.txt", ios::out);

        if (fout.fail())
        {
            throw "\nCould not open projects.txt\n";
        }
    }
    catch (const string *err)
    {
        logtrace(FATAL, *err);
        cerr << err;
        exit(EXIT_FAILURE);
    }

    /* Save data in employee.txt */
    for (auto val : proj_vector)
    {
        fout << getProjectData(*val) << "\n";
        fout.seekp(0, ios::end); /* to ensure the put pointer is at the end */
    }

    /* Clear previous vector */
    for (auto prj : proj_vector)
        delete prj;

    /* Update new vector */
    proj_vector = read_project();

    fout.close();
}

/**********************************************************************************
 *     FUNCTION NAME    :   manage_projects
 *
 *     DESCRIPTION      :   Add / modify / delete project
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   None
 *********************************************************************************/
void manage_projects(
    vector<Project *> &project_vector,
    vector<Ticket *> &ticket_vector,
    string empId)
{
    logtrace(INFO, "manage_projects() started");

    int ch;
    int loop_check = 1;
    do
    {
        cout << "\n-------------- Projects Menu --------------\n";
        cout << "\n1. Add Project";
        cout << "\n2. Modify Project";
        cout << "\n3. Delete Project";
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
            add_project(project_vector);
        }
        break;
        case 2:
        {
            modify_project(project_vector, empId);
        }
        break;
        case 3:
        {
            delete_project(project_vector, ticket_vector);
        }
        break;
        default:
        {
            invalid_choice();
        }
        }
    } while (loop_check);

    logtrace(INFO, "manage_projects() finished");
}

/**********************************************************************************
 *     FUNCTION NAME    :   add_project()
 *
 *     DESCRIPTION      :   Adds new project in project vector and save it in db
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   EXIT_SUCCESS or  EXIT_FAILURE
 *********************************************************************************/
int add_project(vector<Project *> &project_vector)
{
    logtrace(INFO, "add_project() started");

    /* Local Variables */
    string projectId;
    string projectCreatedBy;
    string projectDescription;
    string projectCreationDate;
    string projectDuration;
    string projectDepartment;
    string projectGroup;

    cout << "\n**************** Project Creation ****************\n";
    cout << "\nEnter the Project Id : ";
    getline(cin, projectId);

    /* Check for unique project id */
    for (auto val : project_vector)
    {
        if (val->getProjId() == projectId)
        {
            cout << "\nProject id already exist\n";
            return EXIT_FAILURE;
        }
    }

    cout << "\nEmployee Id of Project creator : ";
    getline(cin, projectCreatedBy);

    cout << "\nEnter the Project Description : ";
    getline(cin, projectDescription);

    cout << "\nEnter the Project Creation date : ";
    getline(cin, projectCreationDate);

    cout << "\nEnter the Project Duration : ";
    getline(cin, projectDuration);

    cout << "\nEnter the Project Department : ";
    getline(cin, projectDepartment);

    cout << "\nEnter the Project Group : ";
    getline(cin, projectGroup);

    /* Create Project object */
    Project *obj = new Project(
        projectId,
        projectCreatedBy,
        projectDescription,
        projectCreationDate,
        projectDuration,
        projectDepartment,
        projectGroup);

    /* Save project in vector */
    project_vector.push_back(obj);

    /* Save project in database */
    save_project(project_vector);

    logtrace(INFO, "add_project() finished");

    return EXIT_SUCCESS;
}

/**********************************************************************************
 *     FUNCTION NAME    :   modify_project()
 *
 *     DESCRIPTION      :   Modify the existing project in project vector and save it in db
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   EXIT_SUCCESS or  EXIT_FAILURE
 *********************************************************************************/
int modify_project(vector<Project *> &project_vector, string empId)
{
    logtrace(INFO, "modify_project() started");

    /* Local Variables */
    int flag1 = 0;
    int flag2 = 0;
    string projectId;
    string projectCreatedBy;
    string projectDescription;
    string projectCreationDate;
    string projectDuration;
    string projectDepartment;
    string projectGroup;

    cout << "\n**************** Project Creation ****************\n";
    cout << "\nEnter the Project Id : ";
    getline(cin, projectId);

    /* Check for project id */
    for (auto val : project_vector)
    {
        if (val->getProjId() != projectId)
        {
            continue;
        }
        else if (val->getProjId() == projectId)
        {
            flag1 = 1;

            /* Check for employee id */
            if (val->getProjCreatedBy() != empId)
            {
                continue;
            }
            else if (val->getProjCreatedBy() == empId)
            {

                flag2 = 1;

                cout << "\n*******Enter Project Modification details*******\n";

                cout << "\nEmployee Id of Project creator : ";
                getline(cin, projectCreatedBy);

                cout << "\nEnter the Project Description : ";
                getline(cin, projectDescription);

                cout << "\nEnter the Project Creation date : ";
                getline(cin, projectCreationDate);

                cout << "\nEnter the Project Duration : ";
                getline(cin, projectDuration);

                cout << "\nEnter the Project Department : ";
                getline(cin, projectDepartment);

                cout << "\nEnter the Project Group : ";
                getline(cin, projectGroup);

                val->addProjDetails(projectCreatedBy, projectDescription, projectCreationDate, projectDuration, projectDepartment, projectGroup);
                save_project(project_vector);

                cout << "\nProject Modified!\n";
                return EXIT_SUCCESS;
            }
        }
    }
    if (flag1 == 0)
    {
        cout << "Project Not Available" << endl;
        return EXIT_FAILURE;
    }

    if (flag2 == 0)
    {
        cout << "Project " << projectId << " not created by " << empId << ", cannot be modified" << endl;
        return EXIT_FAILURE;
    }

    logtrace(INFO, "modify_project() finished");

    return EXIT_SUCCESS;
}

/**********************************************************************************
 *     FUNCTION NAME    :   delete_project()
 *
 *     DESCRIPTION      :   Deletes project in project vector if there are no open tickets associated with it
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   EXIT_SUCCESS or  EXIT_FAILURE
 *********************************************************************************/
int delete_project(vector<Project *> &project_vector, vector<Ticket *> &ticket_vector)
{

    logtrace(INFO, "delete_projects() started");

    /* Local Variables */
    int flag = 0;
    int flag1 = 0;
    string projectId;
    string ticketId;
    int index = 0;
    // vector<Ticket *> ticket_vector;

    // cout << "\n**************** Project Deletion ****************\n";
    cout << "\nEnter the Project Id to delete : ";
    getline(cin, projectId);

    /* Check for project id */
    for (auto val : project_vector)
    {
        index++;
        if (val->getProjId() != projectId)
        {
            continue;
        }
        else if (val->getProjId() == projectId)
        {
            flag = 1;
            cout << "\nProject was present \n";
            break;
        }
    }
    if (flag == 0)
    {
        cout << "Project was not present" << endl;
        return EXIT_FAILURE;
    }

    for (auto val : ticket_vector)
    {
        if (val->getProjId() != projectId)
        {
            continue;
        }
        else if (val->getProjId() == projectId)
        {
            flag1 = 1;
            cout << "\nTicket were present for this project " << projectId << endl;
            return EXIT_FAILURE;
        }
    }
    if (flag1 == 0)
    {
        for (auto val : project_vector)
        {
            if (val->getProjId() == projectId)
            {
                delete val;
                project_vector.erase(project_vector.begin() + index - 1);
                save_project(project_vector);
            }
        }
    }

    logtrace(INFO, "delete_projects() finished");

    return EXIT_SUCCESS;
}