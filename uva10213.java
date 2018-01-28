import java.util.*;
import java.math.*;
public class Main{
    public static void main(String[] args)
    {
        Scanner cin=new Scanner(System.in);
        int T;
        T=cin.nextInt();
        while (T-->0){
            BigInteger n=BigInteger.valueOf(0);
            n=cin.nextBigInteger();
            BigInteger n2=n.multiply(n);
            BigInteger n3=n.multiply(n2);
            n2=n2.negate();
            n2=n2.multiply(BigInteger.valueOf(6));
            BigInteger n1=n.multiply(BigInteger.valueOf(23));
            BigInteger tmp=n3.add(n2);
            tmp=tmp.add(n1);
            tmp=tmp.add(BigInteger.valueOf(-18));
            tmp=tmp.multiply(n);
            tmp=tmp.divide(BigInteger.valueOf(24));
            tmp=tmp.add(BigInteger.valueOf(1));
            System.out.println(tmp);
        }
    }
}
