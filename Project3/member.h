#ifndef _MEMBER_H_
#define _MEMBER_H_

#include "buyer.h"

class member :public buyer {
private:
	int leaguer_grade;
public:
	member(string n, int b, int l, string a, double p) {
		name = n;
		buyerID = b;
		leaguer_grade = l;
		address = a;
		pay = p;
	}
	void display();
	void setpay(double p);
};

#endif
