import java.util.Scanner;

public class PrimeFactorizer {
    
    private static boolean isPrime(long a){
        boolean prime = true;
        for (long i = 2; i <= a/2; i++){
            if (a % i == 0){
                prime = false;
            }
        }
        return prime;
    }
    
    private static void factor(long a){
        long A = a;
        long prod = 1;
        for (long i = 2; i <= A/2; i++){
	    while (a % i == 0){
		System.out.println(i);
		a /= i;
		prod *= i;
		if (prod == A){
		    return;
		}
	    }
        }
    }
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        boolean going = true;
        while (going){
            System.out.print("Enter number to be factored: ");
            long a = sc.nextLong();
            sc.nextLine();
            if (a == 1){
                System.out.println("1 is not factorable.");
            }else if (isPrime(a)){
                System.out.println("*****PRIME NUMBER*****");
            }else{
                factor(a);
            }
            System.out.println("Go again? y/n");
            String answer = sc.nextLine();
            if (answer.equals("n")){
                going = false;
            }
        }
        sc.close();
    }
}
