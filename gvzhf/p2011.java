import java.io.*;
import java.util.*;

public class p2011 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();

        int[] c = {0, 0, 0};

        for (int i = 0; i < n; i++) {
            int t = in.nextInt();
            c[t - 1]++;
        }
        if (c[0] > 0 && c[1] > 0 && c[2] > 0) {
            out.print("Yes");
        } else {
            if ((c[0] >= 2 && c[1] >= 2) || (c[0] >= 2 && c[2] >= 2) || (c[1] >= 2 && c[2] >= 2)) {
                out.print("Yes");
            }else{
                if ((c[0] >= 1 && c[1] >= 5) || (c[0] >= 1 && c[2] >= 5) || (c[1] >= 1 && c[2] >= 5) || (c[0] >= 5 && c[1] >= 1) || (c[0] >= 5 && c[2] >= 1) || (c[1] >= 5 && c[2] >= 1)) {
                    out.print("Yes");
                }else{
                    out.print("No");
                }
            }
        }
        out.flush();
    }
}