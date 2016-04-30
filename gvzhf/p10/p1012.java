import java.io.*;
import java.math.BigDecimal;
import java.util.*;

public class p1012 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        BigDecimal[] cache = new BigDecimal[2000];
        int n = in.nextInt();
        int k = in.nextInt();
        cache[0] = new BigDecimal(1);
        cache[1] = new BigDecimal(k-1);
        for(int i = 2; i<=n; i++)
            cache[i] = cache[i-1].add(cache[i-2]).multiply( new BigDecimal(k-1) );
        out.print(cache[n]);

        out.flush();
    }
}