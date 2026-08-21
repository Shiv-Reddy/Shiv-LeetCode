class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, curEnd = 0, farthest = 0;
        
        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + nums[i]);
            if (i == curEnd) {          // must jump now to progress
                jumps++;
                curEnd = farthest;
                if (curEnd >= n - 1) break;  // already reaches the end
            }
        }
        return jumps;
    }
};