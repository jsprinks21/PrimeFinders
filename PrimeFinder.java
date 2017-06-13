import java.util.Scanner;

public class PrimeFinder{
    static int[] primes;
    static int numFound = 0;
    static int curr = 2;
    static int lc = 0;

    private static int power(int n, int p) {
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

    private static int isqrt(int n) {
	int p = 1, m = n, xi = 0, xii = 0, bits = 0;
	if (n == 0) {
	    return 0;
	}

	//calculate number of bits in n
	while (m / 2 > 1) {
	    p++;
	    m /= 2;
	}
	if (m == 1) {
	    bits = p;
	} else {
	    bits = p + 1;
	}

	// x = 2^ceil(bits(n)/2)
	if (bits % 2 == 0) {
	    xii = power(2, bits / 2);
	} else {
	    xii = power(2, (bits / 2) + 1);
	}

	//loop
	do {
	    xi = xii;
	    xii = ((n / xi) + xi) / 2;
	} while (xii < xi);

	return xi;
    }
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
	int input;

	if (args.length == 0) {
	    System.out.print("How many primes would you like to find?"
			     + "\nCancel=-1: ");
        
	    input = sc.nextInt();
	    sc.nextLine();
	} else {
	    input = Integer.parseInt(args[0]);
	}

	primes = new int[input];
        
        if (!(input <= 0)){
            while (numFound < input){
                boolean prime = true;
		int irt = isqrt(curr);

                for (int i = 0; i < numFound; i++){
		    if (primes[i] > irt) {
			break;
		    }else if (curr % primes[i] == 0){
                        prime = false;
			break;
                    }
                }
                if (prime){
                    primes[numFound++] = curr;
		    if (lc++ < 15) {
			System.out.print(curr + " ");
		    } else {
			System.out.print("\n" + curr + " ");
			lc = 1;
		    }
                }
                curr++;
            }
	    System.out.println();
        }
        sc.close();
        return;
    }
    
}
