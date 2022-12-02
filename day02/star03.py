with open('input.txt') as f:
    lines = f.readlines()

lines = [line.split() for line in lines]

# A/X = rock
# B/Y = paper
# C/Z = scissors

game_score = {'A': {'X': 3, 'Y': 6, 'Z': 0},
              'B': {'X': 0, 'Y': 3, 'Z': 6},
              'C': {'X': 6, 'Y': 0, 'Z': 3}}

play_score = {'X': 1, 'Y': 2, 'Z': 3}

total = 0
for opp, yours in lines:
    score = game_score[opp][yours] + play_score[yours]
    total += score

print(f"{total = }")