#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[]){
  int numFind, numFound, curr, lineCount, *primes, i;
  numFound = 0;
  lineCount = 0;
  curr = 2;
  
  if (argc > 1 && atoi(argv[1]) > 0) {
    numFind = atoi(argv[1]);
  } else {
    do {
      printf("How many primes would you like to find? ");
      (void)scanf("%d", &numFind);
    } while (!(numFind > 0));
  }
  
  primes = calloc(numFind, sizeof(int));
  
  while (numFound < numFind) {
    int prime = 1;
    int irt = isqrt(curr);

    for (i = 0; i < numFound; i++) {
      if (primes[i] > irt) {
	break;
      } else if (curr % primes[i] == 0) {
	prime = 0;
	break;
      }
    }
    
    if (prime){
      primes[numFound++] = curr;
      if (lineCount++ < 14) {
	printf("%d ", curr);
      } else {
	printf("%d\n", curr);
	lineCount = 0;
      }
    }
    curr++;
  }
  printf("\n");
  
  free(primes);
  primes = NULL;
  
  return 0;
}
