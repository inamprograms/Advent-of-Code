from collections import defaultdict

def lookup(val, m):
    _, *ranges = m.split('\n')
    for r in ranges:
        dest, src, n = map(int, r.split())
        if src <= val < src + n:
            return (val - src) + dest
    return val

def part1(lines):
    print(f"Part 1!")
    seeds, *maps = lines.split('\n\n')
    seeds = list(map(lambda x: int(x), seeds.split()[1:]))
    vals = defaultdict(int, {key: key for key in seeds})
    for index, s in enumerate(seeds):
        for mp in maps:
            vals[s] = lookup(vals[s], mp)
    print(f"Result: {min(vals)} has the lowest location value of: {vals[min(vals)]}")


def openFile():
    return open("input.txt", "r").read()

def main():
    f = openFile()
    part1(f)