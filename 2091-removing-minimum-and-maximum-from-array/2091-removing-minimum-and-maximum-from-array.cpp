class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        
        int minIdx = 0, maxIdx = 0;
        int minVal = nums[0], maxVal = nums[0];
        
        for (int i = 1; i < n; i++) {
            int v = nums[i];
            if (v < minVal) { minVal = v; minIdx = i; }
            else if (v > maxVal) { maxVal = v; maxIdx = i; }
        }
        
        int i = min(minIdx, maxIdx);
        int j = max(minIdx, maxIdx);
        
        return min({j + 1, n - i, (i + 1) + (n - j)});
    }
};