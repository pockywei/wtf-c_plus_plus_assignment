#include "honoured_guest.h"

void honoured_guest::display() {
	cout << "Buyer name:" << name << "\t";
	cout << "Buyer ID:" << buyerID << "\t";
	cout << "Buyer is honoured guest! Discount is:" << discount_rate * 100 << "% \n";
	cout << "Address:" << address << "\n\n";
}

void honoured_guest::setpay(double p)
{
	pay = pay + (1 - discount_rate) * p;
}
