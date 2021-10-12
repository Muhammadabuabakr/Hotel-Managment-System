#include"person.h"

person::person(){
	fst_name = " ";
	lst_name = " ";
	Email = " ";
	gender;
	father_name = " ";
	bld_group;
	usr_name = "";
	address = "";
	password = " ";
	contact_nmb = 0;
	emergency_nmb = 0;
	cnic = 0;
}
void person::MainMenu(){
	string s;
	cout << "________________________________________________________________" << endl << endl;
	cout << "      >>>>>>>>    Welcome to Jonny's Hotel    <<<<<<<<" << endl << endl;
	cout << "________________________________________________________________" << endl << endl;
	cout << ">Prove your identity:" << endl << endl;
	cout << ">1.Manager" << endl;
	cout << ">2.Administrator" << endl;
	cout << ">3.Receptionist" << endl;
	cout << ">4.Guest" << endl;
	cout << ">5.Security" << endl << endl;
	cout << ">Enter (M/A/R/G/S):";
	cin >> s;
	if (s == "M"){
		system("cls");
		Manager *m = new Manager;
		m->Mmenu();
	}
	if (s == "A"){
		system("cls");
		Administration *a = new Administration;
		a->Amenu();
	}
	if (s == "R"){
		system("cls");
		Reception *r = new Reception;
		r->pass();
	}
	//if (s == "G"){
		
	//}
	if (s == "S"){
		Security *s = new Security;
		s->Spass();
	}
}

void person::input(){
	cout << ">Enter your identification:" << endl;
	cout << ">First name:";
	cin >> fst_name;
	cout << ">Last name:";
	cin >> lst_name;
	cout << ">Email id:";
	cin.ignore();
	getline(cin, Email);
	cout << ">Gender M/F:";
	cin >> gender;
	cout << ">Father name:";
	cin.ignore();
	getline(cin, father_name);
	cout << ">Blood group A+/A-/B+/B-/AB+/AB-/O+/O-:";
	cin >> bld_group;
	cout << ">Address:";
	cin.ignore();
	getline(cin, address);
	cout << ">Contact Number:";
	cin >> contact_nmb;
	cout << ">Emergency Contact Number:";
	cin >> emergency_nmb;
	cout << ">CNIC:";
	cin >> cnic;
	myfile << fst_name << " , " << lst_name << " , " << Email << " , " << gender << " , " << father_name << " , " << bld_group << " , " << contact_nmb << " , " << emergency_nmb << " , " << cnic << " , ";
	Recfile << fst_name << " , " << lst_name << " , " << Email << " , " << gender << " , " << father_name << " , " << bld_group << " , " << contact_nmb << " , " << emergency_nmb << " , " << cnic << " , ";
	Secfile << fst_name << " , " << lst_name << " , " << Email << " , " << gender << " , " << father_name << " , " << bld_group << " , " << contact_nmb << " , " << emergency_nmb << " , " << cnic << " , ";
	gfile << fst_name << " , " << lst_name << " , " << Email << " , " << gender << " , " << father_name << " , " << bld_group << " , " << contact_nmb << " , " << emergency_nmb << " , " << cnic << " , ";




}
void person::setuser(string s){
	usr_name = s;

}
string person::getuser(){
	return usr_name;
}
void person::setpass(string x){
	password = x;
}
string person::getpass(){
	return password;
}
void Manager::Mmenu(){
	int s;
	cout << "____________________________________________" << endl << endl;
	cout << "    >>>>>>>    Welcome sir!    <<<<<<<" << endl << endl;
	cout << "____________________________________________" << endl << endl;
	cout << ">How can I help:" << endl << endl;
	cout << ">1.Add Admin." << endl;
	cout << ">2.Delete Admin." << endl;
	cout << ">3.Search Guest." << endl;
	cout << ">4.Main Menu." << endl << endl;
	cout << ">Select (1/2/3):";
	cin >> s;
	if (s == 1){
		AddAdmin();
	}
	if (s == 2){
		RemoveAdmin();
	}
	else if (s == 4){
		MainMenu();
	}
}
void Manager::AddAdmin(){
	string u, ps;
	myfile.open("manager.txt", ios::app);
	input();
	date obj;
	cout << "Enter date:" << endl;
	obj.input();
	cout << ">Enter your Username:";
	cin >> u;
	setuser(u);
	cout << ">Enter your Password:";
	cin >> ps;
	setpass(ps);
	myfile << obj.day << "-" << obj.month << "-" << obj.year <<" , "<<getuser()<<" , "<<getpass()<< endl;
	myfile.close();
	system("pause");
	Mmenu();

}
void Manager::RemoveAdmin(){
	//person obj;
	
	cout << ">Enter Data for delete Admin" << endl;
	cout << ">Enter First and last name:";
	cin >> firstname >> lastname;
	file.open("manager.txt");
	cout << ">Deleted Data:" << endl;
	while (!file.eof()){
		getline(file, line);
		istringstream ss(line);
		ss >> first;
		ss >> str;
		ss >> last;
		ofstream outfile,temp;
		outfile.open("delmandata.txt", ios::app);
		temp.open("manRemdata.txt",ios::app);

		if (!outfile.is_open())
		{
			cout << ">file not open" << endl;
		}
		else{
			
			if (first == firstname&&last == lastname)
			{
				
				cout << ">line :: " << line << endl;
				outfile << line << endl;
				outfile.close();
				 
			}
		else{
			remove("manRemdata.txt");
			temp << line << endl;
			temp.close();
		}
			}
			
		}


	system("pause");

	}
void Administration::Amenu(){
	int s;
	cout << "____________________________________________" << endl << endl;
	cout << "    >>>>>>>    Welcome sir!    <<0<<<<<" << endl << endl;
	cout << "____________________________________________" << endl << endl;
	cout << ">How can I help:" << endl << endl;
	cout << ">1.Add Employee." << endl;
	cout << ">2.Delete Employee." << endl;
	cout << ">3.Delete Guest." << endl;
	cout << ">4.Main Menu." << endl << endl;
	cout << ">Select (1/2/3):";
	cin >> s;
	if (s == 1){
		AddEmployee();
}
	if (s == 2){
		RemoveEmployee();
	}
}
void Administration::AddEmployee(){
	
	string a,pass;
	cout << ">Enter Employee Type:" << endl;
	cout << "1.Reception" << endl;
	cout << "2.Security" << endl;
	cout << ">Enter (R/S):";
	cin >> s;
	if (s == "R"){
		Recfile.open("RecEmp.txt", ios::app);
		input();
		cout << ">Enter Date:";
		date obj;
		obj.input();
		cout << ">Enter the user name(without space):";
		cin >> a;
		setuser(a);
		cout << ">Enter the Password:";
		cin >> pass;
		setpass(pass);
		Recfile << obj.day << "-" << obj.month << "-" << obj.year << " , " << getuser() << " , " << getpass() << endl;
		Recfile.close();
	}
	else if (s == "S"){
		Secfile.open("SecEmp.txt", ios::app);
		input();
		cout << ">Enter Date:";
		date obj;
		obj.input();
		cout << ">Enter the username:";
		cin >> a;
		setuser(a);
		cout << ">Enter the password:";
		cin >> pass;
		setpass(pass);
		Secfile << obj.day << "-" << obj.month << "-" << obj.year <<" , "<<getuser()<<" , "<<getpass()<< endl;
		Secfile.close();
	}
}
	
void Administration::RemoveEmployee(){
	string firstname, lastname, line, first, str, last, q, us, pw, fm, lm, m;

	cout << ">Now you are allowed to enter data." << endl;
	cout << ">Enter Employee Type:" << endl;
	cout << ">1.Reception" << endl;
	cout << ">2.Security" << endl;
	cout << ">3.press any key for menu" << endl;
	cout << ">Enter (R/S):";
	cin >> q;
	if (q == "R"){
		cout << ">Enter First and last name for delete Admin" << endl;
		cout << ">Enter First and last name:";
		cin >> firstname >> lastname;
		Recfile.open("RecEmp.txt");
		cout << ">Deleted Data:" << endl;
		while (!Recfile.eof()){
			getline(Recfile, line);
			istringstream ss(line);
			ss >> first;
			ss >> str;
			ss >> last;
			ofstream outfile, temp;
			outfile.open("delRecdata.txt", ios::app);
			temp.open("RecRemdata.txt", ios::app);

			if (!outfile.is_open())
			{
				cout << ">file not open" << endl;
			}
			else{

				if (first == firstname&&last == lastname)
				{

					cout << "line :: " << line << endl;
					outfile << line << endl;

				}
				else{
					//remove("RecRemdata.txt");
					temp << line << endl;

				}
			}

		}
		system("Pause");
	}
	else if (q == "S"){
		cout << ">Enter First and last name for delete Admin" << endl;
		cout << ">Enter First and last name:";
		cin >> firstname >> lastname;
		Secfile.open("SecEmp.txt");
		cout << ">Deleted Data:" << endl;
		while (!Secfile.eof()){
			getline(Secfile, line);
			istringstream ss(line);
			ss >> first;
			ss >> str;
			ss >> last;
			ofstream outfile, temp;
			outfile.open("delSecdata.txt", ios::app);
			temp.open("SecRemdata.txt", ios::app);

			if (!outfile.is_open())
			{
				cout << ">file not open" << endl;
			}
			else{

				if (first == firstname&&last == lastname)
				{

					cout << ">line :: " << line << endl;
					outfile << line << endl;

				}
				else{
					remove("SecRemdata.txt");
					temp << line << endl;

				}
			}
		}
	}
	else{
		system("cls");
		Amenu();
	}
}
	
void Reception::Rmenu(){
	int s;
	cout << "____________________________________________" << endl << endl;
	cout << "    >>>>>>>    Welcome sir!    <<<<<<<" << endl << endl;
	cout << "____________________________________________" << endl << endl;
	cout << ">How can I help:" << endl << endl;
	cout << ">1.Add Guest" << endl;
	cout << ">2.Check In" << endl;
	cout << ">3.Delete Guest." << endl;
	cout << ">4.Main Menu." << endl << endl;
	cout << ">Select (1/2/3):";
	cin >> s;
	if (s == 1){
		Addguest();
	}
	if (s == 2){
		checkin();
	}
}
void Reception::pass(){
	string firstname, lastname, line, first, str, last, q, us, pw, fm, lm, m;
	int v;
	v = getchar();
	cout << ">Give your Identity:" << endl;
	cout << ">Enter your Username:";
	cin >> us;
	cout << ">Enter your Password:";
	cin >> pw;
	ifstream read;
	int comma;
	string  paswd = "", usrnam = "";
	int counter = 0, flag = 0;
	read.open("manager.txt");
	while (!read.eof()){
		counter = 0;
		getline(read, str);
		int len = str.length();
		for (int i = len; i > 0; i--){
			if (str[i] == ','){
				counter++;
				flag = 1;
			}
			if (counter == 1 && flag == 1){
				flag = 0;
				for (int j = i + 1; j < len; j++){
					comma = i + 1;
					paswd += str[j];
				}
			}
			if (counter == 2 && flag == 1){
				flag = 0;

				for (int k = i + 1; k < comma; k++)
				{
					if (str[k] == ',')
					{
						break;
					}
					usrnam += str[k];

				}
			}
		}

		if (us == usrnam && pw == paswd){
				system("pause");
				Rmenu();
				
		}
		else{
			paswd = "";
			usrnam = "";
		}
		
	}
	system("pause");
	
}
//}
void Reception::Addguest(){
	date obj;
	gfile.open("Addguest.txt", ios::app);
	cout << "Enter the check-in-date:" << endl;
	obj.input();
	cout << "Enter the data of guest:" << endl;
	input();
	gfile << obj.day << "-" << obj.month << "-" << obj.year << endl;
	system("pause");
	checkin();
}
void Reception::checkin(){
	char ch;
	
	cout << "Select your Room Type:" << endl;
	cout << "1.Ruby Deluxe" << endl;
	cout << "2.Saphire Deluxe" << endl;
	cout << "3.Platinum Deluxe" << endl;
	cout << "4.Diamond Deluxe" << endl;
	cout << "Enter your room type(R/S/P/D):" << endl;
	cin >> ch;
	if (ch == 'R'){
		int R;
		string line,str,in,line1,name;
		fstream Rubyread,Rubyin,fst,file;
		Rubyread.open("Ruby.txt");
		while (!Rubyread.eof()){
			getline(Rubyread,line);
			istringstream sd(line);
			sd >> str;
		if (!Rubyread.is_open()){
				cout << "File is not open." << endl;
			}
		else{
			//Ruby >> line;
			cout << str << endl;
			Rubyread.close();
		Rubyin.open("Ruby.txt", ios::app);
			if (!Rubyin.is_open()){

				cout << "Now!You Enter room which you want:" << endl;
				cin >> R;
				Rubyin.open("Ruby.txt", ios::app);
				for (int i = 0; i <= R; i++){
					getline(Rubyin, line1);
					istringstream s(line);
					s >> in;
				}
				cout << "Enter name of guest:" << endl;
				cin >> name;
				Rubyin << in << name + ".txt" << endl;
			}
		}
		}
		
	}
	if (ch == 'S'){
		ofstream Saphire;
		Saphire.open("Saphire.txt", ios::app);
	}
	if (ch == 'P'){
		ofstream Platium;
		Platium.open("Platium.txt", ios::app);
	}
	if (ch == 'D'){
		ofstream Diamond;
		Diamond.open("Diamond.txt", ios::app);
	}
}
void Security::Spass(){
	string firstname, lastname, line, first, str, last, q, us, pw, fm, lm, m;
	int v;
	v = getchar();
	cout << ">Give your Identity:" << endl;
	cout << ">Enter your Username:";
	cin >> us;
	cout << ">Enter your Password:";
	cin >> pw;
	ifstream read;
	int comma;
	string  paswd = "", usrnam = "";
	int counter = 0, flag = 0;
	read.open("SecEmp.txt");
	while (!read.eof()){
		counter = 0;
		getline(read, str);
		int len = str.length();
		for (int i = len; i > 0; i--){
			if (str[i] == ','){
				counter++;
				flag = 1;
			}
			if (counter == 1 && flag == 1){
				flag = 0;
				for (int j = i + 1; j < len; j++){
					comma = i + 1;
					paswd += str[j];
				}
			}
			if (counter == 2 && flag == 1){
				flag = 0;

				for (int k = i + 1; k < comma; k++)
				{
					if (str[k] == ',')
					{
						break;
					}
					usrnam += str[k];

				}
			}
		}

		if (us == usrnam && pw == paswd){
			system("pause");
			Smenu();

		}
		else{
			paswd = "";
			usrnam = "";
		}

	}
	system("pause");
	Smenu();

}
void Security::Smenu(){
	int s;
	cout << "____________________________________________" << endl << endl;
	cout << "    >>>>>>>    Welcome sir!    <<<<<<<" << endl << endl;
	cout << "____________________________________________" << endl << endl;
	cout << ">How can I help:" << endl << endl;
	cout << ">1.Search and Display Guest" << endl;
	cout << ">2.Add Visitor" << endl;
	cout << ">3.Display Visitor" << endl;
	cout << ">4.Main Menu." << endl << endl;
	cout << ">Select (1/2/3):";
	cin >> s;
	if (s == 1){
		system("cls");
		Searchguest();
	}
	if (s == 2){
		system("cls");
		Addvisitor();
}
	if (s == 3){
		system("cls");
		Displayvisitor();
	}
	if (s == 4){
		system("cls");
		person *obj = new person;
		obj->MainMenu();
	}
}
void Security::Searchguest(){
	string firstname, lastname, first, str, last, line;
	ifstream search;
	cout << ">Enter First and last name for search Admin" << endl;
	cout << ">Enter First and last name:";
	cin >> firstname >> lastname;
	search.open("Addguest.txt");
	cout << ">Searched Data:" << endl;
	while (!search.eof()){
		getline(search, line);
		istringstream v(line);
		v >> first;
		v >> str;
		v >> last;
		if (first==firstname&&last == lastname)
			{

				cout << "line :: " << line << endl;
			    //search >> line ;
				//cout << "after search:" << line << endl;
				search.close();
				return;
			}
			else{
				first = " ";
				str = " ";
				last = " ";
			}
			

	}
	system("Pause");

}

//}
void Security::Addvisitor(){
	string firstname, lastname, first, str, last, line,cnic;
	ifstream search;
	cout << ">Enter First and last name for search Admin" << endl;
	cout << ">Enter First and last name:";
	cin >> firstname >> lastname;
	search.open("Addguest.txt");
	cout << ">Searched Data:" << endl;
	while (!search.eof()){
		getline(search, line);
		istringstream v(line);
		v >> first;
		v >> str;
		v >> last;
		if (first == firstname&&last == lastname)
		{

			cout << "line :: " << line << endl;
			//search >> line ;
			//cout << "after search:" << line << endl;
			search.close();
			return;
		}
		else if(first != firstname&&last != lastname){
			first = " ";
			str = " ";
			last = " ";
			
			visitor.open("visitor.txt", ios::app);
			cout << "you are not guest!";
			cout << "Enter your CNIC:";
			cin >> cnic;
			visitor << firstname <<" " << lastname <<" "<< cnic << endl;

		}
}

	system("Pause");
	Smenu();
	

}
	//}
void Security::Displayvisitor(){
	string firstname, lastname, cnic,line;
	ifstream handler;
	handler.open("visitor.txt", ios::app);
	while (!handler.eof()){
		getline(handler, line);
		cout << line<<" " <<endl;
		system("pause");
		Smenu();
	}
}

























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































