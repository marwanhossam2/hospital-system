#include "patient.h"
patient::patient()
{
	patient_id = 0;
	disease = "";
	treatment = "";
}
void patient::setpatient(int patient_id, string disease, string treatment)
{
	this->patient_id = patient_id;
	this->disease = disease;
	this->treatment = treatment;
}
int patient::getpatient_id()
{
	return patient_id;
}
string patient::getdisease()
{
	return disease;
}
string patient::gettreatment()
{
	return treatment;
}
void patient::display()
{
	cout << "Patient ID: " << patient_id << endl;
	cout << "Name: " << getname() << endl;
	cout << "Address: " << getaddress() << endl;
	cout << "Phone: " << getphone() << endl;
	cout << "Email: " << getemail() << endl;
	cout << "Age: " << getage() << endl;
	cout << "Disease: " << disease << endl;
	cout << "Treatment: " << treatment << endl;
}
string patient::getpatname()
{
	return name;
}



