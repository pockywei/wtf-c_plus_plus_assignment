#include "buyer_managerment.h"
#include "text.h"

buyer_managerment::buyer_managerment() {}
buyer_managerment::buyer_managerment(vector<buyer*>) {}


void buyer_managerment::add_buyer(buyer* a) {
	cout<<"customer:"<<a->getbuyname()<<"added"<<endl;
	buyerlist.push_back(a);
}

vector<buyer*> buyer_managerment::return_buyerlist() {
	
	return buyerlist;
}
void buyer_managerment::get_buyer_by_id(int id) {
	if (b_list.count(id) > 0)
	{
		cout<<b_list[id]->getbuyname();
	}
}
