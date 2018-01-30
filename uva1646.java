import java.util.*;
import java.math.*;
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n;
        BigInteger d[]=new BigInteger[10006];
        d[1]=BigInteger.valueOf(1);
        d[2]=BigInteger.valueOf(2);
        d[3]=BigInteger.valueOf(3);
        for(int i=4;i<=10000;i++)d[i]=d[i-2].multiply(BigInteger.valueOf(2)).add(d[i-3]);
        while (cin.hasNext()){
            n=cin.nextInt();
            System.out.println(d[n-2].add(d[n]));
        }
    }
}

