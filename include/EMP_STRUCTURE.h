/** @file emp_structure.h
 *  @brief Function prototypes for emp_structure
 *
 *  
 * This header file is used to define 
 * the structure of employee record 
 *
 */
#ifndef EMP_STRUCTURE_H
#define EMP_STRUCTURE_H

struct emp{
    char name[40];/* name of employee */
    int id; /* employee id */
    char pass[10]; /* employee password */
    char desig[10]; /* employee designation */
    int age; /* age of employee */
    int leaves; /* leaves of employee */
    float bs; /*  basic salary of employee */
    int lleaves; /* No of leaves */
    int aleaves; /* applied leaves */
    }e;

#endif /*EMP_STRUCTURE_H*/
