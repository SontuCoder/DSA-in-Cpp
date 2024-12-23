// Dynamic 2D array :-

#include<iostream>
using namespace std;


void print(int **arr, int m, int n){
    for(int i = 0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


// assign value in array 
void assign(int **arr, int m, int n){
    cout<<"Enter the data:-"<<endl;
    for(int i = 0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<"Enter arr["<<i<<"]["<<j<<"] :-";
            cin>>arr[i][j];
        }
        cout<<endl;
    }
}

int main(){
    int m,n;
    cout<<"Enter row:- ";
    cin>>m;
    cout<<"Enter column:- ";
    cin>>n;

    int **arr = new int*[m]; // Make colum arr of row arrays 

    for(int i = 0; i<m; i++){
        arr[i] = new int[n]; // add row array in every row;
    }

    assign(arr,m,n);

    print(arr,m,n);

    // free memory :-
    for(int i=0; i<m; i++){
        delete []arr[i];
    }
    delete []arr;

    return 0;
}