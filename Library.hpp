/*
 * Library.hpp
 *
 *  Created on: Mar 9, 2024
 *      Author: Scorpio
 */

#ifndef LIBRARY_HPP_
#define LIBRARY_HPP_

#include <iostream>
#include <vector>
using namespace std;

class Book{
  private :
    string BookName;
    string AuthorName;
    unsigned int NumberOfPages;
    vector<string> PageContent;

  public:
    Book(string BookName, string AuthorName, int NumberOfPages);
    Book(string BookName, string AuthorName, int NumberOfPage, vector<string> PagesContent);

    string GetPageContent(unsigned int PageNumber)const;
    const string& GetBookName()const;


};


class Library
{
  private:
    /* Each pair contains info of the book and the number of its copies */
    vector<pair<Book,unsigned int>> AvailableBooks;
    unsigned int NumberOfBooks = 0;

    int FindBook(string BookName);
  public:
    void AddBook(const Book& CurrentBook);
    void RemoveBook(string BookName);
    vector<pair<Book,unsigned int>> GetAvailableBooks();
    void PrintAvailableBooks();

};


#endif /* LIBRARY_HPP_ */
