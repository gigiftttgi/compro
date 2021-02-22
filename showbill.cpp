//สร้างแยกไว้ก่อน
#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#include<iomanip>
using namespace std;

int num, booklist, mt;
string name;


//ไม่มั่นใจว่าต้องเอาฟังก์ชั่นนี้ไปใส่ตรงไหน เลยเอาแยกไว้ตรงนี้ก่อน 
void showbill(){
	cout << setw(30) << "CPE THEATER\n";
    cout << bill(); //เห็นว่าในฟังก์ชั่นนี้มีให้ใส่ชื่อกับที่นั่ง เลยดึงมาใช้เลย
    cout << "Movie : " << ch_movie;
    cout << "Show time : " << ch_time;
	cout << setw(30) << "Thank you";
}

//กรณีที่สองถ้าหากว่าอยากอ่านข้อมูลใน.txt แทนก็ได้ แต่เราไม่รู้ว่าต้องไฟล์.txt ไหน เครื่องเราไม่มีงับ เลยทำเป็นแบบฟอร์มให้เห็นเป็นแบบนี้ก่อน
void showbill(){
    fstream source;
    source.open(""); //ไม่มั่นใจว่าเพื่อนใช้ชื่ออะไร เพราะไม่ได้push ลงมางับ ตรงนี้ไว้ค่อยเปลี่ยน
    string textline;
    //หลังจากตรงนี้สร้างอ่านจากไฟล์.txt ที่ไปเก็บไว้ได้

	//คิดว่าแบบที่สองน่าจะสะดวกกว่าไหม เพราะยังไง ก็มีการเก็บข้อมูลไว้อยู่แล้ว
}

int main(){
    showbill();
    return 0;
}