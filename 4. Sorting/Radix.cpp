// Redix sort:-

#include<iostream>
#include<vector>
using namespace std;

void printVector(const vector<int>& vec) {
    cout << "The Vector is: ";
    for(int i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

int getMax(vector<int>& v) {
    int max = v[0];
    for(int i = 1; i < v.size(); i++) {
        if(v[i] > max) max = v[i];
    }
    return max;
}

void coutingSort(vector<int>& v, int div) {
    vector<int> count(10, 0);  // Initialize with zeros
    vector<int> output(v.size());  // Output array
    
    // Count occurrences
    for(int i = 0; i < v.size(); i++) {
        count[(v[i]/div)%10]++;
    }
    
    // Calculate cumulative count
    for(int i = 1; i < 10; i++) {
        count[i] += count[i-1];
    }
    
    // Build output array
    for(int i = v.size()-1; i >= 0; i--) {
        output[count[(v[i]/div)%10]-1] = v[i];
        count[(v[i]/div)%10]--;
    }
    
    // Copy back to original array
    for(int i = 0; i < v.size(); i++) {
        v[i] = output[i];
    }
}

void redixSort(vector<int> & v){
    int m = getMax(v);
    for(int div = 1; m/div>0; div*=10){
        coutingSort(v, div);
    }
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
    redixSort(vec);
    printVector(vec);
    
    
    return 0;
}