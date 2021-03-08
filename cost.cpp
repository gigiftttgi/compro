#include<iostream>
using namespace std;

int numofseat = 2;
float cost = 0;
char r = 'a';
int sn = 2;
string discount;

void admin(){
    cout << "add discount :";
    cin >>discount;
}

/*void costs(){
    for(int i=0;i<numofseat;i++)
	{
		cout << (r+i) << (sn+i) << " ";
		if((r+i) == 'A' or (r+i) == 'a')
		{
			cost+=180;
		}
		else cost+=120;
	}
	//cout << "\nTotal ticket cost : " << cost;
}*/

void promotion(){
    bool user;
    string user_code;
    char key;
    do{
        cout << "Do you have discount (Y or N) : ";
        cin >> key;
        if(key == 'y' || key == 'Y'){
            cout << "Enter code : ";
            cin >> user_code;
            if(discount == user_code){
                cout << "Total ticket cost : " << cost - (cost*10)/100 << "Bath.";
            }
            user = true;
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
    //costs();
}

int main(){
    admin();
    code();
    return 0;
}