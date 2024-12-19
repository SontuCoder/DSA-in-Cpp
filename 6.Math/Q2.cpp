// Count Prime numbers:- (using Sieve of Eratostenes)
// st1. Mark every as a prime.
// st2. If number fall in table, mark it non prime.

#include <iostream>
#include <vector>
using namespace std;

int countPrime(int n) // takes time O(n log log n)
{
    int count = 0;
    vector<int> v(n + 1, true);
    v[0] = v[1] = false;
    for (int i = 0; i <= n; i++) // O(n)
    {
        if (v[i])
        {
            count++;
            for (int j = 2; i * j <= n; j++) // O(log(log n))
            {
                v[i * j] = false;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter the number:-";
    cin >> n;
    cout << "The number of primes:- " << countPrime(n);
    return 0;
}