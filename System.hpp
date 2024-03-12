/*
 * System.hpp
 *
 *  Created on: Mar 11, 2024
 *      Author: Hussein
 */

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_
#include "Users.hpp"
#include "Library.hpp"



class System{
  private:
    Library MyLibrary;
    vector<CustomerUser> CustomerUsers;
    vector<AdminUser> AdminUsers;
    User* CurrentUser; // Regardless if he was admin or customer we dont know , i will use polyramphisim in deducing who he is

  public:
    void LoadInitialDataBase();
    void logout();
    bool login();
    void signup();


};



#endif /* SYSTEM_HPP_ */
