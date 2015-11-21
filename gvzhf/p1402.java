import java.math.BigDecimal;
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        BigDecimal summ = new BigDecimal("0");
        BigDecimal mult = new BigDecimal("1");
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int n = in.nextInt();
        mult = mult.multiply( new BigDecimal(n) );
        for(int i = n-1;i>0;i--){
            mult = mult.multiply( new BigDecimal(i) );
            summ = summ.add(mult);
        }
        out.println(summ);

        out.flush();
    }
}

