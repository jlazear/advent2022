def check(line, left, seq_len=4):
    s = set(line[left:left+seq_len])
    return (len(s) == seq_len)

def find_sequence(line, seq_len=4):
    left = 0
    while not check(line, left, seq_len):
        left += 1
    return left

with open('input.txt') as f:
    line = f.readline()
seq_len = 4

print(f"{seq_len = } {find_sequence(line, seq_len) + seq_len = }")