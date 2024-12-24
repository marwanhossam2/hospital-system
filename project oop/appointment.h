#pragma once
#include "doctor.h"
#include "patient.h"
class appointment 
{
private:
		int appointment_id;
		string appointment_date;
		float appointment_time;
		string appointment_place;
public:
	appointment();
	void setappointment(int appointment_id ,string appointment_date, float appointment_time, string appointment_place);
	int getappointment_id();
	string getappointment_date();
	float getappointment_time();
	string getappointment_place();
	void display();
};

