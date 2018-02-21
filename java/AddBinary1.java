/**
 * Given two binary strings, return their sum (also a binary string).
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 * 
 * Tags: Math, String
 */
import java.lang.*;
import java.io.*;

class AddBinary1{
    
    public static void main(String[] args) {
        String A = "11110011001011110111110001010000111110011110101100011111010010001000001101111001000111";
        String B =         "111001011011111010001001111001100000101010000101100010101100010010010011011000";
        //answer C =11110100000101010011101011011010110111111111010110100100110100110100100000001100011111
        String C = "";
        int a = 0;
        int b = 0;
        int carry = 0;
        int i = 0;
        while(i++ < Math.max(A.length(),B.length())){
            a = ((i > A.length())&(A.length() == Math.min(A.length(),B.length()))&(A.length()!=B.length()))?0:Integer.parseInt(A.valueOf(A.charAt(A.length() - i)));
            b = ((i > B.length())&(B.length() == Math.min(A.length(),B.length()))&(A.length()!=B.length()))?0:Integer.parseInt(B.valueOf(B.charAt(B.length() - i)));
            C = (carry == 1)?(Integer.toString((a^b)^carry) + C):(Integer.toString((a^b)|carry) + C);
            carry = (carry == 1)?((a|b)&carry):((a&b)|carry);
            System.out.println("  a="+a +"  i="+i+"  b="+b+"  C="+C);
        }
        if(carry == 1)
            C = "1" + C;
        System.out.println("C= "+C);
        
    }
}