import java.io.*;
import java.math.BigDecimal;
import java.util.*;

public class p1285 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        double x1a = in.nextDouble();
        double x2a = in.nextDouble();
        double x3a = in.nextDouble();
        double x4a = in.nextDouble();
        double x5a = in.nextDouble();
        double x6a = in.nextDouble();
        double x7a = in.nextDouble();
        double x8a = in.nextDouble();

        double x1b = in.nextDouble();
        double x2b = in.nextDouble();
        double x3b = in.nextDouble();
        double x4b = in.nextDouble();
        double x5b = in.nextDouble();
        double x6b = in.nextDouble();
        double x7b = in.nextDouble();
        double x8b = in.nextDouble();

        double x1c = in.nextDouble();
        double x2c = in.nextDouble();
        double x3c = in.nextDouble();
        double x4c = in.nextDouble();
        double x5c = in.nextDouble();
        double x6c = in.nextDouble();
        double x7c = in.nextDouble();
        double x8c = in.nextDouble();

        double r = in.nextDouble();
        double ab = Math.sqrt((x1a - x1b) * (x1a - x1b) + (x2a - x2b) * (x2a - x2b) + (x3a - x3b) * (x3a - x3b) + (x4a - x4b) * (x4a - x4b) + (x5a - x5b) * (x5a - x5b) + (x6a - x6b) * (x6a - x6b) + (x7a - x7b) * (x7a - x7b) + (x8a - x8b) * (x8a - x8b));
        double ac = Math.sqrt((x1a - x1c) * (x1a - x1c) + (x2a - x2c) * (x2a - x2c) + (x3a - x3c) * (x3a - x3c) + (x4a - x4c) * (x4a - x4c) + (x5a - x5c) * (x5a - x5c) + (x6a - x6c) * (x6a - x6c) + (x7a - x7c) * (x7a - x7c) + (x8a - x8c) * (x8a - x8c));
        double bc = Math.sqrt((x1b - x1c) * (x1b - x1c) + (x2b - x2c) * (x2b - x2c) + (x3b - x3c) * (x3b - x3c) + (x4b - x4c) * (x4b - x4c) + (x5b - x5c) * (x5b - x5c) + (x6b - x6c) * (x6b - x6c) + (x7b - x7c) * (x7b - x7c) + (x8b - x8c) * (x8b - x8c));
        double p = (ab+bc+ac)/2.0;
        double s = Math.sqrt( p * (p-ab) * (p-ac) * (p-bc) );
        double aac = Math.acos( Math.min(1.0, Math.max(-1.0, (ac*ac+ab*ab-bc*bc)/(2.0*ab*ac))) );
        double abc = Math.acos( Math.min(1.0, Math.max(-1.0, (bc*bc+ab*ab-ac*ac)/(2.0*ab*bc))) );
        if( r < 0.000000001 || 2.0*s/ab > r || aac > Math.PI/2.0-0.000000001 || abc > Math.PI/2.0-0.000000001 || (s < 0.000000001 && (ac>ab-0.000000001||bc>ab-0.000000001) ) ){
            out.print( Math.round(100.0*ab)/100.0 );
        }else{
            double al = Math.asin( Math.min(1.0, Math.max(-1.0, r/ac)) ) - Math.acos( Math.min(1.0, Math.max(-1.0, (ac*ac+ab*ab-bc*bc)/(2.0*ab*ac))) );
            double bl = Math.asin( Math.min(1.0, Math.max(-1.0, r/bc)) ) - Math.acos( Math.min(1.0, Math.max(-1.0, (bc*bc+ab*ab-ac*ac)/(2.0*ab*bc))) );
            double t = (al+bl)*r + Math.sqrt(ac*ac-r*r) + Math.sqrt(bc*bc-r*r);
            out.print( Math.round(100.0*t)/100.0 );
        }

        out.flush();
    }
}