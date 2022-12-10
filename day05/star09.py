from collections import deque

def read_input(fname='input.txt'):
    deques = [deque() for _ in range(9)]
    commands = []
    with open(fname) as f:
        for line in f:
            if line[0] in '\r\n':
                break
            for i in range(9):
                if (c := line[1 + i*4]) != ' ':
                    if c not in '1234567890':
                        deques[i].appendleft(c)
        
        for line in f:
            cmdlist = line.strip().split()
            n = int(cmdlist[1])
            source = int(cmdlist[3]) - 1
            dest = int(cmdlist[5]) - 1
            commands.append((n, source, dest))
    
    return deques, commands

def execute_command(deques, cmd):
    n, source, dest = cmd
    for _ in range(n):
        deques[dest].append(deques[source].pop())
    return deques


deques, commands = read_input()
for cmd in commands:
    execute_command(deques, cmd)

print(''.join([d.pop() for d in deques]))