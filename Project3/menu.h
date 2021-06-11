#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include "administrator.h"
#include "buyer_managerment.h"
#include "receipt.h"

using namespace std;

class menu {
public:
	void display_menu();  
	void switch_menu();    
	void return_menu();    
	void display_second_menu();  
	void switch_second_menu();   
	void return_second_menu();  
	int testadm_menu(); 
};
#endif
