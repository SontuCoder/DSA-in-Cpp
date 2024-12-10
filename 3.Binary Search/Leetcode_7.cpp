
// Given an array 'arr' of integer numbers. where 'arr[i]' represents the number of peges in the i th' book. There are 'm' number of students and the task is to allocate all the books to their students. Allocate books in such a way that:

// 1. Each student gets at least one book.
// 2. Each book should be allocated to a student.
// 3. Book allocation should be in a contiguous manner.
// 4. Array could not be sorted.

// You have to allocate the book to 'm' students such that the maximum number of pages assigned to a student is minimum.
// Example:
// Let's consider 'n=4' (number of books) and 'm=2' (number of students).
// [10, 20, 30, 40].

// All possible way to allocate the '4' books in '2' number of students is -
// 10 | 20, 30, 40 -sum of all the pages of books which allocated to student-1 is "10", and student-2 is 20+30+40=90, so maximum is 'max(10, 90)= 90;
// 10, 20 | 30, 40 sum of all the pages of books which allocated to student-1 is 10+ 20 = 30, and student-2 is '30 + 40 =70' so maximum is 'max(30, 70)=70;
// 10, 20, 30 | 40-sum of all the pages of books which allocated to student-1 is 10+ 20+ 30= 60', and student-2 is '40' so maximum is 'max(60, 40)= 60';
// So possible maximum number of pages which allocated to a single student is (90, 70, 60).
// But you have to return a minimum of this so return 'min(90,70,60)=60


#include<iostream>
#include<vector>
#include<numeric> // use #include<bits/stdc++.h> for avoid all header files like <vector>, <string>, <algorithm>, <Iostream> etc;
using namespace std;

bool isPosibleSol(vector<int> v, int s, int mid){
    int stuCount = 1;
    int pageSum = 0;

    for(int i:v){
        if(pageSum+i<=mid){
            pageSum+=i;
        } else {
            stuCount+=1;
            if(stuCount>s || i>mid){
                return false;
            }
            pageSum =i;
        }
    }
    return true;
}


int minPage(vector<int> v, int s){
    int i=0, j= accumulate(v.begin(), v.end(), 0);
    int sum = j;
    int ans = -1;
    while(i<=j){
        int mid = i+(j-i)/2;
        if(isPosibleSol(v,s,mid)){
            ans = mid;
            j=mid-1;
        } else {
            i = mid+1;
        }
    }
}


int main(){
    int n;
    vector<int> v;
    cout<<"Enter the number of books:-";
    cin>>n;
    int j;
    for(int i=0; i<n; i++){
        cout<<"Enter the book pages:-";
        cin>>j;
        v.push_back(j);
    }
    int s;
    cout<<"Enter the number of students:-";
    cin>>s;
    cout<<"The minimum number of pages:-"<<minPage(v,s);
    return 0;
}