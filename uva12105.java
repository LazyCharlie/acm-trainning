import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        int c[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
        Scanner cin = new Scanner(System.in);
        BigInteger[][] d = new BigInteger[110][3005];
        int n, m, cnt = 0;
        while (cin.hasNext()) {
            n = cin.nextInt();
            if (n == 0) break;
            m = cin.nextInt();
            cnt += 1;
            for (int i = 0; i <= n; ++i) {
                for (int j = 0; j < m;++j) {
                    d[i][j] = BigInteger.valueOf(-1);
                }
            }
            BigInteger ans=BigInteger.valueOf(-1);
            d[0][0] = BigInteger.ZERO;
            for (int i = 0; i <= n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (d[i][j].compareTo(BigInteger.valueOf(-1)) == 0) continue;
                    for (int k = 0; k < 10; ++k) {
                        if (i + c[k] > n) continue;
                        BigInteger tmp = d[i][j].multiply(BigInteger.valueOf(10));
                        tmp = tmp.add(BigInteger.valueOf(k));
                        if (d[i + c[k]][(j * 10 + k) % m].compareTo(tmp) == -1) {
                            d[i + c[k]][(j * 10 + k) % m] = tmp;
                        }
                    }
                }
                if (i>=2&&ans.compareTo(d[i][0])==-1)ans=d[i][0];
            }
            System.out.printf("Case %d: ", cnt);
            System.out.println(ans);
        }
    }
}
