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

class AddBinary2{
    
    public static void main(String[] args) {
        String A = "11110011001011110111110001010000111110011110101100011111010010001000001101111001000111";
        String B =         "111001011011111010001001111001100000101010000101100010101100010010010011011000";
        //answer C =11110100000101010011101011011010110111111111010110100100110100110100100000001100011111
        //          11110100000101010011101011011010110111111111010110100100110100110100100000001100011111
        String C = "";
        int a = 0;
        int b = 0;
        int Alen = A.length();
        int Blen = B.length();
        int carry = 0;
        int i = 1;
        while(i<= Alen ||i<= Blen){
            a = i > Alen?0:(A.charAt(Alen - i) -'0');
            b = i > Blen?0:(B.charAt(Blen - i) -'0');
            C = (a + b + carry)%2 + C;
            carry = (a + b + carry)/2;
            System.out.println("  a="+a +"  i="+i+"  b="+b+"  C="+C);
            i++;
        }
        if(carry == 1)
            C = "1" + C;
        System.out.println("----C= "+C);
        
    }
}