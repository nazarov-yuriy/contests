import java.io.*;
import java.util.*;

class MyComparator implements Comparator<Integer> {
    @Override
    public int compare(Integer a, Integer b) {
        return b.compareTo(a);
    }
}

public class Main {
    public static void main(String[] args) {
        TreeSet ts = new TreeSet(new MyComparator());
        HashMap<Integer, Integer> counts = new HashMap<Integer, Integer>();

        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int m = in.nextInt();
        int n = 0;
        int t;
        int[] vals = new int[25000];

        while ((t = in.nextInt()) != -1){
            vals[n++] = t;
        }

        for(int i = 0; i < m; i++){
            int to_add = vals[i];
            if (counts.containsKey(to_add)) {
                counts.put(to_add, counts.get(to_add)+1);
            } else {
                ts.add(to_add);
                counts.put(to_add, 1);
            }
        }
        out.println(ts.first());

        for(int i = m; i < n; i++){
            int to_add = vals[i];
            if (counts.containsKey(to_add)) {
                counts.put(to_add, counts.get(to_add)+1);
            } else {
                ts.add(to_add);
                counts.put(to_add, 1);
            }
            int to_remove = vals[i-m];
            if(counts.get(to_remove) == 1){
                counts.remove(to_remove);
                ts.remove(to_remove);
            }else{
                counts.put(to_remove, counts.get(to_remove)-1);
            }
            out.println(ts.first());
        }

        out.flush();
    }
}
