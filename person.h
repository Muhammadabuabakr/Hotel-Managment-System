#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
class Manager;
class Administration;
class person{
	string fst_name, lst_name, Email, father_name, usr_name, address, password, bld_group;
	long long contact_nmb, emergency_nmb, cnic;
	char gender;
public:
	struct date{
		int day;
		int month;
		int year;
	public:
		void input(){
			cout << "Enter day:";
			cin >> day;
			cout << "Enter month:";
			cin >> month;
			cout << "Enter year:";
			cin >> year;
		}
	};
	void setuser(string);
	string getuser();
	void setpass(string);
	string getpass();
	ofstream myfile, gfile;
	fstream file, Secfile, Recfile;
	person();
	void input();
	void MainMenu();
};
class Manager :public person{
	string last, first, str, firstname, lastname,line;
public:
	void Mmenu();
	void AddAdmin();
	void RemoveAdmin();

};
class Administration:public person{
	string s;
	friend Manager;
public:
	
	void Amenu();
	void AddEmployee();
	void RemoveEmployee();

};
class Reception:public person{
public:
	void pass();
	void Rmenu();
	void Addguest();
	void checkin();
};
//class Guest{
//public:

//};
class Security:public person{
public:
	ifstream reader;
	ofstream visitor;
	void Spass();
	void Searchguest();
	void Addvisitor();
	void Displayvisitor();
	void Smenu();

};