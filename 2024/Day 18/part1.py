from collections import deque

size = 70
n = 1024

grid = [[0] * (size + 1) for _ in range(size + 1)]
coordinates = [list(map(int, line.split(","))) for line in open("2024/input.txt")]

for c, r in coordinates[:n]:
    grid[r][c] = 1

# BFS
q = deque([(0, 0, 0)])
seen = {(r, c)}

while q:
    r, c, d = q.popleft()
    for  nr, nc in [(r - 1, c), (r, c + 1), (r + 1, c), (r, c - 1)]:
        if nr < 0 or nc < 0 or nr > size or nc > size: continue
        if grid[nr][nc] == 1: continue
        if (nr, nc) in seen: continue
        if nr == nc == size:
            print(d + 1)
            exit(0)
        seen.add((nr, nc))
        q.append((nr, nc, d + 1))