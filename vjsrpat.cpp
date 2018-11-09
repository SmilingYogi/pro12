
#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void addpat();
void app();
void view();
void edit();
struct patmain
{
int id;
char name[20];
char city[20];
char blood_gp[5];
}mob;
class patient
{
public:
char name[20];
char city[20];
char contact[10];
char age[5];
char sex[8];
char blood_gp[5];
char disease_past[50];
int id;
void input();
void show();
}pob;
void main()
{
int c;
char ch;
ch='y';
clrscr();
while(ch=='y')
{
cout<<"Make your choice"<<endl;
cout<<"1.Add New Patient Record "<<endl;
cout<<"2.Add Diagnosis Information "<<endl;
cout<<"3.Full History of the Patient"<<endl;
cout<<"4.Delete patient"<<endl;
cout<<"5.Exit the Program"<<endl;
cin>>c;
switch(c)
 { case 1:
	 addpat(); break;
   case 2:
	 app(); break;
   case 3:
	 view(); break;
   case 4:
	 edit(); break;
   case 5:
	  exit(0); break;
   default:
	  cout<<"Invalid choice!!!";
 }}
 getch();
 }
void addpat()
{
time_t rawtime;
  struct tm * timeinfo;
   time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  cout<<"\n\n\t\t"<< asctime (timeinfo);
  ofstream pat_file;
  ofstream mf;
  mfob.open("mf.dat")  ;
  patmain mob;
  char fname[20];
  randomize();
  int rid=1000+random(200);
  mob.id=pob.id=rid;

  cout<<"\n\n\n\nEnter the patient's file name : ";
  cin.ignore();
  gets(fname);
  pat_file.open(fname);
		if(!fname)
		{
		cout<<"\nError creating the file\n";
	       // return();
		}
		else
		{

	    cout<<"\n********************************************************************\n";pat_file<<"\n********************************************************************\n\n";//fn1353 st

	    cout<<"\nPatient ID : "<<pob.id;
	    pat_file<<"Patient ID : ";
	   // gets(pob.id);
	    pat_file<<pob.id<<"\n";
	    cout<<"\nName : ";
	    pat_file<<"Name : ";
	    gets(pob.name);
	    mob.name=pob.name;
	    pat_file<<pob.name<<"\n";
	    cout<<"\nAddress : ";
	    pat_file<<"Address : ";
	    gets(pob.city);
	    mob.city=pob.city;
	    pat_file<<pob.city<<"\n";
	    cout<<"\nContact Number : ";
	    pat_file<<"Contact Number : ";
	    gets(pob.contact);
	    pat_file<<pob.contact<<"\n";
	    cout<<"\nAge : ";
	    pat_file<<"Age : ";
	    gets(pob.age);
	    pat_file<<pob.age<<"\n";
	    cout<<"\nSex : ";
	    pat_file<<"Sex : ";
	    gets(pob.sex);
	    pat_file<<pob.sex<<"\n";
	    cout<<"\nBlood Group : ";
	    pat_file<<"Blood Group : ";
	    gets(pob.blood_gp);
	    mob.blood_gp=pob.blood_gp;
	    pat_file<<pob.blood_gp<<"\n";
	    cout<<"\nAny Major disease suffered earlier : ";
	    pat_file<<"Any Major disease suffered earlier : ";
	    gets(pob.disease_past);
	    pat_file<<pob.disease_past<<"\n";

	    cout<<"\n********************************************************************\n";pat_file<<"\n********************************************************************\n\n";
	    cout<<"\nInformation Saved Successfully\n";


	    }
clrscr();
//return();
}


void app()
{    char fname[20];
 //Appending diagnosis information of patient datewise.................option 2
    fstream pat_file;
    cout<<"\nEnter the patient's file name to be opened : ";
    gets(fname);
    clrscr();
	pat_file.open(fname, ios::in);
		if(!pat_file)
		{
		cout<<"\nError while opening the file\n";
		// return();
		}
		else
		{
		    cout<<"\n\n\n\n\t........................................ Information about "<<fname<<" ........................................\n\n\n\n";
		    char info[1000];
			while(pat_file)
			{
			pat_file.getline(info,1000);
			cout<<info<<"\n";
			}
			time_t rawtime;
			struct tm *timeinfo;
			time(&rawtime);
			timeinfo=localtime(&rawtime);
			cout<<"\n";
			pat_file.close();
			pat_file.open(fname, ios::out | ios::app);
			cout<<"\n";
			cout<<"Adding more information in patient's file on : "<<asctime (timeinfo);
			pat_file<<"Description of "<<asctime (timeinfo)<<"\n";
			    class app
			    {
				public:
				char symptom[500];
				char diagnosis[500];
				char medicine[500];
				char addmission[30];
				char ward[15];
			    };
	    app add;
	    cout<<"\nSymptoms : ";
	    pat_file<<"Symptoms : ";
	    gets(add.symptom);
	    pat_file<<add.symptom<<"\n";
	    cout<<"\nDiagnosis : ";
	    pat_file<<"Diagnosis : ";
	    gets(add.diagnosis);
	    pat_file<<add.diagnosis<<"\n";
	    cout<<"\nMedicines : ";
	    pat_file<<"Medicines : ";
	    gets(add.medicine);
	    pat_file<<add.medicine<<"\n";
	    cout<<"\nAddmission Required? : ";
	    pat_file<<"Addmission Required? : ";
	    gets(add.addmission);
	    pat_file<<add.addmission<<"\n";
	    cout<<"\nType of ward : ";
	    pat_file<<"Type of ward : ";
	    gets(add.ward);
	     pat_file<<add.ward<<"\n";
	 pat_file<<"\n*************************************************************************\n";
	    cout<<"\n\n"<<add.ward<<" ward is alloted Successfully\n";
	    pat_file.close();
	    cout<<"\n\n";
	    clrscr();
	   // return();
}
}
void view()
{   char fname[20];
  fstream pat_file;
    cout<<"\n\nEnter the patient's file name to be opened : ";
    gets(fname);
    clrscr();
  pat_file.open(fname,ios::in);
    if(!pat_file)
    {
    cout<<"\nError while opening the file\n";
    }
    else
    {
	cout<<"\n\n\n\n\t........................................ Full Medical History of "<<fname<<" ........................................\n\n\n\n";
	char info[1000];
      while(pat_file)
      {
      pat_file.getline(info,1000);
      cout<<info<<"\n";
      }
      cout<<"\n";
	}
	getch();
      clrscr();
}
void edit()
{}
