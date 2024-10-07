#include <bits/stdc++.h>
using namespace std;
#define int long long

// Set the limit for the sieve (1e7 + 10 to handle large numbers)
const int N = 1e7 + 10;

// Arrays to store prime status, lowest prime (lp), and highest prime (hp)
vector<bool> isPrime(N, true); // Initially assume all numbers are prime
vector<int> lp(N, 0), hp(N, 0); // Lowest and highest prime factors

// Sieve function to mark non-primes and store prime factors
void sieve()
{
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime
    for (int i = 2; i < N; i++)
    {
        // If 'i' is prime, mark its multiples
        if (isPrime[i] == true)
        {
            lp[i] = hp[i] = i; // Set 'i' as its own lowest and highest prime factor
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false; // Mark multiples of 'i' as non-prime
                hp[j] = i; // Update the highest prime factor for 'j'
                if (lp[j] == 0)
                    lp[j] = i; // Set the lowest prime factor for 'j' if not already set
            }
        }
    }
}

signed main()
{
    // Speed up I/O operations
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t; // Read number of test cases

    sieve(); // Precompute primes and prime factors

    while (t--)
    {
        int n;
        cin >> n; // Read each query number
        // Output the number and its prime status (1 for prime, 0 for non-prime)
        cout << n << " " << isPrime[n] << endl;
    }

    return 0;
}
