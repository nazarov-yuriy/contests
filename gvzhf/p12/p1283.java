import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        double n = in.nextDouble();
        double m = in.nextDouble();
        double p = in.nextDouble();
        if(m<n){
            out.println( (int)Math.ceil( (Math.log(m)-Math.log(n))/Math.log(  (100.0-p)/100  ) ) );
        }else{
            out.println(0);
        }
        out.flush();
    }
}
