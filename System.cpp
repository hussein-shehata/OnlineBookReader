/*
 * System.cpp
 *
 *  Created on: Mar 11, 2024
 *      Author: Hussein
 */


/* mapping between users and library*/
#include "System.hpp"

/*** Implementation of System Functions ******/

void System:: LoadInitialDataBase()
{
//  User Hussein("Hussein","Scorpio1243","Husoali1311@outlook.com",AdminUserAccount);
//  User Youssef("Youssef","Joe1243","Joeali@gmail.com",CustomerUserAccount);

  MyUsers.AddAdminUser("Hussein","Scorpio1243","Husoali1311@outlook.com");
  MyUsers.AddUser("Youssef","Joe1243","Joeali@gmail.com");

  Book HarryPotter ("HarryPotter", "J.K Rowling", 2);

  vector<string> PageContent = {"Hi i am Sherlock Holmes","My friend is Dr Watson","Lets go","Snake Poison","Kill her"};
  Book SherlokHolmes ("The Adventure of SH","Conan Doyle",5,PageContent);

  MyLibrary.AddBook(HarryPotter);
  MyLibrary.AddBook(SherlokHolmes);
  MyLibrary.AddBook(SherlokHolmes);

  MyLibrary.PrintAvailableBooks();

//  Hussein.AddBook()

}

void System:: signup()
{
  string Name,  Password,  Email;
  cout<<"please Enter your Data"<<endl;
  cout<<"Name : "<<endl;
  cin>> Name;
  cout<<"Password : "<<endl;
  cin>> Password;
  cout<<"Email : "<<endl;
  cin>>Email;

  MyUsers.AddUser(Name, Password, Email);

}


bool System:: login()
{
  string Name, Password;
  cout<<"Please Enter your Name "<<endl;
  cin>>Name;
  cout<<"Please Enter your Password "<<endl;
  cin>>Password;

  /* Search for the User in our database */
  bool RetResult = MyUsers.LogIn(Name, Password);

  if (RetResult == false)
    {
      cout<<"Wrong Name or Password"<<endl;
    }
  else if ( RetResult == true)
    {
      cout<<"Welcome Mr/Mrs "<<Name<<endl;
    }

  return RetResult;


}


void System:: logout()
{
  string Name = (MyUsers.GetCurrentUser())->GetName();
  cout<<"Good Bye Mr "<<Name<<endl;
  MyUsers.Logout();
}


void System:: AddBook()
{
  if(MyUsers.GetCurrentUser() == nullptr)
    {
      cout<<"There is no user logged in"<<endl;
      return;
    }
  UserType Usertype = (MyUsers.GetCurrentUser())->GetUserType();
  if(Usertype != AdminUserAccount)
    {
      cout<<"you are not admin you can not add book"<<endl;
      return;
    }

  // TODO we shouldnot use Book in System Module
  // change Add Book to take the content as parameters not a book object
  vector<string> PageContent = {"Hi this is Naruto"};
  Book Naruto ("Naruto","Kikshobo",1,PageContent);
  MyLibrary.AddBook(Naruto);

}

void System::PrintAllBooks()
{
  MyLibrary.PrintAvailableBooks();
}


void System::NextPageCommand()
{
  MyLibrary.NextPage();
}


void System::PrevPageCommand()
{
  MyLibrary.PrevPage();
}


void System::StopReadingCommand()
{

}



void System::SelectBookCommand(unsigned int BookNumber, BookSource BookSource)
{
  MyLibrary.SelectBook(BookNumber, BookSource, MyUsers.GetCurrentUser());
}
void System::ReadCommand()
{
  MyLibrary.ReadBook();
}
