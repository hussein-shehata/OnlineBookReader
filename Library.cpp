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

using namespace std;

/******************** Book Class Functions*************************/
Book::Book(string BookName, string AuthorName, int NumberOfPages):
BookName(BookName), AuthorName(AuthorName), NumberOfPages(NumberOfPages)
{
/*** Take the content of the book ****/
string CurrentPageContent;
for (int idx = 1; idx <= NumberOfPages; idx++)
	{
	  printf("Please Enter the content for page %d / %u :\n",idx, NumberOfPages);
	  cin >> CurrentPageContent;
	  PageContent.push_back(CurrentPageContent);

	}
}


Book::Book(string BookName, string AuthorName, int NumberOfPage, vector<string> PagesContent):
  BookName(BookName), AuthorName(AuthorName), NumberOfPages(NumberOfPage), PageContent(PagesContent)
{

}

string Book::GetPageContent(unsigned int PageNumber)const
{
  /* 1 Biased */
  string RetString = PageContent[PageNumber - 1];
  return RetString;
}

const string& Book::GetBookName()const
{
  return this->BookName;
}


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

