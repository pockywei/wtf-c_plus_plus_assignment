#include "buyer.h"



buyer::buyer() {
	name = "";
	buyerID = 0;
	address = "";
	pay = 0;
}
buyer::buyer(string n, int b, string a, double p) {
	name = n;
	buyerID = b;
	address = a;
	pay = p;
}

string buyer::getbuyname() {
	return name;
}
string buyer::getaddress() {
	return address;
}
int buyer::getbuyerid() {
	return buyerID;
}
//vector<book> buyer::returnbooklist() {
//	vector<book> ret;
// 	return ret;
//}
//void buyer::setbuyerbooks(book a)
//{
//	this->fo_list.push_back(a);
//}
double buyer::getpay() {
	return pay;
}
int buyer::getid() {
	return buyerID;
}

void buyer::display(){
	cout<<"Nothing"<<endl;
}
