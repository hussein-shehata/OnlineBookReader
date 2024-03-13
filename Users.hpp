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
} UserType;


class User {
  private:
    string Name ;
    string Password;
    string Email;
    UserType IsUserAdmin = CustomerUserAccount;
    vector<Book> ReadingHistory;

  public:
    User(string Name, string Password, string Email, UserType IsUserAdmin);

    void ViewProfile();
    string GetName();
    string GetPassword();
    UserType GetUserType();

    void ViewReadingHistory();
    void ReadBook(unsigned int BookIndex);


    void AddBookToReadingHistory(const Book& NewBook);
    void RemoveBookFromReadingHistory(string BookName);
};


class UserManager{
  private:
    vector<User> RegisteredUsers;
    User* CurrentUser = nullptr;
  public:
    void AddUser(string Name, string Password, string Emai);
    void AddAdminUser(string Name, string Password, string Emai);
    void RemoveUser(string UserName);
    bool LogIn(string UserName, string Password);
     User* GetCurrentUser();
    void Logout();
//    bool FindUser(string UserName, string UserPassword);



};

#endif /* USERS_HPP_ */
