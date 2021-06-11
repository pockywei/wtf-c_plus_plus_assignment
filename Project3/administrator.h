#ifndef _ADMINISTRATOR_H_
#define _ADMINISTRATOR_H_

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <algorithm>
#include<string>
#include "text.h"

using namespace std;

class administrator {
public:
	string adminname;
	string password;
	string company;
	void set_adminname(string n);
	void set_password(string p);
	void set_company(string c);
	string get_adminname();
	string get_password();
	string get_company();
	void register_administrator();
	void sign_in_administrator();
	void read_administrator();
};
#endif