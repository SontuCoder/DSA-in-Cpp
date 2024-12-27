// Sorts using Recursion:-

#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>& vec) {
    cout<<"The Vector be:- ";
    for(int i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int> &vec, int n){
    if(n <= 1) return;

    for(int i = 0; i<n-1; i++){
        if(vec[i]>vec[i+1]){
            swap(vec[i],vec[i+1]);
        }
    }
    bubbleSort(vec,n-1);
}

void insertionSort(vector<int> &vec, int i){
    if(i == vec.size()) return;
    
    int a = vec[i];
    int j = i-1;
    while(j>=0 && a<vec[j]){
        vec[j+1] = vec[j];
        j--; 
    }
    vec[j+1] = a;

    insertionSort(vec, i+1);
}

void selectionSort(vector<int> &v, int i){
    if(i==v.size()) return;
    int min = i;
    for(int j=i+1; j<v.size(); j++){
        if(v[j]<v[min]){
            min = j;
        }
    }
    swap(v[i], v[min]);
    selectionSort(v,i+1);
}

int main(){
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;

    vector<int> vec(n);
    cout << "Enter " << n << " elements:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    printVector(vec);
    selectionSort(vec,0);
    printVector(vec);
    return 0;
}