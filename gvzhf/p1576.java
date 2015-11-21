import java.io.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

public class Main {
    public static void main(String[] args) throws ParseException {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n1 = in.nextInt();
        int c1 = in.nextInt();

        int n2 = in.nextInt();
        int t = in.nextInt();
        int c2 = in.nextInt();

        int n3 = in.nextInt();

        int k = in.nextInt();
        in.nextLine();

        long summ = 0;
        for (int i = 0; i < k; i++) {
            String l = in.nextLine();
            SimpleDateFormat sdf = new SimpleDateFormat("mm:ss");
            Date date = sdf.parse(l);
            Calendar calendar = GregorianCalendar.getInstance(); // creates a new calendar instance
            calendar.setTime(date);   // assigns calendar to given date
            int m = calendar.get(Calendar.MINUTE);
            int s = calendar.get(Calendar.SECOND);
            if(m==0 && s <= 6){
                //do nothing
            } else {
                summ += m + (s>0?1:0);
            }
        }
        out.print("Basic:     ");
        out.println(n1+c1*summ);
        out.print("Combined:  ");
        out.println(  n2 + ( summ<t ? 0 : c2*(summ-t) )  );
        out.print("Unlimited: ");
        out.print(n3);

        out.flush();
    }
}
