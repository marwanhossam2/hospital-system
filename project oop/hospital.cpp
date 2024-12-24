#include "hospital.h"
hospital::hospital()
{

}
void hospital::adddoctor()
{
	string spc, qual ,name , add, mail,phone;
	int	age,id;
	doctor d;
	cout << "Enter name: ";
	cin >> name;
	
	cout << "Enter address: ";
	cin >> add;
	cout << "Enter phone: ";
	cin >> phone;
	cout << "Enter email: ";
	cin >> mail;
	cout << "Enter age: ";
	cin >> age;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid input. Please enter a number: ";
		cin >> age;
	}
	d.setdata(name, add, phone, mail, age);
	cout << "Enter specialization: ";
	cin >> spc;
	cout << "Enter qualification: ";
	cin >> qual;
	cout << "Enter doctor_id: ";
	cin >> id;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid input. Please enter a number: ";
		cin >> id;
	}
	while(!checkdocid(id))
	{
		cout << "This id is already taken. Please enter another id: ";
		cin >> id;
		while(cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input. Please enter a number: ";
			cin >> id;
		}
	}
	cout << "\033[1;32m-----------------------------------" << endl;
	cout << "doctor added successfully" << endl;
	cout << "-----------------------------------\033[0m" << endl;
	d.setdoctor(id,spc, qual);
	doc.push_back(d);
}
void hospital::addpatient()
{
	string name, add, mail, phone, disease, treatment;
	int age,id;
	patient p;	
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter address: ";
	cin >> add;
	cout << "Enter phone: ";
	cin >> phone;
	cout << "Enter email: ";
	cin >> mail;
	cout << "Enter age: ";
	cin >> age;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid input. Please enter a number: ";
		cin >> age;
	}
	p.setdata(name, add, phone, mail, age);
	cout << "Enter disease: ";
	cin >> disease;
	cout << "Enter treatment: ";
	cin >> treatment;
	cout << "Enter patient_id: ";
	cin >> id;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid input. Please enter a number: ";
		cin >> id;
	}
	while(!checkpatid(id))
	{
		cout << "This id is already taken. Please enter another id: ";
		cin >> id;
		while(cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input. Please enter a number: ";
			cin >> id;
		}
	}
	cout << "\033[1;32m-----------------------------------" << endl;
	cout << "patient added successfully" << endl;
	cout << "-----------------------------------\033[0m" << endl;
	p.setpatient(id, disease, treatment);
	pat.push_back(p);
}
void hospital::addappointment(string docname,string patname)
{
	string date, place;
	int id;
	float time;
	appointment a;
	int docid,patid;
	for(int i=0;i<doc.size();i++)
	{
		if(doc[i].getdocname()==docname)
		{
			docid=doc[i].getdoctor_id();
		}
		else
		{
			docid = 0;
		}
	}
	for(int i=0;i<pat.size();i++)
	{
		if(pat[i].getpatname()==patname)
		{
			patid=pat[i].getpatient_id();
		}
		else
			patid=0;
	}
	searchpatient(patname);
	cout << "\033[1;32m-----------------------------------\033[0m" << endl;
	if(checkpatid(patid))
	{
		int choice;
		cout << "do you want to a new patient? 1.yes 2.no" << endl;
		cin >> choice;
		while(cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input. Please enter a number: ";
			cin >> choice;
		}
		if(choice==1)
		{
			addpatient();
			
		}
		else
		{
			return;
		}
	}
	checkdocnameavailability(docname);
	cout << "\033[1;32m-----------------------------------\033[0m" << endl;
	if(checkdocid(docid))
	{
		return;
	}
	cout << "Enter appointment_date: ";
	cin >> date;
	cout << "Enter appointment_place: ";
	cin >> place;
	cout << "Enter appointment_time: ";
	cin >> time;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid input. Please enter a number: ";
		cin >> time;
	}
	while(!checkapptimeavailability(time))
	{
		cout << "This time is already booked. Please enter another time: ";
		cin >> time;
		while(cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input. Please enter a number: ";
			cin >> time;
		}
	}
	cout << "Enter appointment_id: ";
	cin >> id;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid input. Please enter a number: ";
		cin >> id;
	}
	while(!checkappid(id))
	{
		cout << "This id is already taken. Please enter another id: ";
		cin >> id;
		while(cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input. Please enter a number: ";
			cin >> id;
		}
	}
	cout << "\033[1;32m-----------------------------------" << endl;
	cout << "appointment added successfully" << endl;
	cout << "-----------------------------------\033[0m" << endl;
	a.setappointment(id, date, time, place);
	app.push_back(a);
}
void hospital::displaydoctor()
{
	for (int i = 0; i < doc.size(); i++)
	{
		doc[i].display();
		cout << "\033[1;32m-----------------------------------\033[0m" << endl;
	}
}
void hospital::displaypatient()
{
	for (int i = 0; i < pat.size(); i++)
	{
		pat[i].display();
		cout << "\033[1;32m-----------------------------------\033[0m" << endl;
	}
}
void hospital::displayappointment()
{
	for (int i = 0; i < app.size(); i++)
	{
		app[i].display();
		cout << "\033[1;32m-----------------------------------\033[0m" << endl;
	}
}
void hospital::searchdoctor(string docname)
{
	int flage = 0;
	for (int i = 0; i < doc.size(); i++)
	{
		if (doc[i].getdocname() == docname)
		{
			doc[i].display();
		}
		else
		{
			flage +=1;
		}
	}
	if (flage == doc.size())
	{
		cout << "Doctor not found" << endl;
	}
}
void hospital::searchpatient(string patname)
{
	int flage = 0;
	for (int i = 0; i < pat.size(); i++)
	{
		if (pat[i].getpatname() == patname)
		{
			pat[i].display();
		}
		else
		{
			flage +=1;
		}
	}
	if (flage == pat.size())
	{
		cout << "Patient not found" << endl;
	}
	
}
void hospital::searchappointment(int appointment_id)
{
	int flage = 0;
	for (int i = 0; i < app.size(); i++)
	{
		if (app[i].getappointment_id() == appointment_id)
		{
			app[i].display();
		}
		else
		{
			flage +=1;
		}
	}
	if (flage == app.size())
	{
		cout << "Appointment not found" << endl;
	}
}
void hospital::deletedoctor(int doctor_id)
{
	int flage = 0;
	for (int i = 0; i < doc.size(); i++)
	{
		if (doc[i].getdoctor_id() == doctor_id)
		{
			doc.erase(doc.begin() + i);
		}
		else
		{
			flage +=1;
		}

	}
	if (flage == doc.size())
	{
		cout << "Doctor not found" << endl;
	}
}
void hospital::deletepatient(int patient_id)
{
	int flage = 0;
	for (int i = 0; i < pat.size(); i++)
	{
		if (pat[i].getpatient_id() == patient_id)
		{
			pat.erase(pat.begin() + i);
		}
		else
		{
			flage +=1;
		}
	}
	if (flage == pat.size())
	{
		cout << "Patient not found" << endl;
	}
}
void hospital::deleteappointment(int appointment_id)
{
	int flage = 0;
	for (int i = 0; i < app.size(); i++)
	{
		if (app[i].getappointment_id() == appointment_id)
		{
			app.erase(app.begin() + i);
		}
		else
		{
			flage +=1;
		}
	}
	if (flage == app.size())
	{
		cout << "Appointment not found" << endl;
	}
}
void hospital::updatedoctor(int doctor_id)
{
	int flage = 0;
	for (int i = 0; i < doc.size(); i++)
	{
		if (doc[i].getdoctor_id() == doctor_id)
		{
			doc[i].display();
			string specialization, qualification;
			int id;
			cout << "Enter specialization: ";
			cin >> specialization;
			cout << "Enter qualification: ";
			cin >> qualification;
			cout << "Enter doctor_id: ";
			cin >> id;
			while(cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Invalid input. Please enter a number: ";
				cin >> id;
			}
			while(!checkdocid(id))
			{
				cout << "This id is already taken. Please enter another id: ";
				cin >> id;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "Invalid input. Please enter a number: ";
					cin >> id;
				}
			}
			doc[i].setdoctor(id,specialization, qualification);
		}
				else
		{
			flage +=1;
		}
	}
	if (flage == doc.size())
	{
		cout << "Doctor not found" << endl;
	}
}
void hospital::updatepatient(int patient_id)
{
	int flage = 0;
	for (int i = 0; i < pat.size(); i++)
	{
		if (pat[i].getpatient_id() == patient_id)
		{
			pat[i].display();
			string  pdisease, ptreatment;
			int id;
			cout << "Enter pdisease: ";
			cin >> pdisease;
			cout << "Enter ptreatment: ";
			cin >> ptreatment;
			cout << "Enter patient_id: ";
			cin >> id;
			while(cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Invalid input. Please enter a number: ";
				cin >> id;
			}
			while(!checkpatid(id))
			{
				cout << "This id is already taken. Please enter another id: ";
				cin >> id;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "Invalid input. Please enter a number: ";
					cin >> id;
				}
			}
			pat[i].setpatient( id,pdisease, ptreatment);
		}
		else
		{
			flage +=1;
		}
	}
	if (flage == pat.size())
	{
		cout << "Patient not found" << endl;
	}
}
void hospital::updateappointment(int appointment_id)
{
	int flage = 0;
	for (int i = 0; i < app.size(); i++)
	{
		if (app[i].getappointment_id() == appointment_id)
		{
			app[i].display();
			string  appointment_date,place ;
			int id;
			float appointment_time;
			cout << "Enter appointment_date: ";
			cin >> appointment_date;
			cout << " enter appointment_place: ";
			cin >> place;
			cout << "Enter appointment_time: ";
			cin >> appointment_time;
			while(cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Invalid input. Please enter a number: ";
				cin >> appointment_time;
			}
			while(!checkapptimeavailability(appointment_time))
			{
				cout << "This time is already booked. Please enter another time: ";
				cin >> appointment_time;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "Invalid input. Please enter a number: ";
					cin >> appointment_time;
				}
			}
			cout << "Enter appointment_id: ";
			cin >> id;
			while(cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Invalid input. Please enter a number: ";
				cin >> id;
			}
			while(!checkappid(id))
			{
				cout << "This id is already taken. Please enter another id: ";
				cin >> id;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "Invalid input. Please enter a number: ";
					cin >> id;
				}
			}
			app[i].setappointment(id, appointment_date, appointment_time,place);
		}
		else
		{
			flage +=1;
		}
	}
	if (flage == app.size())
	{
		cout << "Appointment not found" << endl;
	}
}
bool hospital::checkdoctor()
{
	if (doc.size() == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool hospital::checkpatient()
{
	if (pat.size() == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool hospital::checkappointment()
{
	if (app.size() == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool hospital::checkapptimeavailability(float appointment_time)
{
	int flage = 0;
	for (int i = 0; i < app.size(); i++)
	{
		if (app[i].getappointment_time() == appointment_time)
		{
			flage += 1;
		}
	}
	if (flage == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool hospital::checkdocid(int doctor_id)
{
	int flage = 0;
	for (int i = 0; i < doc.size(); i++)
	{
		if (doc[i].getdoctor_id() == doctor_id)
		{
			flage += 1;
		}
	}
	if (flage == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool hospital::checkpatid(int patient_id)
{
	int flage = 0;
	for (int i = 0; i < pat.size(); i++)
	{
		if (pat[i].getpatient_id() == patient_id)
		{
			flage += 1;
		}
	}
	if (flage == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool hospital::checkappid(int appointment_id)
{
	int flage = 0;
	for (int i = 0; i < app.size(); i++)
	{
		if (app[i].getappointment_id() == appointment_id)
		{
			flage += 1;
		}
	}
	if (flage == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void hospital::checkdocnameavailability(string docname)
{
	int flage = 0;
	int id;
	for (int i = 0; i < doc.size(); i++)
	{
		if (doc[i].getdocname() == docname)
		{
			flage += 1;
		}
	}
	if (flage == 0)
	{
		cout << "Doctor not found" << endl;
	}
	else if (flage == 2)
	{
		cout << "please enter your id to know who are you :" << endl;
		cin >> id;
		while(cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input. Please enter a number: ";
			cin >> id;
		}
		for (int i = 0; i < doc.size(); i++)
		{
			if (doc[i].getdoctor_id() == id)
			{
				doc[i].display();
			}
		}
	}
}