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
#include "receipt.h"
#include <sstream>

extern map<int, buyer*> b_list;

using namespace std;

class text {
public:
	int testadm_menu();
	void read_buyerlist();
	void read_booklist();
	void read_orderlist();
	void read_receipt();
};
#endif
