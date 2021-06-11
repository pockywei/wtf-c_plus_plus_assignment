#ifndef _ORDERLIBRARY_H_
#define _ORDERLIBRARY_H_

#include "honoured_guest.h"
#include "layfolk.h"
#include "member.h"
#include "book_warehouse.h"
#include "order.h"

class order_library {
private:
	order order_instance;
public:
	void create_order();
	void search_order(int);
};

#endif