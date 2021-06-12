#include "book.h"

book::book(string b_id, string b_n, string au, string pu, double pr)
{
	book_ID = b_id;
	book_name = b_n;
	author = au;
	publishing = pu;
	price = pr;
}
book::book()
{
	book_ID = "";
	book_name = "";
	author = "";
	publishing = "";
	price = 0;
}
void book::display()
{
	cout << "book number:" << book_ID << "\t";
	cout << "book name:" << book_name << "\t";
	cout << "Author:" << author << "\t";
	cout << "publisher:" << publishing << "\t";
	cout << "price:" << price << "\n";
}
string book::getbook_ID()
{
	return book_ID;
}
string book::getbook_name()
{
	return book_name;
}
string book::getauthor()
{
	return author;
}
string book::getpublishing()
{
	return publishing;
}
double book::getprice()
{
	return price;
}

