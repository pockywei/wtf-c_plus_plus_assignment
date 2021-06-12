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
	text tx;
	return tx.read_buyerlist();
}
void buyer_managerment::get_buyer_map(map<int, buyer*> bymap) {
	tmp_map = bymap;
}
void buyer_managerment::get_buyer_by_id(int id) {
	int flag = 0;
	vector<buyer*> temp = this->return_buyerlist();
	for(int i = 0;i < temp.size();i++)
	{
		if (temp[i]->getbuyerid() == id) {
			temp[i]->display();
			flag = 1;
			break;
		}
		
	}
	if(flag==0)
		cout << "Error input!" << endl;
}

