//สร้างแยกไว้ก่อน
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

//ส่วนของคิดเงินยังติดบัคอยู่

void showbill(){
    int sum = 0;
    if(row == 'A'){
        sum  =180*numofseat;
    }
    else{
        sum = 120*numofseat;
    }
	cout << setw(30) << "CPE THEATER\n";
    cout << "Name : " ;//<< name;
    cout << "Movie : " ;//<< ch_movie;
    cout << "Show time : ";// << ch_time;
    cout << "Seat : " ;//<< row << seatnum;
    cout << "Total : " << sum;
	cout << setw(30) << "Thank you";
}

int main(){
    showbill();
    return 0;
}