import java.io.*;
import java.math.BigDecimal;
import java.util.*;

public class p1295 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        if ((n - 5) % 20 == 0)
            out.print("2");
        else if ((n - 3) % 4 == 0)
            out.print("2");
        else if ((n - 1) % 2 == 0)
            out.print("1");
        else if ((n - 2) % 4 == 0)
            out.print("1");
        else
            out.print("0");

        out.flush();
    }
}