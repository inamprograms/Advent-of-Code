with open("2024/input.txt", 'r') as file:
        line = file.readline().strip()
        
files = {}
spaces = []
file_id = 0
pos = 0

for i, ch in enumerate(line):
    x = int(ch)
    if i % 2 == 0:
        if x == 0:
            raise ValueError("Unexpected x=0 for file")
        files[file_id] = (pos, x)
        file_id += 1
    else:
        if x != 0:
            spaces.append((pos, x))
    pos += x
    
while file_id > 0:
    file_id -= 1
    pos, size = files[file_id]
    
    for i, (start, length) in enumerate(spaces):
        if start >= pos:
            spaces = spaces[:i]
            break
        if size <= length:
            files[file_id] = (start, size)
            if size == length:
                spaces.pop(i)
            else:
                spaces[i] = (start + size, length - size)
            break

# print(files)

checksum = 0
for fid, (pos, size) in files.items():
    for x in range(pos, pos + size):
        checksum +=  fid * x
print(checksum)

