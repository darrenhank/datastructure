/**
 * Implement atoi to convert a string to an integer.
 * Hint: Carefully consider all possible input cases. If you want a challenge,
 * please do not see below and ask yourself what are the possible input cases.
 * 
 * Keys: Whitespaces, Additional chars, Signs, Out of range
 * 
 * Requirements for atoi:
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this
 * character, takes an optional initial plus or minus sign followed by as many
 * numerical digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior of
 * this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty
 * or it contains only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned. If the
 * correct value is out of the range of representable values, INT_MAX
 * (2147483647) or INT_MIN (-2147483648) is returned.
 * 
 * Tags: Math, String
 */
import java.lang.*;
class atoi {
    public static void main(String[] args) {
        String A = "   -789";
        test0(A);
    }
    public static int test0(String A){
        int Alen = A.length();
        int sign = 1;
        long t = 0;
        int i = 0;
        int c = 0;
        int b = 0;
        while(i < Alen&& b < 13){
            c = A.charAt(i) - '0';
            System.out.println("i = "+i+"  c="+A.charAt(i)+"  b="+b+"  t= "+(int)t);
            i++;
            if((c+'0')==' '){
                continue;
            }else if((c+'0')=='+'){
                sign = 1;
                continue;
            }else if((c+'0')=='-'){
                sign = -1;
                continue;
            }else if(c >= 0 && c <= 9 ) {
                t = 10*t + c;
                System.out.println("i = "+i+"  c="+c+"  b="+b+"  t= "+(int)t);
                b++;
            }else{
                break;
            }
        }
        if(sign*t <= Integer.MAX_VALUE || sign*t >=Integer.MIN_VALUE)
            System.out.println("-------  t= "+(int)(sign*t));
        else
            System.out.println("-------out int range  t= 0");
        return 0;
    }
}