#include <iostream>
#include <vector>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <mmsystem.h>
#include <string>
#include<conio.h>
#include <fstream>
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
int dispatch_count = 1;
int refreshrate = 200;
int orderc = 0;
int custc = 0;
int x = 0;
void superStore(string un);
void mainMenu();
char title[31][112] =
{
	"                                                                                                               ",
	"                                                                                                               ",
	"                                                                                                               ",
	"                             .........                                                                         ",
	"                            ......,###                                                                         ",
	"                                   ###                                                                         ",
	"                                   ###                                                                         ",
	"                                   ###(////////////////////////////////                                        ",
	"                                   (#################################(                                         ",
	"                                   ,################################(                                          ",
	"                                    ################################                                           ",
	"                        ,##########################################                                            ",
	"                                              ####################                                             ",
	"                   ############  ################################(                                             ",
	"                                               #################                                               ",
	"                      (##########, #############################                                               ",
	"                                            (#################                                                 ",
	"                   ######/ ,#################################                                                  ",
	"                                     #######################                                                   ",
	"                                   ####                ,###/                                                   ",
	"                                  #####                ####*                                                   ",
	"								 .                   .                                                          ",
	"                                                                                                               ",
	"                                                                                                               ",
	"                                                                                                               ",
	"                                                                                                               "
};
char menu[5][112] =
{
	"                                       SIGNUP / LOGIN                                                          ",
	"                                                                                                               ",
	"                                    >     SIGN UP     <                                                        ",
	"                                                                                                               ",
	"                                          LOG  IN                                                              "
};
int storecursor = 2;
char storemenu[19][112] =
{
"                                                  MAIN MENU                                                    ",
"                                                                                                               ",
"                                          >       ADD ITEMS       <                                            ",
"                                                                                                               ",
"                                                REMOVE EXPIRED                                                 ",
"                                                                                                               ",
"                                                 VIEW  ITEMS                                                   ",
"                                                                                                               ",
"                                                 VIEW  SALES                                                   ",
"                                                                                                               ",
"                                                 VIEW ORDERS                                                   ",
"                                                                                                               ",
"                                                ADD CUSTOMERS                                                  ",
"                                                                                                               ",
"                                               ADD DISPATCHERS                                                 ",
"                                                                                                               ",
"                                               ATTEND CUSTOMERS                                                ",
"                                                                                                               ",
"                                                   SIGN OUT                                                    "
};
int storecursor2 = 2;
char storemenu2[9][112] =
{
"                                                  ITEM MENU                                                    ",
"                                                                                                               ",
"                                          >        GROCERY        <                                            ",
"                                                                                                               ",
"                                                  CROCKERY                                                     ",
"                                                                                                               ",
"                                                  MEDICINE                                                     ",
"                                                                                                               ",
"                                                    BACK                                                       "
};

struct date { //declares date
	int day = 0;
	int month = 0;
	int year = 0;
	string mon = "";
	string da = "";

	date() { //default constructor

		day = 1;
		month = 1;
		year = 2000;
		mon = "";
		da = "";
	}

	void setdate(string inp) { //datesetter
		string arr[3] = { "","","" };
		int j = 0;
		for (int i = 0; i < inp.length(); i++) {
			if (inp.substr(i, 1) != "/") {
				arr[j] += inp.substr(i, 1);
			}
			else {
				j++;
			}
		}
		day = stoi(arr[0]);
		month = stoi(arr[1]);
		year = stoi(arr[2]);
		da = arr[0] + "/" + arr[1] + "/" + arr[2];
	}

	string getdate() { //dategetter
		return da;
	}

	string set_mon(int m) { //month setter

		if (m == 1) {
			mon = "January";
		}

		if (m == 2) {
			mon = "February";
		}

		if (m == 3) {
			mon = "March";
		}

		if (m == 4) {
			mon = "April";
		}

		if (m == 5) {
			mon = "May";
		}

		if (m == 6) {
			mon = "June";
		}

		if (m == 7) {
			mon = "July";
		}

		if (m == 8) {
			mon = "August";
		}

		if (m == 9) {
			mon = "September";
		}

		if (m == 10) {
			mon = "October";
		}

		if (m == 11) {
			mon = "November";
		}

		if (m == 12) {
			mon = "December";
		}

		return mon;
	};


	date(int d) { //overloaded constructor
		day = d;
	}

	date(int d, int m) { //overloaded constructor
		day = d;
		month = m;
		mon = set_mon(m);
	}

	date(int d, int m, int y) { //overloaded constructor
		day = d;
		month = m;
		mon = set_mon(m);
		year = y;
	}

	date(string inp) {
		string arr[3] = { "","","" };
		int j = 0;
		for (int i = 0; i < inp.length(); i++) {
			if (inp.substr(i, 1) != "/") {
				arr[j] += inp.substr(i, 1);
			}
			else {
				j++;
			}
		}
		day = stoi(arr[0]);
		month = stoi(arr[1]);
		year = stoi(arr[2]);
		da = arr[0] + "/" + arr[1] + "/" + arr[2];
	}

	friend istream& operator >> (istream& in, date& d) {
		cout << "Enter day:";
		in >> d.day;
		while (d.day < 1 || d.day>31) {
			cout << "Invalid input try again: ";
			in >> d.day;
		}
		cout << "Enter month:";
		in >> d.month;
		while (d.month < 1 || d.month>12) {
			cout << "Invalid input try again: ";
			in >> d.month;
		}
		cout << "Enter year:";
		in >> d.year;
		d.mon = d.set_mon(d.month);
		d.da = to_string(d.day) + "/" + to_string(d.month) + "/" + to_string(d.year);
		return in;
	}

	bool isGreater(date d) {
		if (d.year < this->year) {
			return true;
		}
		else if (d.year > this->year) {
			return false;
		}
		else if (d.year == this->year) {
			if (d.month < this->month) {
				return true;
			}
			else if (d.month > this->month) {
				return false;
			}
			else if (d.month == this->month) {
				if (d.day < this->day) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}

	void print() //dateprinter
	{
		cout << day << "-" << mon << "-" << year << endl;
	}

	void IncrementDay(bool cal) { //Incrementsbyaday
		if (cal == true) { //Check for calendar year
			day++;
			if (month == 2) //Check for Feb
			{
				if (year % 4 == 0) //Check for Leap Year
				{
					if (day > 29)
					{
						IncrementMonth();
						day = 1;
					}
				}
				else
				{
					if (day > 28)
					{
						IncrementMonth();
						day = 1;
					}
				}
			}

			if (month % 2 == 1) //Check for odd months
			{
				if (day > 31)
				{
					IncrementMonth();
					day = 1;
				}
			}
			else //even months
			{
				if (day > 30)
				{
					IncrementMonth();
					day = 1;
				}
			}
		}
		else { //if not calendar year
			day++;
			if (day >= 30) {
				IncrementMonth();
				day = 1;
			}
		}
	}

	void IncrementMonth() { //IncrementsbyaMonth
		month++;

		if (month > 12)
		{
			IncrementYear();
			month = 1;
		}
		mon = set_mon(month);

	}

	void IncrementYear() { //IncrementsbyaYear
		year++;
	}

	bool isEqual(date d) { //checks if dates are equal
		if (day == d.day && month == d.month && year == d.year) {
			//cout << "The dates are equal.";
			return true;
		}
		else {
			//cout << "The dates are not equal.";
			return false;
		}
	}

	void Incdmy(int d, bool cal) { //increments by specific days
		for (int i = 0; i < d; i++) {
			IncrementDay(cal);
		}
	}
};
class Items {
private:
	string description;
	int price;
	string type;
public:
	Items() {
		description = "";
		price = 0;
		type = "";
	}
	Items(string d, int p, string t) {
		description = d;
		price = p;
		type = t;
	}
	void set_description(string d) {
		description = d;
	}
	void set_price(int p) {
		price = p;
	}
	void set_type(string t) {
		type = t;
	}
	string get_description() {
		return description;
	}
	int get_price() {
		return price;
	}
	string get_type() {
		return type;
	}
};
class Grocery : public Items {
private:
	date expiryDate;
	int size;
	Grocery* head;
	Grocery* next;
public:
	Grocery() {
		size = 0;
		head = NULL;
		next = NULL;
	}
	Grocery(int s) {
		size = s;
	}
	void set_size(int s) {
		size = s;
	}
	void set_expirydate(date e) {
		expiryDate = e;
	}
	date get_expirydate() {
		return expiryDate;
	}
	int get_size() {
		return size;
	}
	friend ostream& operator << (ostream& output, Grocery& obj) { //overloaded output << operator makes output in form of {x,x,x,x,x}
		output << "DESCRIPTION \t PRICE \t TYPE \t Expiry Date \t Size";
		cout << obj.get_description() << "\t" << obj.get_price() << "\t" << obj.get_type() << "\t" << obj.get_expirydate().getdate() << "\t" << obj.get_size() << endl;
		return output;
	}
	friend istream& operator >> (istream& input, Grocery& obj) { //overloaded input << operator
		string a;
		int b;

		cout << "Enter Description : " << endl;
		input >> a;
		obj.set_description(a);
		cout << "Enter Price : " << endl;
		input >> b;
		obj.set_price(b);
		cout << "Enter Type : " << endl;
		input >> a;
		obj.set_type(a);
		cout << "Enter Expiry Date : " << endl;
		input >> a;
		obj.set_expirydate(a);
		cout << "Enter Size : " << endl;
		input >> b;
		obj.set_size(b);
		cout << endl;
		return input;
	}

	void print() {
		Grocery* temp = head;
		cout << "DESCRIPTION \t PRICE \t TYPE \t Expiry Date \t Size" << endl;
		while (temp != NULL) {
			cout << temp->get_description() << "\t" << temp->get_price() << "\t" << temp->get_type() << "\t" << temp->get_expirydate().da << "\t" << temp->get_size() << endl;
			temp = temp->next;
		}
		cout << endl;
	}
	void printtofile() {
		fstream myfile;
		myfile.open("OnlineStoreData.txt", ios::app);
		Grocery* temp = head;
		int c = 0;
		while (temp != NULL) {
			c++;
			myfile << c << " " << "Item" << " " << temp->get_description() << " " << temp->get_type() << " " << temp->get_expirydate().da << " " << temp->get_size() << endl;
			temp = temp->next;
		}
	}
	~Grocery() {
		if (head == NULL)
			return;
		Grocery* curr = head;
		Grocery* prev = NULL;
		while (curr != NULL) {
			prev = curr;
			curr = curr->next;
			delete prev;
		}
		head = NULL;
	}

	void insertHead(string d, int p, string t, string e, int s) {
		Grocery* temp = new Grocery;
		temp->set_description(d);
		temp->set_price(p);
		temp->set_type(t);
		temp->set_expirydate(e);
		temp->set_size(s);
		temp->next = head;
		head = temp;
	}

	void deleteHead() {
		if (head == NULL)
			return;
		Grocery* temp = head;
		head = head->next;
		delete temp;
	}

	void insertTail(string d, int p, string t, string e, int s) {
		Grocery* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new Grocery;
		temp->next->set_description(d);
		temp->next->set_price(p);
		temp->next->set_type(t);
		temp->next->set_expirydate(e);
		temp->next->set_size(s);
		temp->next->next = NULL;
	}

	void deleteTail() {
		if (head == NULL)
			return;
		Grocery* curr = head;
		Grocery* prev = NULL;
		while (curr->next != NULL) {
			prev = curr;
			curr = curr->next;
		}
		prev->next = NULL;
		delete curr;
	}

	void deleteList() {
		if (head == NULL)
			return;
		Grocery* curr = head;
		Grocery* prev = NULL;
		while (curr != NULL) {
			prev = curr;
			curr = curr->next;
			delete prev;
		}
		head = NULL;
	}

	Grocery* read_items() {
		fstream myfile;
		myfile.open("OnlineStoreData.txt", ios::in);
		string num, type1, name, type2, expdate, size;
		Grocery* items = new Grocery;
		int curr_ind = 0;
		while (!myfile.eof()) {
			num = "", type1 = "", name = "", type2 = "", expdate = "", size = "";
			myfile >> num >> type1 >> name >> type2 >> expdate >> size;
			if (type1 == "Item" && type2 == "Grocery") {
				if (num == "1") {
					items->insertHead(name, 0, type2, expdate, stoi(size));
				}
				else {
					items->insertTail(name, 0, type2, expdate, stoi(size));
				}
			}
			else {
				continue;
			}
		}
		myfile.close();
		return items;
	}

	void insert_items(string d, string t, string d1, int s) {
		fstream myfile;
		myfile.open("OnlineStoreData.txt", ios::in);
		int g_count = 0;
		string num, type1, name, type2, prop1, prop2;
		while (!myfile.eof()) {
			num = "", type1 = "", name = "", type2 = "", prop1 = "", prop2 = "";
			myfile >> num >> type1 >> name >> type2 >> prop1 >> prop2;
			if (type1 == "Item" && type2 == "Grocery") {
				g_count++;
			}
		}
		myfile.close();
		myfile.open("OnlineStoreData.txt", ios::app);
		myfile << g_count+1 << " Item " << d << "   " << t << "   " << d1 << "   " << s << "\n";
		myfile.close();
	}
};
class Crockery : public Items {
private:
	string color;
	string material;
	Crockery* head;
	Crockery* next;
public:
	Crockery() {
		color = "";
		material = "";
		head = NULL;
		next = NULL;
	}
	Crockery(string c, string m) {
		color = c;
		material = m;
		head = NULL;
		next = NULL;
	}
	void set_material(string m) {
		material = m;
	}
	void set_color(string c) {
		color = c;
	}
	string get_color() {
		return color;
	}
	string get_material() {
		return material;
	}
	friend ostream& operator << (ostream& output, Crockery& obj) { //overloaded output << operator makes output in form of {x,x,x,x,x}
		output << "DESCRIPTION \t PRICE \t TYPE \t Color \t Material";
		cout << obj.get_description() << "\t" << obj.get_price() << "\t" << obj.get_type() << "\t" << obj.get_color() << "\t" << obj.get_material() << endl;
		return output;
	}
	friend istream& operator >> (istream& input, Crockery& obj) { //overloaded input << operator
		string a;
		int b;

		cout << "Enter Description : " << endl;
		input >> a;
		obj.set_description(a);
		cout << "Enter Price : " << endl;
		input >> b;
		obj.set_price(b);
		cout << "Enter Type : " << endl;
		input >> a;
		obj.set_type(a);
		cout << "Enter Color : " << endl;
		input >> a;
		obj.set_color(a);
		cout << "Enter Material : " << endl;
		input >> a;
		obj.set_material(a);
		cout << endl;
		return input;
	}

	void print() {
		Crockery* temp = head;
		cout << "DESCRIPTION \t PRICE \t TYPE \t Color \t Material" << endl;
		while (temp != NULL) {
			cout << temp->get_description() << "\t" << temp->get_price() << "\t" << temp->get_type() << "\t" << temp->get_color() << "\t" << temp->get_material() << endl;
			temp = temp->next;
		}
		cout << endl;
	}
	~Crockery() {
		if (head == NULL)
			return;
		Crockery* curr = head;
		Crockery* prev = NULL;
		while (curr != NULL) {
			prev = curr;
			curr = curr->next;
			delete prev;
		}
		head = NULL;
	}

	void insertHead(string d, int p, string t, string c, string m) {
		Crockery* temp = new Crockery;
		temp->set_description(d);
		temp->set_price(p);
		temp->set_type(t);
		temp->set_color(c);
		temp->set_material(m);
		temp->next = head;
		head = temp;
	}

	void deleteHead() {
		if (head == NULL)
			return;
		Crockery* temp = head;
		head = head->next;
		delete temp;
	}

	void insertTail(string d, int p, string t, string c, string m) {
		Crockery* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
		temp->next = new Crockery;
		temp->next->set_description(d);
		temp->next->set_price(p);
		temp->next->set_type(t);
		temp->next->set_color(c);
		temp->next->set_material(m);
		temp->next->next = NULL;
	}

	void deleteTail() {
		if (head == NULL)
			return;
		Crockery* curr = head;
		Crockery* prev = NULL;
		while (curr->next != NULL) {
			prev = curr;
			curr = curr->next;
		}
		prev->next = NULL;
		delete curr;
	}

	void deleteList() {
		if (head == NULL)
			return;
		Crockery* curr = head;
		Crockery* prev = NULL;
		while (curr != NULL) {
			prev = curr;
			curr = curr->next;
			delete prev;
		}
		head = NULL;
	}

	void printtofile() {
		fstream myfile;
		myfile.open("OnlineStoreData.txt", ios::app);
		Crockery* temp = head;
		int c = 0;
		while (temp != NULL) {
			c++;
			myfile << c << " " << "Item" << " " << temp->get_description() << " " << temp->get_type() << " " << temp->get_color() << " " << temp->get_material() << endl;
			temp = temp->next;
		}
	}

	Crockery* read_items() {
		fstream myfile;
		myfile.open("OnlineStoreData.txt", ios::in);
		string num, type1, name, type2, color, material;
		Crockery* items = new Crockery;
		int curr_ind = 0;
		while (!myfile.eof()) {
			num = "", type1 = "", name = "", type2 = "", color = "", material = "";
			myfile >> num >> type1 >> name >> type2 >> color >> material;
			if (type1 == "Item" && type2 == "Crockery") {
				if (num == "1") {
					items->insertHead(name, 0, type2, color, material);
				}
				else {
					items->insertTail(name, 0, type2, color, material);
				}
			}
			else {
				continue;
			}
		}
		myfile.close();
		return items;
	}

	void insert_items(string d, string t, string c, string m) {
		fstream myfile;
		myfile.open("OnlineStoreData.txt", ios::in);
		int g_count = 0;
		string num, type1, name, type2, prop1, prop2;
		while (!myfile.eof()) {
			num = "", type1 = "", name = "", type2 = "", prop1 = "", prop2 = "";
			myfile >> num >> type1 >> name >> type2 >> prop1 >> prop2;
			if (type1 == "Item" && type2 == "Crockery") {
				g_count++;
			}
		}
		myfile.close();
		myfile.open("OnlineStoreData.txt", ios::app);
		myfile << g_count + 1 << " Item " << d << "   " << t << "   " << c << "   " << m << "\n";
		myfile.close();
	}
};
class Medicine : public Items {
private:
	date expiryDate;
	double potency;
	Medicine* head;
	Medicine* next;
public:
	Medicine() {
		potency = 0.0;
		head = NULL;
		next = NULL;
	}
	Medicine(double p) {
		potency = p;
	}
	void set_potency(double p) {
		potency = p;
	}
	double get_potency() {
		return potency;
	}
	void set_expirydate(date e) {
		expiryDate = e;
	}
	date get_expirydate() {
		return expiryDate;
	}
	friend ostream& operator << (ostream& output, Medicine& obj) { //overloaded output << operator makes output in form of {x,x,x,x,x}
		output << "DESCRIPTION \t PRICE \t TYPE \t Expiry Date \t Potency";
		cout << obj.get_description() << "\t" << obj.get_price() << "\t" << obj.get_type() << "\t" << obj.get_expirydate().getdate() << "\t" << obj.get_potency() << endl;
		return output;
	}
	friend istream& operator >> (istream& input, Medicine& obj) { //overloaded input << operator
		string a;
		int b;
		double c;
		cout << "Enter Description : " << endl;
		input >> a;
		obj.set_description(a);
		cout << "Enter Price : " << endl;
		input >> b;
		obj.set_price(b);
		cout << "Enter Type : " << endl;
		input >> a;
		obj.set_type(a);
		cout << "Enter Expiry Date : " << endl;
		input >> a;
		obj.set_expirydate(a);
		cout << "Enter Potency : " << endl;
		input >> c;
		obj.set_potency(c);
		cout << endl;
		return input;
	}
	Medicine* get_item(string d) {
		Medicine* temp = head;
		while (temp->get_description() != d) {
			temp = temp->next;
			if (temp == NULL) {
				break;
			}
		}
		return temp;
	}
	void print() {
		Medicine* temp = head;
		cout << "DESCRIPTION \t PRICE \t TYPE \t Expiry Date \t Size" << endl;
		while (temp != NULL) {
			cout << temp->get_description() << "\t" << temp->get_price() << "\t" << temp->get_type() << "\t" << temp->get_expirydate().da << "\t" << temp->get_potency() << endl;
			temp = temp->next;
		}
		cout << endl;
	}

	void printtofile() {
		fstream myfile;
		myfile.open("OnlineStoreData.txt", ios::app);
		Medicine* temp = head;
		int c = 0;
		while (temp != NULL) {
			c++;
			myfile << c << " " << "Item" << " " << temp->get_description() << " " << temp->get_type() << " " << temp->get_expirydate().da << " " << temp->get_potency() << endl;
			temp = temp->next;
		}
	}

	~Medicine() {
		if (head == NULL)
			return;
		Medicine* curr = head;
		Medicine* prev = NULL;
		while (curr != NULL) {
			prev = curr;
			curr = curr->next;
			delete prev;
		}
		head = NULL;
	}

	Medicine* gethead() {
		return head;
	}

	void insertHead(string d, int p, string t, string e, double po) {
		Medicine* temp = new Medicine;
		temp->set_description(d);
		temp->set_price(p);
		temp->set_type(t);
		temp->set_expirydate(e);
		temp->set_potency(po);
		temp->next = head;
		head = temp;
	}
	void deleteHead() {
		if (head == NULL)
			return;
		Medicine* temp = head;
		head = head->next;
		delete temp;
	}

	void insertTail(string d, int p, string t, string e, double po) {
		Medicine* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new Medicine;
		temp->next->set_description(d);
		temp->next->set_price(p);
		temp->next->set_type(t);
		temp->next->set_expirydate(e);
		temp->next->set_potency(po);
		temp->next->next = NULL;
	}
	void deleteTail() {
		if (head == NULL)
			return;
		Medicine* curr = head;
		Medicine* prev = NULL;
		while (curr->next != NULL) {
			prev = curr;
			curr = curr->next;
		}
		prev->next = NULL;
		delete curr;
	}

	void deleteList() {
		if (head == NULL)
			return;
		Medicine* curr = head;
		Medicine* prev = NULL;
		while (curr != NULL) {
			prev = curr;
			curr = curr->next;
			delete prev;
		}
		head = NULL;
	}

	void insert_items(string d, string t, string d1, double po) {
		fstream myfile;
		myfile.open("OnlineStoreData.txt", ios::in);
		int g_count = 0;
		string num, type1, name, type2, prop1, prop2;
		while (!myfile.eof()) {
			num = "", type1 = "", name = "", type2 = "", prop1 = "", prop2 = "";
			myfile >> num >> type1 >> name >> type2 >> prop1 >> prop2;
			if (type1 == "Item" && type2 == "Medicine") {
				g_count++;
			}
		}
		myfile.close();
		myfile.open("OnlineStoreData.txt", ios::app);
		myfile << g_count+1 << " Item " << d << "   " << t << "   " << d1 << "   " << po << "\n";
		myfile.close();
	}

	Medicine* read_items() {
		fstream myfile;
		myfile.open("OnlineStoreData.txt", ios::in);
		string num, type1, name, type2, expdate, potency;
		Medicine* items = new Medicine;
		while (!myfile.eof()) {
			num = "", type1 = "", name = "", type2 = "", expdate = "", potency = "";
			myfile >> num >> type1 >> name >> type2 >> expdate >> potency;
			if (type1 == "Item" && type2 == "Medicine") {
				if (num == "1") {
					items->insertHead(name, 0, type2, expdate, stod(potency));
				}
				else {
					items->insertTail(name, 0, type2, expdate, stod(potency));
				}
			}
			else {
				continue;
			}
		}
		myfile.close();
		return items;
	}
};
class Orders {
private:
	vector <int> customerID;
	vector <int> dispatcherID;
	vector <int*> items;
	vector <date> orderDate;
	int front;
	int rear;
	int count;

public:
	Orders() {
		front = 0;
		rear = -1;
		count = 0;
	}
	~Orders() {
		customerID.clear();
		dispatcherID.clear();
		items.clear();
		orderDate.clear();
	}
	void dequeue() {
		if (customerID.empty() && dispatcherID.empty() && items.empty() && orderDate.empty()) {
			cout << "UnderFlow\nProgram Terminated\n";
			exit(EXIT_FAILURE);
		}
		cout << "Removing " << customerID[front] << '\n';
		customerID.erase(customerID.begin());
		dispatcherID.erase(dispatcherID.begin());
		items.erase(items.begin());
		orderDate.erase(orderDate.begin());
	}
	void enqueue(int c, int d, int i[], date o) {
		customerID.push_back(c);
		dispatcherID.push_back(d);
		items.push_back(i);
		orderDate.push_back(o);
	}
	int peek() {
		if (customerID.empty() && dispatcherID.empty() && items.empty() && orderDate.empty()) {
			cout << "UnderFlow\nProgram Terminated\n";
			exit(EXIT_FAILURE);
		}
		return customerID.front();
	}
	void print() {
		if (customerID.size() == 0) {
			cout << "Empty " << endl;
		}
		cout << "Customer ID \t Dispatcher ID \t Order Date \t Item ID" << endl;
		for (int i = 0; i < customerID.size(); i++) {
			cout << customerID[i] << " " << dispatcherID[i] << " " << orderDate[i].da << " " << items[i];
		}
		cout << endl;
	}

	void insert_items(int cuid, int did, string i, string d) {
		fstream myfile;
		myfile.open("OnlineStoreData.txt", ios::in);
		int g_count = 0;
		string num, type1, name, type2, prop1, prop2;
		while (!myfile.eof()) {
			num = "", type1 = "", name = "", type2 = "", prop1 = "", prop2 = "";
			myfile >> num >> type1 >> name >> type2 >> prop1 >> prop2;
			if (type1 == "Order") {
				g_count++;
			}
		}
		myfile.close();
		myfile.open("OnlineStoreData.txt", ios::app);
		myfile << g_count + 1 << " Order " << cuid << "   " << did << "   " << i << "   " << d << "\n";
		myfile.close();
	}
};
class Person {
private:
	string name;
public:
	Person() {
		name = "";
	}
	Person(string n) {
		name = n;
	}
	void set_name(string n) {
		name = n;
	}
	string get_name() {
		return name;
	}
};
class Customers : public Person {
private:
	vector <string> name;
	vector <string> pw;
	vector <date> doA;
	int front;
	int rear;
	int count;
public:
	Customers() {
		front = 0;
		rear = -1;
		count = 0;
	}
	~Customers() {
		name.clear();
		pw.clear();
		doA.clear();
	}
	void dequeue() {
		if (name.empty() && pw.empty() && doA.empty()) {
			cout << "UnderFlow\nProgram Terminated\n";
			exit(EXIT_FAILURE);
		}
		cout << "Removing " << name[front] << '\n';
		name.erase(name.begin());
		pw.erase(pw.begin());
		doA.erase(doA.begin());
	}
	void enqueue(string n,string p,date a) {
		name.push_back(n);
		pw.push_back(p);
		doA.push_back(a);
	}
	Customers peek() {
		if (name.empty() && pw.empty() && doA.empty()) {
			cout << "UnderFlow\nProgram Terminated\n";
			exit(EXIT_FAILURE);
		}
		Customers c;
		c.enqueue(name.front(),pw.front(),doA.front());
		return c;
	}
	void print() {
		if (name.size() == 0) {
			cout << "Empty " << endl;
		}
		cout << "NAME \t PASSWORD \t Date of Arrival" << endl;
		for (int i = 0; i < name.size(); i++) {
			cout << name[i] << " " << pw[i] << " " << doA[i].da << endl;
		}
		cout << endl;
	}

	void printtofile() {
		fstream myfile;
		myfile.open("OnlineStoreData.txt", ios::app);
		for (int i = 0; i < name.size(); i++) {
			myfile << i << " " << "Customer" << " " << name[i] << " " << pw[i] << " " << doA[i].da << " " << "-" << endl;
		}
		cout << endl;
	}

	string get_name(){
		return name.front();
	}

	string get_pw() {
		return pw.front();
	}

	date get_date() {
		return doA.front();
	}

	Customers read_items() {
		fstream myfile;
		myfile.open("OnlineStoreData.txt", ios::in);
		string num, type1, name, pw, doA, potency;
		Customers items;
		while (!myfile.eof()) {
			num = "", type1 = "", name = "", pw = "", doA = "", potency = "";
			myfile >> num >> type1 >> name >> pw >> doA >> potency;
			if (type1 == "Customer") {
				date d;
				d.setdate(doA);
				items.enqueue(name, pw, d);
			}
			else {
				continue;
			}
		}
		myfile.close();
		return items;
	}


};
class Admin : public Person {
private:
	string password;
public:
	Admin() {
		password = "";
	}
	Admin(string p) {
		password = p;
	}
	void set_password(string p) {
		password = p;
	}
	string get_password() {
		return password;
	}
};
class Dispatchers : public Person {
private:
	string vehicleNumber;
public:
	Dispatchers() {
		vehicleNumber = "";
	}
	Dispatchers(string v) {
		vehicleNumber = v;
	}
	void set_vehicleNumber(string v) {
		vehicleNumber = v;
	}
	string get_vehiclenumber() {
		return vehicleNumber;
	}
};
class OnlineDepartmentalStore {
public:	
	Orders o;
	Items* i;
	Grocery* g;
	Crockery* c;
	Medicine* m;
	Person* p;
	Admin* a;
	Customers cu;
	Dispatchers* d;
};
Grocery g2;
Crockery c2;
Medicine m2;
OnlineDepartmentalStore ods;
void scrollupstore(int y)
{
	storemenu[y][42] = ' ';
	storemenu[y - 2][42] = '>';
	storemenu[y][66] = ' ';
	storemenu[y - 2][66] = '<';
	storecursor -= 2;
	Sleep(100);
}
void scrolldownstore(int y)
{
	storemenu[y][42] = ' ';
	storemenu[y + 2][42] = '>';
	storemenu[y][66] = ' ';
	storemenu[y + 2][66] = '<';
	storecursor += 2;
	Sleep(100);
}
void scrollupitem(int y)
{
	storemenu[y][42] = ' ';
	storemenu[y - 2][42] = '>';
	storemenu[y][66] = ' ';
	storemenu[y - 2][66] = '<';
	storecursor2 -= 2;
	Sleep(100);
}
void scrolldownitem(int y)
{
	storemenu2[y][42] = ' ';
	storemenu2[y + 2][42] = '>';
	storemenu2[y][66] = ' ';
	storemenu2[y + 2][66] = '<';
	storecursor2 += 2;
	Sleep(100);
}
bool password_check(string p) {
	bool ans = true;
	if (p.length() < 8) {
		return false;
	}
	for (int i = 0; i < p.length(); i++) {
		/*if (p[i] == 0 || p[i] == 1 || p[i] == 2 || p[i] == 3 || p[i] == 4 || p[i] == 5 || p[i] == 6 || p[i] == 7 || p[i] == 8 || p[i] == 9) {
			ans = true;
		}*/
		int temp = p[i];
		if (temp >= 48 && temp <= 57) {	//check digit
			ans = true;
			break;
		}
		else {
			ans = false;
		}

		if (temp < 33 || temp>126) { //check alphanumeric, range might be wrong bcz all characters on keyboard are alphanumeric and that is my range
			ans = false;	//maybe the range should be just capital letters and some char like $ & * etc
		}
	}

	return ans;
}
bool is_emy(string f) {
	ifstream in(f);
	if (in.is_open())
	{
		in.seekg(0, ios::end);
		size_t size = in.tellg();
		if (size == 0)
		{
			return true;
		}
		else {
			return false;
		}
	}
}
string arrtostr(int i[],string j[], int n) {
	string s="";
	for (int a = 0; a < n; a++) {
		s = s + to_string(i[n]) + j[n] + "_";
	}
	return s;
}
void view_items() {
	ods.g->print();
	ods.c->print();
	ods.m->print();
}
void removeItems(int* i) {
	ods.g = ods.g->read_items();
	ods.c = ods.c->read_items();
	ods.m = ods.m->read_items();
	ods.cu = ods.cu.read_items();
}
void update_items() {
	fstream temp;
	temp.open("temporary.txt", ios::app);
	fstream myfile;
	myfile.open("OnlineStoreData.txt", ios::in);
	string num, type1, name, type2, prop1, prop2;
	while (!myfile.eof()) {
		num = "", type1 = "", name = "", type2 = "", prop1 = "", prop2 = "";
		myfile >> num >> type1 >> name >> type2 >> prop1 >> prop2;
		if (type1 == "Admin" || type1 == "Dispatcher") {
			temp << num << "   " << type1 << "   " << name << "   " << type2 << "   " << prop1 << "   " << prop2 << "\n";
		}
		else {
			continue;
		}
	}
	myfile.close();
	temp.close();
	remove("OnlineStoreData.txt");
	cout << "File deleted" << endl;
	rename("temporary.txt", "OnlineStoreData.txt");
	cout << "DONE!!!";
	ods.g->printtofile();
	ods.c->printtofile();
	ods.m->printtofile();
	ods.cu.printtofile();
	return;
}
void takeOrder(string namec) {
	string d;
	date doO;
	string cuid;
	int cid = 0;
	cout << "Enter Order Date : ";
	cin >> d;
	doO.setdate(d);
	cout << "PLACE ORDER FROM THE ITEMS BELOW : " << endl;
	cout << endl;
	view_items();
	cout << endl;
	int n;
	cout << "How many Items would you like to add : " << endl;
	cin >> n;
	int* i = new int[n];
	string* j = new string[n];
	for (int a = 0; a < n; a++) {
		cout << "Enter Item Number and Type : ";
		cin >> i[a] >> j[a];
	}
	string itemlist = arrtostr(i, j, n);
	fstream myfile;
	myfile.open("OnlineStoreData.txt", ios::in);
	int g_count = 0;
	string num, type1, name, type2, prop1, prop2;
	while (!myfile.eof()) {
		num = "", type1 = "", name = "", type2 = "", prop1 = "", prop2 = "";
		myfile >> num >> type1 >> name >> type2 >> prop1 >> prop2;
		if (type1 == "Dispatcher") {
			g_count++;
		}
	}
	while (!myfile.eof()) {
		num = "", type1 = "", name = "", type2 = "", prop1 = "", prop2 = "";
		myfile >> num >> type1 >> name >> type2 >> prop1 >> prop2;
		if (type1 == "Customer") {
			if (name == namec) {
				cuid = num;
				cid = stoi(cuid);
			}
		}
	}
	srand(NULL);
	int disp = rand()%g_count;
	ods.o.insert_items(cid, disp, itemlist, doO.da);
	ods.o.enqueue(cid, disp, i, doO);
	superStore("Admin");
}
void registerCustomer(string un, string pw, date doA) {
	fstream myfile;
	if (is_emy("OnlineStoreData.txt")) {
		myfile.open("OnlineStoreData.txt", ios::out);
		myfile << 1 << " Customer " << un << "   " << pw << "   " << doA.da << " " << "-  \n";
		myfile.close();
	}
	else {
		myfile.open("OnlineStoreData.txt", ios::in);
		int g_count = 0;
		string num, type1, name, type2, prop1, prop2;
		while (!myfile.eof()) {
			num = "", type1 = "", name = "", type2 = "", prop1 = "", prop2 = "";
			myfile >> num >> type1 >> name >> type2 >> prop1 >> prop2;
			if (type1 == "Customer") {
				g_count++;
			}
		}
		myfile.close();
		myfile.open("OnlineStoreData.txt", ios::app);
		myfile << g_count + 1 << " Customer " << un << "   " << pw << "   " << doA.da << " " << "-  \n";
		myfile.close();
		ods.cu.enqueue(un, pw, doA);
	}
}
void add_customers() {
	cout << "Enter Customer Name : ";
	string n;
	cin >> n;
	cout << endl;
	cout << "Enter Customer Password : ";
	string p;
	cin >> p;
	cout << endl;
	cout << "Enter Date of Arrival : ";
	string d;
	cin >> d;
	date doA(d);
	cout << endl;
	registerCustomer(n, p, doA);
}
void attend_customers() {
	Customers c = ods.cu.peek();
	string pw;
	cout << c.get_name() << endl;
	do
	{
		cout << endl;
		do
		{
			cout << "Enter Password : ";
			cin >> pw;
		} while (!password_check(pw));
		if (pw == c.get_pw()) {
			cout << "LOGIN SUCCESSFUL" << endl;
			Sleep(100);
			takeOrder(c.get_name());
		}
	} while (1);
	ods.cu.dequeue();
	//updatefile();
}
void view_orders() {
	ods.o.print();
}
void add_dispatcher() {
	system("cls");
	cout << "ADD DISPATCHER INFORMATION : " << endl;
	cout << endl;
	cout << "Enter Name : ";
	string n;
	cin >> n;
	cout << "Enter Vehicle Number : ";
	string vn;
	cin >> vn;

	fstream myfile;
	myfile.open("OnlineStoreData.txt", ios::in);
	int g_count = 0;
	string num, type1, name, type2, prop1, prop2;
	while (!myfile.eof()) {
		num = "", type1 = "", name = "", type2 = "", prop1 = "", prop2 = "";
		myfile >> num >> type1 >> name >> type2 >> prop1 >> prop2;
		if (type1 == "Dispatcher") {
			g_count++;
		}
	}
	myfile.close();
	myfile.open("OnlineStoreData.txt", ios::app);
	myfile << g_count+1 << "   Dispatcher   " << n << "   " << vn << "    -    -" << "\n";
	myfile.close();
	superStore("Admin");
}
void remove_expired() {
	fstream tempfile;
	tempfile.open("temp.txt", ios::app);
	string exp_item;

	cout << "Enter current date: " << endl;
	date curr_date;
	string s;
	cin >> s;
	curr_date.setdate(s);

	fstream myfile;
	myfile.open("OnlineStoreData.txt", ios::in);

	string num, type1, name, type2, prop1, prop2;
	while (!myfile.eof()) {
		num = "", type1 = "", name = "", type2 = "", prop1 = "", prop2 = "";
		myfile >> num >> type1 >> name >> type2 >> prop1 >> prop2;
		if (type1 == "Item" && (type2=="Grocery" || type2 == "Medicine")) {
			date file_date(prop1);
			if (curr_date.isGreater(file_date) || curr_date.isEqual(file_date)) {
				exp_item = name;
				cout << type1 << "   " << name << "   " << "expired" << endl;
				//myfile.open("OnlineStoreData.txt", ios::trunc);
			}
			else {
				tempfile << num << "   " << type1 << "   " << name << "   " << type2 << "   " << prop1 << "   " << prop2 << "\n";
			}
		}
		else {
			tempfile << num << "   " << type1 << "   " << name << "   " << type2 << "   " << prop1 << "   " << prop2 << "\n";
		}
	}
	myfile.close();
	tempfile.close();
	remove("OnlineStoreData.txt");
	rename("temp.txt", "OnlineStoreData.txt");
	superStore("Admin");
}
void addItems(char x) {
	switch (x)
	{
	case 'g':
		cin >> g2;
		ods.g->insertTail(g2.get_description(), g2.get_price(), g2.get_type(), g2.get_expirydate().da, g2.get_size());
		ods.g->insert_items(g2.get_description(), g2.get_type(), g2.get_expirydate().da, g2.get_size());
		superStore("Admin");
		break;
	case 'c':
		cin >> c2;
		ods.c->insertTail(c2.get_description(), c2.get_price(), c2.get_type(), c2.get_color(), c2.get_material());
		ods.c->insert_items(c2.get_description(), c2.get_type(), c2.get_color(), c2.get_material());
		superStore("Admin");
		break;
	case 'm':
		cin >> m2;
		ods.m->insertTail(m2.get_description(), m2.get_price(), m2.get_type(), m2.get_expirydate().da, m2.get_potency());
		ods.m->insert_items(m2.get_description(), m2.get_type(), m2.get_expirydate().da, m2.get_potency());
		superStore("Admin");
		break;
	}
		
}
int itemMenu(string un) {

	system("cls");
	system("color FB");

	cout << "Hello, " << un << endl;
	cout << endl;
	cout << endl;


	for (int y = 0; y < 19; y++)
		cout << storemenu2[y] << endl;

	while (1)
	{

		if (_kbhit) {
			char i = _getch();

			switch (i) {
			case KEY_DOWN:
				if (storemenu2[9][42] != '>')
					scrolldownitem(storecursor2);
				itemMenu(un);
				break;
			case KEY_UP:
				if (storemenu2[2][42] != '>')
					scrollupitem(storecursor2);
				itemMenu(un);
				break;
			case ' ':
				switch (storecursor2) {
				case 2:
					addItems('g');
					break;
				case 4:
					addItems('c');
					break;
				case 6:
					addItems('m');
					break;
				case 8:
					//view_sales();
					break;
				}
				
			}

		}
	}
};
void superStore(string un) {

	system("cls");
	system("color FB");

	cout << "Hello, " << un << endl;
	cout << endl;
	cout << endl;


	for (int y = 0; y < 19; y++)
		cout << storemenu[y] << endl;

	while (1)
	{

		if (_kbhit) {
			char i = _getch();

			switch (i) {
			case KEY_DOWN:
				if (storemenu[18][42] != '>')
					scrolldownstore(storecursor);
				superStore(un);
				break;
			case KEY_UP:
				if (storemenu[2][42] != '>')
					scrollupstore(storecursor);
				superStore(un);
				break;
			case ' ':
				switch (storecursor)
				{
				case 2:
					itemMenu(un);
					break;
				case 4:
					remove_expired();
					break;
				case 6:
					view_items();
					break;
				case 8:
					//view_sales();
					break;
				case 10:
					view_orders();
					break;
				case 12:
					add_customers();
					break;
				case 14:
					add_dispatcher();
					break;
				case 16:
					attend_customers();
					break;
				case 18:
					update_items();
					break;
				}
				break;
			}
		}
	}
}
void registerAdmin(string un, string pw) {
		fstream myfile;
		if (is_emy("OnlineStoreData.txt")) {
			myfile.open("OnlineStoreData.txt", ios::out);
			myfile << 1 << " Admin " << un << "   " << pw << "   " << "-" << " " << "-  \n";
			myfile.close();
		}
		else {
			myfile.open("OnlineStoreData.txt", ios::in);
			int g_count = 0;
			string num, type1, name, type2, prop1, prop2;
			while (!myfile.eof()) {
				num = "", type1 = "", name = "", type2 = "", prop1 = "", prop2 = "";
				myfile >> num >> type1 >> name >> type2 >> prop1 >> prop2;
				if (type1 == "Admin") {
					g_count++;
				}
			}
			myfile.close();
			myfile.open("OnlineStoreData.txt", ios::app);
			myfile << g_count+1 << " Admin " << un << "   " << pw << "   " << "-" << " " << "-  \n";
			myfile.close();
		}
}
bool loginUser(string un, string pw) {
		fstream myfile;
		myfile.open("OnlineStoreData.txt", ios::in);
		int size = 0;
		string num, type1, name, type2, prop1, prop2;
		while (!myfile.eof()) {
			num = "", type1 = "", name = "", type2 = "", prop1 = "", prop2 = "";
			myfile >> num >> type1 >> name >> type2 >> prop1 >> prop2;
			if (type1 == "Admin") {
				if (name == un && type2 == pw) {
					return true;
				}
			}
			else {
				continue;
			}
		}
		return false;
	
}
void signup() {
	system("cls");
	system("color FB");
	string un;
	string pw;

	cout << "WELCOME TO SUPERMART200!" << endl;
	cout << endl;

	cout << "Enter Username : ";
	cin >> un;
	do
	{
		cout << "Enter Password : ";
		cin >> pw;
	} while (!password_check(pw));

	registerAdmin(un, pw);

	cout << endl;
	cout << endl;
	cout << "You have successfully registered." << endl;
	Sleep(300);

	return;
}
void login() {
	system("cls");
	system("color FB");
	string un;
	string pw;


	cout << "WELCOME TO SUPERMART200!" << endl;
	cout << endl;

	cout << "Enter Username : ";
	cin >> un;
	do
	{
		cout << "Enter Password : ";
		cin >> pw;
	} while (!password_check(pw));
	if (un == " ") {
		signup();
	}
	
	bool isloggedin = loginUser(un, pw);
	
	if (isloggedin) {
		superStore(un);
	}
	else {
		mainMenu();
	}
}
void mainMenu()
{

	system("cls");
	system("color FB");
	for (int y = 0; y < 31; y++)
		cout << title[y] << endl;
	cout << endl;
	cout << endl;
	for (int y = 0; y < 5; y++)
		cout << menu[y] << endl;

	while (1) {

		if (_kbhit) {
			char i = _getch();

			switch (i) {
			case KEY_DOWN:
				menu[2][36] = ' ';
				menu[2][54] = ' ';
				menu[4][36] = '>';
				menu[4][54] = '<';
				mainMenu();
				break;
			case KEY_UP:
				menu[4][36] = ' ';
				menu[4][54] = ' ';
				menu[2][36] = '>';
				menu[2][54] = '<';
				mainMenu();
				break;
			case ' ':
				if (menu[2][36] == '>')
					signup();
				if (menu[4][36] == '>')
					login();
				break;
			}
		}
	}

}
int main() {
	ods.g = new Grocery;
	ods.c = new Crockery;
	ods.m = new Medicine;
	if (!is_emy("OnlineStoreData.txt")) {
		ods.g = ods.g->read_items();
		ods.c = ods.c->read_items();
		ods.m = ods.m->read_items();
		ods.cu = ods.cu.read_items();
	}
	mainMenu();
}