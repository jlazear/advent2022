with open('input.txt') as f:
    lines = f.readlines()

lines = [line.split() for line in lines]

# A = rock
# B = paper
# C = scissors

# X = lose
# Y = draw
# Z = win

play_dict = {'A': {'X': 'S', 'Y': 'R', 'Z': 'P'},  # rock
             'B': {'X': 'R', 'Y': 'P', 'Z': 'S'},  # paper
             'C': {'X': 'P', 'Y': 'S', 'Z': 'R'}}  # scissors

play_score = {'R': 1, 'P': 2, 'S': 3}
game_score = {'X': 0, 'Y': 3, 'Z': 6}

total = 0
for opp, yours in lines:
    score = game_score[yours] + play_score[play_dict[opp][yours]]
    total += score

print(f"{total = }")