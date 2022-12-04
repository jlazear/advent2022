def score(c):
    s = 1 + ord(c)
    s -= ord('a') if c.islower() else (ord('A') - 26)
    return s

def find_error(line):
    line = line.strip()
    comp1 = line[:len(line)//2]
    comp2 = line[len(line)//2:]
    s1 = set(comp1)
    s2 = set(comp2)
    return s1.intersection(s2).pop()

with open('input.txt') as f:
    total = 0
    for line in f:
        total += score(find_error(line))

print(f"{total = }")