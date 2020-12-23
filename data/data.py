#!/usr/bin/python

import random
import sys

if len(sys.argv) < 7:
    # number of customers
    if len(sys.argv) == 1:
        n = random.randint(4, 500)
    else:
        n = int(sys.argv[1])

    # capacity of the vehicles
    Q = random.randint(10, 100)

    # quantity required by customer
    min_q = random.randint(1, Q//10)
    max_q = random.randint(Q//10, Q)

    # distance/cost between two customers
    min_w = random.randint(1, 50)
    max_w = random.randint(50, 100)
else:
    n, Q, min_q, max_q, min_w, max_w = map(int, sys.argv[1:])

q = [round(min_q + random.random()*(max_q-min_q), 2) for i in range(n)]
D = [[round(min_w + random.random()*(max_w-min_w), 2) for i in range(n+1)] for j in range(n+1)]

for i in range(n+1):
    D[i][i] = 0.00

# number of nodes
print("%s" % n)

# quantity of the vehicles
print("%s" % Q)

# demands of the nodes
print("\t".join(str(x) for x in q))

# costs of the edges
for i in range(n+1):
    print("\t".join(str(x) for x in D[i]))
