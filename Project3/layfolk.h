#ifndef _LAYFORK_H_
#define _LAYFORK_H_

#include "buyer.h"

class layfolk :public buyer {
public:
	layfolk(string n, int b, string a, double p){
		name = n;
		buyerID = b;
		address = a;
		pay = p;
	};
	void display();
	void setpay(double p);
};

#endif
