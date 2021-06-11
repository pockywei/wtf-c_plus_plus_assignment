#ifndef _BOOK_H_
#define _BOOK_H_

#include<iostream>
#include<fstream>
#include <stdlib.h>
#include <vector>
#include <map>
//#include <windows.h>
#include <algorithm>
#include<string>

using namespace std;

class book {
protected:
	string book_ID;
	string book_name;
	string author;
	string publishing;
	double price;
public:
	book();
	book(string b_id, string b_n, string au, string pu, double pr);
	void display();
	string getbook_ID();
	string getbook_name();
	string getauthor();
	string getpublishing();
	double getprice();
};

#endif
