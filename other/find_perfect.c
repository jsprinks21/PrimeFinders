#include <stdio.h>
#include <stdlib.h>

#define MAX_LONG 18446744073709551615

int isqrt(int n);
int power(int n, int p);

/* isqrt algorithm from 'http://www.akalin.cx/computing-isqrt' */
/* implementation by Joseph Sprinkle                           */
int isqrt(int n) {
  int p = 1, m = n, xi = 0, xii = 0, bits = 0;
  if (n == 0) {
    return 0;
  }
  
  /* calculate number of bits in n*/
  while(m / 2 > 1) {
    p++;
    m /= 2;
  }
  if (m == 1) {
    bits = p;
  } else {
    bits = p + 1;
  }
  
  /* x = 2^ceil(bits(n)/2) */
  if (bits % 2 == 0) {
    xii = power(2, bits / 2);
  } else {
    xii = power(2, (bits / 2) +1);
  }

  /* loop */
  do {
    xi = xii;
    xii = ((n / xi) + xi) / 2;
  } while (xii < xi);

  return xi;
}

int power(int n, int p) {
  int m = n, i = 1;

  if (p < 0) {
    return -1;
  } else if (p == 0) {
    return 1;
  }

  while (i++ < p) {
    m *= n;
  }

  return m;
}

int main() {
  int find, found = 0;
  unsigned long n = 2;

  printf("Perfect numbers to find: ");
  scanf("%d", &find);

  if (find < 1) {return 0;}

  while (found < find && n <= MAX_LONG) {
    unsigned long sum = 1, i;

    for (i = 2; i <= isqrt(n); i++) {
      if (n % i == 0) {
	sum += i;
	sum += (n / i);
      } /*try dividing n by i, restarting loop with result*/
    }

    if (sum == n) {
      printf("%lu\n", n);
      found++;
    }

    n++;
  }

  return 0;
}
