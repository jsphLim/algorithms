import java.math.BigInteger;
import java.util.Scanner;
public class Main{
    public static void main(String args[]){
    	Scanner sc=new Scanner(System.in);
    	BigInteger[] c=new BigInteger[105];
    	c[1]=BigInteger.valueOf(1);
    	c[2]=BigInteger.valueOf(2);
    	for(int i=3;i<=100;i++){
    		BigInteger b1=BigInteger.valueOf(4*i-2);
    		BigInteger b2=BigInteger.valueOf(i+1);
    		c[i]=c[i-1].multiply(b1).divide(b2);
		}
		while(sc.hasNext()){
			int n=sc.nextInt();
			System.out.println(c[n]);
		}
		
	}
}
