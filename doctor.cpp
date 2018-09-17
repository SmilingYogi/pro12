#include<fstream.h>
#include<iostream.h>
#include<conio.h>
class doctor
{
char docname[20];
char docspecial[20];
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
char *getn()
	{
		return docname;
	}
 void input()
 {
  cout<<"Enter Doctor's name:";           gets(docname);
  cout<<"Enter Doctor speciality:";       gets(docspecial);
  cout<<"Enter years of experience";      cin>>docexp;
  setfee();
 }
 void show()
{
 cout<<"Name==> "<<docname<<endl;
	cout<<"Speciality ==> "<<docspecial<<endl;
	cout<<"Experience==> "<<docexp<<endl;
}
}dob;
fstream fil;
void main()
{
int c;  
clrscr();
cout<<"Make your choice
cout<<"1.Register new doctor"<<endl;
cout<<"2.View doctor list"<<endl;
cout<<"3.Remove doctor"<<endl;
cout<<"4.Edit doctor"<<endl; 
cout<<"5.Exit"<<endl;
switch(c)
 { case 1:
         adddoc(); break;
   case 2:
         dispdoc(); break;
  case 3:
         deldoc(); break;
  case 4:
         editdoc(); break:
  case 5:
          exit(0);
  default:
          cout<<"Invalid choice!!!";
 }
 void adddoc()
 {   
	fil.open("doc.dat",ios::app| ios::binary);
		dob.input();
		fil.write((char*)&fileobj, sizeof(dob));
		
	fil.close();
}
 void dispdoc()		//Function to Display All Record from Data 
{
	fil.open("binary.dat",ios::in| ios::binary);
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
			dob.show();
			cout<<"Press Any Key....For Next Record"<<endl;
			getch();
			fil.read((char*)&dob, sizeof(dob));
		}
	}
	fil.close();
}
void deldoc()		//Function to Delete Particular Record 
{
	char n[100];
	cout<<"Enter Name that should be Deleted :";
	gets(n);
	ofstream o;
	o.open("new.dat",ios::out|ios::binary);
	fil.open("binary.dat",ios::in| ios::binary);
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
			if(strcmp(n,dob.getn())!=0)
			{
				o.write((char*)&dob, sizeof(dob));
			}
			else
			{
				 cout<<"Press Any Key....For Search"<<endl;
				 getch();
			}
			fil.read((char*)&fileobj, sizeof(fileobj));
		}
	}
	o.close();
	fil.close();
	remove("binary.dat");
	rename("new.dat", "binary.dat");
} 
void editdoc()		//Function to Modify Particular Record from Data File
{
	char n[100];
	cout<<"Enter Name that should be searched:";
	gets(n);
	fil.open("binary.dat",ios::in| ios::out|ios::binary);
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
			if(strcmp(n,dob.getn())==0)
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
