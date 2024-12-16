# def find_freespace(idx):
#     while disk[idx] != -1:
#         idx += 1
#     return idx

with open("D:/Git Hub Repos/Advent of Code/2024/input.txt", 'r') as file:
        line = file.readline().strip()
        
disk = []
file_id = 0

for i, ch in enumerate(line):
    x = int(ch)
    if i % 2 == 0:
        disk += [file_id] * x
        file_id += 1
    else:
        disk += [-1] * x

freespaces = [i for i, x in enumerate(disk) if x == -1]
for space in freespaces:
    while disk[-1] == -1:
        disk.pop()
    if len(disk) <= space: break
    disk[space] = disk.pop()

checksum = 0
for i , x in enumerate(disk):
    checksum +=  i * x
print(checksum)