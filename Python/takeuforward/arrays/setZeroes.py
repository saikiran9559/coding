from typing import List
def setZeros(matrix: List[List[int]]) -> None:
	# Write your code here.
    m = len(matrix)
    n = len(matrix[0])
    col = set()
    for i in range(m):
        f=0
        for j in range(n):
            if matrix[i][j]==0:
                f=1
                col.add(j)
        if f==1:
            matrix[i]=[0]*n

    for val in col:
        for i in range(m):
            matrix[i][val]=0
    return matrix

matrix = [[0,2,3],[1,0,3],[1,2,0]]
matrix = [[7,9,13],[4,21,0]]
matrix = [[1,2,3],[4,0,5],[6,7,8]]
matrix = [  [28,4,81, 24,95],
            [0,53,48,39,35], 
            [89,52, 99, 16, 23], 
            [14,0,0,4,16]
        ]
print(setZeros(matrix))

  
   