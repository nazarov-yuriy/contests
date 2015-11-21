import java.io.*;
import java.util.*;

public class p1333 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int res = 1000;
        int n = in.nextInt();
        double s = 0.0;
        char[] picture = new char[res*res];
        for(int x = 0; x < res*res; x++)
            picture[x] = 0;
        for(int i = 0; i<n; i++){
            double bx = in.nextDouble();
            double by = in.nextDouble();
            double br = in.nextDouble();
            for(int y = 0; y < res; y++){
                for(int x = 0; x < res; x++){
                    if( Math.sqrt( (bx-1.0*x/res)*(bx-1.0*x/res) + (by-1.0*y/res)*(by-1.0*y/res) ) < br ){
                        picture[y*res + x] = 1;
                    }
                }
            }
        }
        int ones = 0;
        for(int x = 0; x < res*res; x++)
            ones += picture[x];
        out.print(100.0*ones/res/res);

        out.flush();
    }
}