void show_seat(int mt){
    //open Booklist file and read the data
    fstream source;
    source.open("D:\\Desktop\\code\\project - movie\\compro\\Booklist_m1t1.txt");
    string textline;
    char char_row[2];
    int i = 0, N = 0;
    int col[28] = {};
    int row[28] = {};
    // read the data and covert to row,col to book the seat
    while(getline(source,textline)){
        if(i%2 == 0) {
            strcpy(char_row,textline.c_str());
            if(char_row[0] == 'E') row[i] = 0;
            if(char_row[0] == 'D') row[i] = 1;
            if(char_row[0] == 'C') row[i] = 2;
            if(char_row[0] == 'B') row[i] = 3;
            if(char_row[0] == 'A') row[i] = 4;
        }
        else col[i-1] = stoi(textline);
        i++;
    }
    source.close();

    // update data one by one
    int position;
    for(int j = 0; j<i; j+=2){
        //switch seat array from 2 dimension to 1 dimension
        position = row[j]*6-1+col[j];
        cout<<row[j]<<" "<<col[j]<<" "<<position<<endl;
        update_seat(position);
    }
}