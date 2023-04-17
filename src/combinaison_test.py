from itertools import *

a = list(permutations("123", 3))
print(" ".join([str(a[i][0]) + str(a[i][1]) + str(a[i][2]) for i in range(len(a))]))

a = list(permutations("12345", 5))
print(
    " ".join(
        [
            str(a[i][0]) + str(a[i][1]) + str(a[i][2]) + str(a[i][3]) + str(a[i][4])
            for i in range(len(a))
        ]
    )
)
