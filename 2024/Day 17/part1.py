import re

a, b, c, *program =  map(int, re.findall(r"\d+", open("2024/input.txt").read()))
pointer = 0
output = []

def combo(operand):
    if 0 <= operand <= 3: return operand
    if operand == 4: return a
    if operand == 5: return b
    if operand == 6: return c
    else: raise RuntimeError("Urecognized combo operand", operand)
    
    
while pointer < len(program):
 
    instruction = program[pointer]
    operand = program[pointer + 1]
    
    if instruction == 0: # adv 
        a = a // 2 ** combo(operand)
        # a = a >> combo(operand) # right shifting
    elif instruction == 1: # bxl 
        b = b ^ operand
    elif instruction == 2: # bst
        b = combo(operand) % 8 
    elif instruction == 3: # jnz
        if a != 0:
            pointer = operand 
            continue
    elif instruction == 4: # bxc
        b = b ^ c
    elif instruction == 5: # out
        output.append(combo(operand) % 8)
    elif instruction == 6: # bdv
        b = a >> combo(operand)
    elif instruction == 7: # cdv
        c = a >> combo(operand) 
          
    pointer +=2

print(*output, sep=",")