class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) < 3:
            return 0
        
        water = 0
        
        for i in range(len(height)):
            #TODO: make looking for lmax & rmax more efficient
            
            lmax=0
            rmax=0   
            
            for j in range(0, i):
                #compute lmax
                if height[j] > lmax:
                    lmax = height[j]
                
            for j in range(i+1, len(height)):
                #compute rmax
                if height[j] > rmax:
                    rmax = height[j]
            
            temp = min(lmax, rmax) - height[i]
            
            if temp > 0:
                water+=temp
            
        return water
