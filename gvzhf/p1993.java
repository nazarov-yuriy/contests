import java.io.*;
import java.util.*;

public class p1993 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        String str = in.nextLine();
        String pattern1 = "^(.*)\\{(.*)\\}(.*)\\((.*)\\)(.*)\\[(.*)\\](.*)$";
        String replace1 = "$1$2$3$4$5$6$7";
        String pattern2 = "^(.*)\\{(.*)\\}(.*)\\[(.*)\\](.*)\\((.*)\\)(.*)$";
        String replace2 = "$1$2$3$6$5$4$7";
        String pattern3 = "^(.*)\\((.*)\\)(.*)\\{(.*)\\}(.*)\\[(.*)\\](.*)$";
        String replace3 = "$1$4$3$2$5$6$7";
        String pattern4 = "^(.*)\\[(.*)\\](.*)\\{(.*)\\}(.*)\\((.*)\\)(.*)$";
        String replace4 = "$1$4$3$6$5$2$7";
        String pattern5 = "^(.*)\\((.*)\\)(.*)\\[(.*)\\](.*)\\{(.*)\\}(.*)$";
        String replace5 = "$1$6$3$2$5$4$7";
        String pattern6 = "^(.*)\\[(.*)\\](.*)\\((.*)\\)(.*)\\{(.*)\\}(.*)$";
        String replace6 = "$1$6$3$4$5$2$7";
        String[] parts = str.split(",");
        parts[0] = parts[0].
                replaceFirst(pattern1, replace1).
                replaceFirst(pattern2, replace2).
                replaceFirst(pattern3, replace3).
                replaceFirst(pattern4, replace4).
                replaceFirst(pattern5, replace5).
                replaceFirst(pattern6, replace6).
                toLowerCase();
        out.print(Character.toUpperCase(parts[0].charAt(0)));
        out.print(parts[0].substring(1));
        if (parts.length > 1) {
            out.print(',');
            out.print(
                    parts[1].
                            replaceFirst(pattern1, replace1).
                            replaceFirst(pattern2, replace2).
                            replaceFirst(pattern3, replace3).
                            replaceFirst(pattern4, replace4).
                            replaceFirst(pattern5, replace5).
                            replaceFirst(pattern6, replace6)
            );
        }
        out.flush();
    }
}
