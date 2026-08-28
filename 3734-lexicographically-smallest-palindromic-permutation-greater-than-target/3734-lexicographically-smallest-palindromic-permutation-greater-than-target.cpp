class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        
        int oddCnt = 0, oddChar = -1;
        for (int c = 0; c < 26; c++) {
            if (cnt[c] % 2) { oddCnt++; oddChar = c; }
        }
        bool needMid = (n % 2 == 1);
        if (needMid && oddCnt != 1) return "";
        if (!needMid && oddCnt != 0) return "";
        
        int half = n / 2;
        char midChar = needMid ? ('a' + oddChar) : 0;
        vector<int> pairs(26);
        for (int c = 0; c < 26; c++) pairs[c] = cnt[c] / 2;

        vector<int> avail = pairs;
        int matchedLen = 0, devPos = -1;
        char devChar = 0;
        
        for (int i = 0; i < half; i++) {
            int t = target[i] - 'a';
            for (int c = t + 1; c < 26; c++) {
                if (avail[c] > 0) { devPos = i; devChar = 'a' + c; break; }
            }
            if (avail[t] > 0) { avail[t]--; matchedLen++; }
            else break;
        }
        
        if (matchedLen == half) {
            string firstHalf = target.substr(0, half);
            string mirrored(firstHalf.rbegin(), firstHalf.rend());
            
            if (needMid) {
                char tm = target[half];
                if (midChar > tm) return firstHalf + midChar + mirrored;
                if (midChar == tm && mirrored > target.substr(half + 1))
                    return firstHalf + midChar + mirrored;
            } else if (mirrored > target.substr(half)) {
                return firstHalf + mirrored;
            }
        }

        if (devPos == -1) return "";
        
        vector<int> rem = pairs;
        for (int j = 0; j < devPos; j++) rem[target[j] - 'a']--;
        rem[devChar - 'a']--;
        
        string firstHalf = target.substr(0, devPos) + devChar;
        for (int c = 0; c < 26; c++) firstHalf += string(rem[c], 'a' + c);
        
        string mirrored(firstHalf.rbegin(), firstHalf.rend());
        return needMid ? firstHalf + midChar + mirrored : firstHalf + mirrored;
    }
};