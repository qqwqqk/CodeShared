import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Main {


    /*请完成下面这个函数，实现题目要求的功能
    当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
    ******************************开始写代码******************************/
    static int longestSubStrLength(String s1, String s2) {
        if (s1 == null || s1.length()==0|| s2 == null||s2.length()==0) {
            return 0;
        }
        int max = 0;
        int[][] count = new int[s1.length() + 1][s2.length() + 1];
        for (int i = 0; i < s1.length() + 1; i++) {
            for (int j = 0; j < s2.length() + 1; j++) {
                count[i][j] = 0;
            }
        }

        for (int i = 1; i < s1.length() + 1; i++) {
            for (int j = 1; j < s2.length() + 1; j++) {
                if (s1.charAt(i - 1)== s2.charAt(j - 1)||Math.abs(s1.charAt(i - 1)-s2.charAt(j - 1))==Math.abs('A'-'a')) {
                    count[i][j] = count[i - 1][j - 1] + 1;
                } else {
                    count[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < s1.length() + 1; i++) {
            for (int j = 0; j < s2.length() + 1; j++) {
                if (count[i][j] > max) {
                    max = count[i][j];
                }
            }
        }

        return max;

    }

    /******************************结束写代码******************************/


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int res;

        String _s1;
        try {
            _s1 = in.nextLine();
        } catch (Exception e) {
            _s1 = null;
        }

        String _s2;
        try {
            _s2 = in.nextLine();
        } catch (Exception e) {
            _s2 = null;
        }

        res = longestSubStrLength(_s1, _s2);
        System.out.println(String.valueOf(res));

    }
}