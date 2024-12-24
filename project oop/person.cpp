#include "person.h"
person::person()
{
	name = "";
	address = "";
	phone = "";
	email = "";
	age = 0;
}
void person::setdata(string name, string address, string phone, string email, int age)
{
	this->name = name;
	this->address = address;
	this->phone = phone;
	this->email = email;
	this->age = age;
}
string person::getname()
{
	return name;
}
string person::getaddress()
{
	return address;
}
string person::getphone()
{
	return phone;
}
string person::getemail()
{
	return email;
}
int person::getage()
{
	return age;
}
