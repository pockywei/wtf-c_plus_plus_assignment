#ifndef _BOOKWAREHOUSE_H_
#define _BOOKWAREHOUSE_H_

#include "book.h"
class book_warehouse {
private:
	vector<book> booklist;
	int count;
public:
	void create_book(book);
	void add_book(int,int);
	void get_book_by_id(string);
	vector<book*> returnbooklist();
};

#endif