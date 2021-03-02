int read_seat(char row, int col){

	int int_row;

	switch(row){
		case('A') : int_row = 4; break;
		case('B') : int_row = 3; break;
		case('C') : int_row = 2; break;
		case('D') : int_row = 1; break;
		case('E') : int_row = 0; break;
	}
	
	int position = (int_row*6-1)+col;
	return position;

}

void update_seat(int position,int mt)
{
	string textline;
    vector<int> new_seat(28);
	ifstream source;
	int i = 0;

    // open seat file
	switch(mt){
		case 2 : source.open("seat_m1t1.txt"); break;
		case 3 : source.open("seat_m1t2.txt", ios::app); break;
		case 4 : source.open("seat_m1t3.txt", ios::app); break;
		case 5 : source.open("seat_m2t1.txt", ios::app); break;
		case 6 : source.open("seat_m2t2.txt", ios::app); break;
		case 7 : source.open("seat_m2t3.txt", ios::app); break;
		case 10 : source.open("seat_m3t1.txt", ios::app); break;
		case 11 : source.open("seat_m3t2.txt", ios::app); break;
		case 12 : source.open("seat_m3t3.txt", ios::app); break;
	}

	while(getline(source,textline))
	{  
		new_seat[i] = stoi(textline);
		i++;
    }

	new_seat.at(position) = 1;
	cout<<"\n";
	
	source.close();

	ofstream new_source;
	switch(mt){
		case 2 : new_source.open("seat_m1t1.txt"); break;
		case 3 : new_source.open("seat_m1t2.txt", ios::app); break;
		case 4 : new_source.open("seat_m1t3.txt", ios::app); break;
		case 5 : new_source.open("seat_m2t1.txt", ios::app); break;
		case 6 : new_source.open("seat_m2t2.txt", ios::app); break;
		case 7 : new_source.open("seat_m2t3.txt", ios::app); break;
		case 10 : new_source.open("seat_m3t1.txt", ios::app); break;
		case 11 : new_source.open("seat_m3t2.txt", ios::app); break;
		case 12 : new_source.open("seat_m3t3.txt", ios::app); break;
	}


    for(int j = 0; j<i; j++){
        new_source << new_seat[j] << endl;
    }
    source.close();
}

void show_seat(int mt){

	string textline;
    int new_seat[28];
    int i = 0,n=1;
	ifstream source;
    //open the seat data

	switch(mt){
		case 2 : source.open("seat_m1t1.txt", ios::app); break;
		case 3 : source.open("seat_m1t2.txt", ios::app); break;
		case 4 : source.open("seat_m1t3.txt", ios::app); break;
		case 5 : source.open("seat_m2t1.txt", ios::app); break;
		case 6 : source.open("seat_m2t2.txt", ios::app); break;
		case 7 : source.open("seat_m2t3.txt", ios::app); break;
		case 10 : source.open("seat_m3t1.txt", ios::app); break;
		case 11 : source.open("seat_m3t2.txt", ios::app); break;
		case 12 : source.open("seat_m3t3.txt", ios::app); break;
	}
	while(getline(source,textline))
	{
        new_seat[i] = stoi(textline);
        i++;
    }

    char row[5] = {'E','D','C','B'};
    char display[2] = {'\0', 'X'};

    cout<<setw(25)<<"-----------------------------------------\n";
    cout<<setw(25)<<"|SCREEN|\n";

    //display normal row E-B 

    for(int i = 0; i<23; i = i+6){
        cout<<row[n-1]<<"\t";
        for(int j = i; j<6+i; j++){
            if(j == 2+i && new_seat[j] == 1) cout<<"|X| \t";
			if(j != 2+i && new_seat[j] == 1) cout<<"|X| ";
			if(j == 2+i && new_seat[j] == 0) cout<<"| | \t";
			if(j != 2+i && new_seat[j] == 0) cout<<"| | ";

        }
        cout<<"\n";
        n++;
    }

    //display sofa row A
    //the bug is seat C6 (position == 17) is not working
    
    cout<<setw(28)<<"- SOFA seat -\n";
    cout<<"A\t";
    for(int j = 23; j<29; j++){
        if(j == 23) cout<<setw(2)<<" ";
        else if(j < 26) {
            if(new_seat[j] == 0) cout<<setw(2)<<"| |"<<" ";
            else if(new_seat[j] == 1) cout<<setw(2)<<"|X|"<<" ";
        }
        else if(j > 26){
            if(new_seat[j-1] == 0) cout<<setw(2)<<"| |"<<" ";
            else if(new_seat[j-1] == 1) cout<<setw(2)<<"|X|"<<" ";
        }
        else cout<<"\t";
    }
}