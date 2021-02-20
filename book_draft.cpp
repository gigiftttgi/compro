#include<iostream>
#include<string>
#include<fstream>
#include<cctype>
using namespace std;

void book_seat(string);

string m1t1[28];

int main()
{
    string book;
    bool test=false;
    char check;
    do{
        cout << "Enter seat (row,seat) : ";
        getline(cin,book);
        book_seat(book);
        cout << "Book again(Y/N) : ";
        cin >> check;
        if(check == 'N' or check == 'n')
            test = true;
        else
            test = false;
        cin.ignore();
    }while(test==false);
}

void book_seat(string bk)
{
    string booklist[4];
    int num = (bk.size()/3)+1;
    int start = 0;
    int end = bk.find_first_of(" ");
    while(end != -1)
    {
        for(int i=0;i<bk.size()/3;i++)
        {
            booklist[i] = bk.substr(start,end-start);
            start = end+1;
            end = bk.find_first_of(" ",start);
        }
    }
        booklist[num-1] = bk.substr(start,bk.size()-start);    
	fstream source;
	source.open("Booking.txt"); 
	for(int j=0;j<num;j++)
	{
		source << booklist[j] << "\n";
	} 
	source.close();
}
