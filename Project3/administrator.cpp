#include "administrator.h"
#include "menu.h"

vector<administrator> admin_list;
map<string, administrator> adm_list;

void administrator::set_adminname(string n) {
    adminname = n;
}
void administrator::set_password(string p) {
    password = p;
}
void administrator::set_company(string c) {
    company = c;
}
string administrator::get_adminname() {
    return adminname;
}
string administrator::get_password() {
    return password;
}
string administrator::get_company() {
    return company;
}
void administrator::read_administrator() {

    ifstream inf("administrator.txt", ios::in);
    if (!inf) {
        cout << "fail to open file" << endl;
        exit(1);
    }
    string t_adminname;
    while (inf >> t_adminname) {
        administrator a;

        a.adminname = t_adminname;
        inf >> a.password >> a.company;
        adm_list[a.adminname] = a;
        admin_list.push_back(a);
    }
    inf.close();
}
void administrator::register_administrator() {
    administrator t;
    t.read_administrator();
    menu men;
    map<string, int> admin;
    string r_adminname;
    string r_password;
    string r_company;
    int flag = 1;
    for (int i = 0; flag; i++) {
        cout << "User register; " << endl;
        cout << endl;
        cout << "please enter your name:";

        cin >> r_adminname;
        map<string, administrator> ::iterator iter = adm_list.find(r_adminname);
        if (iter != adm_list.end()) {
            cout << endl;
            cout << "*********user already exist return after 3s*********" << endl;
            //sleep(3000);
            //system("cls");
        }
        else {
            flag = 0;
        }
    }
    cout << endl;
    cout << "***************Right password Access granted**************" << endl;
    cout << endl;
    cout << "Pls enter password:";
    cin >> r_password;
    cout << "pls enter company name:";
    cin >> r_company;

    ofstream fout;
    fout.open("administrator.txt", ios::app);
    fout << r_adminname << ' ' << r_password << ' ' << r_company << endl;
    fout.close();
    t.read_administrator();
    cout << endl;
    cout << "********register success,return to main menu after 3s ********" << endl;
    //sleep(3000);
    //system("cls");
    men.display_menu();
    men.switch_menu();
}
void administrator::sign_in_administrator() {
    menu men;
    administrator t;
    t.read_administrator();
    cout << "welcome;" << endl;
    cout << endl;
    cout << "pls enter your name;";
    int cmd;
    string s_adminname;
    string s_password;
    cin >> s_adminname;
    map<string, administrator> ::iterator iter = adm_list.find(s_adminname);
    for (map<string, administrator>::iterator it = adm_list.begin(); it != adm_list.end(); it++) {
        cout << it->first << ":" << it->second.get_adminname() << endl;
        if (s_adminname == (it->first))
        {
            cout << "yes:" << s_adminname << it->first << endl;
        }
        else
        {
            cout << "No:" << s_adminname << it->first << endl;

        }
    }
    cout << "dd" << iter->first;
    cout << iter->second.get_adminname();


    if (iter != adm_list.end()) {
        int flag1 = 0;
        for (int i = 0; flag1 != 1; i++) {
            cout << endl;
            cout << "pls enter password:";
            cin >> s_password;
            if (s_password == (*iter).second.password) {
                cout << endl;
                cout << "********* login success*********" << endl;
                flag1 = 1;
            }
            else {
                cout << endl;
                cout << "*************** wrong password****************" << endl;
            }
        }
        //sleep(3000);
        //system("cls");
        men.display_second_menu();
        men.switch_second_menu();
    }
    else {
        cout << "\n\n************** User does not exist!***************" << endl;
        cout << endl;
        int flag2 = 0;
        for (int j = 0; flag2 != 1; j++) {
            cout << "Choice; " << endl;
            cout << endl;
            cout << "1.login" << endl;
            cout << "2.register" << endl;
            cout << endl;
            cout << "======================================================================4;" << endl;
            cout << endl;
            cout << "Choice:";
            cin >> cmd;
            switch (cmd) {
            case 1:
                //system("cls");
                sign_in_administrator();
                break;
            case 2:
                cout << endl;
                register_administrator();
                break;
            }
        }
    }
}
