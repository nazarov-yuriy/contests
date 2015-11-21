import java.io.*;
import java.math.BigDecimal;
import java.util.*;

public class p1075 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        double xa = in.nextDouble();
        double ya = in.nextDouble();
        double za = in.nextDouble();
        double xb = in.nextDouble();
        double yb = in.nextDouble();
        double zb = in.nextDouble();
        double xc = in.nextDouble();
        double yc = in.nextDouble();
        double zc = in.nextDouble();
        double r = in.nextDouble();
        double ab = Math.sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb) + (za - zb) * (za - zb));
        double ac = Math.sqrt( (xa-xc)*(xa-xc) + (ya-yc)*(ya-yc) + (za-zc)*(za-zc) );
        double bc = Math.sqrt( (xc-xb)*(xc-xb) + (yc-yb)*(yc-yb) + (zc-zb)*(zc-zb) );
        double p = (ab+bc+ac)/2.0;
        double s = Math.sqrt( p * (p-ab) * (p-ac) * (p-bc) );
        double aac = Math.acos( (ac*ac+ab*ab-bc*bc)/(2.0*ab*ac) );
        double abc = Math.acos( (bc*bc+ab*ab-ac*ac)/(2.0*ab*bc) );
        if(2.0*s/ab > r || aac > Math.PI/2.0-0.00000001 || abc > Math.PI/2.0-0.00000001 || (s < 0.000000001 && (ac>ab||bc>ab) ) ){
            out.print( Math.round(100.0*ab)/100.0 );
        }else{
            double al = Math.asin( r/ac ) - Math.acos( (ac*ac+ab*ab-bc*bc)/(2.0*ab*ac) );
            double bl = Math.asin( r/bc ) - Math.acos( (bc*bc+ab*ab-ac*ac)/(2.0*ab*bc) );
            double t = (al+bl)*r + Math.sqrt(ac*ac-r*r) + Math.sqrt(bc*bc-r*r);
            out.print( Math.round(100.0*t)/100.0 );
        }

        out.flush();
    }
}