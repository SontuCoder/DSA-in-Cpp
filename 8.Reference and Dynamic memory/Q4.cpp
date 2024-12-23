// Jaggered array :-

#include<iostream>
using namespace std;

int main(){
    int row;
    cout<<"Enter the number of row :- ";
    cin>>row;

    int **arr = new int*[row];
    int length[row] = {0};// array for store all row lengths;

    for(int i=0; i<row; i++){
        int col;
        cout<<"Enter the elements number in row "<<i<<":- ";
        cin>>col;

        length[i] = col;
        arr[i] = new int[col];
        
        for(int j=0; j<col; j++){
            cout<<"Enter arr["<<i<<"]["<<j<<"] :-";
            cin>>arr[i][j];
        }
        cout<<endl;
    }

    cout << "\nThe jagged array is:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < length[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < row; i++) {
        delete[] arr[i]; 
    }
    delete[] arr;

    return 0;
}