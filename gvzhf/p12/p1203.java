import java.io.*;
import java.util.*;

public class p1203 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int[] count = new int[30003];
        TreeSet<Integer>[] starts = new TreeSet[30003];
        for (int i = 0; i < n; i++) {
            int start = in.nextInt();
            int end = in.nextInt();
            if(starts[end] == null)
                starts[end] = new TreeSet<Integer>();
            starts[end].add(start);
        }
        count[0] = 0;
        for(int i=1;i<30003;i++){
            if(starts[i-1] != null){
                int c = count[i-1];
                for (Integer j : starts[i-1]) {
                    int from = j.intValue();
                    if (count[from]+1 > c){
                        c = count[from]+1;
                    }
                }
                count[i] = c;
            }
            else{
                count[i] = count[i-1];
            }

        }
        out.print( count[30002] );

        out.flush();
    }
}