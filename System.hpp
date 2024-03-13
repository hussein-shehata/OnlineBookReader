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
    UserManager MyUsers;

  public:
    void LoadInitialDataBase();
    void logout();
    bool login();
    void signup();

    void AddBook();
    void PrintAllBooks();


};



#endif /* SYSTEM_HPP_ */
