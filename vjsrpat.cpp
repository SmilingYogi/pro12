#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void addpat();
void app();
void pattasks();
void view();
void del();
void search_city(char[]);
void search_view(int);
void search_menu();
struct patmain
{
int id;
char name[20];
char city[30];
char blood_gp[5];
}mob;
class patient
{
public:
char name[20];
char city[30];
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
clrscr();
cout<<"*************************************************************************"<<"\n";
cout<<"\t\t\t***PATIENT MENU***"<<"\n";
cout<<"************************************************************************* "<<"\n";
pattasks();
 getch();
 }
 void pattasks()
 {
  int c;
  cout<<"Make your choice"<<endl;
  cout<<"1.Add New Patient Record "<<endl;
  cout<<"2.Search for existing patient record"<<endl;
  cout<<"3.Add Diagnosis Information "<<endl;
  cout<<"4.Full History of the Patient"<<endl;
  cout<<"5.Delete patient"<<endl;
  cout<<"6.Exit the Program"<<endl;
  cin>>c;
  switch(c)
  { case 1:
   addpat(); break;
   case 2:
   search_menu();break;
   case 3:
   app(); break;
   case 4:
   view(); break;
   case 5:
   del(); break;
   case 6:
    exit(0); break;
   default:
    cout<<"Invalid choice!!!";
 }
}
void addpat()
{
time_t rawtime;
  struct tm * timeinfo;
   time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  cout<<"\n\n\t"<< asctime (timeinfo);
  ofstream pat_file;
  ofstream mfob;
  mfob.open("mf.dat",ios::binary);
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

      cout<<"\nPatient ID(auto-genarated) : "<<pob.id;
      pat_file<<"Patient ID : ";
     // gets(pob.id);
      pat_file<<pob.id<<"\n";
      cout<<"\nName : ";
      pat_file<<"Name : ";
      gets(pob.name);
      strcpy(mob.name,pob.name);
      pat_file<<pob.name<<"\n";
      cout<<"\nCity : ";
      pat_file<<"City : ";
      gets(pob.city);
      strcpy(mob.city,pob.city);
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
      strcpy(mob.blood_gp,pob.blood_gp);
      pat_file<<pob.blood_gp<<"\n";
      cout<<"\nAny Major disease suffered earlier : ";
      pat_file<<"Any Major disease suffered earlier : ";
      gets(pob.disease_past);
      pat_file<<pob.disease_past<<"\n";

      cout<<"\n********************************************************************\n";pat_file<<"\n********************************************************************\n\n";
      cout<<"\nInformation Saved Successfully\n";
      mfob.write((char*)&mob,sizeof(mob));

      }
      
      clrscr();
      mfob.close();
      pat_file.close();
      cout<<"/n/n";
      pattasks();
//return();
}
  void search_menu()
   {
    //T1.ssi_count=0;
    char ent;
    int s_choice;
    ifstream fob;
    fob.open("mf.dat",ios::binary);
    fob.seekg(1);
    if(fob.eof())
      {
	cout<<"\n\n\n";
	cout<<"\t Database is empty !!!"<<"\n";
	cout<<"\tPlease enter some information first. "<<"\n";
	cout<<"\n\n\tDo you want to enter now (Y/N) : ";
	cin>>ent;
      while(ent!='Y'&&ent!='y'&&ent!='N'&&ent!='n')
	  {
	    cout<<"\n\tPlease enter a correct option (Y/N) : ";
	    cin>>ent;
	  }
	  if(ent=='y'||ent=='Y')
	    addpat();
	  else
	    pattasks();
      }
      //T1.search_number=0;
      cout<<"\n\n\t\t ***SEARCH MENU***"<<"\n";
      cout<<"\n\n\t\t 1. Search by city "<<"\n";
	   cout<<"\t\t 2. Search by blood group "<<"\n";
	   cout<<"\t\t 3. Return to main menu "<<"\n";
	   cout<<"\n\n\t Enter your choice : ";
	   cin>>s_choice;
	  // cin.get(ch);
	   cout<<"\n\n\n";
	   switch(s_choice)
	    {
	       case 1:
		   //T1.search_index=1;
		   cout<<"\n\n\t\t***SEARCHING BY CITY***\n";
		   char s_city[30];
		   cout<<"\n\n\tEnter city : ";
		   cin.getline(s_city,30);
		   cout<<"\n\n\n";
		   while(strlen(s_city)==0) //if enter is pressed before input for city
		   { cout<<"\n\tPlease enter a city : ";
		     cin.getline(s_city,30);
		    }
		   search_city(s_city);
		   break;
	       case 2:
		   //T1.search_index=2;
		   cout<<"\n\n\t\t***SEARCHING BY BLOOD GROUP***\n";
		   cout<<"\n\n\t\t ***BLOOD GROUP MENU***\n\n";
		   cout<<"\t1. A+ "<<"\n";
		   cout<<"\t2. A- "<<"\n";
		   cout<<"\t3. B+ "<<"\n";
		   cout<<"\t4. B- "<<"\n";
		   cout<<"\t5. AB+ "<<"\n";
		   cout<<"\t6. AB- "<<"\n";
		   cout<<"\t7. O+ "<<"\n";
		   cout<<"\t8. O- "<<"\n";
		   int s_group;
		   cout<<"\n\n Enter the serial of your required group : ";
		   cin>>s_group;
		   while(s_group!=1&&s_group!=2&&s_group!=3&&s_group!=4&& s_group!=5&&s_group!=6&&s_group!=7&&s_group!=8)
		   {
		    cout<<"\n";
		    cout<<"\tInvalid search criteria !!!"<<"\n";
		    cout<<"\tValid serials are 1 to 8."<<"\n";
		    cout<<"\tEnter a valid blood group : ";
		    cin>>s_group;
		   }
		   cout<<"\n\n\n";
		   //search_blood_group(s_group);
		   break;
	       case 3:
		   pattasks();
		   break;
	       default:
		   cout<<"\n\n Invalid search criteria !!!"<<"\n";
		   cout<<" Valid options are 1 and 2 !!!"<<"\n";
		   cout<<" Press any key to return to the main searching menu....."<<"\n";
		   getch();
		   search_menu();
	   } //end of switch
    } //end of function
 void search_city(char s_city[30])
      {
	  int search_count=0;
	  char after_search_answer;
	  //int search_number++;
	  ifstream fin;
	  fin.open("mf.dat",ios::binary);
	  cout<<"\n\n\n";
	  while(!fin.eof())
	    {
	     fin.read((char*)&mob,sizeof(mob));
	      if(strcmp(mob.city,s_city)==0)
		 {
		    if(fin.eof())
		      continue;
		    if(search_count==0)
		      cout<<"\t\tPatient ID. Name of patient\n\n";
		      cout<<"\n\t\t "<<mob.id<<"\t\t"<<mob.name;
		      search_count++;
		 }
	   }

	      cout<<"\n\n\n\t\t Search is complete !!! "<<"\n";
	      if(search_count==0)
		{
		  cout<<"\t\t No result found !!!"<<"\n\n\n";
		  cout<<"\t\t Press any key to continue.....";
		  getch();
		 // after_search_options();
		}
	      if(search_count>1)
		cout<<"\t\t "<<search_count<<" results found !!! "<<"\n\n\n";
	      if(search_count==1)
		cout<<"\t\t "<<search_count<<" result found !!! "<<"\n\n\n";
	      cout<<"\n\n\t\tWant to view in detail : ";
		  cin>>after_search_answer;
	 while(after_search_answer!='y'&&after_search_answer!='Y'&&after_search_answer!='N'&&after_search_answer!='n')
			    {
			      cout<<"\n\n\t\tPlease enter a correct option .";
			      cout<<"\n\t\tDo you want to view in detail (Y/N): ";
			      cin>>after_search_answer;
			    }
			   if(after_search_answer=='y'||after_search_answer=='Y')
			    {
			     int pid;
			      cout<<"\n\n\n\t\tWhich patient ID : ";
			      cin>>pid;

			      view();
			    }
			  // else
			  // after_search_options();
          fin.close();


       } //end of function
void app()
{   //Appending diagnosis information of patient datewise.......
   char fname[20];
 
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
	cout<<"\n\n\n\n\t.................................... Information about "<<fname<<" ................................\n\n\n\n";
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
       cout<<"\n\n";
      clrscr();
      cout<<"\n\n";
       // return();
  }
  pat_file.close();
  pattasks();

}
void view()
{
  char fname[20];
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
      cout<<"/n/n";
      pattasks();
}
void search_view(int pid)
{
  char fname[10];
  ifstream fob;
  fob.open("mf.dat",ios::binary);
  while(!fob.eof())
    {
      fob.read((char*)&mob,sizeof(mob));

      if(mob.id==pid)
	 {
	  strcpy(fname,mob.name);
	  break;
	 }
    }
 clrscr();
  fstream pat_file;
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
void del()
{
char fname[20];
cout<<"Enter patient file name to delete:";
gets(fname);
remove("fname");
cout<<"Patient file is deleted Successfully";
cout<<"/n/n";
pattasks();
}
