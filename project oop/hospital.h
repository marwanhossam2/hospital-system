#pragma once
#include "doctor.h"
#include "patient.h"
#include "appointment.h"
#include <vector>
class hospital : public doctor, public patient , public appointment
{
public:
	vector<doctor>doc;
	vector<patient>pat;
	vector<appointment>app;
	
		hospital();
		void adddoctor();
		void addpatient();
		void addappointment(string docname,string patname);
		void displaydoctor();
		void displaypatient();
		void displayappointment();
		void searchdoctor(string docname);
		void searchpatient(string patname);
		void searchappointment(int appointment_id);
		void deletedoctor(int doctor_id);
		void deletepatient(int patient_id);
		void deleteappointment(int appointment_id);
		void updatedoctor(int doctor_id);
		void updatepatient(int patient_id);
		void updateappointment(int appointment_id);
		bool checkdoctor();
		bool checkpatient();
		bool checkappointment();
		bool checkapptimeavailability(float appointment_time);
		bool checkdocid(int doctor_id);
		bool checkpatid(int patient_id);
		bool checkappid(int appointment_id);
		void checkdocnameavailability(string docname);
		
};

