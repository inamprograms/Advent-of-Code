# Reverse engineering problem
import re
program =  list(map(int, re.findall(r"\d+", open("2024/input.txt").read())[3:]))

def find(program, ans):
    if program == []: return ans
    for t in range(8):
        a = ans << 3 | t
        b = a % 8
        b = b ^ 3
        c = a >> b 
        # a = a >> 3
        b = b ^ 5
        b = b ^ c
        if b % 8 == program[-1]:
            sub = find(program[:-1], a)
            if sub is None: continue
            return sub

print(find(program, 0))