// finding the sum of maximum and minimum elements in every window of size 𝑘

#include <iostream>
#include <deque>
using namespace std;

int solve(int arr[], int n, int k) {
    deque<int> mini, maxi;
    int ans = 0;

    // Process first k elements
    for (int i = 0; i < k; i++) {
        // Maintain decreasing order in maxi deque
        while (!maxi.empty() && arr[maxi.back()] <= arr[i]) {
            maxi.pop_back();
        }
        // Maintain increasing order in mini deque
        while (!mini.empty() && arr[mini.back()] >= arr[i]) {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    // First window sum
    ans += arr[maxi.front()] + arr[mini.front()];

    // Process remaining elements
    for (int i = k; i < n; i++) {
        // Remove elements out of this window
        while (!maxi.empty() && maxi.front() <= i - k) {
            maxi.pop_front();
        }
        while (!mini.empty() && mini.front() <= i - k) {
            mini.pop_front();
        }

        // Add new element to the deques
        while (!maxi.empty() && arr[maxi.back()] <= arr[i]) {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.back()] >= arr[i]) {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

        // Add current window sum
        ans += arr[maxi.front()] + arr[mini.front()];
    }

    return ans;
}

int main() {
    int arr[] = {2, -5, -1, 7, -3, -1, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    cout << "Sum of max and min in each window: " << solve(arr, n, k) << endl;

    return 0;
}
