import re
# https://github.com/mgtezak/Advent_of_Code/blob/master/2024/03/p2.py

file_name = "input.txt"
with open(file_name, "r") as file:
        puzzle_input = file.read()
        
def part2(puzzle_input):
    do = r"do\(\)"
    dont = r"don't\(\)"
    mul = r"mul\((\d+),(\d+)\)"
    total = 0
    enabled = True
    for x in re.finditer(f'{do}|{dont}|{mul}', puzzle_input):
        if re.fullmatch(do, x.group()):
            enabled = True
        elif re.fullmatch(dont, x.group()):
            enabled = False
        elif enabled:
            total += int(x.group(1)) * int(x.group(2))

    return total

print(part2(puzzle_input))