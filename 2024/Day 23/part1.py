# Graph theory problem
edges = [line.strip().split("-") for line in open("2024/input.txt")]

conns = {}
for x, y in edges:
    if x not in conns: conns[x] = set()
    if y not in conns: conns[y] = set()
    
    conns[x].add(y)
    conns[y].add(x)

# sets = set()
# for x in conns: # key
#     for y in conns[x]: # value - set()
#         for z in conns[y]: 
#             if x !=  z and x in conns[z]:
#                 sets.add(tuple(sorted([x, y, z])))

# print(len([s for s in sets if any(cn.startswith("t") for cn in s)]))

total = 0
sets = set()
for x in conns:
    for y in conns[x]:
        for z in conns[y]: 
            if x !=  z and x in conns[z] and any(cn.startswith("t") for cn in [x, y, z]):
                total += 1

print(total // 6)