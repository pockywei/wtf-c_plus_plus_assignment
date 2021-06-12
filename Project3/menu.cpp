#include "menu.h"

administrator adm;
buyer_managerment bm;
book_warehouse bw;
order_library ol;
receipt re;
menu men;
text tx;


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

	int cmd;
	cin >> cmd;

	switch (cmd) {
	case 1: 
		//system("cls");
		tx.read_buyerlist();
		int n;
		cout << endl;
		cout << "*******************************" << endl;
		cout << "Make a choice:" << endl;
		cout << "Add buyer." << endl;
		cout << "Return to main nemu." << endl;
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
			if (tx.addbuyer_into_file(na, na_id, ads, dis)==1)
				cout << "Added successfully";
			else {
				if (tx.addbuyer_into_file(na, na_id, ads, dis) == 3) {
					cout << "*** Buyer name already exists!***" << endl;
					cout << "***Back to main menu***" << endl;
					men.display_second_menu();
				}
				else {
					if (tx.addbuyer_into_file(na, na_id, ads, dis) == 2) {
						cout << "*** Wrong input!***" << endl;
						cout << "***Back to main menu***" << endl;
						men.display_second_menu();
					}
				}
			}

		}
		else {
			if (n == 2)
				men.display_second_menu();
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
		break;
	case 3:
		//system("cls");
		tx.read_booklist();
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
			int a, b;
			cin >> a >> b;
			bw.add_book(a,b);
		}
		else {
			if (m == 2)
				men.display_second_menu();
			else {
				cout << endl;
				cout << "*** Wrong input!***" << endl;
				cout << "***Back to main menu***" << endl;
				men.display_second_menu();
			}
		}
		break;
	case 4:
		//system("cls");
		int b;
		cin >> b;
		bw.get_book_by_id(b);
		break;
	case 5:
		//system("cls");
		tx.read_orderlist();
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
			ol.create_order();
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
		ol.search_order(c);
		break;
	case 7:
		//system("cls");
		re.add_receipt();
		break;
	case 8:
		//system("cls");
		int q;
		cout << "Pls enter recipt info:";
		cin >> q;
		re.get_receipt_by_id(q);
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

