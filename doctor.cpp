#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void adddoc();
void dispdoc();
void deldoc();
void editdoc();
class doctor
{
char docname[20];
char docspecial[20];
int docid;
int docexp;
int docfee;
void setfee()
{if (docexp<10)
 docfee=250;
 else if(docexp<20)
 docfee=400;
 else
  docfee=600;
}
 public:
int getn()
	{
		return docid;
	}
	void input();
	void show();
	}dob;
void doctor::input()
 {
  cout<<"Enter the Doctor's ID:"; cin>>docid;
  cout<<"Enter Doctor's name:"; gets(docname);
  cout<<"Enter Doctor speciality:"; gets(docspecial);
  cout<<"Enter years of experience:"; cin>>docexp;
  setfee();
 }
void doctor::show()
{
	cout<<"Doctor ID==> "<<docid<<endl;
	cout<<"Name==> "<<docname<<endl;
	cout<<"Speciality ==> "<<docspecial<<endl;
	cout<<"Experience==> "<<docexp<<endl;
}

fstream fil;
void main()
{
int c;
char ch;
ch='y';
clrscr();
while(ch=='y')
{
cout<<"Make your choice"<<endl;
cout<<"1.Register new doctor"<<endl;
cout<<"2.View doctor list"<<endl;
cout<<"3.Remove doctor"<<endl;
cout<<"4.Edit doctor"<<endl;
cout<<"5.Exit"<<endl;
cin>>c;
switch(c)
 { case 1:
	 adddoc(); break;
   case 2:
	 dispdoc(); break;
   case 3:
	 deldoc(); break;
   case 4:
	 editdoc(); break;
   case 5:
	  exit(0); break;
   default:
	  cout<<"Invalid choice!!!";
 }}
 getch();
 }
 void adddoc()
 {     //ofstream fil;
	fil.open("doc.dat",ios::out| ios::binary|ios::ate);
		dob.input();
		fil.write((char*)&dob,sizeof(dob));

	fil.close();

}
 void dispdoc()
{       ifstream filo;
	filo.open("doc.dat",ios::in|ios::binary);
	filo.seekg(0);
       if(!filo)
	{
		cout<<"File not Found";
		exit(0);
	}
       else
	{

		while(!filo.eof())
		{       filo.read((char*)&dob, sizeof(dob));
			if(!filo.eof())
			dob.show();
		       //	cout<<"Press Any Key....For Next Record"<<endl;
		       //	getch();
		       //	filo.read((char*)&dob, sizeof(dob));
		}
	}
	filo.close();
}
void deldoc()		//Function to Delete Particular Record
{
	int n;
	cout<<"Enter ID that should be Deleted :";
	cin>>n;
	ofstream o;
	o.open("new.dat",ios::out|ios::binary);
	fil.open("doc.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&dob, sizeof(dob));
		while(!fil.eof())
		{
			if(n!=dob.getn())
			{
				o.write((char*)&dob, sizeof(dob));
			}
			else
			{
				// cout<<"Press Any Key....For Search"<<endl;
				 //getch();
			}
			fil.read((char*)&dob,sizeof(dob));
		}
	}
	o.close();
	fil.close();
	remove("doc.dat");
	rename("new.dat", "doc.dat");
}
void editdoc()		//Function to Modify Particular Record from Data File
{
	int n;
	cout<<"Enter ID that should be searched:";
	cin>>n;
	fil.open("doc.dat",ios::in| ios::out|ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&dob, sizeof(dob));
		while(!fil.eof())
		{
			if(n==dob.getn())
			{
				fil.seekg(0,ios::cur);
				cout<<"Enter New Record.."<<endl;
				dob.input();
				fil.seekp(fil.tellg() - sizeof(dob));
				fil.write((char*)&dob, sizeof(dob));
			}
			else
			{
				 cout<<"Press Any Key....For Search"<<endl;
				 getch();
			}
			fil.read((char*)&dob, sizeof(dob));
		}
	}
	fil.close();
}




