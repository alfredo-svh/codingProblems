class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return None
        
        l = u = 0
        r = len(matrix[0])
        d = len(matrix)
        
        spiral = []
        
        while l<r and u<d:

            #top
            for i in range(l,r):
                spiral.append(matrix[u][i])
                
            u+=1


            #right
            for i in range(u, d):
                spiral.append(matrix[i][r-1])

            r-=1

			#bottom
            if u<d:
                for i in range(r-1, l-1,-1):
                    spiral.append(matrix[d-1][i])

                d-=1

			#left
            if l<r:
                for i in range(d-1, u-1, -1):
                    spiral.append(matrix[i][l])

                l+=1
            
        return spiral
