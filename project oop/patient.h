#pragma once
#include "person.h"
class patient : public person
{
	private:
	int patient_id;
	string disease;
	string treatment;
	public:
		patient();
		void setpatient(int patient_id,string disease, string treatment);
		int getpatient_id();
		string getdisease();
		string gettreatment();
		void display();
		string getpatname();

};


