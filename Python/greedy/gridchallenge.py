grid = [
    'ebacd', 'fghij', 'olmkn', 'trpqs', 'xywuv'
]
def gridChallenge(grid):
    n = len(grid)
    m = len(grid[0])
    for i in range(n):
        h = list(grid[i])
        h.sort()
        grid[i] = h
    for i in range(m):
        for j in range(n-1):
            if ord(grid[j][i]) > ord(grid[j+1][i]):
                return 'NO'
    return "YES"

print(gridChallenge(grid))
