/********************************************************************************
 *     FILENAME           :    trails.cpp
 *
 *     DESCRIPTION        :    ==========
 *
 *     REVISION HISTORY   :
 *
 *     DATE                NAME              REFERENCE               REASON
 *     --------------------------------------------------------------------
 *     ==========        ==========          trails.cpp             ==========
 *
 *     Copyright © 2022 Capgemini Group  All Rights Reserved
 *
 ********************************************************************************/

/********************************************************************************
 *                               HEADER FILES
 ********************************************************************************/
#include <utility.h>
#include <Trail.h>

/********************************************************************************
 *                               LOCAL FUNCTIONS
 ********************************************************************************/
int add_trail(vector<Trail *> &);

/**********************************************************************************
 *     FUNCTION NAME    :   Trail
 *
 *     DESCRIPTION      :   Non parameterized constructor for Employee class
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   None
 *********************************************************************************/
Trail::Trail()
{
    this->ticketId = "";
    this->changeDate = "";
    this->oldEmployeeId = "";
    this->newEmployeeId = "";
    this->oldStatus = "";
    this->newStatus = "";
}

/**********************************************************************************
 *     FUNCTION NAME    :   Trail
 *
 *     DESCRIPTION      :   Parameterized constructor for Trail class
 *
 *     PARAMETERS       :   createdBy,TrailDescription,changeDate,TrailDuration,
 *                          department,group
 *
 *     RETURNS          :   None
 *********************************************************************************/
Trail::Trail(
    string ticketId,
    string changeDate,
    string oldEmployeeid,
    string newEmployeeid,
    string oldStatus,
    string newStatus)
{
    this->ticketId = ticketId;
    this->changeDate = changeDate;
    this->oldEmployeeId = oldEmployeeid;
    this->newEmployeeId = newEmployeeid;
    this->oldStatus = oldStatus;
    this->newStatus = newStatus;
}

/**********************************************************************************
 *     FUNCTION NAME    :   Trail
 *
 *     DESCRIPTION      :   Copy constructor for Trail class
 *
 *     PARAMETERS       :   Employee &obj
 *
 *     RETURNS          :   None
 *********************************************************************************/
Trail::Trail(const Trail &ob)
{
    this->ticketId = ob.ticketId;
    this->changeDate = ob.changeDate;
    this->oldEmployeeId = ob.oldEmployeeId;
    this->newEmployeeId = ob.newEmployeeId;
    this->oldStatus = ob.oldStatus;
    this->newStatus = ob.newStatus;
}

/**********************************************************************************
 *     FUNCTION NAME    :   printTrailDetails()
 *
 *     DESCRIPTION      :   Function to print details of Trail
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   None
 *********************************************************************************/
void Trail::printTrailDetails()
{
    cout << "\n**************** Trail Details ****************\n";
    cout << "Ticket Id: " << this->ticketId << endl
         << "Created date: " << this->changeDate << endl
         << "Old employee id: " << this->oldEmployeeId << endl
         << "New employee id: " << this->newEmployeeId << endl
         << "Old status: " << this->oldStatus << endl
         << "New status: " << this->newStatus << endl;
}
/**********************************************************************************
 *     FUNCTION NAME    :   Trail
 *
 *     DESCRIPTION      :   Destructor for Trail class
 *
 *     PARAMETERS       :   Trail obj
 *
 *     RETURNS          :   None
 *********************************************************************************/
Trail::~Trail()
{
}
/**********************************************************************************
 *     FUNCTION NAME    :   read_Trail
 *
 *     DESCRIPTION      :   Function to read Trail from file and return an
 *                          Trail vector *
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   vector<Trail *>
 *********************************************************************************/
vector<Trail *> read_trail()
{
    /* Local variables */
    ifstream fin;
    string Trail_data;
    string trail_fields[6];
    vector<Trail *> Trail_vector;

    /* Try opening file and handle error */
    try
    {
        fin.open("../data/trails.txt", ios::in);

        if (fin.fail())
        {
            throw "\nCould not open trails.txt\n";
        }
    }
    catch (const string *err)
    {
        cerr << err;
        exit(EXIT_FAILURE);
    }

    /* Read each line and store in obj */
    while (getline(fin, Trail_data))
    {
        /* For each line tokenize the string */
        istringstream trail_obj(Trail_data);
        string word;
        int i = 0;

        while (getline(trail_obj, word, DELIMITER))
        {
            trail_fields[i] = word;
            i++;
        }

        /* Initialize Employee object with vector elements */
        Trail *obj = new Trail(
            trail_fields[0],  /* Ticket Id */
            trail_fields[1],  /* Creation Date */
            trail_fields[2],  /* Old Employee Id */
            trail_fields[3],  /* New Employee Id */
            trail_fields[4],  /* New status */
            trail_fields[5]); /* Old status */

        /* Push employee in employee vector */
        Trail_vector.push_back(obj);
    }

    fin.close();
    return Trail_vector;
}

/**********************************************************************************
 *     FUNCTION NAME    :   getTrailData
 *
 *     DESCRIPTION      :   Function to access all private data member of object,
 *                          concat them with ',' (format of employee.txt) and return
 *                          the final string
 *
 *     PARAMETERS       :   Trail obj
 *
 *     RETURNS          :   string
 *********************************************************************************/
string getTrailData(Trail obj)
{
    return obj.ticketId + "," +
           obj.changeDate + "," +
           obj.oldEmployeeId + "," +
           obj.newEmployeeId + "," +
           obj.oldStatus + "," +
           obj.newStatus;
}

/**********************************************************************************
 *     FUNCTION NAME    :   save_Trail
 *
 *     DESCRIPTION      :   Function to save each element of vector into database
 *
 *     PARAMETERS       :   vector<Trail *>
 *
 *     RETURNS          :   None
 *********************************************************************************/
void save_Trail(vector<Trail *> &trail_vector)
{
    fstream fout;

    /* Try opening file and handle error */
    try
    {
        fout.open("../data/trails.txt", ios::out);

        if (fout.fail())
        {
            throw "\nCould not open trails.txt\n";
        }
    }
    catch (const string *err)
    {
        cerr << err;
        exit(EXIT_FAILURE);
    }

    /* Save data in employee.txt */
    for (auto val : trail_vector)
    {
        fout << getTrailData(*val) << "\n";
        fout.seekp(0, ios::end); /* to ensure the put pointer is at the end */
    }

    /* Clear previous vector */
    for (auto trl : trail_vector)
        delete trl;

    /* Update new vector */
    trail_vector = read_trail();

    fout.close();
}

/**********************************************************************************
 *     FUNCTION NAME    :   add_trail()
 *
 *     DESCRIPTION      :   Adds new trail in trail vector and save it in db
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   string
 *********************************************************************************/
int add_trail(vector<Trail *> &trail_vector)
{
    /* Local Variables */
    string ticketId;
    string changeDate;
    string oldEmployeeId;
    string newEmployeeId;
    string oldStatus;
    string newStatus;

    cout << "\n**************** trail Creation ****************\n";
    cout << "\nEnter the ticket Id : ";
    getline(cin, ticketId);

    cout << "\nEnter the created date  : ";
    getline(cin, changeDate);

    cout << "\nEnter the old employee id : ";
    getline(cin, oldEmployeeId);

    cout << "\nEnter the new employee id : ";
    getline(cin, newEmployeeId);

    cout << "\nEnter the old status : ";
    cin >> oldStatus;

    cout << "\nEnter the new status : ";
    cin >> newStatus;

    /* Create trail object */
    Trail *obj = new Trail(
        ticketId,
        changeDate,
        oldEmployeeId,
        newEmployeeId,
        oldStatus,
        newStatus);

    /* Save trail in vector */
    trail_vector.push_back(obj);

    /* Save trail in database */
    save_Trail(trail_vector);

    return EXIT_SUCCESS;
}
