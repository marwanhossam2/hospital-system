#pragma once
#include <iostream>
using namespace std;
class person
{
protected:
		string name;
		string address;
		string phone;
		string email;
		int age;
public:
		person();
		void setdata(string name, string address, string phone, string email, int age);
		string getname();
		string getaddress();
		string getphone();
		string getemail();
		int getage();
		

};

