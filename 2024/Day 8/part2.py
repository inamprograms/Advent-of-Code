grid = [line.strip() for line in open('2024/input.txt')]

rows = len(grid)
cols = len(grid[0])

antennas = {}
for r, row in enumerate(grid):
    for c, ch in enumerate(row):
        if ch != '.': 
            if ch not in antennas: antennas[ch] = []
            antennas[ch].append((r, c))

antinodes = set()
for array in antennas.values():
    for i in range(len(array)):
        for j in range(len(array)):
            if i == j: continue
            r1, c1 = array[i]
            r2, c2 = array[j]
            dr = r2 - r1
            dc = c2 - c1
            r = r1
            c = c1
            while 0 <= r < rows and 0 <= c < cols:
                antinodes.add((r, c))
                r += dr
                c += dc
            

print(len([0 for r, c in antinodes if 0 <= r < rows and 0 <= c < cols]))