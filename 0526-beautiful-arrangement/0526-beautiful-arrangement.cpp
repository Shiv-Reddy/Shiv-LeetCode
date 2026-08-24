class Solution {
public:
    int countArrangement(int n) {
        vector<int> memo(1 << n, -1);
        return backtrack(n, 1, 0, memo);
    }
    
private:
    int backtrack(int n, int pos, int mask, vector<int>& memo) {
        if (pos > n) return 1;
        if (memo[mask] != -1) return memo[mask];
        
        int count = 0;
        for (int num = 1; num <= n; num++) {
            if (!(mask & (1 << (num - 1))) && (num % pos == 0 || pos % num == 0)) {
                count += backtrack(n, pos + 1, mask | (1 << (num - 1)), memo);
            }
        }
        
        memo[mask] = count;
        return count;
    }
};