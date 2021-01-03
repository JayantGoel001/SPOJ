import java.io.*;
import java.lang.*;
import java.math.BigInteger;
import java.util.*;

public class JULKA {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 10; i++) {
            BigInteger sum = new BigInteger(sc.nextLine());
            BigInteger diff = new BigInteger(sc.nextLine());
            BigInteger a = (sum.add(diff)).divide(new BigInteger("2"));
            BigInteger b = (sum.subtract(diff)).divide(new BigInteger("2"));
            System.out.println(a);
            System.out.println(b);
        }
    }
}
