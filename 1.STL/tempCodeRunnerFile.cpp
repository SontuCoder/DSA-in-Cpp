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
    sort(a.begin(),a.begin()+2);
    cout<<"The array: ";