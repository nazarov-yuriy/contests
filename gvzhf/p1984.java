import java.io.*;
import java.util.*;

public class p1984{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        double r = 0.0;
        if(n==1){
            r=1;
        }else if(n==2){
            r=2;
        }else{
            r=1.0+1.0/Math.sin(Math.PI/n);
        }
        out.print(r);
        out.flush();
    }
}