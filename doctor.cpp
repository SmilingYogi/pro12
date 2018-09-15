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
};
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
          break;
   case 2:
          break;
  case 3:
          break;
  case 4:
          break:
  case 5:
          exit(0);
  default:
          cout<<"Invalid choice!!!";
 }
 void adddoc()
 {
  doctor ob;
  cout<<"Enter Doctor's name:";
  gets(ob.docname);
  cout<<"Enter Doctor speciality:";
  gets(ob.docspecial);
  cout<<"Enter years of experience";
  cin>>docexp;
