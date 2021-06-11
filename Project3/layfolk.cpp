#include "layfolk.h"

void layfolk::display()
{
	cout << "Buyer name:" << name << "\t";
	cout << "Buyer ID:" << buyerID << "\t";
	cout << "Buyer is Normal customer." << "\n";
	cout << "Address:" << address << "\n\n";
}
void layfolk::setpay(double p) {
	pay = pay + p;
}