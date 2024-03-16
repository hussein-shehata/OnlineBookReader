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

#include "User.hpp"
#include "Book.hpp"

typedef enum
{
  FromReadingHistory,
  FromAvailableBooks
}BookSource;




class Library
{
  private:
    /* Each pair contains info of the book and the number of its copies */
    vector<pair<Book,unsigned int>> AvailableBooks;
    unsigned int NumberOfBooks = 0;

    pair<const Book*, unsigned int> CurrentBook = {nullptr,0};

    int FindBook(string BookName);
  public:
    void AddBook(const Book& CurrentBook);
    void RemoveBook(string BookName);
    vector<pair<Book,unsigned int>> GetAvailableBooks();
    void PrintAvailableBooks();

    void SelectBook(unsigned int BookNumber, BookSource BookSource, User* CurrentUser);
    void ReadBook();

    void NextPage();
    void PrevPage();


};


#endif /* LIBRARY_HPP_ */
