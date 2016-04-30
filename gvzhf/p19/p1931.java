import java.io.*;
import java.util.*;

public class p1931{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int[] comp = new int[n+1];
        int current_disadv = in.nextInt();
        int current_index = 1;
        for (int i=0;i<=n;i++){
            comp[i] = 0;
        }
        for (int i=1;i<n;i++){
            int disadv = in.nextInt();
            comp[current_index]++;
            comp[i+1]++;
            if (disadv < current_disadv){
                current_disadv = disadv;
                current_index = i+1;
            }
        }
        int max = 0;
        int max_ind = 1;
        for(int i = 1; i<=n; i++){
            if (comp[i]>max){
                max=comp[i];
                max_ind = i;
            }
        }
        out.print(max_ind);
        out.flush();
    }
}