import java.io.*;
import java.util.*;

public class p1260 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        long[] res = new long[60];
        res[1]=1;
        res[2]=1;
        res[3]=2;
        res[4]=4;
        for (int i = 5; i <= n; i++) {
            res[i]=res[i-1]+res[i-3]+1;
        }
        out.print(res[n]);

        out.flush();
    }
}