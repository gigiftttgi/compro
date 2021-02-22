#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<vector>
using namespace std;

void read_seat(int );
void update_seat(int );
void clear_seat(int );
void show_seat();

int main(){
    int mt;
    cin >> mt;
    //to do all function read,update,show you only call read_seat function
    //mt is switch condition which leads to open different files for differents case
    read_seat(mt);
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