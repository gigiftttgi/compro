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
    string user_code, textline;
    char key;
        while(key != 'y' && key != 'Y' && key != 'n' && key != 'N'){
            cout << "Do you have discount (Y or N) : ";
            cin >> key;
            if(key == 'y' || key == 'Y'){
                cout << "Enter code : ";
                cin >> user_code;
                ifstream source;
                source.open("promotioncode.txt");
                while(getline(source,textline)){
                    if(textline == user_code){
                        cost - (cost*10)/100;
                    }
                }
                source.close();
                cout << "Total ticket cost : " << cost << " Bath.\n";
            }
            else if(key =='n' || key == 'N'){
                cout << "Total ticket cost : " << cost << " Bath.\n";
            }
            else{
                cout << "Please try again. ";
            }
        };
    //costs();
}

int main(){
    admin();
    promotion();
    return 0;
}