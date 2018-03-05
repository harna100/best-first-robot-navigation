import os
import sys

# get the files in the current directory
if len(sys.argv) != 2:
    print "Args not given"
    exit()
directory = sys.argv[1]
os.chdir(directory)
files = os.listdir(directory)

# get the map
for f in files:
    if "case" not in f.lower():
        mapName = f
        files.remove(f)
    elif "case3" in f.lower():
        case3 = directory + "/" + f
    elif "case4" in f.lower():
        case4 = directory + "/" + f

fullFile3 = open(case3).read()
fullFile4 = open(case4).read()
# check if there's no path and print the filename
if "No path exists for file" in fullFile3:
    print "No path for: " + fullFile3

# check if case 3 and 4 are different, if they are print it
if fullFile3 != fullFile4:
    print case3
    print case4
