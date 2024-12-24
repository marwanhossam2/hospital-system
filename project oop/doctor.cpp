#include "doctor.h"
doctor::doctor()
{
	specialization = "";
	qualification = "";
	doctor_id =0;
}
void doctor::setdoctor(int doctor_id,string specialization, string qualification)
{
	this->doctor_id = doctor_id;
	this->specialization = specialization;
	this->qualification = qualification;
	
}
string doctor::getspecialization()
{
	return specialization;
}
string doctor::getqualification()
{
	return qualification;
}
int doctor::getdoctor_id()
{
	return doctor_id;
}
void doctor::display()
{
	cout << "Doctor ID: " << doctor_id << endl;
	cout << "Name: " << getname() << endl;
	cout << "Address: " << getaddress() << endl;
	cout << "Phone: " << getphone() << endl;
	cout << "Email: " << getemail() << endl;
	cout << "Age: " << getage() << endl;
	cout << "Specialization: " << specialization << endl;
	cout << "Qualification: " << qualification << endl;
}
string doctor::getdocname()
{
	return name;
}
