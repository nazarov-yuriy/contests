import java.io.*;
import java.util.*;

public class p1874 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        double a = in.nextDouble();
        double b = in.nextDouble();
        double r = 32768.0;
        double delta = 16384.0;
        for(int i = 0; i< 60;i++){
            double alpha = Math.asin(0.5*a/r);
            double beta = Math.asin(0.5*b/r);
            if(alpha+beta < Math.PI/4.0){
                r-=delta;
            }else{
                r+=delta;
            }
            delta /= 2.0;
        }
        double pa = (a+r+r)/2.0;
        double pb = (b+r+r)/2.0;
        double s = Math.sqrt(pa*(pa-a)*(pa-r)*(pa-r))+Math.sqrt(pb*(pb-b)*(pb-r)*(pb-r));
        out.print(s);

        out.flush();
    }
}