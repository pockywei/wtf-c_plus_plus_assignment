#ifndef _HOUOURED_GUEST_H_
#define _HOUOURED_GUEST_H_

#include "buyer.h"

class honoured_guest :public buyer {
	double discount_rate;
public:
	honoured_guest(string n, int b, double r, string a, double p) {
		name = n;
		buyerID = b;
		discount_rate = r;
		address = a;
		pay = p;
	}
	void display();
	void setpay(double p);
};

#endif
