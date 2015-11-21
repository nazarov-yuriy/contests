import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        out.println( 2*(2*n-1) );
        for(int i = 1; i<=n;i++){
            out.println(i);
        }
        for(int i = n-1; i>=1;i--){
            out.println(i);
        }
        for(int i = 1; i<=n;i++){
            out.println(i);
        }
        for(int i = n-1; i>=1;i--){
            out.println(i);
        }

        out.flush();
    }
}
