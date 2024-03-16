/*
 * Book.cpp
 *
 *  Created on: Mar 15, 2024
 *      Author: Hussein
 */

#include "Book.hpp"
/******************** Book Class Functions*************************/
Book::Book(string BookName, string AuthorName, int NumberOfPages):
BookName(BookName), AuthorName(AuthorName), NumberOfPages(NumberOfPages)
{
/*** Take the content of the book ****/
string CurrentPageContent;
for (int idx = 1; idx <= NumberOfPages; idx++)
	{
	  printf("Please Enter the content for page %d / %u :\n",idx, NumberOfPages);
	  getline(cin,CurrentPageContent);
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


