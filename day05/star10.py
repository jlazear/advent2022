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
    
    lists = [list(d) for d in deques]
    return lists, commands

def execute_command(lists, cmd):
    n, source, dest = cmd
    lists[dest].extend(lists[source][-n:])
    del lists[source][-n:]
    return lists


lists, commands = read_input()
for cmd in commands:
    execute_command(lists, cmd)

print(''.join([d.pop() for d in lists]))