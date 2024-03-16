/*
 * Users.hpp
 *
 *  Created on: Mar 9, 2024
 *      Author: Scorpio
 */

#ifndef USERMANAGER_HPP_
#define USERMANAGER_HPP_

#include <iostream>
//#include <string>
#include <vector>
#include "Book.hpp"
#include "User.hpp"
using namespace std;


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

#endif /* USERMANAGER_HPP_ */
