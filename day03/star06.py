def score(c):
    s = 1 + ord(c)
    s -= ord('a') if c.islower() else (ord('A') - 26)
    return s

def find_badge(lines):
    s1, s2, s3 = map(set, lines)
    badge = (s1 & s2 & s3).pop()
    return badge

with open('input.txt') as f:
    total = 0
    while True:
        lines = [f.readline().strip() for _ in range(3)]
        if not lines[0]:
            break
        total += score(find_badge(lines))

print(f"{total = }")