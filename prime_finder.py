#!/usr/bin/env python
import sys

def isqrt(n):
    p = 1
    m = n
    xi = 0
    xii = 0
    bits = 0
    if (n == 0):
        return 0
        
    #calculate number of bits in n
    while (m / 2 > 1):
        p += 1
        m /= 2
    if (m == 1):
        bits = p
    else:
        bits = p + 1
    
    # x = 2^ceil(bits(n)/2)
    if (bits % 2 == 0):
        xi = 2**(bits / 2);
    else:
        xi = 2**((bits / 2) + 1);

    #loop
    xii = ((n / xi) + xi) / 2
    while (xii < xi):
        xi = xii
        xii = ((n / xi) + xi) / 2

    return xi;

find = int(sys.argv[1])
found = 0
lc = 0
curr = 2
primes = []

while (found < find):
    prime = True
    irt = isqrt(curr)

    for x in xrange(0, found):
        if (primes[x] > irt):
            break
        elif (curr % primes[x] == 0):
            prime = False
            break
    if (prime):
        primes.append(curr)
        found += 1
        lc += 1
        if (lc < 15):
            print str(curr),
        else:
            lc = 1
            print str(curr)
    curr += 1
