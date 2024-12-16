
# grid = [] 
# with open("../input.txt", 'r') as file:  
#     for line in file:  
#         line = line.strip()  
#         row = [] 
#         for char in line:  
#             row.append(int(char))  
#         grid.append(row)  

# trailheads = []
# for r in range(rows):
#     for c in range(cols):
#         if grid[r][c] == 0:
#             trailheads.append((r,c))

from collections import deque
grid = [[int(char) for char in line.strip()] for line in open("../input.txt", 'r')]

rows = len(grid)
cols = len(grid[0])

# Finding all start positions
trailheads = [(r, c) for r in range(rows) for c in range(cols) if grid[r][c] == 0]

# Finding score of each trailheads - BFS

def score(grid, r, c):    
    q = deque([(r, c)])
    seen = {(r, c)}
    summits = 0
    while len(q) > 0:
        # pop current item
        cr, cc = q.popleft() 
        # get all neighbours(above, right, below, left) of crrent item 
        for  nr, nc in [(cr - 1, cc), (cr, cc + 1), (cr + 1, cc), (cr, cc - 1)]:
            # check for out of bounds/ if item is not on our map, skip it
            if nr < 0 or nc < 0 or nr >= rows or nc >= cols: continue
            # if we cannot make step by 1 then skip
            if grid[nr][nc] != grid[cr][cc] + 1: continue
            if (nr, nc) in seen: continue
            seen.add((nr, nc))
            # check if next position is 9
            if grid[nr][nc] == 9:
                summits += 1
            else:
                q.append((nr, nc))
    
    return summits

print(sum(score(grid, r, c) for r, c in trailheads))
            
