#include "buyer_managerment.h"
#include "text.h"

map<int, buyer*> tmp_map;

buyer_managerment::buyer_managerment() {}
buyer_managerment::buyer_managerment(vector<buyer*>) {}


void buyer_managerment::add_buyer(buyer* a) {
	cout<<"customer:"<<a->getbuyname()<<"added"<<endl;
	buyerlist.push_back(a);
}

vector<buyer*> buyer_managerment::return_buyerlist() {
	
	return buyerlist;
}
void buyer_managerment::get_buyer_map(map<int, buyer*> bymap) {
	tmp_map = bymap;
}
void buyer_managerment::get_buyer_by_id(int id) {
	for(int i = 0;i < b_list.size();i++)
	{
		if (b_list[i]->getbuyerid() == id) {
			b_list[i]->display();
			break;
		}
		else
			cout << "Error input!" << endl;
	}
}
