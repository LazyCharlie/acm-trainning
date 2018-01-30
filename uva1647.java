import java.util.*;
        import java.math.*;
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n;
        BigInteger d[]=new BigInteger[1006];
        d[1]=BigInteger.valueOf(0);
        for(int i=2;i<=1000;i++){
            d[i]=d[i-1].multiply(BigInteger.valueOf(2));
            if (i%2==0)d[i]=d[i].add(BigInteger.valueOf(1));
            else d[i]=d[i].add(BigInteger.valueOf(-1));
        }
        while (cin.hasNext()){
            n=cin.nextInt();
            System.out.println(d[n]);
        }
    }
}
