class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        int oddCount = 0, oddChar = -1;
        for (int c = 0; c < 26; c++) {
            if (count[c] % 2 == 1) { oddCount++; oddChar = c; }
        }
        if (n % 2 == 0 && oddCount != 0) return "";
        if (n % 2 == 1 && oddCount != 1) return "";
        
        int half_len = n / 2;
        int mid = n % 2;
        char mid_char = (mid == 1) ? ('a' + oddChar) : 0;
        
        vector<int> pairs(26);
        for (int c = 0; c < 26; c++) pairs[c] = count[c] / 2;
        
        vector<int> avail = pairs;
        int matched_len = 0;
        int bestDevPos = -1;
        char bestDevChar = 0;
        
        for (int i = 0; i < half_len; i++) {
            int t = target[i] - 'a';
            for (int c = t + 1; c < 26; c++) {
                if (avail[c] > 0) {
                    bestDevPos = i;
                    bestDevChar = 'a' + c;
                    break;
                }
            }
            if (avail[t] > 0) {
                avail[t]--;
                matched_len++;
            } else {
                break;
            }
        }
        
        if (matched_len == half_len) {
            string T1 = target.substr(0, half_len);
            string rev = T1;
            reverse(rev.begin(), rev.end());
            
            if (mid == 1) {
                char tm = target[half_len];
                if (mid_char > tm) {
                    return T1 + mid_char + rev;
                } else if (mid_char == tm) {
                    string T2 = target.substr(half_len + 1);
                    if (rev > T2) return T1 + mid_char + rev;
                }
            } else {
                string T2 = target.substr(half_len);
                if (rev > T2) return T1 + rev;
            }
        }
        
        if (bestDevPos == -1) return "";
        
        vector<int> rem = pairs;
        for (int j = 0; j < bestDevPos; j++) rem[target[j] - 'a']--;
        rem[bestDevChar - 'a']--;
        
        string firstHalf = target.substr(0, bestDevPos);
        firstHalf += bestDevChar;
        for (int c = 0; c < 26; c++) {
            firstHalf += string(rem[c], 'a' + c);
        }
        
        string result = firstHalf;
        if (mid == 1) result += mid_char;
        string rev = firstHalf;
        reverse(rev.begin(), rev.end());
        result += rev;
        
        return result;
    }
};