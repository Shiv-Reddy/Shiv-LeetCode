class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> ones;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') ones.push_back(i);
        }
        
        if (ones.size() < k) return "";
        
        string best = "";
        int minLen = INT_MAX;
        
        for (int i = 0; i + k - 1 < ones.size(); i++) {
            int start = ones[i];
            int end = ones[i + k - 1];
            int len = end - start + 1;
            string candidate = s.substr(start, len);
            
            if (len < minLen) {
                minLen = len;
                best = candidate;
            } else if (len == minLen && candidate < best) {
                best = candidate;
            }
        }
        
        return best;
    }
};