class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<long long> ugly(n);
        ugly[0] = 1;
        
        vector<int> pointers(k, 0);      // index into ugly[] for each prime
        vector<long long> candidates(primes.begin(), primes.end()); // next candidate value for each prime
        
        for (int i = 1; i < n; i++) {
            long long nextUgly = *min_element(candidates.begin(), candidates.end());
            ugly[i] = nextUgly;
            
            // advance all pointers that produced this value (avoid duplicates)
            for (int j = 0; j < k; j++) {
                if (candidates[j] == nextUgly) {
                    pointers[j]++;
                    candidates[j] = primes[j] * ugly[pointers[j]];
                }
            }
        }
        
        return (int)ugly[n - 1];
    }
};