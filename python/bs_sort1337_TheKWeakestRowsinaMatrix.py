class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        def countone(row):
            l, h = 0, len(row)
            while l < h:
                mid = int((l + h) / 2)
                if row[mid]: 
                    l = l + 1
                else:
                    h = mid
            return l
        
        st = sorted([(countone(row), i) for i, row in enumerate(mat)])
        return [v[1] for v in st][: k]
                    
                    
