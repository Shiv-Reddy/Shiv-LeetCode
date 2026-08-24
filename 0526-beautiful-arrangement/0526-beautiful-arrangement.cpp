class Solution {
public:
    int count = 0;
    
    int countArrangement(int n) {
        vector<bool> used(n + 1, false);
        backtrack(n, 1, used);
        return count;
    }
    
    void backtrack(int n, int pos, vector<bool>& used) {
        if (pos > n) {
            count++;
            return;
        }
        
        for (int num = 1; num <= n; num++) {
            if (!used[num] && (num % pos == 0 || pos % num == 0)) {
                used[num] = true;
                backtrack(n, pos + 1, used);
                used[num] = false;
            }
        }
    }
};