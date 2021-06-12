#ifndef _BUYERMANAGERMENT_H_
#define _BUYERMANAGERMENT_H_

#include "honoured_guest.h"
#include "layfolk.h"
#include "member.h"

class buyer_managerment {
private:
	vector<buyer*> buyerlist;
public:
	buyer_managerment();
	buyer_managerment(vector<buyer*>);  //读取购买人列表
	void add_buyer(buyer*);  //增加购买人信息
	vector<buyer*> return_buyerlist();  //查看购买人列表
	void get_buyer_by_id(int);  //通过编号查找购买人信息
	void get_buyer_map(map<int, buyer*>);
};

#endif
