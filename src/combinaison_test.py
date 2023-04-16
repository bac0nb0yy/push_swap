from itertools import *

a = list(permutations("123", 3))
print(" ".join([str(a[i][0]) + str(a[i][1]) + str(a[i][2]) for i in range(len(a))]))
