from collections import deque
grid = [list(line.strip()) for line in open("2024/input.txt")]

rows = len(grid)
cols = len(grid[0])

# Identifying regions using (BFS) flood filling
regions = []
seen = set()

for r in range(rows):
    for c in range(cols):
        if (r, c) in seen: continue
        seen.add((r, c))
        region = {(r, c)}
        q = deque([(r, c)])
        crop  = grid[r][c]
        while q:
            cr, cc = q.popleft()
            for nr, nc in [(cr, cc + 1), (cr, cc - 1), (cr - 1, cc), (cr + 1, cc)]:
                if nr < 0 or nc < 0 or nr >= rows or nc >= cols: continue
                if grid[nr][nc] != crop: continue
                if (nr, nc) in region: continue
                region.add((nr, nc))
                # seen.add((nr, nc))
                q.append((nr, nc))
        seen |= region
        regions.append(region)

def perimeter(region):
    output = 0
    for (r, c) in region:
        output += 4
        for nr, nc in [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)]:
            if (nr, nc) in region:
                output -= 1
    return output

print(sum(len(region) * perimeter(region) for region in regions))