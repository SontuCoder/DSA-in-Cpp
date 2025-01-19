// Next permutation :-

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print(vector<int> v)
{
    cout << "Elements :- ";
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

void nextPer(vector<int> &v)
{
    next_permutation(v.begin(), v.end());
}

void reverse(vector<int> &v)
{
    int i = 0;
    int j = v.size() - 1;
    while (i < j)
    {
        swap(v[i], v[j]);
        i++;
        j--;
    }
}

// TC => O(nlogn) SC=> O(1)
void nextPer2(vector<int> &nums) // 1 3 2
{
    if (nums.size() <= 1)
        return;

    int i;
    for (i = nums.size() - 2; i >= 0; i--) // find the first index of element from right which is smaller then after it's; (1) 3 2
    {
        if (nums[i] < nums[i + 1])
        {
            break;
        }
    }
    if (i == -1) // in case the numbers is revers sorted like 321
    {
        reverse(nums);
        return;
    }

    int mini = i + 1;
    for (int small = i; small < nums.size(); small++) // find the index of the next greater element (not just the smallest in the right subarray). 1 3 (2)
    {
        if (nums[small] > nums[i] && nums[small] < nums[mini])
        {
            mini = small;
        }
    }
    swap(nums[i], nums[mini]); // 2 3 1

    sort(nums.begin() + i + 1, nums.end()); // sort rest elements after index i -> 2 1 3
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    print(v);
    // nextPer(v);
    // print(v);
    nextPer2(v);
    print(v);
    return 0;
}