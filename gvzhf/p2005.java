import java.io.*;
import java.util.*;

public class p2005 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int[][] len = new int[5][];
        for (int i = 0; i < 5; i++)
            len[i] = new int[5];

        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                len[i][j] = in.nextInt();

        int min = 1000000000;
        int min_path = 0;
        int[][] paths = {
                {1, 2, 3, 4, 5},
                {1, 3, 2, 4, 5},
                {1, 4, 3, 2, 5},
                {1, 3, 4, 2, 5},
        };
        for (int i = 0; i < paths.length; i++) {
            int sum_len = 0;
            for (int j = 1; j < paths[i].length; j++) {
                int from = paths[i][j - 1] - 1;
                int to = paths[i][j] - 1;
                sum_len += len[from][to];
            }
            if (sum_len < min) {
                min = sum_len;
                min_path = i;
            }
        }

        out.println(min);
        for (int j = 0; j < paths[min_path].length; j++){
            out.print(paths[min_path][j]);
            out.print(' ');
        }

        out.flush();
    }
}