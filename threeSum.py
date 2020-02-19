class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        
        nums = sorted(nums)
        
        for i in range(len(nums)-2):
            
            if nums[i]>0:
                return res
            
            if i>0 and nums[i]==nums[i-1]:
                continue

            r = len(nums)-1
            
            for j in range(i+1, len(nums)-1):
                if j>i+1 and nums[j]==nums[j-1]:
                    continue
                while r > j:
                    if r< len(nums)-1 and nums[r] == nums[r+1]:
                        r-=1
                        continue
                    target = nums[i] + nums[j] + nums[r]
                    if target < 0:
                        break
                    if target == 0:
                        res.append([nums[i], nums[j], nums[r]])
                        break
                    r-=1
        
        return res
