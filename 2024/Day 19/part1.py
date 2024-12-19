lines = open("2024/input.txt").read().splitlines()

patterns = set(lines[0].split(", "))
maxlen = max(map(len, patterns))

cache = {} # for memoization, manual caching for not to recompute answer for given substring 
def can_obtain(design):
    if design == "": return True
    if design in cache: return cache[design]
    for i in range(min(len(design), maxlen) + 1):
        if design[:i] in patterns and can_obtain(design[i:]):
            cache[design] = True
            return True
    cache[design] = False
    return False    
print(sum(1 if can_obtain(design) else 0 for design in lines[2:]))