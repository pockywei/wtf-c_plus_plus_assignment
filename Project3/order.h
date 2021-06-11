#include "member.h"

class order {
private:
	int buyer_id;
	vector<book> booklist;
	int order_id;
public:
	void set_buyer_id(int);
	void set_booklist(vector<book>);
	void set_order_id();
};