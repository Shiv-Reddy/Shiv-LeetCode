class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        
        int i = min(minIdx, maxIdx);
        int j = max(minIdx, maxIdx);
        
        int fromFront = j + 1;

        int fromBack = n - i;

        int fromBoth = (i + 1) + (n - j);
        
        return min({fromFront, fromBack, fromBoth});
    }
};