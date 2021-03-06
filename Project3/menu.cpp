#include "menu.h"
#include "text.h"
#include <sstream>
#include<windows.h>

administrator adm;
buyer_managerment bm;
book_warehouse bw;
//order_library ol;
//receipt re;
menu men;
text tx;

string menu::generate_order_number()
{
	int s=0;
	long t1 = GetTickCount64();					//开始时间			
	for (int i = 0; i < 1000000; i++)
	{
		s += i;
	}
	long t2 = GetTickCount64();					 //结束时间 	
	cout << "程序执行时间：" << t2 - t1 << endl;  //程序运行的时间得到的时间单位为毫秒 /1000为秒

	return to_string(t2 - t1);
}

void menu::display_menu() {
	cout << "======Welcome to use online book store system============" << endl;
	cout << "            Pls make a choice             " << endl;
	cout << "             1.admin login                " << endl;
	cout << "             2.admin register             " << endl;
	cout << "             3.quit                       " << endl;
	cout << endl;
	cout << "==========================================" << endl;
}
void menu::switch_menu() {
	cout << endl;
	cout << "Make Choice:";

	int cmd;
	cin >> cmd;

	switch (cmd) {
	case 1: 
		//system("cls");
		adm.sign_in_administrator();
		break;
	case 2:
		//system("cls");
		if (tx.testadm_menu()) {
			cout << endl;
			cout << "Code correct!" << endl;
			cout << endl;
			cout << "==========================" << endl;
			//sleep(3000);
			//system("cls");
			adm.register_administrator();
		}
		else {
			cout << endl;
			cout << "Wrong Code!" << endl;
			cout << endl;
			cout << "===========================" << endl;
			//sleep(3000);
			//system("cls");
			men.display_menu();
			men.switch_menu();
		}
		break;
	case 3: 
		cout << endl;
		cout << "========Have a good day!===============" << endl;
		exit(1);
		break;
	default: 
		cout << endl;
		cout << "*****Wrong CMD!******" << endl;
		men.switch_menu();
		break;
	}
}
void menu::return_menu() {
	char ch;
	cout << endl;
	cout << "Enter 'R' back to main menu!" << endl;
	cout << "Enter 'Q' to quit!" << endl;
	cout << endl;
	cout << "Choice:";

	cin >> ch;

	switch (ch) {
	case 'R': 
		//system("cls");
		menu::display_menu();
		menu::switch_menu();
		break;
	case 'r': 
		//system("cls");
		menu::display_menu();
		menu::switch_menu();
		break;
	case 'E': 
		cout << endl;
		cout << "==============Have a good day=============" << endl;
		exit(1);
		break;
	case 'e': 
		cout << endl;
		cout << "==============Have a good day=============" << endl;
		exit(1);
		break;
	default: 
		cout << endl;
		cout << "******Wrong input!*********" << endl;
		men.return_menu();
		break;
	}
}
void menu::display_second_menu() {
	cout << "==============Weclome=====================" << endl;
	cout << endl;
	cout << "            Pls make a choice.            " << endl;
	cout << "            1.Check buyer list.           " << endl;
	cout << "            2.Find the buyer info.        " << endl;
	cout << "            3.Check all books.            " << endl;
	cout << "            4.Find the book info.         " << endl;
	cout << "            5.Check order list.           " << endl;
	cout << "            6.Find order history.         " << endl;
	cout << "            7.Add recipt.                 " << endl;
	cout << "            8.Find recipt.                " << endl;
	cout << "            9.Quit                        " << endl;
	cout << "======================================== = " << endl;
}
void menu::switch_second_menu() {
	cout << endl;
	cout << "Choice:";
	string bookID;//
	vector<buyer*> temp_tx_read_buy;
	vector<book*> temp_tx_read_book;
	vector<order*> temp_tx_read_order;
	//vector<receipt*> temp_tx_read_order;

	int cmd;
	cin >> cmd;

	switch (cmd) {
	case 1: 
		//system("cls");
		
		temp_tx_read_buy = tx.read_buyerlist();
		for (int i = 0; i < temp_tx_read_buy.size(); i++)
		{
			temp_tx_read_buy[i]->display();

		}
		int n;
		cout << endl;
		cout << "*******************************" << endl;
		cout << "Make a choice:" << endl;
		cout << "1.Add buyer." << endl;
		cout << "2.Return to main nemu." << endl;
		cout << endl;
		cout << "Choice:" << endl;
		cin >> n;
		if (n == 1)
		{
			string na,ads;
			int na_id;
			double dis;
			cout << "Buyer name:" ;
			cin >> na;
			cout << endl;
			cout << "Buyer ID:";
			cin >> na_id;
			cout << endl;
			cout << "Address:";
			cin >> ads;
			cout << endl;
			cout << "Discount:";
			cin >> dis;
			cout << endl;
			int index = tx.addbuyer_into_file(na, na_id, ads, dis);
			if (index == 1) {
				cout << "Added successfully";
				men.display_second_menu();
				men.switch_second_menu();
			}
			else {
				if (index == 3) {
					cout << "*** Buyer name already exists!***" << endl;
					cout << "***Back to main menu***" << endl;
					men.display_second_menu();
				}
				else {
					if (index == 2) {
						cout << "*** Wrong input!***" << endl;
						cout << "***Back to main menu***" << endl;
						men.display_second_menu();
					}
				}
			}

		}
		else {
			if (n == 2) {
				men.display_second_menu();
				men.switch_second_menu();
			}
			else {
				cout << endl;
				cout << "*** Wrong input!***" << endl;
				cout << "***Back to main menu***" << endl;
				men.display_second_menu();
			}
		}
		break;
	case 2: 
		//system("cls");
		int a;
		cout << "Enter the ID of buyer:";
		cin >> a;
		bm.get_buyer_by_id(a);
		men.display_second_menu();
		men.switch_second_menu();
		break;
	case 3:
		//system("cls");
		temp_tx_read_book=tx.read_booklist();
		for (int i = 0; i < temp_tx_read_book.size(); i++)
		{
			temp_tx_read_book[i]->display();

		}
		int m;
		cout << endl;
		cout << "*******************************" << endl;
		cout << "Choice" << endl;
		cout << "1.Add book" << endl;
		cout << "2.Back to main menu." << endl;
		cout << endl;
		cout << "Choice:" << endl;
		cin >> m;
		if (m == 1) {
			string b_id;
		    string b_n;
		    string au;
		    string pu;
		    double pr;
			cout << "Book id:";
			cin >> b_id;
			cout << endl;
			cout << "Book name:";
			cin >> b_n;
			cout << endl;
			cout << "Author:";
			cin >> au;
			cout << endl;
			cout << "publisher:";
			cin >> pu;
			cout << endl;
			cout << "price:";
			cin >> pr;
			cout << endl;
			int index2 = tx.addbook_into_file(b_id, b_n, au,pu, pr);
			if (index2 == 1) {
				cout << "Added successfully";
				men.display_second_menu();
				men.switch_second_menu();
			}
			else {
				if (index2 == 3) {
					cout << "*** Book name already exists!***" << endl;
					cout << "***Back to main menu***" << endl;
					men.display_second_menu();
				}
				else {
					if (index2 == 2) {
						cout << "*** Wrong input!***" << endl;
						cout << "***Back to main menu***" << endl;
						men.display_second_menu();
					}
				}
			}
		}
		else {
			if (m == 2) {
				cout << "Added successfully";
				men.display_second_menu();
				men.switch_second_menu();
			}
			else {
				cout << endl;
				cout << "*** Wrong input!***" << endl;
				cout << "***Back to main menu***" << endl;
				men.display_second_menu();
				men.switch_second_menu();
			}
		}
		break;
	case 4:
		//system("cls");
		cout << "Enter the ID of book:";
		cin >> bookID;
		bw.get_book_by_id(bookID);
		men.display_second_menu();
		men.switch_second_menu();
		break;
	case 5:
		//system("cls");
		//tx.read_orderlist();
		int p;
		cout << endl;
		cout << "*******************************" << endl;
		cout << "Choice:" << endl;
		cout << "1.Add order." << endl;
		cout << "2.Back to main menu." << endl;
		cout << endl;
		cout << "Choice:" << endl;
		cin >> p;
		if (p == 1) {
			int num_of_buyer;
			string number_of_book;
			vector<book*> book_choice;
			vector<book*> tempbooklist;
			string order_id;
			double price=0;
			//选人
			cout << "choose a buyer by number:";
			vector<buyer*> buytem;
			buytem = tx.read_buyerlist();
			for (int i = 0; i < buytem.size(); i++) 
			{
				cout << "["<<i<<"] ";
				buytem[i]->display();
			}
			cin >> num_of_buyer;
			cout << endl;

			//选书
			cout << "choose a Book by number(Enter 'q' to quit choose book.):" << endl;
			tempbooklist = tx.read_booklist();
			for (int i = 0; i < tempbooklist.size(); i++)
			{
				cout << "[" << i << "] ";
				tempbooklist[i]->display();
			}
			cin >> number_of_book;
			book_choice.push_back(tempbooklist[atoi(number_of_book.c_str())]);
			while (number_of_book != "q") {
				cout << "choose a Book by number(Enter 'q' to quit choose book.):" << endl;
				for (int i = 0; i < tempbooklist.size(); i++)
				{
					cout << "[" << i << "] ";
					tempbooklist[i]->display();
				}
				
				cin >> number_of_book;
				book_choice.push_back(tempbooklist[atoi(number_of_book.c_str())]);
			}
			cout << endl;

			//生成单号
			string temp_order = this->generate_order_number();

			//算数价格
			for (int i = 0; i < book_choice.size(); i++) {
				price = price + book_choice[i]->getprice();
			}
			int index = tx.addorder_into_file(buytem[num_of_buyer]->getbuyerid(), book_choice, temp_order, price);
			if (index == 1) {
				cout << "Added successfully";
				men.display_second_menu();
				men.switch_second_menu();
			}
			else {
				if (index == 3) {
					cout << "*** Book name already exists!***" << endl;
					cout << "***Back to main menu***" << endl;
					men.display_second_menu();
				}
				else {
					if (index == 2) {
						cout << "*** Wrong input!***" << endl;
						cout << "***Back to main menu***" << endl;
						men.display_second_menu();
					}
				}
			}

		}
		else {
			if (p == 2)
				men.display_second_menu();
			else {
				cout << endl;
				cout << "*** Wrong input!***" << endl;
				cout << "***Back to main menu***" << endl;
				men.display_second_menu();
			}
		}
		break;
	case 6:
		//system("cls");
		int c;
		cin >> c;
		//ol.search_order(c);
		break;
	case 7:
		//system("cls");
		//re.add_receipt();
		break;
	case 8:
		//system("cls");
		int q;
		cout << "Pls enter recipt info:";
		cin >> q;
		//re.get_receipt_by_id(q);
		break;
	case 9: 
		cout << endl;
		cout << "==============Have a good day==================" << endl;
		exit(1);
		break;
	default: 
		cout << endl;
		cout << "*** Wrong input! ***" << endl;
		men.switch_second_menu();
		break;
	}
}
void menu::return_second_menu() {
	char ch;
	cout << endl;
	cout << "Pls enter 'R' to go back." << endl;
	cout << "Pls enter 'Q' to quit." << endl;
	cout << endl;
	cout << "Choice:";

	cin >> ch;

	switch (ch) {
	case 'R': //system("cls");
		menu::display_second_menu();
		menu::switch_second_menu();
		break;
	case 'r': //system("cls");
		menu::display_second_menu();
		menu::switch_second_menu();
		break;
	case 'Q': cout << endl;
		cout << "=================Have a good day==================" << endl;
		exit(1);
		break;
	case 'e': cout << endl;
		cout << "=================Have a good day==================" << endl;
		exit(1);
		break;
	default: cout << endl;
		cout << "*** Wrong input! ***" << endl;
		men.return_second_menu();
		break;
	}
}

