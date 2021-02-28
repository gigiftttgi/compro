void valiable_seat(int mt){
	string s[8];
	string textline;
    string seat[30] = {"A1", "A2", "A3", "A4","","","B1", "B2", "B3", "B4", "B5", "B6", "C1", "C2", "C3", "C4", "C5", "C6", "D1", "D2", "D3", "D4", "D5", "D6", "E1", "E2", "E3", "E4", "E5", "E6"};
	int k = 0;
	ifstream source;
	switch(mt){
		case 2 : source.open("Booklist_m1t1.txt"); break;
		case 3 : source.open("Booklist_m1t2.txt"); break;
		case 4 : source.open("Booklist_m1t3.txt"); break;
		case 5 : source.open("Booklist_m2t1.txt"); break;
		case 6 : source.open("Booklist_m2t2.txt"); break;
		case 7 : source.open("Booklist_m2t3.txt"); break;
		case 10 : source.open("Booklist_m3t1.txt"); break;
		case 11 : source.open("Booklist_m3t2.txt"); break;
		case 12 : source.open("Booklist_m3t3.txt"); break;
	}

	while(getline(source,textline)){
		s[k] = textline;
		k++;  
    }
	source.close();
	int N= k/2;
    string out[N];
    int x=0;
	int y=0;
	
    while(y < k){
        out[x] = s[y] + s[y+1];
       	y = y+2;
       	x++;    	
	}
	
    for(int i =0 ; i<30 ; i++){
        for(int j=0 ; j<x ; j++){
            if(out[j] == seat[i]){
                seat[i] = "--";
            }
        }
    }
    
 	cout << "Valiable Seats";

    for(int i=0; i<30 ; i++){
		if(i%6 == 0){
			cout << endl ;
            cout << seat[i] << "  ";

		}else{
            cout << seat[i] << "  ";

		}
	}
    
    
}
