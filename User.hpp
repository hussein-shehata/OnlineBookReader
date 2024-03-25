/*
 * User.hpp
 *
 *  Created on: Mar 15, 2024
 *      Author: Hussein
 */

#ifndef USER_HPP_
#define USER_HPP_

#include <iostream>
//#include <string>
#include <vector>
#include "Book.hpp"

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
    vector<pair<Book,unsigned int>> ReadingHistory; //the second member indicates the last page accessed for each book

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

     const vector<pair<Book,unsigned int>> &GetReadingHistory();
};






#endif /* USER_HPP_ */
