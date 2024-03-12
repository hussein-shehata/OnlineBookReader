/*
 * Users.hpp
 *
 *  Created on: Mar 9, 2024
 *      Author: Scorpio
 */

#ifndef USERS_HPP_
#define USERS_HPP_

#include <iostream>
//#include <string>
#include <vector>
#include "Library.hpp"
using namespace std;

typedef enum
{
  CustomerUserAccount,
  AdminUserAccount
} UserTypes;


class User {
  protected:
    string Name ;
    string Password;
    string Email;

  public:
    User(string Name, string Password, string Email) :
      Name(Name), Password(Password), Email(Email)
    {

    }
    void ViewProfile();
    void Logout();
    string GetName();
    string GetPassword();
//    virtual void GetUserType();
};


class CustomerUser : public User{
  private:
    vector<Book> ReadingHistory;

  public:
    CustomerUser(string Name, string Password, string Email):
      User( Name,  Password,  Email)
    {

    }
    void ViewReadingHistory();
    void ViewAvailableBooks();
    void ReadBook(unsigned int BookNumber);
//    void GetUserType();

};


class AdminUser : public User{
  private :
  public:
    AdminUser(string Name, string Password, string Email):
      User( Name,  Password,  Email)
    {

    }

//    void AddBook();
//    void GetUserType();

};


#endif /* USERS_HPP_ */
