import re
file_name = "input.txt"
with open(file_name, "r") as file:
        puzzle_input = file.read()


def part1(puzzle_input):
    total = 0
    for a, b in re.findall(r"mul\((\d+),(\d+)\)", puzzle_input):
        total += int(a) * int(b)
        
    return total

print(part1(puzzle_input))