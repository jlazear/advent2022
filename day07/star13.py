
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

small_sizes = 0
threshold = 100000
small_dirs = [d.size for d in directories.values() if d.size <= threshold]

print(f"{sum(small_dirs) = }")