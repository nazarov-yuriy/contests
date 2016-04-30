import java.io.*;
import java.util.*;

public class p1348 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        double xa = in.nextDouble();
        double ya = in.nextDouble();
        double xb = in.nextDouble();
        double yb = in.nextDouble();
        double xc = in.nextDouble();
        double yc = in.nextDouble();
        double l = in.nextDouble();
        double ab = Math.sqrt( (xa-xb)*(xa-xb) + (ya-yb)*(ya-yb) );
        double ac = Math.sqrt( (xa-xc)*(xa-xc) + (ya-yc)*(ya-yc) );
        double bc = Math.sqrt( (xc-xb)*(xc-xb) + (yc-yb)*(yc-yb) );
        double p = 0.5 * (ab+bc+ac);
        double s = Math.sqrt( p * (p-ab) * (p-bc) * (p-ac) );
        double h = 2.0*s/ab;
        double ah = Math.sqrt(ac*ac - h*h);
        double bh = Math.sqrt(bc*bc - h*h);
        double acl = Math.max(ac - l, 0);
        double bcl = Math.max(bc - l, 0);
        double hl = Math.max(h - l, 0);
        if(ab < 0.00000001){
            out.println( Math.round(acl*100.0)/100.0 );
            out.println( Math.round(acl*100.0)/100.0 );
        } else if( ah > ab - 0.00000001 || bh > ab - 0.00000001 ){
            out.println( Math.round(Math.min(acl, bcl)*100.0)/100.0 );
            out.println( Math.round(Math.max(acl, bcl)*100.0)/100.0 );
        }else{
            out.println( Math.round(hl*100.0)/100.0 );
            out.println( Math.round(Math.max(acl, bcl)*100.0)/100.0 );
        }
        out.flush();
    }
}