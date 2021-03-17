#include<iostream>
#include<fstream>
using namespace std;

int numofseat = 2;
float cost = 180;
char r = 'a';
int sn = 2;
string discount;
bool ck_member = false;
//completed
void admin(){
            fstream source;
    while(discount != "0"){
        cout << "add discount( 0 for exit) : ";
        cin >> discount;
        source.open("promotioncode.txt",ios::app);
        source << discount << endl;
        source.close();
    }
    //cout << "add discount :";
    //cin >>discount;
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
    string user_code, textline;
    char key;
    if(ck_member == true){
        cout << "cost\n";
    }else{
        do{
            cout << "Do you have discount (Y or N) : ";
            cin >> key;
            if(key == 'y' || key == 'Y'){
                cout << "Enter code : ";
                cin >> user_code;
                ifstream source;
                source.open("promotioncode.txt");
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
    //costs();
}

int main(){
    admin();
    promotion();
    return 0;
}