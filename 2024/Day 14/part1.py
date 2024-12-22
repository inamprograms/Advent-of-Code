import re

WIDTH = 101
HEIGHT = 103

rebots = []

for line in open("2024/input.txt"): 
    rebots.append(tuple(map(int, re.findall(r"-?\d+", line))))

results = []

for px, py, vx, vy in rebots:
    results.append(((px + vx * 100) % WIDTH, (py + vy * 100) % HEIGHT))

# grid = [[0] * WIDTH for _ in range(HEIGHT)]

# for px, py in results:
#     grid[py][px] += 1

# for row in grid:
#     print(*row, sep="")

tl = bl = tr = br = 0
VM = (HEIGHT - 1) // 2
HM = (WIDTH - 1) // 2

for px, py in results:
    if px == HM or py == VM: continue
    if px < HM:
        if py < VM:
            tl += 1
        else:
            bl += 1
    else:
        if py < VM:
            tr += 1
        else:
            br += 1

print(tl * bl * tr * br)