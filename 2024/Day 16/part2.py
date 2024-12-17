from collections import deque
import heapq

# Input processing and find start position
grid = [list(line.strip()) for line in open("2024/input.txt")]
rows = len(grid)
cols = len(grid[0])

for r in range(rows):
    for c in range(cols):
        if grid[r][c] == "S":
            sr = r
            sc = c
            break
    else:
        continue
    break

pq = [(0, sr, sc, 0, 1)] # pq to find next posible cheepest option/lowest cost to get to end (E)
lowest_cost = {(sr, sc, 0, 1): 0} # map to get what is lowest cost of each state to get there
backtrack = {} # map which gives all of the previous states along the path for each position / for eaach state what all possible ways to get there were
best_cost = float("inf") # best way to the loswest cost to get to the a ctual end
end_states = set() # list of all possible states that got us to end (E)

# Dijkstra's for all path algorithm with backtracking computed
while pq:
    cost, r, c, dr, dc = heapq.heappop(pq) # grab next possible state we can reach
    if cost > lowest_cost.get((r, c, dr, dc), float("inf")): continue # if state is worse than lowest then ignore it
    lowest_cost[(r, c, dr, dc)] = cost
    if grid[r][c] == "E": # if state is at the end(E) of grid
        if cost > best_cost: break # if state cost is worse that the best cost it means we already processed the all of best ways to get to end, all future states are inferior so we can break 
        best_cost = cost # update the best cost
        end_states.add((r, c, dr, dc)) # add one of the possible state (E)
    # Otherwise Loop through each of possible procedures (moving forward, turning clockwise, turning counter clockwise)
    for new_cost, nr, nc, ndr, ndc in [(cost + 1, r + dr, c + dc, dr, dc), (cost + 1000, r, c, dc,-dr), (cost + 1000, r, c, -dc, dr)]:
        if grid[nr][nc] == "#": continue # skip if there is wall
        lowest = lowest_cost.get((nr, nc, ndr, ndc), float("inf")) # lowest cost to get to the next state
        if new_cost > lowest: continue # if this method is worse then skip it
        if new_cost < lowest: # if this method is better
            backtrack[(nr,nc, ndr, ndc)] = set() # dump the backtrack
            lowest_cost[(nr,nc, ndr, ndc)] = new_cost # update the cost threshold
        backtrack[(nr,nc, ndr, ndc)].add((r, c, dr, dc)) # add current(r, c, dr, dc)state as one of optimal ways to get to next(nr,nc, ndr, ndc) state. if this is not optimal it will be dumped at line 39
        heapq.heappush(pq, (new_cost, nr, nc, ndr, ndc)) # add next state to pq for processing later when we get it

# BFS Fill algorithm
# look at all of end states as beginning of our flood fill
states = deque(end_states)
seen = set(end_states)
while states: # beginning of our flood fill
    # For each state we look at all ways that could have goten there and add them into set
    key = states.popleft()
    for last in backtrack.get(key, []):
        if last in seen: continue
        seen.add(last)
        states.append(last)  
              
# Set of all states that are along the path along with any optimal path to the end postion, we get rid of directions such that we only have actual cells(r, c). 
# Turn cells into set to remove duplicates and count the number of tiles along any optimal path in the maze
print(len({(r, c) for r, c, _, _ in seen})) 
        
        
# ***************************************************************************************************************** #                
# BACKTRACKING WAY 1        
    
# pq = [(0, sr, sc, 0, 1)]
# lowest_cost = {(sr, sc, 0, 1): 0}
# backtrack = {}
# best_cost = float("inf")      
# while pq:
#     cost, r, c, dr, dc = heapq.heappop(pq)
#     if cost > lowest_cost.get((r, c, dr, dc), float("inf")): continue
#     lowest_cost[(r, c, dr, dc)] = cost
#     if grid[r][c] == "E":
#         print(cost)
#         if cost > best_cost: break
#         best_cost = cost
#     for new_cost, nr, nc, ndr, ndc in [(cost + 1, r + dr, c + dc, dr, dc), (cost + 1000, r, c, dc,-dr), (cost + 1000, r, c, -dc, dr)]:
#         if grid[nr][nc] == "#": continue
#         lowest = lowest_cost.get((nr, nc, ndr, ndc), float("inf"))
#         if new_cost > lowest: continue
#         if new_cost < lowest: 
#             backtrack[(nr,nc, ndr, ndc)] = set()
#             lowest_cost[(nr,nc, ndr, ndc)] = new_cost
#         backtrack[(nr,nc, ndr, ndc)].add((r, c, dr, dc))
#         heapq.heappush(pq, (new_cost, nr, nc, ndr, ndc))    
# print(backtrack)    
         
                         
# BACKTRACKING WAY 2
        
# pq = [(0, sr, sc, 0, 1, None, None, None, None)]
# lowest_cost = {(sr, sc, 0, 1): 0}
# backtrack = {}
# best_cost = float("inf")
# while pq:
#     cost, r, c, dr, dc, lr, lc, ldr, ldc = heapq.heappop(pq)
#     if cost > lowest_cost.get((r, c, dr, dc), float("inf")): continue
#     lowest_cost[(r, c, dr, dc)] = cost
#     if grid[r][c] == "E":
#         print(cost)
#         if cost > best_cost: break
#         best_cost = cost
#     if (r, c, dr, dc) not in backtrack: backtrack[(r, c, dr, dc)] = set()
#     backtrack[(r, c, dr, dc)].add((lr, lc, ldr, ldc))
#     for new_cost, nr, nc, ndr, ndc in [(cost + 1, r + dr, c + dc, dr, dc), (cost + 1000, r, c, dc,-dr), (cost + 1000, r, c, -dc, dr)]:
#         if grid[nr][nc] == "#": continue
#         if cost > lowest_cost.get((nr, nc, ndr, ndc), float("inf")): continue
#         heapq.heappush(pq, (new_cost, nr, nc, ndr, ndc, r, c, dr, dc))
# print(backtrack)