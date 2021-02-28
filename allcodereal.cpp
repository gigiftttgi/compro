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
void bill(int,char *,int *);
void read_seat(int);
void update_seat(int,int);
//void clear_seat(int );
void show_seat(int,int []);
void valiable_seat(int);

//string fileseat[9]={"\"D:\\Desktop\\code\\project - movie\\compro\\seat_m1t1.txt\"","seat_m1t2.txt","seat_m1t3.txt","seat_m2t1.txt","seat_m2t2.txt","seat_m2t3.txt","seat_m3t1.txt","seat_m3t2.txt","seat_m3t3.txt"};
//string filebill[9]={"D:\\Desktop\\code\\project - movie\\compro\\Bill_m1t1.txt","Bill_m1t2.txt","Bill_m1t3.txt","Bill_m2t1.txt","Bill_m2t2.txt","Bill_m2t3.txt","Bill_m3t1.txt","Bill_m3t2.txt","Bill_m3t3.txt"};
//string filelist[9]={"\"D:\\Desktop\\code\\project - movie\\compro\\Booklist_m1t1.txt\"","Booklist_m1t2.txt","Booklist_m1t3.txt","Booklist_m2t1.txt","Booklist_m2t2.txt","Booklist_m2t3.txt","Booklist_m3t1.txt","Booklist_m3t2.txt","Booklist_m3t3.txt"};
string st[3] = {"11:00 - 13:00 | 14:30 - 16:30 | 18:30 - 20:30","11:30 - 13:30 | 15:00 - 17:00 | 19:00 - 21:00","12:00 - 14:00 | 15:30 - 17:30 | 19:30 - 21:30"};
string booklist[100],book;
string movie[3];
string name;
int new_seat[28];
int seatnum[4];
char row[4];
int ch_movie,ch_time,numofseat,mt;

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
		cout << "\n< Check Valiable Seat >\n";
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

	mt = pow(ch_movie,2)+ch_time;

	valiable_seat(mt);

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

	mt = pow(ch_movie,2)+ch_time;
	cin.ignore();
	show_seat(mt,new_seat);
	cout << "Price\nRow B-E : 120\nRow A : 180\n";  
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
    }

	cout<<"\nhere\n";
	//read_seat(mt);
	//show_seat(mt,new_seat);
	cin.ignore();
	cout << "\nEnter name : ";
	getline(cin,name);
	bill(mt,row,seatnum);
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



void read_seat(int mt){
    //open Booklist file and read the data
    ifstream source;
	string textline;
    char char_row[2];
    int i = 0, N = 0;
    int col[28] = {};
    int row[28] = {};
    // mt varible is important here

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
	while(getline(source,textline))
	{
        if(i%2 == 0) 
		{
        	strcpy(char_row,textline.c_str());
            if(char_row[0] == 'E' or char_row[0] == 'e') row[i] = 0;
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
    for(int j = 0; j<i; j+=2)
	{
        //switch seat array from 2 dimension to 1 dimension
        position = row[j]*6-1+col[j];
        update_seat(position,mt);
    }
    //show_seat(mt);
}

void update_seat(int position,int mt)
{
	string textline;
    //int new_seat[28];
    int i = 0;
	ifstream source;
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
        if(i == position)
		{
            new_seat[i] = 1;
        }
        else
		{
            new_seat[i] = stoi(textline);
        }
        i++;
    }
    source.close();


    ofstream copy_source;
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
    for(int j = 0; j<28; j++)
	{
        copy_source << new_seat[j] << endl;
    }
    copy_source.close();
}

/*void clear_seat(int mt){
    //this function for admin when they update the movie and seat need to be clear
    ofstream copy_source("seat_m1t1.txt");
    for(int j = 0; j<28; j++){
        copy_source << "0" << endl;
    }
    copy_source.close();
    ofstream Booklist("Booklist_m1t1.txt");
    Booklist.clear();
    //show_seat();
}*/

void show_seat(int mt,int new_seat[28])
{
	string textline;
    //int new_seat[28];
    int i = 0,n=1;
	ifstream source;
    //open the seat data

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

    char row[5] = {'E','D','C','B'};
    char display[2] = {'\0', 'X'};

    cout<<setw(25)<<"-----------------------------------------\n";
    cout<<setw(25)<<"|SCREEN|\n";

    //display normal row E-B 

    for(int i = 0; i<23; i = i+6){
        cout<<row[n-1]<<"\t";
        for(int j = i; j<6+i; j++){
            if(new_seat[j] == 0) cout<<"| | ";
            if(new_seat[j] == 1) cout<<"|X| ";
            else if(j == 2+i) cout<<"\t";

        }
        cout<<"\n";
        n++;
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

void bill(int mt,char *r,int *sn)
{
	int cost=0;
	cout << "Name : " << name;
	cout << "\nSeat : ";
	//cout << *r << r << &r;
	for(int i=0;i<numofseat;i++)
	{
		cout << *(r+i) << *(sn+i) << " ";
		if(*(r+i) == 'A' or *(r+i) == 'a')
		{
			cost+=180;
		}
		else cost+=120;
	}
	cout << "\nTotal ticket cost : " << cost;
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
	cout << "\n\t**The booking is successful.**\n";
	cout << "\n\t\t**Thank you**\n";
	home();
}

void valiable_seat(int mt){
	string s[30];
	string textline;
    string seat[30] = {"A1", "A2", "A3", "A4","","","B1", "B2", "B3", "B4", "B5", "B6", "C1", "C2", "C3", "C4", "C5", "C6", "D1", "D2", "D3", "D4", "D5", "D6", "E1", "E2", "E3", "E4", "E5", "E6"};
	int k = 0;
	ifstream source;
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
    
 	cout << "Valiable Seats";

    for(int i=0; i<30 ; i++){
		if(i%6 == 0){
			cout << endl ;
            cout << seat[i] << "  ";

		}else{
            cout << seat[i] << "  ";

		}
	}
    
    
}
