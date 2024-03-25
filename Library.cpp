/*
 * Library.cpp
 *
 *  Created on: Mar 9, 2024
 *      Author: Scorpio
 */

#include "Library.hpp"
#include <vector>
//#include <utility>
//#include <tuple>

#include "UserManager.hpp"

using namespace std;




/************** Library Functions Implementation ********/
int Library::FindBook(string BookName)
{
  int Counter = 0;
  for (auto pair:AvailableBooks)
    {
      if (pair.first.GetBookName() == BookName)
	{
	  return Counter;
	}
      Counter++;
    }
  //Did not find the book
  return -1;
}

void Library::AddBook(const Book& CurrentBook)
{
  int index = Library::FindBook(CurrentBook.GetBookName());
  if( index != -1)
    {
      // There is already another copy of this book
      (AvailableBooks[index].second)++; //increment the counter of this book

    }
  else
    {
      //Create the new book
      pair<Book, unsigned int> Currentpair(CurrentBook, 1);
      AvailableBooks.push_back(Currentpair);
      NumberOfBooks++;
    }
}


void Library::RemoveBook(string BookName)
{
  int index = Library::FindBook(BookName);
  if(index != -1)
    {
      auto CurrentPair = AvailableBooks[index];
      if(CurrentPair.second == 1)
	{
	  // This is the last copy of the book
	  // we should remove the book completely from the vector of available books
	  AvailableBooks.erase( (AvailableBooks.begin() + index) );
	  NumberOfBooks--;
	}
      else
	{
	  (AvailableBooks[index].second)++; //decrement the counter of this book
	}
    }
}

vector<pair<Book,unsigned int>> Library::GetAvailableBooks()
{
  return (this->AvailableBooks);
}

void Library::PrintAvailableBooks()
{
  for (auto Idx:AvailableBooks)
    {
      cout<<"Book "<<Idx.first.GetBookName()<<" has number of copies = "<<Idx.second<<endl;
    }
}


void Library::SelectBook(unsigned int BookNumber, BookSource BookSource, User* CurrentUser) //if it was from the reading history or the new one
{
  if(BookSource == FromReadingHistory)
    {
      CurrentBook.first = &((CurrentUser->GetReadingHistory())[BookNumber].first);
      CurrentBook.second = ((CurrentUser->GetReadingHistory())[BookNumber].second);
    }

  else if(BookSource == FromAvailableBooks)
      {
        CurrentBook.first = & (AvailableBooks[BookNumber].first);
        CurrentBook.second = 1; //First Page
        CurrentUser->AddBookToReadingHistory(*(CurrentBook.first));

      }
}




void Library::ReadBook()
{
  string CurrentPage = (CurrentBook.first->GetPageContent(CurrentBook.second));
  cout<<CurrentPage<<endl;
}


void Library::NextPage()
{

  if( CurrentBook.second >= (CurrentBook.first->GetNumberOfPages() ) )
    {
      cout<<"You already reached the end of the book"<<endl;
      return ;
    }
  CurrentBook.second++;
  Library::ReadBook();
}

void Library::PrevPage()
{
 if( CurrentBook.second == 1) //Start of the book
   {
     cout<<"You already reached at the start of the book"<<endl;
     return ;
   }
  CurrentBook.second--;
  Library::ReadBook();
}
