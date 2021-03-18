#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<cctype>
#include<conio.h>
#include<cmath>
#include<iomanip>
#include<vector>
#include "windows.h"
using namespace std;

void book_seat(string);
void home();
void admin();
void op_admin();
void user();
void list(int);
void filebooklist(char,int,int);
//void bill(int,char *,int *);
void update_seat(int,int);
void show_seat(int);
void valiable_seat(int);
void member(bool &ck_member,string &);
void checkmem(string,bool &,string &);
void ppl_seat(int);
void promotion(int);
void cost_ticket(int,char *,int *);
int read_seat(char , int);
bool check_seat(int , int );
bool cancel_reserve(int, int);
void edit_booklist(int , char , int );
void reset_seat(int );
int choose_movie_and_time();
char getrow();
int getseatnum(char );
string rand_id();

//add
string discount;
string st[3] = {"11:00 - 13:00 | 14:30 - 16:30 | 18:30 - 20:30","11:30 - 13:30 | 15:00 - 17:00 | 19:00 - 21:00","12:00 - 14:00 | 15:30 - 17:30 | 19:30 - 21:30"};
string booklist[100],book;
string movie[3];
string name;
string name_mem;
int new_seat[28];
int seatnum[4];
char row[4];
int ch_movie,ch_time,numofseat=0,mt;
string string_numofseat,string_ch_time,string_ch_movie,string_seatnum;
bool ck_member = false;
int cost = 0;

int main()
{
	HWND console = GetConsoleWindow();
  	RECT ConsoleRect;
  	GetWindowRect(console, &ConsoleRect); 

   	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 600, 600, TRUE);
	home();
	return 0;
}


void home()
{
	string op;
	bool c_op = false;
	bool be_mem = false;
	bool a_member = false;
	do{
		cout << "\n\n\n\n\n";
		cout << setw(43) <<"--------------------------"<<endl;
		cout << setw(45) << "| ***Welcome to Theater*** |\n";
		cout << setw(43) <<"--------------------------"<<endl;
		cout << "\n";
		cout << setw(30) << "\t1. for User\n";
		cout << setw(30) << "\t2. for Admin\n";
		cout << setw(30) << "\t0. for Exit\n";
		cout << setw(30) << "\t\tSelect option :  ";
		cin >> op;
		if(op=="1")
        {
            string key;
					 do
					 {
						 cout <<"\n\t----------------------------------------------------\n";
						 cout << "\t\tAre you a member? (Y/N) : ";
					 	 cin >> key;
					 	 if(key == "y" || key == "Y")
					 	 {
						 	do{
								 string ch_id;
								 cout << "\t\tEnter member id (0 to exit): ";
						 	 	 cin >> ch_id;
						 	 	 checkmem(ch_id,ck_member,name_mem);
								 if(ck_member==false)
								 {
                                     if(ch_id=="0")
                                     {
                                         ck_member=true;
                                     }
                                     else
                                        cout << "\t\tWrong id!!\n";
								 }
								 else
								 {
							 	 cout<<endl;
						 	 	 cout << "\t\t\t**Welcome K." << name_mem << " **";
						 	 	 user();
							 	 a_member = true;
								 }
							  }while(ck_member==false);
					 	 }
					 	 else if(key == "N" || key == "n")
					 	 {
						  	 string key1;
							 do
							 {
								 
								 cout << "\t\tWould you like to become a member? (Y/N) : ";
						 	 	 cin >> key1;
						 	 	 if(key1 == "y" || key1 == "Y")
					 	 	 	 {
							  	 	 member(ck_member,name_mem);
									 cout<<endl;
							 	 	 cout << "\t\t**Welcom K." << name_mem << " **";
							 	 	 user();
									 be_mem=true;
					 	 	 	 }
						 	 	 else if(key1 == "N" || key1 == "n")
						 	     {
							 	 	 user();
									 be_mem=true;
						 	 	 }
							 	 else 
								 {
									 cout << "\t\t Please enter y/n \n";
								 }
							 }while(be_mem==false);
							 a_member = true;
					 	 }
						 else
						 {
							cout << "\t\t Please enter y/n ";

						 }
					 }while(a_member == false);
					 c_op = true;
        }
		else if(op=="2")
        {
            admin();
			c_op = true; 
        }
		else if(op=="0")
        {
            c_op = true; 
        }
        else
		{
			cout<<endl;
			cout << "\n\t\tPlease select again\n\n";
		}
	}while(c_op == false);
}

void admin(){
	string keypass = "1";
	string pass = "";
	char passch;
	bool c_pass = false;
	int count = 0;
	
	cout <<"\n\t----------------------------------------------------";

    while(c_pass==false){
        pass="";
	    cout << "\n\t\tEnter passcode : ";
	    passch = getch();

	    while(passch != 13){
      	    pass.push_back(passch);
      	    cout << '*';
      	    passch = getch();
   	    }
		
	    if(pass == keypass){
		    c_pass = true;
            op_admin();
	    }else{
            count++;
			cout << "\nWrong passcode!!!\n" ;
			cout<< "Please enter again.\n";
			if(count >= 4){
				cout<< "System lock!!!";
				home();
            }
		}
        if(count >= 4){
			cout<< "System lock!!!";
			home();
		}
		
	}
}

void op_admin()
{
	string aop;
	bool c_aop = false;
	cout <<"\n\t----------------------------------------------------";
	cout << "\n\n\t\t|\t***Admin Menu***\t|\n";
	cout <<"\n\t----------------------------------------------------\n";
	do{
		cout << "\t1. Add movie"<<endl;
		cout << "\t2. Change movie"<<endl;
		cout << "\t3. Check movie"<<endl;
		cout << "\t4. Check valiable seat"<<endl;
		cout << "\t5. Cancel reservation"<<endl;
		cout << "\t6. Change discount"<<endl;
		cout << "\t7. Reset seat"<<endl;
		cout << "\t0. Exit to home"<<endl;
		cout << "\tEnter option : ";
		cin >> aop;
			if(aop == "0"){
				home();
				c_aop = true;	
			}else if(aop == "1"){
				list(1);
				c_aop = true;
			}else if(aop == "2"){
				list(2);
			    c_aop = true;
			}else if(aop == "3"){
				list(3);
			   	c_aop = true;
			}else if(aop == "4"){
				list(4);
			   	c_aop = true;
			}else if(aop == "5"){
				list(5);
			   	c_aop = true;
			}else if(aop == "6"){
				list(6);
				c_aop = true;
			}else if(aop == "7"){
				list(7);
				c_aop = true;
			}else cout << setw(30) << "\t\tPlease enter again.\n";
	}while(c_aop == false);		
}


void list(int l){
	string *m = &movie[0];
	cin.ignore();
	if(l==1)
	{
		cout << "\n\t\t< Adding Movie >\n";
		for(int i=0;i<3;i++)
		{
			cout << "\t\tEnter movie (Theater " << i+1 << ") : ";
			getline(cin,movie[i]);
		}
		op_admin();
	}
	else if(l==2)
	{
		int th;
		string n_mo;
		cout << "\n\t\t< Changing Movie >\n";
		cout << "\t\tEnter theater that you want to change : ";
		cin >> th;
		cin.ignore();
		cout << "\t\tEnter new movie : ";
		getline(cin,n_mo);
		*(m+th-1) = n_mo;
		cout << "\t\tChange already.\n\n";
		op_admin();	
	}
	else if(l==3)
	{
		cout << "\n\t\t< Show time >\n";
		for(int i=0;i<3;i++)
		{
			cout << "\t\tTheater " << i+1 << " : " << movie[i] << "\n";
			cout << "\t\tTime\n" << st[i] << "\n";
		}
		cout << "\n";
		op_admin();
	}
	else if(l==4)
	{
		cout << "\n\t\t< Check Valiable Seat >\n";
		
		mt = choose_movie_and_time();
		valiable_seat(mt);
	}
	else if(l==5){
		int ch_movie,ch_time,seatnum;
		char row,char_seatnum;
		cout << "\n\t\t< Cancel Reservation >\n";

		mt = choose_movie_and_time();
		show_seat(mt);

        row = getrow();
		char_seatnum = getseatnum(row);

		seatnum = char_seatnum - '0';
    	
		int position = read_seat(row,seatnum);
		bool cancel = cancel_reserve(mt,position);
	

		if(!cancel){
			cout<<"\t\tCancel Reservation Error.\n\t\tThis seat is still empty.";
			list(5);
		}
		else {
			edit_booklist(mt,row,seatnum);
			cout<<"\t\tCancel Reservation Completed.\n";
		}
		op_admin();
	}
	else if(l == 6){
			while(discount != "0"){
        		cout << "\t\tadd discount( 0 for exit) : ";
        		cin >> discount;
        		fstream source;
        		source.open("promotioncode.txt",ios::app);
        		source << discount << endl;
        		source.close();
    		}
		op_admin();
	}
	else if(l == 7){
		cout << "\n\t\t< Reset seat >\n";

		mt = choose_movie_and_time();

		reset_seat(mt);
		cout<<"\n";
		edit_booklist(mt,'0',0);
		op_admin();
	}
}

void edit_booklist(int mt, char input_row, int input_seatnum){

	ifstream source;
	string textline;

	vector<string> row;
    vector<int> seatnum;

    string rowstring(1,input_row);

	switch(mt){
		case 2 : source.open("Booklist_m1t1.txt"); break;
		case 3 : source.open("Booklist_m1t2.txt"); break;
		case 4 : source.open("Booklist_m1t3.txt"); break;
		case 5 : source.open("Booklist_m2t1.txt"); break;
		case 6 : source.open("Booklist_m2t2.txt"); break;
		case 7 : source.open("Booklist_m2t3.txt"); break;
		case 10 : source.open("Booklist_m3t1.txt"); break;
		case 11 : source.open("Booklist_m3t2.txt"); break;
		case 12 : source.open("Booklist_m3t3.txt"); break;
	}

	int i = 0, j = 0;

	while(getline(source,textline)){ 
		if(i%2 == 0){
            row.push_back(textline);
			i++;
        }
        else{
            seatnum.push_back(stoi(textline));
			i++;
			
        }
    }

	source.clear();
	source.close();

	ofstream new_source;

	switch(mt){
		case 2 : new_source.open("Booklist_m1t1.txt"); break;
		case 3 : new_source.open("Booklist_m1t2.txt"); break;
		case 4 : new_source.open("Booklist_m1t3.txt"); break;
		case 5 : new_source.open("Booklist_m2t1.txt"); break;
		case 6 : new_source.open("Booklist_m2t2.txt"); break;
		case 7 : new_source.open("Booklist_m2t3.txt"); break;
		case 10 : new_source.open("Booklist_m3t1.txt"); break;
		case 11 : new_source.open("Booklist_m3t2.txt"); break;
		case 12 : new_source.open("Booklist_m3t3.txt"); break;
	}

    if(input_row == '0' && input_seatnum == 0){
		new_source << " ";
		cout<<"\t\t*** Booklist clear. *** ";
	}else{
		while(j<row.size()){
        	if(row[j] == rowstring && seatnum[j] == input_seatnum){
				j++;
			}
			else{
				new_source << row[j] <<"\n";
				new_source << seatnum[j] <<"\n";
				j++;
			}
    	}
	}

    new_source.close();

}

bool cancel_reserve(int mt, int position){
	
	string textline;
    vector<int> new_seat(28);
	ifstream source;
	int i = 0;

    // open seat file
	switch(mt){
		case 2 : source.open("seat_m1t1.txt"); break;
		case 3 : source.open("seat_m1t2.txt"); break;
		case 4 : source.open("seat_m1t3.txt"); break;
		case 5 : source.open("seat_m2t1.txt"); break;
		case 6 : source.open("seat_m2t2.txt"); break;
		case 7 : source.open("seat_m2t3.txt"); break;
		case 10 : source.open("seat_m3t1.txt"); break;
		case 11 : source.open("seat_m3t2.txt"); break;
		case 12 : source.open("seat_m3t3.txt"); break;
	}

	while(getline(source,textline)){  
		new_seat[i] = stoi(textline);
		i++;
    }
	source.close();

	bool update = true;

	for(int i = 0; i<28; i++){
		if(new_seat[i] == 0 && i == position){
			update = false;
			break;
		}
		else if(new_seat[i] == 1 && i == position){
			new_seat.at(position) = 0;
			update = true;
		}
		else new_seat[i] = new_seat[i];
	}



	if(update){
		ofstream new_source;
		switch(mt){
			case 2 : new_source.open("seat_m1t1.txt"); break;
			case 3 : new_source.open("seat_m1t2.txt"); break;
			case 4 : new_source.open("seat_m1t3.txt"); break;
			case 5 : new_source.open("seat_m2t1.txt"); break;
			case 6 : new_source.open("seat_m2t2.txt"); break;
			case 7 : new_source.open("seat_m2t3.txt"); break;
			case 10 : new_source.open("seat_m3t1.txt"); break;
			case 11 : new_source.open("seat_m3t2.txt"); break;
			case 12 : new_source.open("seat_m3t3.txt"); break;
		}

		for(int j = 0; j<i; j++){
			new_source << new_seat[j] << endl;
		}
		source.close();
	}
	
	return update;
	
}

void valiable_seat(int mt){
	string s[60];
	string textline;
    string seat[30] = {"A1", "A2", "A3", "A4"," "," ","B1", "B2", "B3", "B4", "B5", "B6", "C1", "C2", "C3", "C4", "C5", "C6", "D1", "D2", "D3", "D4", "D5", "D6", "E1", "E2", "E3", "E4", "E5", "E6"};
	int k = 0;
	ifstream source;
	switch(mt){
        case 2 : cout << "Theater 1 :" << movie[1];
				cout << "\nTime : 1 | 11:00 - 13:00 |\n"; 
				source.open("Booklist_m1t1.txt"); break;
		case 3 : cout << "Theater 1 :" << movie[1];
				cout << "\nTime : 2 | 14:30 - 16:30 |\n"; 
				source.open("Booklist_m1t2.txt"); break;
		case 4 : cout << "Theater 1 :" << movie[1];
				cout << "\nTime : 3 | 18:30 - 20:30 |\n"; 
				source.open("Booklist_m1t3.txt"); break;
		case 5 : cout << "Theater 2 : " << movie[2];
				cout << "Time : 1 | 11:30 - 13:30 |\n"; 
				source.open("Booklist_m2t1.txt"); break;
		case 6 : cout << "Theater 2 : " << movie[2];
				cout << "Time : 2 | 15:00 - 17:00 |\n"; 
				source.open("Booklist_m2t2.txt"); break;
		case 7 : cout << "Theater 2 : " << movie[2];
				cout << "Time : 3 | 19:00 - 21:00 |\n"; 
				source.open("Booklist_m2t3.txt"); break;
		case 10 : cout << "Theater 3 : " << movie[3];
				cout << "Time : 1 | 12:00 - 14:00 |\n"; 
				source.open("Booklist_m3t1.txt"); break;
		case 11 : cout << "Theater 3 : " << movie[3];
				cout << "Time : 2 | 15:30 - 17:30 |\n"; 
				source.open("Booklist_m3t2.txt"); break;
		case 12 : cout << "Theater 3 : " << movie[3];
				cout << "Time : 3 | 19:30 - 21:30 |\n"; 
				source.open("Booklist_m3t3.txt"); break;
	}
	while(getline(source,textline)){
		s[k] = textline;
		k++;  
    }
	source.close();
	
    string out[28];
    int x=0;
	int y=0;	
    while(y < k){
        out[x] = s[y] + s[y+1];
       	y = y+2;
       	x++;    	
	}
    for(int i =0 ; i<30 ; i++){
        for(int j=0 ; j<x ; j++){
            if(out[j] == seat[i]){
                seat[i] = "--";
            }
        }
    }   
 	cout << "<Valiable Seats>";
    for(int i=0; i<30 ; i++){
		if(i%6 == 0){
			cout << endl ;
            cout << seat[i] << "  ";

		}else{
            cout << seat[i] << "  ";

		}
	}
	cout << "\nTotal : " << 28-x ;
	if(28-x >1){
		cout << " seats\n";
	}else{
		cout << "seat\n";
	}

	string opt;
	bool op = false;

	while(op==false){
		cout << "\nDo you want to check who belong to seat? (1.Yes | 2.No)\n";
		cout << "Enter option : ";
		cin >> opt;

		if(opt == "1"){
			op=true;
			ppl_seat(mt);
		}else if(opt == "2"){
			op=true; 
			op_admin();
		}else{
			cout << "Error. Please enter again.\n";
		}
	}
	   

}

void ppl_seat(int mt){
	ifstream source;
	string s;
	string textline;
	vector<string> names;
    vector<string> seat;

	switch(mt){
		case 2 : source.open("Bill_m1t1.txt"); break;
		case 3 : source.open("Bill_m1t2.txt"); break;
		case 4 : source.open("Bill_m1t3.txt"); break;
		case 5 : source.open("Bill_m2t1.txt"); break;
		case 6 : source.open("Bill_m2t2.txt"); break;
		case 7 : source.open("Bill_m2t3.txt"); break;
		case 10 : source.open("Bill_m3t1.txt"); break;
		case 11 : source.open("Bill_m3t2.txt"); break;
		case 12 : source.open("Bill_m3t3.txt"); break;
	}

	int N=0;
	while(getline(source,textline)){
		if(N%3==0 || N==0){

		}else if((N+2)%3==0 ){
			textline.erase(0,7);
			names.push_back(textline);
			
		}else{
			textline.erase(0,7);
			seat.push_back(textline);
		}

		N++;
    }

	source.close();
	
	string opt = "1";
	while(opt=="1"){
		cout << "\nPlease input seat you want: ";
		cin >> s;
		int found;
		int status = 0;
		for(unsigned int i = 0 ; i < seat.size() ; i++){
			found = seat[i].find(s);
        	if(found != -1){
				status = 1;
       			cout << s << " belongs to '" << names[i] << "'" << endl; break;
        	}
		}
		if(status==0) cout << "This seat hasn't bought yet.\n";

		bool op =false;
		
		do{
		cout << "\nDo you want to check it again? (1.Yes | 2.No)\n";
		cout << "Enter option : ";
		cin >> opt;
		if(opt=="1" || opt == "2") op=true;
		else cout << "Error. Please enter again.\n";
		}while(op==false);
	}
	op_admin();
}



void member(bool &ck_member,string &name_mem){
    string mem_id;
    int id[5];
	cin.ignore();
    cout << "\t\tEnter name : ";
    getline(cin,name_mem);
    cout << "\t\tsuscess\n";
	mem_id = rand_id();
    cout << "\t\tyour member id is " << mem_id;
    fstream source;
    source.open("member.txt" ,ios::app);
    source << mem_id;
    source << " " << name_mem << "\n";
    source.close();
	ck_member = true;
}

string rand_id()
{
    int id[5];
    string text,memid;
    string realid;
    bool use = false;
    do
    {
        //string realid;
        use = false;
        realid.clear();
        srand(time(0));
        for(int i=0;i<5;i++)
        {
    	    id[i] = rand()%10;
        }
        for (int i:id) 
        {
		    realid.push_back(i + '0');
	    }
        //cout << realid << " ";
        ifstream source;
        source.open("member.txt");
        while(getline(source,text))
        {
        int start=0;
        int end = text.find_first_of(" ");
        while( end != -1)
        {
            if(text.substr(start,end-start)==realid)
            {
                use = true;
                //realid.clear();
            }
            start = end+1;
            end = text.find_first_of(" ",start);
        }
    }
    source.close();
    //memid = realid;
    }while(use==true);
    return realid;
    
}

void checkmem(string key,bool &ck_member,string &name_mem)
{
    string text;
    ifstream source;
    source.open("member.txt");
    while(getline(source,text))
    {
        int start=0;
        int end = text.find_first_of(" ");
        while( end != -1)
        {
            if(text.substr(start,end-start)==key)
            {
                ck_member = true;
                name_mem = text.substr(end+1,text.size()-end+1);
            }
            start = end+1;
            end = text.find_first_of(" ",start);
        }
    }
    source.close();
}

void user()
{
	cout <<"\n\t----------------------------------------------------\n";
	cout << "\n\t\t\t***Cinema Show time***\n";
	cout <<"\n\t----------------------------------------------------\n";

	mt = choose_movie_and_time();

	show_seat(mt);
 	if(ck_member==true) cout << "\n\n\t\tPrice Row B-E : 90\tRow A : 150\n\n";
 	else cout << "\n\n\t\tPrice Row B-E : 120\tRow A : 180\n\n";

	cout << "\tHow many seat do you want? (Max 4|Min 1) : ";
    cin >> string_numofseat;
	
	do{
		cout<<"\tPlease input 1-4\n";
		cout << "\tHow many seat do you want? (Max 4|Min 1) : ";
    	cin >> string_numofseat;
	}while(string_numofseat != "1" && string_numofseat != "2" && string_numofseat != "3" && string_numofseat != "4");

	numofseat = stoi(string_numofseat);

    for(int i=0;i<numofseat;i++)
    {
		bool checkseat;
		int position;

		cout << "\n\t\tSeat " << i+1;

		do{
			row[i] = getrow();
			string_seatnum = getseatnum(row[i]);
			seatnum[i] = stoi(string_seatnum);
			position = read_seat(row[i],seatnum[i]);
			if(check_seat(mt,position) == false) cout<<"\t\tError. This seat has been booked.\n\t\tPlease try again. ";
			if(position > 28) cout<<"\t\tError. Invalid seat.\n\t\tPlease try again";
		}while(check_seat(mt,position) == false || position > 28);

		update_seat(position,mt);

    }

	show_seat(mt);
	cin.ignore();
	cout << "\n\n\t\tEnter name : ";
	getline(cin,name);
	cost_ticket(mt,row,seatnum);
}

void filebooklist(char row,int seatnum,int mt)
{
	fstream source;
	switch(mt){
		case 2 : source.open("Booklist_m1t1.txt", ios::app); break;
		case 3 : source.open("Booklist_m1t2.txt", ios::app); break;
		case 4 : source.open("Booklist_m1t3.txt", ios::app); break;
		case 5 : source.open("Booklist_m2t1.txt", ios::app); break;
		case 6 : source.open("Booklist_m2t2.txt", ios::app); break;
		case 7 : source.open("Booklist_m2t3.txt", ios::app); break;
		case 10 : source.open("Booklist_m3t1.txt", ios::app); break;
		case 11 : source.open("Booklist_m3t2.txt", ios::app); break;
		case 12 : source.open("Booklist_m3t3.txt", ios::app); break;
	}
    source << row << "\n";
    source << seatnum << "\n";
	source.close();
}


int read_seat(char row, int col)
{
	int int_row;
	switch(row){
		case('A') : int_row = 4; break;
		case('B') : int_row = 3; break;
		case('C') : int_row = 2; break;
		case('D') : int_row = 1; break;
		case('E') : int_row = 0; break;
	}
	
	int position = (int_row*6-1)+col;
	return position;

}

bool check_seat(int mt, int position)
{
	string textline;
    vector<int> new_seat(28);
	ifstream source;
	int i = 0;

    // open seat file
	switch(mt){
		case 2 : source.open("seat_m1t1.txt"); break;
		case 3 : source.open("seat_m1t2.txt"); break;
		case 4 : source.open("seat_m1t3.txt"); break;
		case 5 : source.open("seat_m2t1.txt"); break;
		case 6 : source.open("seat_m2t2.txt"); break;
		case 7 : source.open("seat_m2t3.txt"); break;
		case 10 : source.open("seat_m3t1.txt"); break;
		case 11 : source.open("seat_m3t2.txt"); break;
		case 12 : source.open("seat_m3t3.txt"); break;
	}

	while(getline(source,textline))
	{  
		new_seat[i] = stoi(textline);
		i++;
    }
	source.close();

	cout<<"\n";
	
	for(int i = 0; i<new_seat.size(); i++){
		if(new_seat[i] == 1 && i == position) return false;
	}

	return true;

}

void reset_seat(int mt){

	ofstream new_source;
	switch(mt){
		case 2 : new_source.open("seat_m1t1.txt"); break;
		case 3 : new_source.open("seat_m1t2.txt"); break;
		case 4 : new_source.open("seat_m1t3.txt"); break;
		case 5 : new_source.open("seat_m2t1.txt"); break;
		case 6 : new_source.open("seat_m2t2.txt"); break;
		case 7 : new_source.open("seat_m2t3.txt"); break;
		case 10 : new_source.open("seat_m3t1.txt"); break;
		case 11 : new_source.open("seat_m3t2.txt"); break;
		case 12 : new_source.open("seat_m3t3.txt"); break;
	}

	for(int j = 0; j<28; j++){
        new_source << "0" <<endl;
	}
	cout<<"\t\t*** Seatfile clear. ***";
	new_source.close();



}

void update_seat(int position,int mt){

	string textline;
    vector<int> new_seat(28);
	ifstream source;
	int i = 0;

    // open seat file
	switch(mt){
		case 2 : source.open("seat_m1t1.txt"); break;
		case 3 : source.open("seat_m1t2.txt"); break;
		case 4 : source.open("seat_m1t3.txt"); break;
		case 5 : source.open("seat_m2t1.txt"); break;
		case 6 : source.open("seat_m2t2.txt"); break;
		case 7 : source.open("seat_m2t3.txt"); break;
		case 10 : source.open("seat_m3t1.txt"); break;
		case 11 : source.open("seat_m3t2.txt"); break;
		case 12 : source.open("seat_m3t3.txt"); break;
	}

	while(getline(source,textline))
	{  
		new_seat[i] = stoi(textline);
		i++;
    }

	new_seat.at(position) = 1;
	cout<<"\n";
	
	source.close();

	ofstream new_source;
	switch(mt){
		case 2 : new_source.open("seat_m1t1.txt"); break;
		case 3 : new_source.open("seat_m1t2.txt"); break;
		case 4 : new_source.open("seat_m1t3.txt"); break;
		case 5 : new_source.open("seat_m2t1.txt"); break;
		case 6 : new_source.open("seat_m2t2.txt"); break;
		case 7 : new_source.open("seat_m2t3.txt"); break;
		case 10 : new_source.open("seat_m3t1.txt"); break;
		case 11 : new_source.open("seat_m3t2.txt"); break;
		case 12 : new_source.open("seat_m3t3.txt"); break;
	}

	
	for(int j = 0; j<i; j++){
        new_source << new_seat[j] << endl;
    }
    
    new_source.close();
}

void show_seat(int mt){

	string textline;
    int new_seat[28];
    int i = 0,n=1;
	ifstream source;
    //open the seat data

	switch(mt){
		case 2 : source.open("seat_m1t1.txt", ios::app); break;
		case 3 : source.open("seat_m1t2.txt", ios::app); break;
		case 4 : source.open("seat_m1t3.txt", ios::app); break;
		case 5 : source.open("seat_m2t1.txt", ios::app); break;
		case 6 : source.open("seat_m2t2.txt", ios::app); break;
		case 7 : source.open("seat_m2t3.txt", ios::app); break;
		case 10 : source.open("seat_m3t1.txt", ios::app); break;
		case 11 : source.open("seat_m3t2.txt", ios::app); break;
		case 12 : source.open("seat_m3t3.txt", ios::app); break;
	}
	while(getline(source,textline))
	{
        new_seat[i] = stoi(textline);
        i++;
    }

    char row[5] = {'E','D','C','B'};
    char display[2] = {'\0', 'X'};

    cout <<"\n\t----------------------------------------------------";
	cout << "\n\n\t|\t\t\tSCREEN\t\t\t|\n";
	cout <<"\n\t----------------------------------------------------\n";
	cout <<" \t\t 1     2     3   \t 4     5     6\n";

    //display normal row E-B 

    for(int i = 0; i<23; i = i+6){
        cout<<"\t"<<row[n-1]<<"\t";
        for(int j = i; j<6+i; j++){
            if(j == 2+i && new_seat[j] == 1) cout<<"|X|   \t";
			if(j != 2+i && new_seat[j] == 1) cout<<"|X|   ";
			if(j == 2+i && new_seat[j] == 0) cout<<"| |   \t";
			if(j != 2+i && new_seat[j] == 0) cout<<"| |   ";

        }
        cout<<"\n";
        n++;
    }


    //display sofa row A
    cout<<setw(28)<<"\n\t\t\t  -- SOFA seat --\n\n";
	cout <<" \t\t   1     2     \t\t   3\t   4\n";
    cout<<"\tA\t";
    for(int j = 23; j<29; j++){
        if(j == 23) cout<<setw(2)<<" ";
        else if(j < 26) {
            if(new_seat[j] == 0) cout<<setw(2)<<"| |"<<"   ";
            else if(new_seat[j] == 1) cout<<setw(2)<<"|X|"<<"   ";
        }
        else if(j > 26){
            if(new_seat[j-1] == 0) cout<<setw(2)<<"  | |"<<"   ";
            else if(new_seat[j-1] == 1) cout<<setw(2)<<"  |X|"<<"   ";
        }
        else cout<<"\t\t";
    }
}

//add
void cost_ticket(int mt,char *r,int *sn){
	int cost=0;
	cout <<"\n\n\t----------------------------------------------------\n";
	cout << "\t\tName : " << name;
	cout << "\n\t\tSeat : ";
	//cout << *r << r << &r;
	//add price of member
	for(int i=0;i<numofseat;i++){
		if(ck_member == true){
			cout << *(r+i) << *(sn+i) << " ";
				if(*(r+i) == 'A' || *(r+i) == 'a'){
						cost+=150;
					}else{
						cost+=90;
					}
			}else{
				cout << *(r+i) << *(sn+i) << " ";
				if(*(r+i) == 'A' || *(r+i) == 'a'){
					cost+=180;
				}else cost+=120;
			}
		}
	//add
	cout << "\n\t\tTotal ticket cost : " << cost;
	promotion(cost);
	fstream source;	
	switch(mt){
		case 2 : source.open("Bill_m1t1.txt", ios::app); break;
		case 3 : source.open("Bill_m1t2.txt", ios::app); break;
		case 4 : source.open("Bill_m1t3.txt", ios::app); break;
		case 5 : source.open("Bill_m2t1.txt", ios::app); break;
		case 6 : source.open("Bill_m2t2.txt", ios::app); break;
		case 7 : source.open("Bill_m2t3.txt", ios::app); break;
		case 10 : source.open("Bill_m3t1.txt", ios::app); break;
		case 11 : source.open("Bill_m3t2.txt", ios::app); break;
		case 12 : source.open("Bill_m3t3.txt", ios::app); break;
	}
	source << "\n\t\tName : " << name << "\n";
	source << "\t\tSeat : ";
	for(int i=0;i<numofseat;i++)
	{
		source << *(r+i) << *(sn+i) << " ";
	}
	source << "\n";
	source.close();
	//add
	cout << "\n\t\t**The booking is successful.**\n";
	cout << "\n\t\t\t**Thank you**\n";
	home();
}


void promotion(int cost){
    //bool user=false,ck_pro=false;
    string user_code, textline;
    char key;
 bool valid_code = false,ck_pro=false;
    do{
        cout << "\n\t\tDo you have discount (Y or N) : ";
        cin >> key;
        if(key == 'y' || key == 'Y'){
            cout << "\t\tEnter code : ";
            cin >> user_code;
            ifstream source;
            source.open("promotioncode.txt");
            while(getline(source,textline)){
                if(textline == user_code){
                    cost = cost - (cost*10)/100;
     valid_code = true;
                }
            }
            source.close();
   if(!valid_code) 
   {
    cout<<"\t\tSorry. Invalide code.\n";
    ck_pro=false;
   }
   else
   {
    cout << "\t\tTotal ticket cost : " << cost << " Bath.\n";
    ck_pro=true;
   }
        }else if(key =='n' || key == 'N'){
            cout << "\t\tTotal ticket cost : " << cost << " Bath.\n";
   ck_pro=true;
        }else
  {
   cout<<"\t\tInvalid Input.\n";
   ck_pro=false;
   //promotion(cost);
  }
    }while(ck_pro==false);
 cout <<"\t----------------------------------------------------\n";
}

int choose_movie_and_time(){
	for(int i=0;i<3;i++){
			cout << "\tTheater " << i+1 << " : " << movie[i] << "\n";
			cout << "\tTime   " << st[i] << "\n";
	}

	cout<<"\t\tChoose movie (1-3) :";
	cin>>string_ch_movie;

	do{
		cout<<"\tPlease input 1-3\n";
		cout<<"\t\tChoose movie (1-3) :";
		cin>>string_ch_movie;
	}while(string_ch_movie != "1" && string_ch_movie != "2" && string_ch_movie != "3");


	cout << "\t\tChoose Time (1-3) : ";
	cin >> string_ch_time;

	do{
		cout<<"\tPlease input 1-3\n";
		cout << "\t\tChoose Time (1-3) : ";
		cin >> string_ch_time;
	}while(string_ch_time != "1" && string_ch_time != "2" && string_ch_time != "3");

	ch_movie = stoi(string_ch_movie);
	ch_time = stoi(string_ch_time);

	mt = pow(ch_movie,2)+ch_time;
	return mt;
}

char getrow(){
	
	string row;
	cout << "\n\t\tEnter row : ";
	cin >> row;

	do{
        cout << "Please enter A,B,C,D,E : ";
		cout << "\n\t\tEnter row : ";
		cin >> row;
	}while(row != "A" && row != "B" && row != "C" && row != "D" && row != "E");

	char char_row = row[0];

	return char_row;
}

int getseatnum(char row){

	string seatnum;
	cout << "\t\tEnter seat number : ";
    cin >> seatnum;

	do{
		if(row == 'A' && seatnum != "1" && seatnum != "2"&& seatnum != "3"&& seatnum != "4") cout <<"\t\tError. Row must be 1-4\n";
		if(row != 'A' && seatnum != "1" && seatnum != "2"&& seatnum != "3"&& seatnum != "4" && seatnum != "5" && seatnum != "6") cout <<"\t\tError. Row must be 1-6\n";
	}while(seatnum != "1" && seatnum != "2"&& seatnum != "3"&& seatnum != "4" && seatnum != "5" && seatnum != "6");
	
	return stoi(seatnum);
}
