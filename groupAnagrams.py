class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        if not strs:
            return []
        
        t = collections.Counter(strs[0])
            
        res =[[strs[0]]]
        
        cnt = [t]
        
        for i in range(1, len(strs)):
            f=False
            t = collections.Counter(strs[i])
            for j in range(len(cnt)):
                if cnt[j]==t:
                    res[j].append(strs[i])
                    f=True
                    break
            if f == False:
                res.append([strs[i]])
                cnt.append(t)
        
        return res
