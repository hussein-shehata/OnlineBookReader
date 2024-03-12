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
  AdminUser Hussein("Hussein","Scorpio1243","Husoali1311@outlook.com");
  CustomerUser Youssef("Youssef","Joe1243","Joeali@gmail.com");

  CustomerUsers.push_back(Youssef);
  AdminUsers.push_back(Hussein);

  Book HarryPotter ("HarryPotter", "J.K Rowling", 2);

  vector<string> PageContent = {"Hi i am Sherlock Holmes","My friend is Dr Watson","Lets go","Snake Poison","Kill her"};
  Book SherlokHolmes ("The Adventure of SH","Conan Doyle",5,PageContent);

  MyLibrary.AddBook(HarryPotter);
  MyLibrary.AddBook(SherlokHolmes);
  MyLibrary.AddBook(SherlokHolmes);

  MyLibrary.PrintAvailableBooks();

  Hussein.AddBook()

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

  CustomerUser NewUser (Name, Password, Email);
  CustomerUsers.push_back(NewUser);

}


bool System:: login()
{
  string Name, Password;
  cout<<"Please Enter your Name "<<endl;
  cin>>Name;
  cout<<"Please Enter your Password "<<endl;
  cin>>Password;

  /* Search for the User in our database */
  for (auto it : CustomerUsers)
    {
      if((it.GetName() == Name) && (it.GetPassword() == Password))
	{
	  cout<<"Welcome Mr/Mrs "<<Name<<endl;
	  CurrentUser = (User*)&it;
	  return true;
	}
    }

  for (auto it : AdminUsers)
      {
        if((it.GetName() == Name) && (it.GetPassword() == Password))
  	{
  	  cout<<"Welcome Mr/Mrs "<<Name<< " Your are admin "<<endl;
  	  CurrentUser = (User*)&it;
  	  return true;
  	}
      }

  cout<<"Wrong Name or Password"<<endl;

  return false;


}


void System:: logout()
{
  string Name = CurrentUser->GetName();
  cout<<"Good Bye Mr "<<Name<<endl;
  CurrentUser = nullptr;
}


