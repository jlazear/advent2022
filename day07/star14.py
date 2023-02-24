
class Directory:
    def __init__(self, name=None):
        self.name = name
        self.parent = None
        self.children = {}
        self.size = 0
        self.files = {}

def parse_line(line, pwd, directories):
    line = line.strip()
    if line.startswith('$ cd ..'):
        pwd = pwd.parent
    elif line.startswith('$ cd'):
        dirname = line[5:]
        fulldirname = f"{pwd.name}{dirname}/" if pwd else dirname
        try:
            pwd = directories[fulldirname]
        except KeyError:
            directories[fulldirname] = Directory(fulldirname)
            pwd = directories[fulldirname]
    elif line.startswith('$ ls'):
        pass
    elif line.startswith('dir'):
        dirname = line[4:]
        fulldirname = f"{pwd.name}{dirname}/" if pwd else dirname
        newdir = Directory(fulldirname)
        pwd.children[dirname] = newdir
        newdir.parent = pwd
        directories[fulldirname] = newdir
    else:
        size, name = line.split()
        size = int(size)
        pwd.files[name] = size
    return pwd, directories

def compute_size(directories, pwd=None):
    if pwd is None:
        pwd = directories['/']
    pwd.size += sum(pwd.files.values())
    for child in pwd.children.values():
        pwd.size += compute_size(directories, child)
    return pwd.size
    

with open('input.txt') as f:
    pwd = None
    directories = {}
    for line in f:
        pwd, directories = parse_line(line, pwd, directories)

compute_size(directories)

total_disk_size = 70000000
size_needed_for_update = 30000000
max_allowed = total_disk_size - size_needed_for_update

min_to_delete = directories['/'].size - max_allowed

smallest = directories['/'].size
for directory in directories.values():
    size = directory.size
    if size >= min_to_delete and size < smallest:
        smallest = size

print(f"{min_to_delete = }, {smallest = }")