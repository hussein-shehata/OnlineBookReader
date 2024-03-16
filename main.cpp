/*
 * main.cpp
 *
 *  Created on: Mar 9, 2024
 *      Author: Hussein
 */


#include "Library.hpp"
#include "System.hpp"
#include "UserManager.hpp"

int main()
{
  Library MyLibrary;
//  MyLibrary.AddBook("SH", "Conan", 2);
//  MyLibrary.AddBook("SH", "Conan", 2);

  System MySystem;
  MySystem.LoadInitialDataBase();

  MySystem.login();
  MySystem.AddBook();

  MySystem.login();
  MySystem.AddBook();

  MySystem.PrintAllBooks();
  MySystem.SelectBookCommand(0, FromAvailableBooks);
  MySystem.ReadCommand();
  MySystem.NextPageCommand();
  MySystem.PrevPageCommand();
  MySystem.logout();
asm("NOP");
  return 0;
}

