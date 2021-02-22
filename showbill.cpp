//สร้างแยกไว้ก่อน
#include<iostream>
#include<iomanip>
using namespace std;

//ไม่มั่นใจว่าต้องเอาฟังก์ชั่นนี้ไปใส่ตรงไหน เลยเอาแยกไว้ตรงนี้ก่อน 
void showbill(){
	cout << setw(30) << "CPE THEATER\n";
    cout << bill(); //เห็นว่าในฟังก์ชั่นนี้มีให้ใส่ชื่อกับที่นั่ง เลยดึงมาใช้เลย ไม่รู้ว่าอันไหนคือตัวแปรของชื่อผู้ใช้และที่นั่งที่เลือกไว้
    cout << "Movie : " << ch_movie;
    cout << "Show time : " << ch_time;
	cout << setw(30) << "Thank you";
}

//กรณีที่สองถ้าหากว่าอยากอ่านข้อมูลใน.txt แทนก็ได้ แต่เราไม่รู้ว่าต้องไฟล์.txt ไหนงับ

int main(){
    showbill();
    return 0;
}