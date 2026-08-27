class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        
        int devPos = -1;
        char devChar = 0;
        
        vector<int> curFreq = freq;
        
        int i = 0;
        for (; i < n; i++) {
            int t = target[i] - 'a';
 
            for (int c = t + 1; c < 26; c++) {
                if (curFreq[c] > 0) {
                    devPos = i;
                    devChar = 'a' + c;
                    break;
                }
            }
            if (curFreq[t] > 0) {
                curFreq[t]--;  
            } else {
                break;           
            }
        }
        
        if (devPos == -1) return "";
        
        vector<int> rem = freq;
        for (int j = 0; j < devPos; j++) {
            rem[target[j] - 'a']--;
        }
        rem[devChar - 'a']--;
        
        string result = target.substr(0, devPos);
        result += devChar;
        for (int c = 0; c < 26; c++) {
            result += string(rem[c], 'a' + c);
        }
        
        return result;
    }
};