import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        HashMap<Integer, Integer> vals = new HashMap<Integer, Integer>();

        vals.put(1, 2);
        vals.put(2, 3);
        vals.put(3, 5);
        vals.put(4, 7);
        vals.put(5, 13);
        vals.put(6, 17);
        vals.put(7, 19);
        vals.put(8, 31);
        vals.put(9, 61);
        vals.put(10, 89);
        vals.put(11, 107);
        vals.put(12, 127);
        vals.put(13, 521);
        vals.put(14, 607);
        vals.put(15, 1279);
        vals.put(16, 2203);
        vals.put(17, 2281);
        vals.put(18, 3217);
        vals.put(19, 4253);
        vals.put(20, 4423);
        vals.put(21, 9689);
        vals.put(22, 9941);
        vals.put(23, 11213);
        vals.put(24, 19937);
        vals.put(25, 21701);
        vals.put(26, 23209);
        vals.put(27, 44497);
        vals.put(28, 86243);
        vals.put(29, 110503);
        vals.put(30, 132049);
        vals.put(31, 216091);
        vals.put(32, 756839);
        vals.put(33, 859433);
        vals.put(34, 1257787);
        vals.put(35, 1398269);
        vals.put(36, 2976221);
        vals.put(37, 3021377);
        vals.put(38, 6972593);

        for (int i = 0; i < n; i++) {
            out.println(vals.get(in.nextInt()));
        }

        out.flush();
    }
}
