#ifndef _RECEIPT_H_
#define _RECEIPT_H_

#include "order_library.h"

class receipt {
private:
	order order_instance;
	string company_name;
	int receipt_id;
public:
	void set_order(order);
	void set_company_name(string);
	void set_receipt_id(int);
	string get_company_name();
	void add_receipt();
	vector<order> get_receipt_by_id(int);
};

#endif