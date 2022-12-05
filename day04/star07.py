def check_line(line):
    line = line.strip()
    xs, ys = line.split(',')
    x1, x2 = map(int, xs.split('-'))
    y1, y2 = map(int, ys.split('-'))

    return (x1 <= y1 and y2 <= x2) or (y1 <= x1 and x2 <= y2)

n = 0
with open('input.txt') as f:
    for line in f:
        if check_line(line):
            n += 1

print(f"{n = }")
