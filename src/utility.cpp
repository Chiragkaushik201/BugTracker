/********************************************************************************
 *     FILENAME           :    utility.cpp
 *
 *     DESCRIPTION        :    ==========
 *
 *     REVISION HISTORY   :
 *
 *     DATE                NAME              REFERENCE               REASON
 *     --------------------------------------------------------------------
 *     ==========        ==========          utility.cpp             ==========
 *
 *     Copyright © 2022 Capgemini Group  All Rights Reserved
 *
 ********************************************************************************/

/********************************************************************************
 *                               HEADER FILES
 ********************************************************************************/
#include <utility.h>
#include <Employee.h>

/**********************************************************************************
 *     FUNCTION NAME    :   Employee
 *
 *     DESCRIPTION      :   Non parameterized constructor for Employee class
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   None
 *********************************************************************************/
Employee::Employee()
{
    this->empId = "";
    this->empPassword = "";
    this->empName = "";
    this->empDepartment = "";
    this->empMobileNum = "";
    this->empEmailId = "";
    this->empSkypeId = "";
}

/**********************************************************************************
 *     FUNCTION NAME    :   Employee
 *
 *     DESCRIPTION      :   Parameterized constructor for Employee class
 *
 *     PARAMETERS       :   name, password, mobile, email, skype, department
 *
 *     RETURNS          :   None
 *********************************************************************************/
Employee::Employee(
    string empId,
    string empPassword,
    string empName,
    string empDepartment,
    string empMobileNum,
    string empEmailId,
    string empSkypeId)
{
    this->empId = empId;
    this->empPassword = empPassword;
    this->empName = empName;
    this->empDepartment = empDepartment;
    this->empMobileNum = empMobileNum;
    this->empEmailId = empEmailId;
    this->empSkypeId = empSkypeId;
}

/**********************************************************************************
 *     FUNCTION NAME    :   Employee
 *
 *     DESCRIPTION      :   Copy constructor for Employee class
 *
 *     PARAMETERS       :   Employee &obj
 *
 *     RETURNS          :   None
 *********************************************************************************/
Employee::Employee(const Employee &obj)
{
    this->empId = obj.empId;
    this->empPassword = obj.empPassword;
    this->empName = obj.empName;
    this->empDepartment = obj.empDepartment;
    this->empMobileNum = obj.empMobileNum;
    this->empEmailId = obj.empEmailId;
    this->empSkypeId = obj.empSkypeId;
}

/**********************************************************************************
 *     FUNCTION NAME    :   Employee
 *
 *     DESCRIPTION      :   Destructor for Employee class
 *
 *     PARAMETERS       :   Employee obj
 *
 *     RETURNS          :   None
 *********************************************************************************/
Employee::~Employee()
{
}

/**********************************************************************************
 *     FUNCTION NAME    :   printEmployeeDetails()
 *
 *     DESCRIPTION      :   Function to print details of employee
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   None
 *********************************************************************************/
void Employee::printEmployeeDetails()
{
    cout << "\n**************** Employee Details ****************\n";
    cout << "Employee Id: " << this->empId << endl
         << "Employee Name: " << this->empName << endl
         << "Employee Mobile Number: " << this->empMobileNum << endl
         << "Employee Email Id: " << this->empEmailId << endl
         << "Employee Skype Id: " << this->empSkypeId << endl
         << "Employee Department: " << this->empDepartment << endl;
}

/**********************************************************************************
 *     FUNCTION NAME    :   getEmpId()
 *
 *     DESCRIPTION      :   Returns the employee id of employee
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   string
 *********************************************************************************/
string Employee::getEmpId()
{
    return this->empId;
}

/**********************************************************************************
 *     FUNCTION NAME    :   read_employees
 *
 *     DESCRIPTION      :   Function to read employees from file and return an
 *                          employee vector *
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   vector<Employee *>
 *********************************************************************************/
vector<Employee *> read_employees()
{
    /* Local variables */
    ifstream fin;
    string emp_data;
    vector<string> emp_fields;
    vector<Employee *> emp_vector;

    /* Try opening file and handle error */
    try
    {
        fin.open("../data/employees.txt", ios::in);

        if (fin.fail())
        {
            throw "\nCould not open employees.txt\n";
        }
    }
    catch (const string *ex)
    {
        logtrace(FATAL, *ex);
        cerr << ex;
        exit(EXIT_FAILURE);
    }

    /* Read each line and store in obj */
    while (getline(fin, emp_data))
    {
        /* For each line tokenize the string */
        istringstream ss(emp_data);
        string token;

        while (getline(ss, token, DELIMITER))
        {
            emp_fields.push_back(token);
        }

        /* Initialize Employee object with vecotor elements */
        Employee *obj = new Employee(
            emp_fields[0],  /* Employee Id */
            emp_fields[1],  /* Employee Password */
            emp_fields[2],  /* Employee Name */
            emp_fields[3],  /* Employee Department */
            emp_fields[4],  /* Employee MobileNum */
            emp_fields[5],  /* Employee EmailId */
            emp_fields[6]); /* Employee SkypeId*/

        if (obj == NULL)
        {
            logtrace(FATAL, ERR_MEM_ALLOC);
            cerr << ERR_MEM_ALLOC;
            exit(EXIT_FAILURE);
        }

        /* Push employee in employee vector */
        emp_vector.push_back(obj);
        emp_fields.clear();
    }

    fin.close();
    return emp_vector;
}

/**********************************************************************************
 *     FUNCTION NAME    :   getEmployeeData
 *
 *     DESCRIPTION      :   Function to access all private data member of object,
 *                          concat them with ',' (format of employee.txt) and return
 *                          the final string
 *
 *     PARAMETERS       :   Employee obj
 *
 *     RETURNS          :   string
 *********************************************************************************/
string getEmployeeData(Employee obj)
{
    return obj.empId + "," +
           obj.empPassword + "," +
           obj.empName + "," +
           obj.empDepartment + "," +
           obj.empMobileNum + "," +
           obj.empEmailId + "," +
           obj.empSkypeId;
}

/**********************************************************************************
 *     FUNCTION NAME    :   save_employees
 *
 *     DESCRIPTION      :   Function to save each element of vector into database
 *
 *     PARAMETERS       :   vector<Employee *>
 *
 *     RETURNS          :   None
 *********************************************************************************/
void save_employees(vector<Employee *> &emp_vector)
{
    ofstream fout;

    /* Try opening file and handle error */
    try
    {
        fout.open("../data/employees.txt", ios::out);

        if (fout.fail())
        {
            throw "\nCould not open employees.txt\n";
        }
    }
    catch (const string *ex)
    {
        logtrace(FATAL, *ex);
        cerr << ex;
        exit(EXIT_FAILURE);
    }

    /* Save data in employee.txt */
    for (auto val : emp_vector)
    {
        fout << getEmployeeData(*val) << "\n";
        fout.seekp(0, ios::end); /* to ensure the put pointer is at the end */
    }

    /* Clear previous vector */
    for (auto emp : emp_vector)
        delete emp;

    /* Update new vector */
    emp_vector = read_employees();

    fout.close();
}

/**********************************************************************************
 *     FUNCTION NAME    :   register_employee
 *
 *     DESCRIPTION      :   Function to dynamically create new employee save them in
 *                          vector then call save_employee() to save them in database
 *
 *     PARAMETERS       :   vector<Employee *>
 *
 *     RETURNS          :   EXIT_SUCCESS or EXIT_FAILURE
 *********************************************************************************/
int register_employee(vector<Employee *> &emp_vector)
{
    /* Local variables */
    string empId = "";
    string empPassword = "";
    string empName = "";
    string empDepartment = "";
    string empMobileNum = "";
    string empEmailId = "";
    string empSkypeId = "";

    cout << "\n**************** Employee Registration ****************\n";

    cout << "\nEnter the Employee Id : ";
    getline(cin, empId);

    /* Check for unique employee id */
    for (auto val : emp_vector)
    {
        if (val->getEmpId() == empId)
        {
            cout << "\nEmployee id already exist\n";
            return EXIT_FAILURE;
        }
    }

    cout << "\nEnter the Employee Password : ";
    getline(cin, empPassword);

    cout << "\nEnter the Employee Name : ";
    getline(cin, empName);

    cout << "\nEnter the Employee Department : ";
    getline(cin, empDepartment);

    cout << "\nEnter the Employee Mobile Number : ";
    getline(cin, empMobileNum);

    cout << "\nEnter the Employee email : ";
    getline(cin, empEmailId);

    cout << "\nEnter the Employee Skype Id : ";
    getline(cin, empSkypeId);

    /* Create employee object */
    Employee *obj = new Employee(
        empId,
        empPassword,
        empName,
        empDepartment,
        empMobileNum,
        empEmailId,
        empSkypeId);

    if (obj == NULL)
    {
        logtrace(FATAL, ERR_MEM_ALLOC);
        cerr << ERR_MEM_ALLOC;
        exit(EXIT_FAILURE);
    }

    /* Save employee in vector */
    emp_vector.push_back(obj);

    /* Save employee in database */
    save_employees(emp_vector);

    return EXIT_SUCCESS;
}
/**********************************************************************************
 *     FUNCTION NAME    :   employee_login
 *
 *     DESCRIPTION      :   Function to check and validate employee credentials
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   None
 *********************************************************************************/
string employee_login(vector<Employee *> emp)
{
    string emp_id;
    string pass;
    cout << "\nEnter Employee ID : ";
    cin >> emp_id;
    cout << "\nEnter Password : ";
    cin >> pass;

    string emp_line;
    string class_empid;
    string class_pass;
    for (auto val : emp)
    {
        emp_line = getEmployeeData(*val);
        stringstream ss(emp_line);
        getline(ss, class_empid, DELIMITER);
        getline(ss, class_pass, DELIMITER);

        if (class_empid == emp_id)
        {
            if (class_pass == pass)
            {
                logtrace(INFO, "Employee login successful!");
                return class_empid;
            }
        }
    }

    logtrace(INFO, "Employee login failed!");
    return EMPTY_STRING;
}

/**********************************************************************************
 *     FUNCTION NAME    :   choice_input
 *
 *     DESCRIPTION      :   Prompts and take input from user and return to caller
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   int choice
 *********************************************************************************/
int choice_input()
{
    int choice;
    cout << ENTER_CHOICE;
    cin >> choice;
    cin.ignore();

    return choice;
}

/**********************************************************************************
 *     FUNCTION NAME    :   choice_input
 *
 *     DESCRIPTION      :   Display invalid choice to user
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   None
 *********************************************************************************/
void invalid_choice()
{
    cout << INVALID_CHOICE;
    cout << ENTER_TO_CONTINUE;
    cin.ignore();
}

/**********************************************************************************
 *     FUNCTION NAME    :   logtrace
 *
 *     DESCRIPTION      :   Adds log
 *
 *     PARAMETERS       :   None
 *
 *     RETURNS          :   None
 *********************************************************************************/
void logtrace(string criticality, string message)
{
    time_t tm = time(NULL);
    char *curr_time = ctime(&tm);

    ofstream fout;

    /* Try opening file and handle error */
    try
    {
        fout.open(LOG_FILENAME, ios::app);

        if (fout.fail())
        {
            throw "\nCould not open employees.txt\n";
        }
    }
    catch (const string *ex)
    {
        cerr << ex;
        exit(EXIT_FAILURE);
    }

    fout << "\nT: " << curr_time << "C: " << criticality << "\nM: " << message << endl;

    fout.close();
}