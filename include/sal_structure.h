/** @file sal_structure.h
 *  @brief Function prototypes for sal_structure
 *
 *  
 * This header file is used to define the 
 * structure of salary
 *
 */
#ifndef sal_h
#define sal_h

struct sal
    {
        int id; /* employee id*/
        char name[40]; /* name of employee*/
        float hours; /* no of hours worked*/
        int mon; /* month*/
        float salary; /* salary for that month */
    };
    struct sal s;

#endif /* end of sal_structure.h */
