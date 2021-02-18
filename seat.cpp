#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

const int numof_row = 5;
const int numof_col = 8;

void update_seat(bool [][numof_col],int , int);
void show_seat(const bool [][numof_col]);

int main(){
    bool av_seat[numof_row][numof_col] = {};
    int seat,row,col;
    char char_row;
    cout << "Enter seat : ";
    cin >> char_row >> col;
    switch(char_row){
        case('A') : row = 4; break;
        case('B') : row = 3; break;
        case('C') : row = 2; break;
        case('D') : row = 1; break;
        case('E') : row = 0; break;
    }
    update_seat(av_seat,row,col);
    show_seat(av_seat);
}

void update_seat(bool av_seat[][numof_col],int row, int col){
    for(int i = 0;i<numof_row; i++){
        for(int j=0; j<numof_col; j++){
            if(row != 4 ){
                if(col >=4 ) col = col+1;
                if(i == row && j == col) av_seat[i][j+1] = 1; break;
            }
            else{
                switch(col){
                    case(1) : col = 2; break;
                    case(2) : col = 3; break;
                    case(3) : col = 5; break;
                    case(4) : col = 6; break;
                }
                if(i == row && j == col) av_seat[i][j] = 1;
            }
        }
    }
}


void show_seat(const bool av_seat[numof_row][numof_col]){
    cout<<setw(40)<<"| | = avaible , |X| = booked\n";
    cout<<setw(40)<<"-----------SCREEN----------\n";
    for(int i = 0; i<numof_row;i++){
        for(int j = 0; j<numof_col;j++){
            if(j == 0){
                if(i == 0) cout<<"E\t";
                if(i == 1) cout<<"D\t";
                if(i == 2) cout<<"C\t";
                if(i == 3) cout<<"B\t";
                if(i == 4) cout<<"A\t";
            }
            else if(i == 4 && j == 1) cout<<setw(5)<<" ";
            else if(i == 4 && j == 7) cout<<setw(5)<<"  \t  ";
            else if(j == 4) cout <<"\t";
            else if(av_seat[i][j] == 1) cout<<setw(5)<<"|X| ";
            else cout<<setw(5)<<"| | ";
        }
        cout<<"\n";
    }
}


