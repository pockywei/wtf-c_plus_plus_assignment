#include "order.h"

order::order(int buyerid, vector<book> booklist, string orderid, double price)
{
	vector<book> temp;
	buyer_id = buyerid;
	booklist = temp;
	order_id = "";
	price = 0;


}

void order::set_buyer_id(int) {}
void order::set_booklist(vector<book>) {}
void order::set_order_id() {}