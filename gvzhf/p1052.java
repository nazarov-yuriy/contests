import java.io.*;
import java.util.*;

public class p1052 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        double[] x = new double[205];
        double[] y = new double[205];
        double[] a = new double[n];
        int[] counts = new int[205];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextDouble();
            y[i] = in.nextDouble();
        }
        int max = 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    a[j] = 100.0;
                } else {
                    if(x[i]>x[j])
                        a[j] = Math.atan2(x[i] - x[j], y[i] - y[j]);
                    else
                        a[j] = Math.atan2(-x[i] + x[j], -y[i] + y[j]);
                }
            }
            Arrays.sort(a);
            counts[0] = 2;
            for (int j = 1; j < n; j++) {
                if (a[j - 1] + 0.00000001 > a[j]) {
                    counts[j] = counts[j - 1] + 1;
                    if (counts[j] > max)
                        max = counts[j];
                } else {
                    counts[j] = 2;
                }
            }
        }
        out.print(max);
        out.flush();
    }
}