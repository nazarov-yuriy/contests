import java.io.*;
import java.util.*;

public class p1413 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int c;
        int c8 = 0;
        int c9 = 0;
        int c6 = 0;
        int c3 = 0;
        try {
            while( (c=System.in.read()) != -1 ){
                if( c == '0' )
                    break;
                if( c == '8' )
                    c8++;
                if( c == '9' )
                    c9++;
                if( c == '6' )
                    c6++;
                if( c == '3' )
                    c3++;
                if( c == '2' )
                    c8--;
                if( c == '1' )
                    c9--;
                if( c == '4' )
                    c6--;
                if( c == '7' )
                    c3--;
            }
        } catch (IOException e) {
        }
        double x = c6 + (c3+c9)*Math.sqrt(2.0)/2.0;
        out.print(x);
        out.print(' ');
        double y = c8 + (c9-c3)*Math.sqrt(2.0)/2.0;
        out.print(y);

        out.flush();
    }
}