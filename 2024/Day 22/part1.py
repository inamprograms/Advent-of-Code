# modulus = 2 ** 24 - 1
# def step(num):
#     num = (num ^ (num << 6)) & 0xFFFFFF
#     num = (num ^ (num >> 5)) & 0xFFFFFF
#     num = (num ^ (num << 11)) & modulus
#     return num

# total = 0

# for line in open("2024/input.txt"):
#     num = int(line)
#     for _ in range(2000):
#         num = step(num)
#     total += num
# print(total)

init_sec = [int(line.strip()) for line in open("2024/input.txt")]

def generate(num):
    
    sn = num
    for i in range(2000):
        given_num = sn
        sn = sn * 64
        sn = given_num ^ sn
        sn = sn % 16777216
        
        given_num = sn
        sn = sn // 32
        sn = given_num ^ sn
        sn = sn % 16777216
        
        given_num = sn
        sn = sn * 2048
        sn = given_num ^ sn
        sn = sn % 16777216
    return sn

print(sum(generate(n) for n in init_sec))