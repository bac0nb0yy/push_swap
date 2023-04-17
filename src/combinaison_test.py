from itertools import *

a = list(permutations("123", 3))
print(
    "Number of total permutations:",
    len(a),
    "\n"
    + "\n".join(["".join([str(a[i][k]) for k in range(3)]) for i in range(len(a))]),
)

a = list(permutations("12345", 5))
print(
    "Number of total permutations:",
    len(a),
    "\n"
    + "\n".join(["".join([str(a[i][k]) for k in range(5)]) for i in range(len(a))]),
)
