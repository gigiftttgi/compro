#include<iostream>
#include<string>
#include<fstream>
#include<cctype>
#include<conio.h>
#include<cmath>
using namespace std;

void book_seat(string);
void home();
void admin();
void op_admin();
void user();
void list(int);
void book_seat(string);
void filebooklist(int);
void bill();

string st[3] = {"11:00 - 13:00 | 14:30 - 16:30 | 18:30 - 20:30","11:30 - 13:30 | 15:00 - 17:00 | 19:00 - 21:00","12:00 - 14:00 | 15:30 - 17:30 | 19:30 - 21:30"};
string booklist[4],book;
string movie[3];
int ch_movie,ch_time,num,mt;

int main()
{
	home();
	return 0;
}

void home(){
	int op;
	bool c_op = false;
	do{
		cout << "\n\t***Welcome to Theater***\n";
		cout << "1. for User\n";
		cout << "2. for Admin\n";
		cout << "0. for Exit\n";
		cout << "Select option :  ";
		cin >> op;
		switch(op){
			case 1 : user();
					 c_op = true;
					 break;
			case 2 : admin();
					 c_op = true; 
					 break;
			case 0 : c_op = true; 
					 break;
			default : cout << "\nPlease select again\n\n";
					  break;
	}
	}while(c_op == false);
}

void admin(){
	string keypass = "1";
	string pass = "";
	char passch;
	bool c_pass = false;
	int count = 0;
	do{
		cout << "\nEnter passcode : ";
		passch = getch();
		while(passch != 13){
      		pass.push_back(passch);
      		cout << '*';
      		passch = getch();
   		}
		if(pass == keypass){
			c_pass = true;
		}
		else{
			cout << "\nWrong passcode!!!\n" ;
			if(count >= 4){
				cout<< "System lock!!! Please wait and try again\n";
				home();
			}
			cout<< "Please enter again.\n";
			count++;
		}
	}while(c_pass==false);
	
	op_admin();
}

void op_admin()
{
	int aop;
	bool c_aop = false;
	do{
		cout << "\n< Admin menu >\n";
		cout << "1. Add movie\n";
		cout << "2. Change movie\n";
		cout << "3. Check movie\n";
		cout << "4. Check valiable seat\n";
		cout << "0. Exit to home\n";
		cout << "Enter option : ";
		cin >> aop;
		switch(aop){
			case 0 : home();
					 c_aop = true;
					 break;
			case 1 : list(1);
					 c_aop = true;
					 break;
			case 2 : list(2);
			         c_aop = true;
					 break;
			case 3 : list(3);
			   	     c_aop = true;
					 break;
			case 4 : list(4);
			   	     c_aop = true;
					 break;
			default : cout << "Please enter again.\n";
					  break;
		}
	}while(c_aop == false);		
}


void list(int l){
	string *m = &movie[0];
	cin.ignore();
	if(l==1)
	{
		cout << "\n< Adding Movie >\n";
		for(int i=0;i<3;i++)
		{
			cout << "Enter movie (Theater " << i+1 << ") : ";
			getline(cin,movie[i]);
		}
		op_admin();
	}
	else if(l==2)
	{
		int th;
		string n_mo;
		cout << "\n< Changing Movie >\n";
		cout << "Enter theater that you want to change : ";
		cin >> th;
		cin.ignore();
		cout << "Enter new movie : ";
		getline(cin,n_mo);
		*(m+th-1) = n_mo;
		cout << "Change already.\n\n";
		op_admin();	
	}
	else if(l==3)
	{
		cout << "\n< Show time >\n";
		for(int i=0;i<3;i++)
		{
			cout << "Theater " << i+1 << " : " << movie[i] << "\n";
			cout << "Time\n" << st[i] << "\n";
		}
		cout << "\n";
		op_admin();
	}
	else
	{
		cout << "Func check";
	}
}

void user(){
	cout << "\n\t***Cinema Show time***\n";
	for(int i=0;i<3;i++)
	{
		cout << "Theater " << i+1 << " : " << movie[i] << "\n";
		cout << "Time   " << st[i] << "\n";
	}
	cout << "Choose movie (1-3) : ";
	cin >> ch_movie;
	cout << "Choose Time (1-3) : ";
	cin >> ch_time;
	mt = pow(ch_movie,2)+ch_time;
	cin.ignore();
	cout << "Choose seat : ";
	getline(cin,book);
	book_seat(book);
}

void book_seat(string bk)
{
    int start = 0;
    int end = bk.find_first_of(" ");
	num = (bk.size()/3)+1;
    while(end != -1)
    {
        for(int i=0;i<bk.size()/3;i++)
        {
            booklist[i] = bk.substr(start,end-start);
            start = end+1;
            end = bk.find_first_of(" ",start);
        }
    }
    booklist[num-1] = bk.substr(start,bk.size()-start);   
	filebooklist(mt); 
}

void filebooklist(int mt)
{
	fstream source;
	switch(mt)
	{
		case 2 : 
				 source.open("Booklist_m1t1.txt", ios::app); 
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << "\n";
				 } 
				 source.close();
				 bill();
				 break;
		case 3 : 
				 source.open("Booklist_m1t2.txt", ios::app); 
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << "\n";
				 } 
				 source.close();
				 bill();
				 break;
		case 4 : 
				 source.open("Booklist_m1t3.txt", ios::app); 
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << "\n";
				 } 
				 source.close();
				 bill();
				 break;
		case 5 : 
				 source.open("Booklist_m2t1.txt", ios::app); 
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << "\n";
				 } 
				 source.close();
				 bill();
				 break;
		case 6 : 
				 source.open("Booklist_m2t2.txt", ios::app); 
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << "\n";
				 } 
				 source.close();
				 bill();
				 break;
		case 7 : 
				 source.open("Booklist_m2t3.txt", ios::app); 
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << "\n";
				 } 
				 source.close();
				 bill();
				 break;
		case 10 : 
				 source.open("Booklist_m3t1.txt", ios::app); 
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << "\n";
				 } 
				 source.close();
				 bill();
				 break;
		case 11 : 
				 source.open("Booklist_m3t2.txt", ios::app); 
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << "\n";
				 } 
				 source.close();
				 bill();
				 break;
		case 12 : 
				 source.open("Booklist_m3t3.txt", ios::app); 
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << "\n";
				 } 
				 source.close();
				 bill();
				 break;
	}	
}

void bill()
{
	string name;
	cout << "Enter name : ";
	getline(cin,name);
	cout << "Seat : ";
	for(int i=0;i<num;i++)
	cout << booklist[i] << " ";
	fstream source;
	switch(mt)
	{
		case 2 : 
				 source.open("Bill_m1t1.txt", ios::app); 
				 source << "Name : " << name << "\n";
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << " ";
				 } 
				 source.close();
				 home();
				 break;
		case 3 : 
				 source.open("Bill_m1t2.txt", ios::app); 
				 source << "Name : " << name << "\n";
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << " ";
				 } 
				 source.close();
				 home();
				 break;
		case 4 : 
				 source.open("Bill_m1t3.txt", ios::app); 
				 source << "Name : " << name << "\n";
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << " ";
				 } 
				 source.close();
				 home();
				 break;
		case 5 : 
				 source.open("Bill_m2t1.txt", ios::app); 
				 source << "Name : " << name << "\n";
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << " ";
				 } 
				 source.close();
				 home();
				 break;
		case 6 : 
				 source.open("bill_m2t2.txt", ios::app); 
				 source << "Name : " << name << "\n";
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << " ";
				 } 
				 source.close();
				 home();
				 break;
		case 7 : 
				 source.open("Bill_m2t3.txt", ios::app); 
				 source << "Name : " << name << "\n";
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << " ";
				 } 
				 source.close();
				 home();
				 break;
		case 10 : 
				 source.open("Bill_m3t1.txt", ios::app); 
				 source << "Name : " << name << "\n";
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << " ";
				 } 
				 source.close();
				 home();
				 break;
		case 11 : 
				 source.open("Bill_m3t2.txt", ios::app); 
				 source << "Name : " << name << "\n";
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << " ";
				 } 
				 source.close();
				 home();
				 break;
		case 12 : 
				 source.open("Bill_m3t3.txt", ios::app); 
				 source << "Name : " << name << "\n";
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << " ";
				 } 
				 source.close();
				 home();
				 break;
	}	
	home();
}



