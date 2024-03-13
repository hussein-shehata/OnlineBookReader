/*
 * Users.cpp
 *
 *  Created on: Mar 9, 2024
 *      Author: Scorpio
 */

#include "Users.hpp"


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
      cout<<"Book Name : "<<it.GetBookName();
    }
}
//TODO
/* Empty so far till we see what should I do to link it to UserManager and Books */
void User::ReadBook(unsigned int BookIndex)
{

}

void User::AddBookToReadingHistory(const Book& NewBook)
{
  ReadingHistory.push_back(NewBook);
}
void User::RemoveBookFromReadingHistory(string BookName)
{
  for(auto it = ReadingHistory.begin(); it != ReadingHistory.end(); it++)
    {
      if ((*it).GetBookName() == BookName)
	{
	  ReadingHistory.erase(it);
	  return;
	}
    }
}


/************ User Manager Functions Implementations **********/

void UserManager::AddUser(string Name, string Password, string Email)
{
  User NewUser ( Name,  Password,  Email, CustomerUserAccount);
  RegisteredUsers.push_back(NewUser);
}

void UserManager::AddAdminUser(string Name, string Password, string Email)
{
  User NewUser ( Name,  Password,  Email, AdminUserAccount);
  RegisteredUsers.push_back(NewUser);
}
void UserManager::RemoveUser(string UserName)
{
  for(auto it = RegisteredUsers.begin(); it != RegisteredUsers.end(); it++)
    {
      if ((*it).GetName() == UserName)
      	{
	  RegisteredUsers.erase(it);
      	  return;
      	}
    }
}
 User* UserManager::GetCurrentUser()
{
  return CurrentUser;
}

bool UserManager::LogIn(string UserName, string Password)
{
  for (auto it = RegisteredUsers.begin(); it != RegisteredUsers.end(); it++)
    {
      if(((*it).GetName() == UserName) && ((*it).GetPassword() == Password))
	{
	  CurrentUser = (User*) (&(*it));
	  return true;
	}
    }
  return false;
}

void UserManager::Logout()
{
  CurrentUser = nullptr;
}

//bool UserManager::FindUser(string UserName, string UserPassword)
//{
//
//}
