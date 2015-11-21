import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    static long fact(long a){
        long res = 1;
        for(long i = 1; i<=a; i++){
            res *= i;
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int[] answers = {0,0,3,13,75,541,4683,47293,545835,7087261,102247563};

        int n = in.nextInt();
        while(n>0){
            out.println(answers[n]);
            n = in.nextInt();
        }
        out.flush();

/*        long max = (long) Math.pow(2, n-1);
        long res = 0;
        for(long i=0;i<max;i++){
            long t = fact(n);
            long seq = 1;
            for(long j=0;j<n-1;j++){
                if(   0 != (  i & (1<<j)  )   ){
                    seq++;
                }else{
                    t /= fact(seq);
                    seq = 1;
                }
            }
            t /= fact(seq);
            res += t;
        }
        out.println(res);

        out.flush();*/
    }
}

