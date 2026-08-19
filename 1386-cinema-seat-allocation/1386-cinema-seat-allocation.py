class Solution(object):
    def maxNumberOfFamilies(self, n, reservedSeats):
        """
        :type n: int
        :type reservedSeats: List[List[int]]
        :rtype: int
        """
        rowMask = {}
        for row, col in reservedSeats:
            if 2 <= col <= 9:
                rowMask[row] = rowMask.get(row, 0) | (1 << (col - 2))
        
        LEFT = 0x0F   # seats 2-5
        MID  = 0x3C   # seats 4-7
        RIGHT = 0xF0  # seats 6-9
        
        result = 0
        for mask in rowMask.values():
            if (mask & LEFT) == 0 and (mask & RIGHT) == 0:
                result += 2
            elif (mask & MID) == 0:
                result += 1
            elif (mask & LEFT) == 0 or (mask & RIGHT) == 0:
                result += 1
        
        result += 2 * (n - len(rowMask))
        
        return result