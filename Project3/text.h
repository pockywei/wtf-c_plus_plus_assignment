#ifndef _TEXT_H_
#define _TEXT_H_

#include<iostream>
#include<fstream>
#include <stdlib.h>
#include <vector>
#include <map>
//#include <windows.h>
//#include <unistd.h>
#include <algorithm>
#include<string>

#include "administrator.h"
#include "book_warehouse.h"
#include "buyer_managerment.h"
#include "order_library.h"
//#include "receipt.h"
#include <sstream>


using namespace std;

class text {
public:
	int testadm_menu();
	vector<buyer*> read_buyerlist();
	int addbuyer_into_file(string name, int id, string ad, double discount);

	vector<book*> read_booklist();
	int addbook_into_file(string b_id, string b_n, string au, string pu, double pr);

	//vector<order*> read_orderlist();
	int addorder_into_file(int buyerid, vector<book*> booklist, string orderid, double price);


	/*vector<receipt*> read_receipt();
	int addreceipt_into_file(string, int, string, double);*/

};
#endif
