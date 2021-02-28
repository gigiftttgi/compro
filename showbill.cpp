//สร้างแยกไว้ก่อน
#include<iostream>
#include<iomanip>
using namespace std;


void showbill(){
	cout << setw(30) << "CPE THEATER\n";
    cout << "Name : " << name;
    cout << "Movie : " << ch_movie;
    cout << "Show time : " << ch_time;
    cout << "Seat : " << row << seatnum;
	cout << setw(30) << "Thank you";
}

int main(){
    showbill();
    return 0;
}