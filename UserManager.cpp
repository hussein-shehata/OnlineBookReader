/*
 * Users.cpp
 *
 *  Created on: Mar 9, 2024
 *      Author: Scorpio
 */

#include "UserManager.hpp"



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
