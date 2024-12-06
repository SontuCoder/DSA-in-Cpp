#include<iostream>
#include<algorithm>
#include <numeric> // For accumulate
#include<vector>
#include<array>
using namespace std;

void print(array<int,10> a){
    for(int i: a){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    
    vector<int> v = {1,3,5,6,8,9,12,42};

    // Binary search use in vector, array, deque;
    cout<<binary_search(v.begin(),v.end(),6) << endl; 
    cout<<binary_search(v.begin(),v.end(),32) << endl;

    cout<<"Max between them: "<<max(5,6)<<endl;
    auto max = max_element(v.begin(),v.end()); // it gives reference.
    cout<<"Max in v: "<<*max<<endl;
    // Smae for min , min_element;

    array<int,10> a={3,1,3,6,5,3,1,5,3,8};
    cout<<"The array: ";
    print(a);

    // Sort and reverse canbe used in array, deque, vector, string; 
    sort(a.begin(),a.end());
    cout<<"The array: ";
    print(a);

    cout<<"Search 3: "<<binary_search(a.begin(),a.end(),3)<<endl;

    rotate(a.begin(),a.begin()+2,a.end());
    cout<<"After two rotate: ";
    print(a);

    reverse(a.begin(),a.end());
    cout<<"The array: ";
    print(a);

    cout<<"The count of 1: "<<count(a.begin(),a.end(),1)<<endl;

    cout<<"The Sum of all in a: "<<accumulate(a.begin(),a.end(),0)<<endl;

    cout << "Product of all elements: " << accumulate(a.begin(), a.end(), 1, [](int x, int y) { return x * y; }) << endl; 

    int c = 12;
    int b = 32;
    cout << "c : " << c << endl;
    cout<<"b : "<<b<<endl;
    swap(c,b);
    cout << "c : " << c << endl;
    cout<<"b : "<<b<<endl;

    return 0;
}