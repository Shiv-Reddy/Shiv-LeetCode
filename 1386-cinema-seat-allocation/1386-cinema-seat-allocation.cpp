class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask;
        
        for (auto& seat : reservedSeats) {
            int row = seat[0], col = seat[1];
            if (col >= 2 && col <= 9) {
                rowMask[row] |= (1 << (col - 2));
            }
        }
        
        int result = 0;
        const int LEFT = 0x0F;   // seats 2-5
        const int MID  = 0x3C;   // seats 4-7
        const int RIGHT = 0xF0;  // seats 6-9
        
        for (auto& [row, mask] : rowMask) {
            if ((mask & LEFT) == 0 && (mask & RIGHT) == 0) {
                result += 2;
            } else if ((mask & MID) == 0) {
                result += 1;
            } else if ((mask & LEFT) == 0 || (mask & RIGHT) == 0) {
                result += 1;
            }
        }
        
        // rows with no reservations at all get 2 groups each
        result += 2 * (n - (int)rowMask.size());
        
        return result;
    }
};