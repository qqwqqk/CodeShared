import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Integer> list = new ArrayList<>();
        String s = sc.nextLine();
        String[] s1 = s.split(" ");
        int[] in = new int[s1.length];
        for (int i = 0; i < in.length; i++) {
            list.add(Integer.valueOf(s1[i]));
        }
        int max = list.get(0);
        int min = list.get(0);
        int temp = 0;
        int mul = 0;
        for (int i = 1; i < list.size(); i++) {
            int t = list.get(i);
            temp =Math.max(max * t,Math.max(min * t, t));
            min =Math.min(max * t,Math.min(min * t, t));
            max = temp;
            mul = Math.max(mul, max);

        }
        System.out.println(mul);

    }
}