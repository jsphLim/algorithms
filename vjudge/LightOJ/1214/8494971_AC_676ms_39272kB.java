import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		int n,kcase=1;
        Scanner sc = new Scanner(System.in);
        n=sc.nextInt();
        BigInteger a,b;
       for(int i=0;i<n;i++){
    	   a=sc.nextBigInteger();
    	   b=sc.nextBigInteger();
    	   a=a.abs();
    	   b=b.abs();
    	   if(a.mod(b)==BigInteger.ZERO){
    		   System.out.println("Case "+kcase+++": divisible");
    	   }
    	   else  System.out.println("Case "+kcase+++": not divisible");
       }
	}

}