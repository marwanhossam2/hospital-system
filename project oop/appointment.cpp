#include "appointment.h"
appointment::appointment()
{
	appointment_id = appointment_id+1;
	appointment_date = "";
	appointment_time = 0.0;
	appointment_place = "";
}
void appointment::setappointment(int appointment_id, string appointment_date, float appointment_time, string appointment_place)
{
	this->appointment_id = appointment_id;
	this->appointment_date = appointment_date;
	this->appointment_time = appointment_time;
	this->appointment_place = appointment_place;
}
int appointment::getappointment_id()
{
	return appointment_id;
}
string appointment::getappointment_date()
{
	return appointment_date;
}
float appointment::getappointment_time()
{
	return appointment_time;
}
string appointment::getappointment_place()
{
	return appointment_place;
}
void appointment::display()
{
	cout << "Appointment ID: " << appointment_id << endl;
	cout << "Appointment Date: " << appointment_date << endl;
	cout << "Appointment Time: " << appointment_time << endl;
	cout << "Appointment Place: " << appointment_place << endl;
}
