import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class test2 {


    /*请完成下面这个函数，实现题目要求的功能
    当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
    ******************************开始写代码******************************/
    static String sortVersion(String s1, String s2) {
        String [] t1 = s1.split("\\.");
        String [] t2 = s2.split("\\.");
        int count =0;
        while(count<t1.length&&count<t2.length){
            int a1 = Integer.valueOf(t1[count]);
            int a2 =Integer.valueOf(t2[count]);
            if(a1>a2){
                return s2+","+s1;
            }else if(a1<a2){
                return s1+","+s2;
            }
            count++;
        }
        if(count>=t1.length){
            return s1+","+s2;
        }
        return s2+","+s1;

    }
    /******************************结束写代码******************************/


    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        String res;

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

        res = sortVersion(_s1, _s2);
        System.out.println(res);
    }