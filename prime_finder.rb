#!/usr/bin/ruby

def isqrt(n)
  p = 1
  m = n
  xi = 0
  xii = 0
  bits = 0
  if n == 0
    return 0
  end

  #calculate number of bits in n
  while m / 2 > 1 do
    p += 1
    m /= 2
  end
  if m == 1
    bits = p
  else
    bits = p + 1
  end

  # x = 2^ceil(bits(n)/2)
  if bits % 2 == 0
    xi = 2**(bits / 2)
  else
    xi = 2**((bits / 2) + 1)
  end

  #loop
  xii = ((n / xi) + xi) / 2
  while xii < xi do
    xi = xii
    xii = ((n / xi) + xi) / 2
  end

  xi
end

find = ARGV[0].to_i
found = 0
lc = 0
curr = 2
primes = []

while found < find do
  prime = true
  irt = isqrt(curr)

  (0...found).each do |x|
    if primes[x] > irt
      break
    elsif curr % primes[x] == 0
      prime = false
      break
    end
  end
  if prime
    primes << curr
    found = found + 1
    lc = lc + 1
    if lc <= 15
      print curr.to_s + " "
    else
      lc = 1
      print "\n" + curr.to_s + " "
    end
  end
  curr = curr + 1
end
puts
