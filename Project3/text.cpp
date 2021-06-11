#include "text.h"

vector<buyer*> buy_list;
map<int, buyer*> b_list;

int get_code_list()
{
	ifstream in("code.txt");
	string line;
	int n = 0;
	while (getline(in, line))
	{
		n++;
	}
	in.close();
	return n;
}
int text::testadm_menu() {
	string code;
	string tmp_code;
	cout << "pls";
	cin >> code;
	ifstream cd("/Users/WEI/Desktop/网上结算/code.txt", ios::in);
	if (!cd) {      
		cout << "can not open file" << endl;
		exit(1);
	}
	int n = get_code_list();
	for (int i = 0; i < n; i++) {  
		cd >> tmp_code;
	}
	cd.close();
	if (code == tmp_code)
		return 1;
	else
		return 0;
};
void text::read_buyerlist() {
	buyer_managerment bylist;
	vector<string> buyer_info;//临时接一下个人信息，数组存放
	string str;
	string substr;
	ifstream inf("buyerlist.txt", ios::in);

	if (!inf) {     
		cout << "can not find file"<<endl;
		exit(1);
	}
	else{
		while(getline(inf, str)){
			buyer_info.clear();//下一条之前要清空。
			istringstream ss(str);
			while ( getline( ss, substr, ' ' ) ) {
				//cout<<substr;
				buyer_info.push_back(substr);
			}
			if(atoi(buyer_info[2].c_str()) <1 && buyer_info.size()==5){
				buyer* a = new honoured_guest(buyer_info[0], atoi(buyer_info[1].c_str()), atof(buyer_info[2].c_str()), buyer_info[3], atof(buyer_info[2].c_str()));
				cout<<"honoured_guest:"<<buyer_info[0]<<atoi(buyer_info[1].c_str())<<atof(buyer_info[2].c_str())<< buyer_info[3]<< atof(buyer_info[2].c_str())<<endl;
				bylist.add_buyer(a);
				b_list[a->getbuyerid()] = a;
					//buy_list.push_back(a);    
			}
			else if(atoi(buyer_info[2].c_str()) > 1 && buyer_info.size()==5){
				buyer* b = new member(buyer_info[0], atoi(buyer_info[1].c_str()), atof(buyer_info[2].c_str()), buyer_info[3], atof(buyer_info[2].c_str()));
				cout<<"member:"<<buyer_info[0]<<atoi(buyer_info[1].c_str())<<atof(buyer_info[2].c_str())<< buyer_info[3]<< atof(buyer_info[2].c_str())<<endl;
				bylist.add_buyer(b);
				cout<<"member:"<<b->getbuyerid()<<endl;
				b_list[b->getbuyerid()] = b;
					//buy_list.push_back(b);
			}
			else{
				buyer* c = new layfolk(buyer_info[0],atof(buyer_info[1].c_str()),buyer_info[2],atof(buyer_info[3].c_str()));
				cout<<"layfolk:"<<buyer_info[0]<<atof(buyer_info[1].c_str())<<buyer_info[2]<<atof(buyer_info[3].c_str())<<endl;
				bylist.add_buyer(c);
				cout<<c->getbuyerid()<<endl;
				b_list[c->getbuyerid()] = c;
					//buy_list.push_back(c);
			}
		}
		
	}
	inf.close();
	
	//vector<buyer*> buyerlist;
	for (int i=0;i<bylist.return_buyerlist().size(); i++)
	{
		bylist.return_buyerlist()[i]->display();
		
	}
}
void text::read_booklist() {}
void text::read_orderlist() {}
void text::read_receipt() {}
