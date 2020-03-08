#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iomanip.h>
#include<stdlib.h>

void menu()                              //MAIN MENU
 {
  clrscr();
  gotoxy(36,1);
  cout<<"90's Cafe"<<endl;
  gotoxy(35,4);
  cout<<"--MAIN MENU--";
  gotoxy(34,6);
  cout<<"1.Items";
  gotoxy(34,7);
  cout<<"2.Reservations"<<endl;
  gotoxy(34,8);
  cout<<"3.Inventory"<<endl;
  gotoxy(34,9);
  cout<<"4.Payroll"<<endl;
  gotoxy(34,10);
  cout<<"5.Exit"<<endl;

  for(int i=1;i<19;i++)     //for border
  {
   gotoxy(31+i,5);
   cout<<"-";
   gotoxy(31+i,11);
   cout<<"-";
  }
  for(int j=1;j<6;j++)      //for border
  {
   gotoxy(32,5+j);
   cout<<"|";
   gotoxy(49,5+j);
   cout<<"|";
  }
}
void item_menu()                         //ITEM MENU
{
 clrscr();
 gotoxy(36,1);
 cout<<"90's Cafe"<<endl;
 gotoxy(35,4);
 cout<<"--ITEM MENU--";
 gotoxy(34,6);
 cout<<"1.View Items";
 gotoxy(34,7);
 cout<<"2.Add Item"<<endl;
 gotoxy(34,8);
 cout<<"3.Delete Item"<<endl;
 gotoxy(34,9);
 cout<<"4.Main Menu"<<endl;
 for(int i=1;i<19;i++)     //for border
 {
  gotoxy(31+i,5);
  cout<<"-";
  gotoxy(31+i,10);
  cout<<"-";
 }
 for(int j=1;j<5;j++)      //for border
 {
  gotoxy(32,5+j);
  cout<<"|";
  gotoxy(49,5+j);
  cout<<"|";
 }
}

class item                          //CLASS DEFINTION FOR ITEM
{
 public:  char name[20];
	  int price;
	  item()
	  {
	   strcpy(name,"null");
	   price=0;
	  }
	  void input()
	  {
	   cout<<"Name of item:";
	   gets(name);
	   cout<<"Enter Price:";
	   cin>>price;
	  }

};

void line()                           //Line function defintion
{
 for(int i=1;i<=80;i++)
 cout<<"-";
}
void view_items()                   //to view all items
{
 clrscr();
 item r;
 gotoxy(36,1);
 cout<<"90's Cafe"<<endl;
 gotoxy(35,4);
 cout<<"--ITEM LIST--";
 gotoxy(1,5);
 line();
 cout<<setw(24)<<"S.No"<<setw(10)<<"Name"<<setw(25)<<"Price"<<endl;
 line();
 int n=1,row=1;
 ifstream infile;
 infile.open("foodlist.txt",ios::in);
 while(!infile.eof())
 {
  infile.read((char*)&r,sizeof(r));
  if(infile.eof()==0)
  {
   gotoxy(22,7+row);
   cout<<n;
   gotoxy(31,7+row);
   cout<<r.name;
   gotoxy(56,7+row);
   cout<<r.price;
   row++;
   n++;
  }
 }
}

void add_item()                       //function to add item
{
 clrscr();
 gotoxy(36,1);
 cout<<"90's Cafe"<<endl;
 item r;
 ofstream ofile;
 ofile.open("foodlist.txt",ios::app);
 gotoxy(1,5);
 cout<<"Name of item to be added:";
 gets(r.name);
 cout<<"Price of item:";
 cin>>r.price;
 ofile.write((char*)&r,sizeof(r));
 ofile.close();
 cout<<"Item Added Succesfully."<<endl;
 getch();
}

void del_item()              //function to delete item
{
 clrscr();
 item r;
 gotoxy(36,1);
 cout<<"90's Cafe"<<endl;
 char name_del[20];
 char found='f',confirm='n';
 gotoxy(1,3);
 cout<<"Name of item to be deleted:";
 gets(name_del);

 ifstream infile;
 ofstream ofile;
 ofile.open("temp.txt");
 infile.open("foodlist.txt",ios::in);
 while(!infile.eof())
 {
  infile.read((char*)&r,sizeof(r));
  if(strcmpi(name_del,r.name)==0)
  {
   found='t';
   cout<<r.name;
   cout<<endl;
   cout<<r.price;
   cout<<endl;
   cout<<"Are you sure, you want to delete this item?(y/n)";
   cin>>confirm;
   if(confirm=='y'||confirm=='Y')
   {
    cout<<"Item Deleted Successfully.";
    break;
   }
   if(confirm=='n'||confirm=='N')
   {
    ofile.write((char*)&r,sizeof(r));
    cout<<"Item Deletion Cancelled.";
    break;
   }
  }
  else
   ofile.write((char*)&r,sizeof(r));
 }
 if(found=='f')
 cout<<"Item not found!!"<<endl;
 infile.close();
 ofile.close();
 remove("foodlist.txt");
 rename("temp.txt","foodlist.txt");
 getch();
}

void reservation_menu()             //RESERVATION MENU
{
 clrscr();
 gotoxy(36,1);
 cout<<"90's Cafe"<<endl;
 gotoxy(32,4);
 cout<<"--RESERVATIONS--";
 gotoxy(31,6);
 cout<<"1.View Reservations";
 gotoxy(31,7);
 cout<<"2.Add Reservation"<<endl;
 gotoxy(31,8);
 cout<<"3.Delete Reservation"<<endl;
 gotoxy(31,9);
 cout<<"4.Main Menu"<<endl;
 for(int i=1;i<24;i++)     //for border
 {
  gotoxy(28+i,5);
  cout<<"-";
  gotoxy(28+i,10);
  cout<<"-";
 }
  for(int j=1;j<5;j++)      //for border
  {
   gotoxy(29,5+j);
   cout<<"|";
   gotoxy(51,5+j);
   cout<<"|";
  }
}

class reserver                      //CLASS DEFINTION FOR RESERVER
{
 public:  char name[20];
	  int person;
	  char time[4];
	  reserver()
	  {
	   strcpy(name,"null");
	   person=0;
	   strcpy(time,"null");
	  }
	  void input()
	  {
	   cout<<"Name of Reserver:";
	   gets(name);
	   cout<<"Table for:";
	   cin>>person;
	   cout<<"Time:";
	   gets(time);
	  }
};

void view_reservations()         //to view all reservations
{
 clrscr();
 reserver r;
 gotoxy(36,1);
 cout<<"90's Cafe"<<endl;
 gotoxy(30,4);
 cout<<"--RESERVATION LIST--";
 gotoxy(1,5);
 line();
 cout<<setw(15)<<"S.No"<<setw(10)<<"Name"<<setw(30)<<"Person"<<setw(15)<<"Time"<<endl;
 line();
 int n=1,row=1;
 ifstream infile;
 infile.open("reservations.txt",ios::in);
 while(!infile.eof())
 {
  infile.read((char*)&r,sizeof(r));
  if(infile.eof()==0)
  {
   gotoxy(13,7+row);
   cout<<n;
   gotoxy(22,7+row);
   cout<<r.name;
   gotoxy(52,7+row);
   cout<<r.person;
   gotoxy(67,7+row);
   cout<<r.time;
   gotoxy(71,7+row);
   for(int i=1;i<=10;i++)
   cout<<' ';
   row++;
   n++;
  }
 }

getch();
}

void add_reservation()         //function to add reservations
{
 clrscr();
 gotoxy(36,1);
 cout<<"90's Cafe"<<endl;
 reserver r;
 ofstream ofile;
 ofile.open("reservations.txt",ios::app);
 gotoxy(1,4);
 cout<<"Name of Reserver to be added:";
 gets(r.name);
 cout<<"Table for:";
 cin>>r.person;
 cout<<"Time:";
 cin>>r.time;
 ofile.write((char*)&r,sizeof(r));
 ofile.close();
 cout<<"Reservation Added Succesfully."<<endl;
 getch();
}

void del_reservation()            //to delete reservation
{
 clrscr();
 reserver r;
 gotoxy(36,1);
 cout<<"90's Cafe"<<endl;
 char name_del[20];
 char found='f',confirm='n';
 gotoxy(1,3);
 cout<<"Name of reserver to be deleted:";
 gets(name_del);

 ifstream infile;
 ofstream ofile;
 ofile.open("temp.txt");
 infile.open("reservations.txt",ios::in);
 while(!infile.eof())
 {
  infile.read((char*)&r,sizeof(r));
  if(strcmpi(name_del,r.name)==0)
  {
   found='t';
   cout<<r.name;
   cout<<endl;
   cout<<r.person;
   cout<<endl;
   cout<<"Are you sure, you want to delete this reservation?(y/n)";
   cin>>confirm;
   if(confirm=='y'||confirm=='Y')
   {
    cout<<"Reservation Deleted Successfully.";
    break;
   }
   if(confirm=='n'||confirm=='N')
   {
    ofile.write((char*)&r,sizeof(r));
    cout<<"Reservation Deletion Cancelled";
    break;
   }
  }
  else
   ofile.write((char*)&r,sizeof(r));
 }
 if(found=='f')
 cout<<"Reservation not found!!"<<endl;
 infile.close();
 ofile.close();
 remove("reservations.txt");
 rename("temp.txt","reservations.txt");
 getch();

}

class ingredient                    //class defintion for ingredient
{
 public: char name[20];
	 int quantity;
	 char unit[5];
	 char status[6];
	 ingredient()
	 {
	  strcpy(name,"null");
	  quantity=0;
	  strcpy(unit,"null");
	  strcpy(status,"null");
	 }
	 void input()
	 {
	  cout<<"Name of ingredient:";
	  gets(name);
	  cout<<"Quantity:";
	  cin>>quantity;
	  cout<<"Unit:";
	  gets(unit);
	  cout<<"Status:";
	  gets(status);
	 }
};


void inventory_menu()                  //INVENTORY  MENU
{
 clrscr();
 gotoxy(36,1);
 cout<<"90's Cafe"<<endl;
 gotoxy(30,4);
 cout<<"--INVENTORY MENU--";
 gotoxy(31,6);
 cout<<"1.View Inventory";
 gotoxy(31,7);
 cout<<"2.Add Ingredient"<<endl;
 gotoxy(31,8);
 cout<<"3.Update Ingredient"<<endl;
 gotoxy(31,9);
 cout<<"4.Main Menu"<<endl;
 for(int i=1;i<21;i++)     //for border
 {
  gotoxy(29+i,5);
  cout<<"-";
  gotoxy(29+i,10);
  cout<<"-";
 }
 for(int j=1;j<5;j++)      //for border
 {
  gotoxy(29,5+j);
  cout<<"|";
  gotoxy(50,5+j);
  cout<<"|";
 }
}

void view_inventory()                  //to view all ingredients
{
 clrscr();
 ingredient ing;
 gotoxy(36,1);
 cout<<"90's Cafe"<<endl;
 gotoxy(33,4);
 cout<<"--INVENTORY--";
 gotoxy(1,5);
 line();
 cout<<setw(5)<<"S.No"<<setw(10)<<"Name"<<setw(25)<<"Quantity"<<setw(12)<<"Unit"<<setw(20)<<"Status"<<endl;
 line();
 int n=1,row=1;
 ifstream infile;
 infile.open("ingredient.txt",ios::in);
 while(!infile.eof())
 {
  infile.read((char*)&ing,sizeof(ing));
  if(infile.eof()==0)
  {
   gotoxy(3,7+row);
   cout<<n;
   gotoxy(12,7+row);
   cout<<ing.name;
   gotoxy(35,7+row);
   cout<<ing.quantity;
   gotoxy(49,7+row);
   cout<<ing.unit;
   gotoxy(67,7+row);
   cout<<(ing.status);
   gotoxy(73,7+row);
   for(int i=1;i<=5;i++)
   cout<<' ';
   row++;
   n++;
  }
 }

getch();
}

void add_ingredient()                    //to add ingredient
{
 clrscr();
 gotoxy(36,1);
 cout<<"90's Cafe"<<endl;
 ingredient ing;
 ofstream ofile;
 ofile.open("ingredient.txt",ios::app);
 gotoxy(1,4);
 cout<<"Name of ingredient to be added:";
 gets(ing.name);
 cout<<"Quantity:";
 cin>>ing.quantity;
 cout<<"Unit:";
 gets(ing.unit);
 cout<<"Status:";
 gets(ing.status);
 ofile.write((char*)&ing,sizeof(ing));
 ofile.close();
 cout<<"Ingredient Added Succesfully."<<endl;
 getch();
}

void upd_ingredient()                     //to update ingredient
{
 clrscr();
 ingredient ing;
 gotoxy(36,1);
 cout<<"90's Cafe"<<endl;
 char name_upd[20];
 int quantity_upd;
 char status_upd[6];
 char found='f',confirm='n';
 gotoxy(1,3);
 cout<<"Name of item to be updated:";
 gets(name_upd);

 ifstream infile;
 ofstream ofile;
 ofile.open("temp.txt");
 infile.open("ingredient.txt",ios::in);
 while(!infile.eof())
 {
  infile.read((char*)&ing,sizeof(ing));
  if(strcmpi(name_upd,ing.name)==0)
  {
   found='t';
   cout<<ing.name;
   cout<<endl;
   cout<<ing.quantity;
   cout<<endl;
   cout<<ing.status;
   cout<<endl;
   cout<<"Updated Quantity:";
   cin>>quantity_upd;

   cout<<endl;
   cout<<"Updated Status:";
   gets(status_upd);
   cout<<endl;
   cout<<"Are you sure, you want to update this ingredient?(y/n)";
   cin>>confirm;
   if(confirm=='y'||confirm=='Y')
   {
    cout<<"Ingredient Updated Successfully.";
    ing.quantity=quantity_upd;
    strcpy(ing.status,status_upd);
    ofile.write((char*)&ing,sizeof(ing));
    if(confirm=='n'||confirm=='N')
    ofile.write((char*)&ing,sizeof(ing));
   }
   else
    {
     ofile.write((char*)&ing,sizeof(ing));
     cout<<"Ingredient Updation Cancelled.";
    }
  }
  else
  ofile.write((char*)&ing,sizeof(ing));

}
 if(found=='f')
 cout<<"Ingredient not found!!"<<endl;
 infile.close();
 ofile.close();
 remove("ingredient.txt");
 rename("temp.txt","ingredient.txt");
 getch();

}

void payroll_menu()                 //PAYROLL MENU
{
 clrscr();
 gotoxy(36,1);
 cout<<"90's Cafe"<<endl;
 gotoxy(32,4);
 cout<<"--PAYROLL MENU--";
 gotoxy(31,6);
 cout<<"1.View Payroll";
 gotoxy(31,7);
 cout<<"2.View Employee";
 gotoxy(31,8);
 cout<<"3.Add Employee"<<endl;
 gotoxy(31,9);
 cout<<"4.Delete Employee"<<endl;
 gotoxy(31,10);
 cout<<"5.Main Menu"<<endl;
 for(int i=1;i<24;i++)     //for border
 {
  gotoxy(28+i,5);
  cout<<"-";
  gotoxy(28+i,11);
  cout<<"-";
 }
 for(int j=1;j<6;j++)      //for border
 {
  gotoxy(29,5+j);
  cout<<"|";
  gotoxy(51,5+j);
  cout<<"|";
 }
}

struct contract_remaining              //part of class employee
{
 int years;
 int months;
 int days;
};
class employee                         //class defintion for employee
{
 public: char name[30];
	 char designation[15];
	 char phone[15];
	 char address[30];
	 char initial[3];
	 long salary;
	 contract_remaining cr;
	 employee()
	 {
	  strcpy(name,"null");
	  strcpy(designation,"null");
	  strcpy(phone,"null");
	  strcpy(address,"null");
	  strcpy(initial,"N");
	  salary=0;
	  cr.years=cr.months=cr.days=0;
	 }
	 void input()
	 {
	  cout<<"Name of Employee:";
	  gets(name);
	  cout<<"Designation:";
	  gets(designation);
	  cout<<"Phone no.:";
	  gets(phone);
	  cout<<"Address:";
	  gets(address);
	  cout<<"Initial:";
	  gets(initial);
	  cout<<"Salary:";
	  cin>>salary;
	  cout<<"Contract Remaining:"<<endl;
	  cout<<"Years:";
	  cin>>cr.years;
	  cout<<"Months:";
	  cin>>cr.months;
	  cout<<"Days:";
	  cin>>cr.days;
	 }

};

void view_payroll()          //to view payroll
{
 clrscr();
 employee emp;
 gotoxy(36,1);
 cout<<"90's Cafe"<<endl;
 gotoxy(35,4);
 cout<<"--PAYROLL--";
 gotoxy(1,5);
 line();
 cout<<setw(5)<<"S.No"<<setw(10)<<"Name"<<setw(25)<<"Designation"<<setw(12)<<"Salary"<<setw(24)<<"Contract Remaining"<<endl;
 line();
 int n=1,row=1;
 ifstream infile;
 infile.open("payroll.txt",ios::in);
 while(!infile.eof())
 {
  infile.read((char*)&emp,sizeof(emp));
  if(infile.eof()==0)
  {
   gotoxy(3,7+row);
   cout<<n;
   gotoxy(12,7+row);
   cout<<emp.name;
   gotoxy(30,7+row);
   cout<<emp.designation;
   gotoxy(47,7+row);
   cout<<emp.salary;
   gotoxy(61,7+row);
   cout<<emp.cr.years<<"-Y "<<emp.cr.months<<"-M "<<emp.cr.days<<"-D ";
   gotoxy(75,7+row);
   for(int i=1;i<=5;i++)
   cout<<' ';
   row++;
   n++;
  }
 }

getch();
}

void view_emp()              // to view employee details
{
 clrscr();
 gotoxy(36,1);
 cout<<"90's Cafe"<<endl;
 gotoxy(1,4);
 char in[3];
 cout<<"Enter initial of Employee to be viewed:";
 gets(in);
 employee emp;
 ifstream infile;
 infile.open("payroll.txt",ios::in);
 char found='f';
 while(!infile.eof())
 {
  infile.read((char*)&emp,sizeof(emp));
  if(strcmpi(in,emp.initial)==0)
  {
   found='t';
   if(!infile.eof())
   {
    cout<<endl;
    cout<<"Name of Employee:"<<emp.name<<endl;
    cout<<"Designation:"<<emp.designation<<endl;
    cout<<"Phone no.:"<<emp.phone<<endl;
    cout<<"Address:"<<emp.address<<endl;
    cout<<"Initial:"<<emp.initial<<endl;
    cout<<"Salary:"<<emp.salary<<endl;
    cout<<"Contract Remaining: "<<emp.cr.years<<" Years "<<emp.cr.months<<" Months "<<emp.cr.days<<" Days "<<endl;
   }
  }
 }
 if(found=='f')
 cout<<"No such Employee Found.!!"<<endl;
 infile.close();
getch();

}

void add_employee()          //to add employee
{
 clrscr();
 gotoxy(36,1);
 cout<<"90's Cafe"<<endl;
 employee emp;
 ofstream ofile;
 ofile.open("payroll.txt",ios::app);
 gotoxy(1,4);
 cout<<"Name of Employee to be added:";
 gets(emp.name);
	  cout<<"Designation:";
	  gets(emp.designation);
	  cout<<"Phone no.:";
	  gets(emp.phone);
	  cout<<"Address:";
	  gets(emp.address);
	  cout<<"Initial:";
	  gets(emp.initial);
	  cout<<"Salary:";
	  cin>>emp.salary;
	  cout<<"Contract Remaining:"<<endl;
	  cout<<"Years:";
	  cin>>emp.cr.years;
	  cout<<"Months:";
	  cin>>emp.cr.months;
	  cout<<"Days:";
	  cin>>emp.cr.days;
 ofile.write((char*)&emp,sizeof(emp));
 ofile.close();
 cout<<"Employee Added Succesfully."<<endl;
 getch();
}

void del_employee()           //to delete employee
{
 clrscr();
 employee emp;
 gotoxy(36,1);
 cout<<"90's Cafe"<<endl;
 char initial_del[3];
 char found='f',confirm='n';
 gotoxy(1,3);
 cout<<"Initial of Employee to be deleted:";
 gets(initial_del);

 ifstream infile;
 ofstream ofile;
 ofile.open("temp.txt");
 infile.open("payroll.txt",ios::in);
 while(!infile.eof())
 {
  infile.read((char*)&emp,sizeof(emp));
  if(strcmpi(initial_del,emp.initial)==0)
  {
   found='t';
   cout<<emp.name;
   cout<<endl;
   cout<<emp.designation;
   cout<<endl;
   cout<<"Are you sure, you want to delete this Employee?(y/n)";
   cin>>confirm;
   if(confirm=='y'||confirm=='Y')
   {
    cout<<"Employee Deleted Successfully.";
    break;
   }
   if(confirm=='n'||confirm=='N')
   {
    ofile.write((char*)&emp,sizeof(emp));
    cout<<"Employee Deletion Cancelled.";
    break;
   }
  }
  else
   ofile.write((char*)&emp,sizeof(emp));
 }
 if(found=='f')
 cout<<"Employee not found!!"<<endl;
 infile.close();
 ofile.close();
 remove("payroll.txt");
 rename("temp.txt","payroll.txt");
 getch();

}



void main()                          //MAIN FUNCTION
{
 clrscr();

  start:                            // start:
  menu();
   char choice_main;
   gotoxy(30,14);
   cout<<"Enter Choice(1-5):";
   gotoxy(48,14);
   for(int i=1;i<40;i++)
   cout<<" ";
   gotoxy(48,14);
   cin>>choice_main;
      if(choice_main!='1'&&choice_main!='2'&&choice_main!='3'&&choice_main!='4'&&choice_main!='5')
      {
	gotoxy(30,15);
	cout<<"!Invalid choice";
	goto start;
      }
      if(choice_main=='1')            //  main choice item started
      {
	start_item:             //start_item:
	item_menu();

	char choice_item;
	gotoxy(30,14);
	cout<<"Enter Choice(1-4):";
	gotoxy(48,14);
	for(int i=1;i<40;i++)
	cout<<" ";
	gotoxy(48,14);
	cin>>choice_item;
	if(choice_item!='1'&&choice_item!='2'&&choice_item!='3'&&choice_item!='4')
	{
	  gotoxy(30,15);
	  cout<<"!Invalid choice";
	  goto start_item;
	 }
	if(choice_item=='1')
	{
	 view_items();
	 getch();
	 goto start_item;
	}
	if(choice_item=='2')
	{
	 add_item();
	 goto start_item;
	}
	if(choice_item=='3')
	{
	 del_item();
	 goto start_item;
	}
	if(choice_item=='4')
	 goto start;

       }                           //main choice item ended
      if(choice_main=='2')             //main choice reservation started
      {
	start_rsrv:              //start_rsrv
	reservation_menu();
	  char choice_rsrv;
	  gotoxy(30,14);
	  cout<<"Enter Choice(1-4):";
	  gotoxy(48,14);
	  for(int i=1;i<40;i++)
	  cout<<" ";
	  gotoxy(48,14);
	  cin>>choice_rsrv;
	  if(choice_rsrv!='1'&&choice_rsrv!='2'&&choice_rsrv!='3'&&choice_rsrv!='4')
	  {
	    gotoxy(30,15);
	    cout<<"!Invalid choice";
	    goto start_rsrv;
	  }
	  if(choice_rsrv=='1')
	  {
	   view_reservations();
	   goto start_rsrv;
	  }
	  if(choice_rsrv=='2')
	  {
	   add_reservation();
	   goto start_rsrv;
	  }
	  if(choice_rsrv=='3')
	  {
	   del_reservation();
	   goto start_rsrv;
	  }
	  if(choice_rsrv=='4')
	   goto start;
      }                           //main choice reservation ended
      if(choice_main=='3')        //main choice inventory started
      {
       start_inv:                 //start_inv:
       inventory_menu();
       char choice_inv;
       gotoxy(30,14);
       cout<<"Enter Choice(1-4):";
       gotoxy(48,14);
       for(int i=1;i<40;i++)
       cout<<" ";
       gotoxy(48,14);
       cin>>choice_inv;
       if(choice_inv!='1'&&choice_inv!='2'&&choice_inv!='3'&&choice_inv!='4')
       {
	gotoxy(30,15);
	cout<<"!Invalid choice";
	goto start_inv;
       }
       if(choice_inv=='1')
       {
	view_inventory();
	goto start_inv;
       }
       if(choice_inv=='2')
       {
	add_ingredient();
	goto start_inv;
       }
       if(choice_inv=='3')
       {
	upd_ingredient();
	goto start_inv;
       }
       if(choice_inv=='4')
	goto start;
      }                    //main choice inventory ended
      if(choice_main=='4') //main choice payroll started
      {
       start_payroll:      //start_payroll:
       payroll_menu();
       char choice_pay;
       gotoxy(30,14);
       cout<<"Enter Choice(1-5):";
       gotoxy(48,14);
       for(int i=1;i<40;i++)
       cout<<" ";
       gotoxy(48,14);
       cin>>choice_pay;
       if(choice_pay!='1'&&choice_pay!='2'&&choice_pay!='3'&&choice_pay!='4'&&choice_pay!='5')
       {
	gotoxy(30,15);
	cout<<"!Invalid choice";
	goto start_payroll;
       }
       if(choice_pay=='1')
       {
	 view_payroll();
	 goto start_payroll;
       }
       if(choice_pay=='2')
       {
	view_emp();
	 goto start_payroll;
       }
       if(choice_pay=='3')
       {
	add_employee();
	goto start_payroll;
       }
       if(choice_pay=='4')
       {
	del_employee();
	goto start_payroll;
       }
       if(choice_pay=='5')
	goto start;
      }                //main choice payroll ended
      if(choice_main=='5')
      exit(0);
}                        //main function ended
