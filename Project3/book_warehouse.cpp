#include "book_warehouse.h"
#include "text.h"

void book_warehouse::create_book(book) {}
void book_warehouse::add_book(int,int) {

}

vector<book*> book_warehouse::returnbooklist() {
	text tx;
	return tx.read_booklist();
}
void book_warehouse::get_book_by_id(string id) {

	int flag = 0;
	vector<book*> temp = this->returnbooklist();
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i]->getbook_ID() == id) {
			temp[i]->display();
			flag = 1;
			break;
		}

	}
	if (flag == 0)
	cout << "Error input!" << endl;
	
}