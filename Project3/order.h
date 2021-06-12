#ifndef _ORDER_H_
#define _ORDER_H_

#include "member.h"

class order {
private:
	int buyer_id;
	vector<book> booklist;
	string order_id;
	double price;
public:
	order(int buyer_id, vector<book> booklist, string order_id, double price);
	void set_buyer_id(int);
	void set_booklist(vector<book>);
	void set_order_id();
};

#endif