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
	buyer_managerment(vector<buyer*>);  //��ȡ�������б�
	void add_buyer(buyer*);  //���ӹ�������Ϣ
	vector<buyer*> return_buyerlist();  //�鿴�������б�
	void get_buyer_by_id(int);  //ͨ����Ų��ҹ�������Ϣ
	void get_buyer_map(map<int, buyer*>);
};

#endif
