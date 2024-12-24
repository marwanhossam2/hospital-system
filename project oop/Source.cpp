#include "hospital.h"
int main() {
	cout << "\033[4;34mWelcome to Hospital Management System\033[0m" << endl;
	hospital h;
	doctor d;
	patient p;
	appointment a;
	int doctorid;
	int patientid;
	int appointmentid;
	int choice;
	string docname;
	string patname;
	do {
		cout << "\033[1;36m1. Add Doctor" << endl;
		cout << "2. Add Patient" << endl;
		cout << "3. Add Appointment" << endl;
		cout << "4. Display Doctors" << endl;
		cout << "5. Display Patients" << endl;
		cout << "6. Display Appointments" << endl;
		cout << "7. Search Doctor" << endl;
		cout << "8. Search Patient" << endl;
		cout << "9. Search Appointment" << endl;
		cout << "10.update doctor" << endl;
		cout << "11.update patient" << endl;
		cout << "12.update appointment" << endl;
		cout << "13.delete doctor" << endl;
		cout << "14.delete patient" << endl;
		cout << "15.delete appointment" << endl;
		cout << "16.Exit\033[0m" << endl;
		cout << "\033[4;35mEnter your choice: \033[0m";
		cin >> choice ;
		while(cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\033[1;31mInvalid input. Please enter a number: \033[0m";
			cin >> choice;
		}
		
		switch (choice) {
		case 1:
			h.adddoctor();
			break;
		case 2:
			h.addpatient();
			break;
		case 3:
			if (h.checkdoctor() == false)
			{
				cout << "\033[1;31mNo doctors available\033[0m" << endl;
				break;
			}
			else if (h.checkpatient() == false)
			{
				cout << "\033[1;31mNo patients available\033[0m" << endl;
				break;
			}
			else
				{
				cout << "Enter Patient name: ";
				cin >> patname;
				cout << "Enter Doctor name: ";
				cin >> docname;
				cout << "\033[1;32m-----------------------------------\033[0m" << endl;
				h.addappointment(docname,patname);
				}
			break;
			
		case 4:
			if(h.checkdoctor() == false)
			{
				cout<<"\033[1;31mNo doctors available\033[0m"<<endl;
				break;
			}
			else
				h.displaydoctor();
			break;
		case 5:
			if(h.checkpatient() == false)
			{
				cout<<"\033[1;31mNo patients available\033[0m"<<endl;
				break;
			}
			else
				h.displaypatient();
			break;
		case 6:
			if (h.checkappointment() == false)
			{
				cout << "\033[1;31mNo appointments available\033[0m" << endl;
				break;
			}
			else
				h.displayappointment();
			break;
		case 7:
			if(h.checkdoctor() == false)
			{
				cout<<"\033[1;31mNo doctors available\033[0m"<<endl;
				break;
			}
			else
				{
				cout << "Enter Doctor name: ";
				cin >> docname;
				h.checkdocnameavailability(docname);
				}
			break;
		case 8:
			if(h.checkpatient() == false)
			{
				cout<<"\033[1;31mNo patients available\033[0m"<<endl;
				break;
			}
			else
				{
				cout << "Enter Patient name: ";
				cin >> patname;
				h.searchpatient(patname);
				}
			break;
			
		case 9:
			if(h.checkappointment() == false)
			{
				cout<<"\033[1;31mNo appointments available\033[0m"<<endl;
				break;
			}
			else
				{
				cout << "Enter Appointment ID: ";
				cin >> appointmentid;
				h.searchappointment(appointmentid);
				}
			break;
		case 10:
			if(h.checkdoctor() == false)
			{
				cout<<"\033[1;31mNo doctors available\033[0m"<<endl;
				break;
			}
			else
				{
				cout << "Enter Doctor ID: ";
				cin >> doctorid;
				h.updatedoctor(doctorid);
				}
			break;
		case 11:
			if(h.checkpatient() == false)
			{
				cout<<"\033[1;31mNo patients available\033[0m"<<endl;
				break;
			}
			else
				{
				cout << "Enter Patient ID: ";
				cin >> patientid;
				h.updatepatient(patientid);
				}
			break;
		case 12:
			if(h.checkappointment() == false)
			{
				cout<<"\033[1;31mNo appointments available\033[0m"<<endl;
				break;
			}
			else
				{
				cout << "Enter Appointment ID: ";
				cin >> appointmentid;
				h.updateappointment(appointmentid);
				}
			break;
		case 13:
			if(h.checkdoctor() == false)
			{
				cout<<"\033[1;31mNo doctors available\033[0m"<<endl;
				break;
			}
			else
				{
				cout << "Enter Doctor ID: ";
				cin >> doctorid;
				h.deletedoctor(doctorid);
				}
			break;
		case 14:
			if(h.checkpatient() == false)
			{
				cout<<"\033[1;31mNo patients available\033[0m"<<endl;
				break;
			}
			else
				{
				cout << "Enter Patient ID: ";
				cin >> patientid;
				h.deletepatient(patientid);
				}
			break;
		case 15:
			if(h.checkappointment() == false)
			{
				cout<<"\033[1;31mNo appointments available\033[0m"<<endl;
				break;
			}
			else
				{
				cout << "Enter Appointment ID: ";
				cin >> appointmentid;
				h.deleteappointment(appointmentid);
				}
			break;
		case 16:
			cout << "\033[1;32mThank you for using Hospital Management System\033[0m" << endl;
			break;
		default:
			cout << "Invalid choice" << endl;
			break;

		}
		} while (choice != 16);
	return 0;
	}

	