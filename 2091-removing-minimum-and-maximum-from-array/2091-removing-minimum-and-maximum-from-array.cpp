class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        
        const int* p = nums.data();
        int minVal = p[0], maxVal = p[0];
        int minIdx = 0, maxIdx = 0;
        
        for (int i = 1; i < n; i++) {
            int v = p[i];
            if (v < minVal) { minVal = v; minIdx = i; }
            else if (v > maxVal) { maxVal = v; maxIdx = i; }
        }
        
        int i = minIdx < maxIdx ? minIdx : maxIdx;
        int j = minIdx < maxIdx ? maxIdx : minIdx;
        
        int opt1 = j + 1;
        int opt2 = n - i;
        int opt3 = (i + 1) + (n - j);
        
        int ans = opt1 < opt2 ? opt1 : opt2;
        return ans < opt3 ? ans : opt3;
    }
};