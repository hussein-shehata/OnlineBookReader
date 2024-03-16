/*
 * System.hpp
 *
 *  Created on: Mar 11, 2024
 *      Author: Hussein
 */

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_
#include "Library.hpp"
#include "UserManager.hpp"



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

    void SelectBookCommand(unsigned int BookNumber, BookSource BookSource);
    void ReadCommand();
    void NextPageCommand();
    void PrevPageCommand();
    void StopReadingCommand();


};



#endif /* SYSTEM_HPP_ */
