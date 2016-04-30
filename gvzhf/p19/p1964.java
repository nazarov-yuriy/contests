import java.io.*;
import java.util.*;

public class p1964 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int k = in.nextInt();
        int prev = in.nextInt();
        for (int i = 1; i < k; i++) {
            int next = in.nextInt();
            int cross = prev + next - n;
            prev = cross > 0 ? cross : 0;
        }
        out.print(prev);

        out.flush();
    }
}