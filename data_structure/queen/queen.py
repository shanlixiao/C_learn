from itertools import *
cols = range(4)
i = 0
for vec in permutations(cols):
    if (4 == len(set(vec[i]+i for i in cols))
          == len(set(vec[i]-i for i in cols))):
        print(vec)
        i = i + 1
print(i)
