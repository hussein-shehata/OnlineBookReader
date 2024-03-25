/*
 * User.cpp
 *
 *  Created on: Mar 15, 2024
 *      Author: Hussein
 */

#ifndef USER_CPP_
#define USER_CPP_


#include "User.hpp"

/************** User Functions Implementation *********/

User::User(string Name, string Password, string Email, UserType IsUserAdmin) :
Name(Name), Password(Password), Email(Email), IsUserAdmin (IsUserAdmin)
{

}

void User::ViewProfile()
{
  cout<<"User Name : "<<Name<<endl;
  cout<<"User Email : "<<Email<<endl;
}

string User::GetName()
{
  return Name;
}
string User::GetPassword()
{
  return Password;
}

UserType User::GetUserType()
{
  return IsUserAdmin;
}


void User::ViewReadingHistory()
{
  for (auto it : ReadingHistory)
    {
      cout<<"Book Name : "<<(it.first).GetBookName();
    }
}
//TODO
/* Empty so far till we see what should I do to link it to UserManager and Books */
void User::ReadBook(unsigned int BookIndex)
{

}

void User::AddBookToReadingHistory(const Book& NewBook)
{
  pair<Book, unsigned int > NewBookPair(NewBook, 1);
  ReadingHistory.push_back(NewBookPair);
}
void User::RemoveBookFromReadingHistory(string BookName)
{
  for(auto it = ReadingHistory.begin(); it != ReadingHistory.end(); it++)
    {
      if (((*it).first).GetBookName() == BookName)
	{
	  ReadingHistory.erase(it);
	  return;
	}
    }
}


 const vector<pair<Book,unsigned int>>& User::GetReadingHistory()
{
   /*Information
    * lw kont 3mltha return value kan higeb Run Time Error 3shan hwa bi3ml copy constructor
    * l el Member ely brg3o w yrg3o l el caller f lma el caller yst5dm el member fe ai haga
    * zy eny a3ml call el member l function 3ndo higeb values w reading 8lt */
//   cout<<"Address inside of the function "<<&(ReadingHistory[0].first)<<endl;
  return ReadingHistory;
}




#endif /* USER_CPP_ */
