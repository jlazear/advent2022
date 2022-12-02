elves = []
with open('input.txt') as f:
    calories = 0
    for line in f:
        if not line.strip():
            elves.append(calories)
            calories = 0
            continue
        calories += int(line.strip())

elves = sorted(elves)

print(sum(elves[-3:]))