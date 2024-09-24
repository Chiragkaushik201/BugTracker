/********************************************************************************
 *     FILENAME           :    Trail.h
 *
 *     DESCRIPTION        :    ==========
 *
 *     REVISION HISTORY   :
 *
 *     DATE                NAME              REFERENCE               REASON
 *     --------------------------------------------------------------------
 *     ==========        ==========          Trail.h             ==========
 *
 *     Copyright © 2022 Capgemini Group  All Rights Reserved
 *
 ********************************************************************************/

/********************************************************************************
 *                             INCLUDE GUARDS
 ********************************************************************************/
#ifndef __TRAIL_H_
#define __TRAIL_H_

/********************************************************************************
 *                               HEADER FILES
 ********************************************************************************/
#include <utility.h>
using namespace std;

/********************************************************************************
 *     CLASS NAME       :   Trail
 *
 *     DESCRIPTION      :   ==========
 *
 *     DATA             :   None
 *
 *     FUNCTIONS        :   None
 *******************************************************************************/
class Trail
{

    /* Friend function */
    friend string getTrailData(Trail);

public:
    /* Constructors */
    Trail();
    Trail(string, string, string, string, string, string);
    Trail(const Trail &);

    /* Destructor */
    ~Trail();

    /* Functions */
    void printTrailDetails();

private:
    string ticketId;
    string changeDate;
    string oldEmployeeId;
    string newEmployeeId;
    string oldStatus;
    string newStatus;
};

#endif
