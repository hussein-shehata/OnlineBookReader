/*
 * main.cpp
 *
 *  Created on: Mar 9, 2024
 *      Author: Hussein
 */


#include "Library.hpp"
#include "System.hpp"
#include "UserManager.hpp"

using namespace std;

class SubClass{
  private:
    char* Name = "s";
  public:
    void PrintName()
    {
      cout<<"Name is : "<<Name[0]<<endl;
    }
};

class Test{
  public:
    int x;
    SubClass MySubClass;

    int& GetX()
    {
      return x;
    }

    SubClass GetMySubClass()
    {
      cout<<"Address inside the function : "<<&MySubClass<<endl;
      return MySubClass;
    }

};

int main()
{
/*
  Test MyTest;
  MyTest.x = 5;
  cout<<"X = "<<MyTest.x<<"With address = "<<&(MyTest.x)<<endl;
  int& Xref = MyTest.GetX();
  Xref = 25;
  cout<<"X = "<<MyTest.x<<"With address = "<<&(Xref)<<endl;;

  int* Xptr = &MyTest.GetX();
  *Xptr = 20;
  cout<<"X = "<<MyTest.x<<"With address = "<<Xptr<<endl;

  MyTest.GetMySubClass().PrintName();
  SubClass* Testing =  &(MyTest.GetMySubClass());
  cout<<"Address : "<<Testing<<endl;
  Testing->PrintName();
  */
  Library MyLibrary;
//  MyLibrary.AddBook("SH", "Conan", 2);
//  MyLibrary.AddBook("SH", "Conan", 2);

  System MySystem;
  MySystem.LoadInitialDataBase();

  MySystem.login();
  MySystem.AddBook();
  MySystem.SelectBookCommand(0, FromAvailableBooks);
  MySystem.ReadCommand();
  MySystem.NextPageCommand();


  MySystem.login();
  MySystem.AddBook();

  MySystem.PrintAllBooks();
  MySystem.SelectBookCommand(1, FromAvailableBooks);
  MySystem.ReadCommand();
  MySystem.NextPageCommand();
  MySystem.PrevPageCommand();


  MySystem.login();
  MySystem.SelectBookCommand(1, FromReadingHistory); // msh sh8ala sa7
  MySystem.ReadCommand();
  MySystem.logout();
asm("NOP");

  return 0;
}

