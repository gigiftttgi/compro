#include<iostream>
#include<string>
#include<fstream>
#include<cctype>
#include<conio.h>
#include<cmath>
#include<iomanip>
#include<vector>
#include<cstring>
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

void read_seat(int );
void update_seat(int );
void clear_seat(int );
void show_seat();

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
	// function show_seat here
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
				 source.open("D:\\Desktop\\code\\project - movie\\compro\\Booklist_m1t1.txt", ios::app); 
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
				 read_seat(mt);
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

void read_seat(int mt){
    //open Booklist file and read the data
    fstream source;
    // mt varible is important here
    source.open("D:\\Desktop\\code\\project - movie\\compro\\Booklist_m1t1.txt");
    string textline;
    char char_row[2];
    int i = 0, N = 0;
    int col[28] = {};
    int row[28] = {};
    // read the data and covert to row,col to book the seat
    while(getline(source,textline)){
        if(i%2 == 0) {
            strcpy(char_row,textline.c_str());
            if(char_row[0] == 'E') row[i] = 0;
            if(char_row[0] == 'D') row[i] = 1;
            if(char_row[0] == 'C') row[i] = 2;
            if(char_row[0] == 'B') row[i] = 3;
            if(char_row[0] == 'A') row[i] = 4;
        }
        else col[i-1] = stoi(textline);
        i++;
    }
    source.close();

    // update data one by one
    int position;
    for(int j = 0; j<i; j+=2){
        //switch seat array from 2 dimension to 1 dimension
        position = row[j]*6-1+col[j];
        update_seat(position);
    }

    show_seat();
}

void update_seat(int position){
    // open seat file
    ifstream source("D:\\Desktop\\code\\project - movie\\compro\\seat_m1t1.txt");
    string textline;
    int new_seat[28];
    int i = 0;
    // update the seat into new_seat
    while(getline(source,textline)){
        if(i == position){
            new_seat[i] = 1;
        }
        else{
            new_seat[i] = stoi(textline);
        }
        i++;
    }
    source.close();

    // push all new data into the same file
    ofstream copy_source("D:\\Desktop\\code\\project - movie\\compro\\seat_m1t1.txt");
    for(int j = 0; j<i; j++){
        copy_source << new_seat[j] << endl;
    }
    copy_source.close();

}

void clear_seat(int mt){
    //this function for admin when they update the movie and seat need to be clear
    ofstream copy_source("D:\\Desktop\\code\\project - movie\\compro\\seat_m1t1.txt");
    for(int j = 0; j<28; j++){
        copy_source << "0" << endl;
    }
    copy_source.close();
    ofstream Booklist("D:\\Desktop\\code\\project - movie\\compro\\Booklist_m1t1.txt");
    Booklist.clear();
    show_seat();
}

void show_seat(){
    //open the seat data
    ifstream source("D:\\Desktop\\code\\project - movie\\compro\\seat_m1t1.txt");
    string textline;
    int new_seat[28];
    int i = 0,n=4;
    while(getline(source,textline)){
        new_seat[i] = stoi(textline);
        i++;
    }
    source.close();

    char row[5] = {'A','B','C','D','E'};

    cout<<setw(25)<<"-----------------------------------------\n";
    cout<<setw(25)<<"|SCREEN|\n";

    //display normal row E-B 
    //varible n to display E D C B can change anytime when theater got bigger
    //condition of k can calculate with number of each row's seat -1 * number of row // in this case is 4*7

    for(int k = 0; k<28; k = k+7){
        cout<<row[n]<<"\t";
        for(int j = 0+k; j<7+k; j++){
            if(j<3+k){
                if(new_seat[j] == 0) cout<<setw(2)<<"| |"<<" ";
                else if(new_seat[j] == 1) cout<<setw(2)<<"|X|"<<" ";
            }
            else if(j > 3+k){
                if(new_seat[j-1] == 0) cout<<setw(2)<<"| |"<<" ";
                else if(new_seat[j-1] == 1) cout<<setw(2)<<"|X|"<<" ";
            }
            else cout<<"\t";
        }
        n--;
        cout<<"\n";
    }

    
    //display sofa row A
    //the bug is seat C6 (position == 17) is not working
    
    cout<<setw(28)<<"- SOFA seat -\n";
    cout<<"A\t";
    for(int j = 23; j<29; j++){
        if(j == 23) cout<<setw(2)<<" ";
        else if(j < 26) {
            if(new_seat[j] == 0) cout<<setw(2)<<"| |"<<" ";
            else if(new_seat[j] == 1) cout<<setw(2)<<"|X|"<<" ";
        }
        else if(j > 26){
            if(new_seat[j-1] == 0) cout<<setw(2)<<"| |"<<" ";
            else if(new_seat[j-1] == 1) cout<<setw(2)<<"|X|"<<" ";
        }
        else cout<<"\t";
    }
}
