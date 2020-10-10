/**
* @mainpage contact Management System  by Manushna Bandari with PS:ID-104908 @subpage contactmanagementsystem.h
* @file contactmanagementsystem.h
* contactmanagementsystem application with 5 operations
*
*/
#ifndef CONTACTMANAGEMENTSYSTEM_H_
#define CONTACTMANAGEMENTSYSTEM_H_

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct contact
{
    long phone;
    char name[20],add[20],email[30];
};

/**
*  adds the contact and returns the result
* @param[in] c.name
* @param[in] c.phone
* @param[in] c.add
* @param[in] c.email
* @return Result Contact Added Successfully
*/
int ADD_CONTACT();


/**
*  adds the contact and returns the result
* @return Result of all contacts with details of c.name c.phone c.add c.email
*/

int VIEW_CONTACT();

/**
*  adds the contact and returns the result
* @param[in] c.name
* @return Result of contact details c.name c.phone c.add c.email
*/
int SEARCH_CONTACT();


/**
* edits the contact and returns the result
* @param[in] c.name
* @param[in] c.phone
* @param[in] c.add
* @param[in] c.email
* @return Result Contact edited Successfully
*/

int EDIT_CONTACT();


/**
* deletes the contact and returns the result
* @return Result Contact deleted Successfully
*/
int DELETE_CONTACT();


#endif // CONTACTMANAGEMENTSYSTEM_H_INCLUDED
