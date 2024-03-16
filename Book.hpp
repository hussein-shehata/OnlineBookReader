/*
 * Book.hpp
 *
 *  Created on: Mar 15, 2024
 *      Author: Hussein
 */

#ifndef BOOK_HPP_
#define BOOK_HPP_


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




#endif /* BOOK_HPP_ */
