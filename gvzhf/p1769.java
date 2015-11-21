import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        HashSet<Integer> cache = new HashSet<Integer>();
        String s = in.nextLine();
        for(int i = 0; i<s.length(); i++){
            int l = Integer.parseInt(s.substring(i, i+1));
            cache.add(l);
        }
        for(int i = 0; i<s.length()-1; i++){
            int l = Integer.parseInt(s.substring(i, i+2));
            cache.add(l);
        }
        for(int i = 0; i<s.length()-2; i++){
            int l = Integer.parseInt(s.substring(i, i+3));
            cache.add(l);
        }
        for(int i = 0; i<s.length()-3; i++){
            int l = Integer.parseInt(s.substring(i, i+4));
            cache.add(l);
        }
        for(int i = 0; i<s.length()-4; i++){
            int l = Integer.parseInt(s.substring(i, i+5));
            cache.add(l);
        }
        for(int i = 0; i<s.length()-5; i++){
            int l = Integer.parseInt(s.substring(i, i+6));
            cache.add(l);
        }

        long res = 0;
        for(int i = 1; i < 1000000; i++){
            if(!cache.contains(i)){
                out.println(i);
                break;
            }
        }

        out.flush();
    }
}
