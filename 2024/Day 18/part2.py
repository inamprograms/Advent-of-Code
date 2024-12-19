from collections import deque

size = 70
coordinates = [list(map(int, line.split(","))) for line in open("2024/input.txt")]

def connected(n):
    
    grid = [[0] * (size + 1) for _ in range(size + 1)]

    for c, r in coordinates[:n]:
        grid[r][c] = 1

    # BFS
    q = deque([(0, 0)])
    seen = {(r, c)}

    while q:
        r, c = q.popleft()
        for  nr, nc in [(r - 1, c), (r, c + 1), (r + 1, c), (r, c - 1)]:
            if nr < 0 or nc < 0 or nr > size or nc > size: continue
            if grid[nr][nc] == 1: continue
            if (nr, nc) in seen: continue
            if nr == nc == size: return True
            seen.add((nr, nc))
            q.append((nr, nc))
    return 

# Binary search
low = 0
high = len(coordinates) - 1
while low < high:
    mid = (low + high) // 2
    if connected(mid + 1):
        low = mid + 1
    else:
        high = mid
        
print(*coordinates[low], sep=",")