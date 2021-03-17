#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<cctype>
#include<conio.h>
#include<cmath>
#include<iomanip>
#include<vector>
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
void promotion();
void cost_ticket(int,char *,int *);
int read_seat(char , int);
bool check_seat(int , int );
bool cancel_reserve(int, int);
void edit_booklist(int , char , int );

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
int ch_movie,ch_time,numofseat,mt;
bool ck_member = false;
int cost = 0;

int main()
{
	home();
	return 0;
}

void home()
{
	int op;
	bool c_op = false;
	bool be_mem = false;
	bool a_member = false;
	do{
		cout << "\n\t\t***Welcome to Theater***\n";
		cout << setw(15) << "1. for User\n";
		cout << setw(15) << "2. for Admin\n";
		cout << setw(15) << "0. for Exit\n";
		cout << setw(15) << "Select option :  ";
		cin >> op;
		switch(op)
		{
			case 1 : char key;
					 do
					 {
						 cout << setw(15) << "\nAre you a member? (Y/N) : ";
					 	 cin >> key;
					 	 if(key == 'y' or key == 'Y')
					 	 {
						 	 string ch_id;
						 	 cout << setw(15) << "Enter member id : ";
						 	 cin >> ch_id;
						 	 checkmem(ch_id,ck_member,name_mem);
						 	 cout << "\n\t\t**Welcom K." << name_mem << " **";
						 	 user();
							 a_member = true;
					 	 }
					 	 else if(key == 'N' or key == 'n')
					 	 {
						  	 char key;
							 do
							 {
								 cout << stw(15) << "\nWould you like to become a member? (Y/N) : ";
						 	 	 cin >> key;
						 	 	 if(key == 'y' or key == 'Y')
					 	 	 	 {
							  	 	 member(ck_member,name_mem);
							 	 	 cout << "\n\t\t**Welcom K." << name_mem << " **";
							 	 	 user();
									 be_mem=true;
					 	 	 	 }
						 	 	 else if(key == 'N' or key == 'n')
						 	     {
							 	 	 user();
									 be_mem=true;
						 	 	 }
							 	 else 
								 {
									 cout << setw(15) << "Please enter y/n\n";
								 }
							 }while(be_mem==false);
							 a_member = true;
					 	 }
						 else
						 {
							cout << setw(15) << "Please enter y/n\n";

						 }
					 }while(a_member == false);
					 c_op = true;
					 break;
			case 2 : admin();
					 c_op = true; 
					 break;
			case 0 : c_op = true; 
					 break;
			default : cout << setw(15) << "\nPlease select again\n\n";
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
		cout << setw(15) << "\nEnter passcode : ";
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
			cout << setw(15) << "\nWrong passcode!!!\n" ;
			if(count >= 4){
				cout<< setw(15) << "System lock!!! Please wait and try again\n";
				home();
			}
			cout<< setw(15) << "Please enter again.\n";
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
		cout << "\t\n< Admin menu >\n";
		cout << setw(15) << "1. Add movie\n";
		cout << setw(15) << "2. Change movie\n";
		cout << setw(15) << "3. Check movie\n";
		cout << setw(15) << "4. Check valiable seat\n";
		cout << setw(15) << "5. Cancel reservation\n";
		//add 
		cout << setw(15) << "6. Change discount\n";
		cout << setw(15) << "0. Exit to home\n";
		cout << setw(15) << "Enter option : ";
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
			case 5 : list(5);
			   	     c_aop = true;
					 break;		
		//add
			case 6 : list(6);
					 c_aop = true;
					 break;
			default : cout << setw(15) << "Please enter again.\n";
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
	else if(l==4)
	{
		cout << "\n< Check Valiable Seat >\n";
		cout << "Choose movie (1-3) : ";
		cin >> ch_movie;
		while (ch_movie || ch_movie == 0)
		{
			if(ch_movie >=1 && ch_movie <= 3) break;
			cout << "This movie does not exist. Please Select Again.\n";
			cout << "\nChoose movie (1-3) : ";
			cin >> ch_movie;
		}
		cout << "Choose Time (1-3) : ";
		cin >> ch_time;
		while (ch_time || ch_time==0)
		{
			if(ch_time >= 1 && ch_time <= 3) break;
			cout << "This time does not exist. Please Select Again.\n";
			cout << "\nChoose time (1-3) : ";
			cin >> ch_time;		
		}
		mt = pow(ch_movie,2)+ch_time;
		valiable_seat(mt);
	}
	else if(l==5){
		int ch_movie,ch_time,seatnum;
		char row;
		cout << "\n< Cancel Reservation >\n";
		for(int i=0;i<3;i++)
		{
			cout << "Theater " << i+1 << " : " << movie[i] << "\n";
			cout << "Time   " << st[i] << "\n";
		}
		cout << "Choose movie (1-3) : ";
		cin >> ch_movie;
		while (ch_movie || ch_movie == 0){
			if(ch_movie >=1 && ch_movie <= 3) break;
			cout << "This movie does not exist. Please Select Again.\n";
			cout << "\nChoose movie (1-3) : ";
			cin >> ch_movie;
		}

		cout << "Choose Time (1-3) : ";
		cin >> ch_time;
		while (ch_time || ch_time==0){
			if(ch_time >= 1 && ch_time <= 3) break;
			cout << "This time does not exist. Please Select Again.\n";
			cout << "\nChoose time (1-3) : ";
			cin >> ch_time;	
		}

		int mt = pow(ch_movie,2)+ch_time;

        cout << "\nEnter row : ";
        cin >> row;
        cout << "Enter seat number : ";
        cin >> seatnum;
    	
		int position = read_seat(row,seatnum);

		bool cancel = cancel_reserve(mt,position);
	

		if(!cancel){
			cout<<"Cancel Reservation Error.\n The seat is still empty.";
			list(5);
		}
		else {
			edit_booklist(mt,row,seatnum);
			cout<<"Cancel Reservation Completed.\n";
		}
		op_admin();
	}
	//add loop discount**
	else if(l == 6){
			while(discount != "0"){
        		cout << "add discount( 0 for exit) : ";
        		cin >> discount;
        		fstream source;
        		source.open("promotioncode.txt",ios::app);
        		source << discount << endl;
        		source.close();
    		}
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
	
	int N= k/2;
    string out[N];
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

	int opt;
	cout << "\nDo you want to check who belong to seat? (1.Yes | 2.No)\n";
	cout << "Enter option : ";
	cin >> opt;
	if(opt == 1){
		ppl_seat(mt);
	}else{ 
		op_admin();
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
	
	int opt = 1;
	while(opt==1){
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
		cout << "\nDo you want to check it again? (1.Yes | 2.No)\n";
		cout << "Enter option : ";
		cin >> opt;
	}
	op_admin();
}



void member(bool &ck_member,string &name_mem){
    string mem_id;
    int id[5];
	cin.ignore();
    cout << "Enter name : ";
    getline(cin,name_mem);
    cout << "suscess\n";
	mem_id = rand_id();
    cout << "your member id is " << mem_id;
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
	cout << "\n\t***Cinema Show time***\n";
	for(int i=0;i<3;i++)
	{
		cout << "Theater " << i+1 << " : " << movie[i] << "\n";
		cout << "Time   " << st[i] << "\n";
	}
	cout << "Choose movie (1-3) : ";
	cin >> ch_movie;
	while (ch_movie || ch_movie == 0)
	{
		if(ch_movie >=1 && ch_movie <= 3) break;
		cout << "This movie does not exist. Please Select Again.\n";
		cout << "\nChoose movie (1-3) : ";
		cin >> ch_movie;		
	}

	cout << "Choose Time (1-3) : ";
	cin >> ch_time;
	while (ch_time || ch_time==0)
	{
		if(ch_time >= 1 && ch_time <= 3) break;
		cout << "This time does not exist. Please Select Again.\n";
		cout << "\nChoose time (1-3) : ";
		cin >> ch_time;		
	}
	mt = pow(ch_movie,2)+ch_time;
	cin.ignore();
	show_seat(mt);
	if(ck_member==true){
		cout << "Price\nRow B-E : 90\nRow A : 150\n"; 
	}
	else{
		cout << "Price\nRow B-E : 120\nRow A : 180\n"; 
	} 
    cout << "How many seat do you want? (MAx 4|Min 1) : ";
    cin >> numofseat;
	while (numofseat || numofseat == 0){
		if(numofseat>=1 && numofseat<=4) break;
		if(numofseat > 4){
			cout << "There are too many seats. Please Enter Again.";
		}else{
			cout << "Error. Please Enter number of seats you want";
		}
		cout << "\n\nHow many seat do you want? (MAx 4|Min 1) : ";
    	cin >> numofseat;		
	}

    for(int i=0;i<numofseat;i++)
    {
        cout << "\nSeat " << i+1;
        cout << "\nEnter row : ";
        cin >> row[i];
        cout << "Enter seat number : ";
        cin >> seatnum[i];
        filebooklist(row[i],seatnum[i],mt);

		int position = read_seat(row[i],seatnum[i]);
		bool checkseat = check_seat(mt,position);

		while(checkseat == false){
			cout<<"Error. This seat has been booked.\n";
			cout<<"Please try again";
			user();
		}
		update_seat(position,mt);	
    }
	show_seat(mt);
	cin.ignore();
	cout << "\nEnter name : ";
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

void update_seat(int position,int mt)
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
    source.close();
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

    cout<<setw(25)<<"-----------------------------------------\n";
    cout<<setw(25)<<"|SCREEN|\n";

    //display normal row E-B 

    for(int i = 0; i<23; i = i+6){
        cout<<row[n-1]<<"\t";
        for(int j = i; j<6+i; j++){
            if(j == 2+i && new_seat[j] == 1) cout<<"|X| \t";
			if(j != 2+i && new_seat[j] == 1) cout<<"|X| ";
			if(j == 2+i && new_seat[j] == 0) cout<<"| | \t";
			if(j != 2+i && new_seat[j] == 0) cout<<"| | ";

        }
        cout<<"\n";
        n++;
    }

    //display sofa row A
    
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

//add
void cost_ticket(int mt,char *r,int *sn){
	//int cost=0;
	cout << "Name : " << name;
	cout << "\nSeat : ";
	//cout << *r << r << &r;
	//add price of member
		for(int i=0;i<numofseat;i++){
			if(ck_member == true){
				cout << *(r+i) << *(sn+i) << " ";
					if(*(r+i) == 'A' or *(r+i) == 'a'){
						cost+=150;
					}else{
						cost+=90;
					}
			}else{
				if(*(r+i) == 'A' or *(r+i) == 'a'){
					cost+=180;
				}else cost+=120;
			}
		}
	//add
	if(ck_member == false){
		promotion();
	}
	//cout << "\nTotal ticket cost : " << cost;
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
	source << "\nName : " << name << "\n";
	source << "Seat : ";
	for(int i=0;i<numofseat;i++)
	{
		source << *(r+i) << *(sn+i) << " ";
	}
	source << "\n";
	source.close();
	//add
	cout << "\n\t**The booking is successful.**\n";
	cout << "\n\t\t**Thank you**\n";
	home();
}

void promotion(){
    bool user;
    string user_code, textline;
    char key;
    	do{
        	cout << "Do you have promotion (Y or N) : ";
        	cin >> key;
        	if(key == 'y' || key == 'Y'){
            	cout << "Enter promotion : ";
            	cin >> user_code;
				ifstream source;
				source.open("promotion.txt");
				while(getline(source,textline)){
            		if(textline == user_code){
                		cout << "Total ticket cost : " << cost - (cost*10)/100 << "Bath.";
            		}
            	user = true;
				}
        	}
        	else if(key =='n' || key == 'N'){
            	cout << "Total ticket cost : " << cost << "Bath.";
            	user = true;
        	}
        	else{
            	cout << "Please try again. ";
            	user = false;
        	}
    	}while(user == false);
}
