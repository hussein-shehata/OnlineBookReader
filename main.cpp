/*
 * main.cpp
 *
 *  Created on: Mar 9, 2024
 *      Author: Hussein
 */


#include "Users.hpp"
#include "Library.hpp"
#include "System.hpp"

int main()
{
  Library MyLibrary;
//  MyLibrary.AddBook("SH", "Conan", 2);
//  MyLibrary.AddBook("SH", "Conan", 2);

  System MySystem;
  MySystem.LoadInitialDataBase();

  MySystem.login();

  MySystem.logout();
asm("NOP");
  return 0;
}

