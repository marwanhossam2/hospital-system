#pragma once
#include "person.h"
class doctor : public person
{
private:
	string specialization;
	string qualification;
	int doctor_id;
public:
	doctor();
	string getdocname();
	void setdoctor(int doctor_id,string specialization, string qualification);
	string getspecialization();
	string getqualification();
	int getdoctor_id();
	void display();

};

