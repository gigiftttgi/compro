//สร้างแยกไว้ก่อน
#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#include<iomanip>
using namespace std;

int num, booklist, mt;
string name;

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
				 //home();
				 break;
		case 3 : 
				 source.open("Bill_m1t2.txt", ios::app); 
				 source << "Name : " << name << "\n";
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << " ";
				 } 
				 source.close();
				 //home();
				 break;
		case 4 : 
				 source.open("Bill_m1t3.txt", ios::app); 
				 source << "Name : " << name << "\n";
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << " ";
				 } 
				 source.close();
				 //home();
				 break;
		case 5 : 
				 source.open("Bill_m2t1.txt", ios::app); 
				 source << "Name : " << name << "\n";
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << " ";
				 } 
				 source.close();
				 //home();
				 break;
		case 6 : 
				 source.open("bill_m2t2.txt", ios::app); 
				 source << "Name : " << name << "\n";
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << " ";
				 } 
				 source.close();
				 //home();
				 break;
		case 7 : 
				 source.open("Bill_m2t3.txt", ios::app); 
				 source << "Name : " << name << "\n";
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << " ";
				 } 
				 source.close();
				 //home();
				 break;
		case 10 : 
				 source.open("Bill_m3t1.txt", ios::app); 
				 source << "Name : " << name << "\n";
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << " ";
				 } 
				 source.close();
				 //home();
				 break;
		case 11 : 
				 source.open("Bill_m3t2.txt", ios::app); 
				 source << "Name : " << name << "\n";
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << " ";
				 } 
				 source.close();
				 //home();
				 break;
		case 12 : 
				 source.open("Bill_m3t3.txt", ios::app); 
				 source << "Name : " << name << "\n";
				 for(int j=0;j<num;j++)
				 {
					source << booklist[j] << " ";
				 } 
				 source.close();
				 //home();
				 break;
	}	
	//home();
}

void showbill(){
    fstream source;
    source.open("seat.txt"); //ไม่มั่นใจว่าเพื่อนใช้ชื่ออะไร เพราะไม่ได้push ลงมางับ ตรงนี้ไว้ค่อยเปลี่ยน
    string textline;
    //หลังจากตรงนี้สร้างอ่านจากไฟล์.txt ที่ไปเก็บไว้ได้ แล้วค่อยcout ออกมา

    cout << setw(40) << "CPE THEATER\n";
    cout << bill(); //เพราะมีการให้user enter name
}

int main(){
    showbill();
    return 0;
}