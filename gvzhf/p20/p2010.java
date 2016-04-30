import java.io.*;
import java.util.*;

public class p2010 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        long n = in.nextLong();
        long x = in.nextLong() - 1;
        long y = in.nextLong() - 1;
        long nx = n - x;
        long ny = n - y;

        long king = 0;
        if (x - 1 >= 0 && y - 1 >= 0) king++;
        if (x - 1 >= 0 && y + 0 < n) king++;
        if (x - 1 >= 0 && y + 1 < n) king++;
        if (x + 0 < n && y - 1 >= 0) king++;
        if (x + 0 < n && y + 1 < n) king++;
        if (x + 1 < n && y - 1 >= 0) king++;
        if (x + 1 < n && y + 0 < n) king++;
        if (x + 1 < n && y + 1 < n) king++;

        long knight = 0;
        if (x + 1 < n && y + 2 < n) knight++;
        if (x + 2 < n && y + 1 < n) knight++;
        if (x - 1 >= 0 && y - 2 >= 0) knight++;
        if (x - 2 >= 0 && y - 1 >= 0) knight++;
        if (x + 1 < n && y - 2 >= 0) knight++;
        if (x + 2 < n && y - 1 >= 0) knight++;
        if (x - 1 >= 0 && y + 2 < n) knight++;
        if (x - 2 >= 0 && y + 1 < n) knight++;

        long bishop = 2*n - 2 - Math.abs(x - y) - Math.abs(n - 1 - x - y);
        long rook = 2*n-2;
        long queen = rook+bishop;

        out.print("King: ");
        out.println(king);
        out.print("Knight: ");
        out.println(knight);
        out.print("Bishop: ");
        out.println(bishop);
        out.print("Rook: ");
        out.println(rook);
        out.print("Queen: ");
        out.println(queen);

        out.flush();
    }
}