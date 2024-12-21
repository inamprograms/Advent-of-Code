import re

total = 0
for block in open("2024/input.txt").read().split('\n\n'):
    ax, ay, bx, by, px, py = map(int, re.findall(r"\d+", block))
    
# Brute force    
    # min_score = float("inf")
    # for i in range(101):
    #     for j in range(101):
    #         if ax * i + bx * j == px and ay * i + by * j == py:
    #              min_score = min(min_score, i * 3 + j)
    # if min_score != float("inf"):
    #     total += min_score

# Geometrically(by finding intersetion of two lines) or algebraically (by solving system of linear equations)
    px, py = px + 10000000000000, py + 10000000000000 # For part 2
    ca = (px * by - py * bx) / (ax * by - ay * bx)
    cb= (px - ax * ca) / bx
    if ca % 1 == cb % 1 == 0:
        # if ca <= 100 and cb <= 100: # For part 1
        total += int(ca * 3 + cb)

print(total)