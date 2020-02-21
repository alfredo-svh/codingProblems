class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        if not prices:
            return 0
    
        maxDif = 0
        mn = prices[0]

        for i in range(1,len(prices)):
            if prices[i] < mn:
                mn = prices[i]
                
            else:
                curDif = prices[i] - mn
                if curDif > maxDif:
                    maxDif = curDif
                    
        return maxDif
