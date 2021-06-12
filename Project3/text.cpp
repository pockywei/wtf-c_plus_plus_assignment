#include "text.h"

vector<buyer*> buy_list;
map<int, buyer*> b_list;

vector<book*> book_list;

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
}//hjhkjhkjhkj
int text::testadm_menu() {
	string code;
	string tmp_code;
	cout << "pls";
	cin >> code;
	ifstream cd("code.txt", ios::in);
	if (!cd) {      
		cout << "Can not open file" << endl;
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
vector<buyer*> text::read_buyerlist() {
	/*buyer_managerment *bylist=new buyer_managerment;*/
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
				buyer* a = new honoured_guest(buyer_info[0], atoi(buyer_info[1].c_str()), atof(buyer_info[2].c_str()), buyer_info[3], atof(buyer_info[4].c_str()));
				//cout<<"honoured_guest:"<<buyer_info[0]<<atoi(buyer_info[1].c_str())<<atof(buyer_info[2].c_str())<< buyer_info[3]<< atof(buyer_info[2].c_str())<<endl;
				//bylist->add_buyer(a);
				b_list[a->getbuyerid()] = a;
			    buy_list.push_back(a);    
			}
			else if(atoi(buyer_info[2].c_str()) > 1 && buyer_info.size()==5){
				buyer* b = new member(buyer_info[0], atoi(buyer_info[1].c_str()), atof(buyer_info[2].c_str()), buyer_info[3], atof(buyer_info[4].c_str()));
				//cout<<"member:"<<buyer_info[0]<<atoi(buyer_info[1].c_str())<<atof(buyer_info[2].c_str())<< buyer_info[3]<< atof(buyer_info[2].c_str())<<endl;
				//bylist->add_buyer(b);
				cout<<"member:"<<b->getbuyerid()<<endl;
				b_list[b->getbuyerid()] = b;
			    buy_list.push_back(b);
			}
			else{
				buyer* c = new layfolk(buyer_info[0],atof(buyer_info[1].c_str()),buyer_info[2],atof(buyer_info[3].c_str()));
				//cout<<"layfolk:"<<buyer_info[0]<<atof(buyer_info[1].c_str())<<buyer_info[2]<<atof(buyer_info[3].c_str())<<endl;
				//bylist->add_buyer(c);
				cout<<c->getbuyerid()<<endl;
				b_list[c->getbuyerid()] = c;
				buy_list.push_back(c);
			}
		}
		
	}
	inf.close();
	
	//vector<buyer*> buyerlist;


	return buy_list;
}
int text::addbuyer_into_file(string name, int id, string ad, double discount) {
	vector<buyer*> temp_buyer_list;
	temp_buyer_list = this->read_buyerlist();
	ofstream BLout("buyerlist.txt", ios::app);
	if (!BLout) {
		cout << "can not open file" << endl;
		return 0;
	}
	else {
		int flag = 0;
		for (int i = 0; i < temp_buyer_list.size(); i++)
		{
			if (id == temp_buyer_list[i]->getbuyerid()) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			BLout.close();
			return 3;
		}
		else {
			if (discount == 0) {
				BLout << name << ' ' << id << ' ' << ad << ' ' << '0' << endl;
				BLout.close();
				return 1;
			}
			else {
				if (discount < 1) {
					BLout << name << ' ' << id << ' ' << discount << ' ' << ad << ' ' << '0' << endl;
					BLout.close();
					return 1;
				}
				else {
					if (discount <= 5)
					{
						BLout << name << ' ' << id << ' ' << discount << ' ' << ad << ' ' << '0' << endl;
						BLout.close();
						return 1;
					}
					else
						BLout.close();
					return 2;
				}
			}
		}
	}
}

//void text::send_buyer_list() {
//	bylist->get_buyer_map(b_list);
//}
vector<book*> text::read_booklist() {
	/*buyer_managerment *bylist=new buyer_managerment;*/
	vector<string> book_info;//临时接一下个人信息，数组存放
	string str;
	string substr;
	ifstream inf("booklist.txt", ios::in);

	if (!inf) {
		cout << "can not find file" << endl;
		exit(1);
	}
	else {
		while (getline(inf, str)) {
			book_info.clear();//下一条之前要清空。
			istringstream ss(str);
			while (getline(ss, substr, ' ')) {
				//cout<<substr;
				book_info.push_back(substr);
			}
			if (book_info.size()>1) {
				book* a = new book(book_info[0], book_info[1], book_info[2], book_info[3], atof(book_info[4].c_str()));
				//cout<< book_info[0]<< book_info[1]<< book_info[2]<<book_info[3]<<atof(book_info[4].c_str()) <<endl;
				//bylist->add_buyer(a);
				book_list.push_back(a);
			}
		}

	}
	inf.close();

	return book_list;
}
int text::addbook_into_file(string b_id, string b_n, string au, string pu, double pr)
{
	vector<book*> temp_book_list;
	temp_book_list = this->read_booklist();

	ofstream BLout("booklist.txt", ios::app);
	if (!BLout) {
		cout << "can not open file" << endl;
		return 0;
	}
	else {
		int flag = 0;
		for (int i = 0; i < temp_book_list.size(); i++)
		{
			if (b_id == temp_book_list[i]->getbook_ID()) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			BLout.close();
			return 3;
		}
		else {
				BLout << b_id << ' ' << b_n << ' ' << au << ' ' << pu << ' '<<pr << endl;
				BLout.close();
				return 1;
		
		}
	}
	return 0;
}
//vector<order*> text::read_orderlist() {
//
//}

//int text::addorder_into_file(string, int, string, double)
//{
//	return 0;
//}
////vector<receipt*>  text::read_receipt() {}
//
//int text::addreceipt_into_file(string, int, string, double)
//{
//	return 0;
//}
