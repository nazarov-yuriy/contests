import java.io.*;
import java.util.*;

public class p1640 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        double max = 0.0;
        for(int i = 0; i< n;i++){
            double x = in.nextDouble();
            double y = in.nextDouble();
            double r = Math.sqrt(x*x+y*y);
            if(r>max)
                max=r;
        }
        out.print("0 0 ");
        out.print(max);

        out.flush();
    }
}