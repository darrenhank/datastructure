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

class AddBinary{
    
    public static void main(String[] args) {
        String A = "11110011001011110111110001010000111110011110101100011111010010001000001101111001000111";
        String B =         "111001011011111010001001111001100000101010000101100010101100010010010011011000";
        //answer C =11110100000101010011101011011010110111111111010110100100110100110100100000001100011111
//                  11110100000101010011101011011010110111111111010110100100110100110100100000001100011111
		String C = "";
		int carry = 0;
		int Alast = A.length();
		int Blast = B.length();
		int min_len = Math.min(Alast,Blast);
		int max_len = Math.max(Alast,Blast);
		int i = 0, a = 0, b = 0, c = 0;
		System.out.println("Alast="+Alast);
		System.out.println("Blast="+Blast);
		System.out.println("min_len="+min_len);
		System.out.println("max_len="+max_len);
	
		while(--min_len >=0){
			
			a = Integer.parseInt(A.valueOf(A.charAt(--Alast)));
			b = Integer.parseInt(B.valueOf(B.charAt(--Blast)));
			if(carry == 0){
				if((a == 1)&&(b == 1)){
					carry = 1;
					C = "0" + C;
				}
				else{
					C = Integer.toString(a|b) + C;
				}
			
			}
			else{
				if((a == 0)&&(b == 0)){
					carry = 0;
					C = "1" + C;
				}
				else{
					C = Integer.toString((a&b&1)) + C;
				}
			
			}
			System.out.println("Alast="+ Alast +""+ "    Blast="+Blast+""+ "   min_len="+min_len+""+"  a="+a+""+" b="+b+""+"  carry=" +carry+""+"  C="+C);
			
		}
		
		min_len = Math.min(A.length(),B.length());
		if(max_len == min_len){
			C = "1" + C;
			System.out.println(" "+A);
			System.out.println(" "+B);
			System.out.println("1C="+C);
			return;
		}else{
			i = max_len - min_len;
			c  = (Alast > Blast) ? Integer.parseInt(A.valueOf(A.charAt(i-1))):Integer.parseInt(B.valueOf(B.charAt(i-1)));
    		if(carry == 0){
				C = (Alast > Blast) ? A.substring(0,i):B.substring(0,i) + C;
				System.out.println("2C="+C);
				return;
			}else if(carry == 1 && c == 0  ) {
				C = (Alast > Blast) ? A.substring(0,i-1):B.substring(0,i-1) + "1"+ C;
				System.out.println("3C="+C);
				return;
			}else{
				System.out.println("before last while i = "+i+"  C="+C);
				while(i-- >= 0){
					System.out.println("into last while i = "+i+"  C="+C);
					c  = (Alast > Blast) ? Integer.parseInt(A.valueOf(A.charAt(i))):Integer.parseInt(B.valueOf(B.charAt(i)));
					System.out.println("in the while c="+c+"  i="+i+" carry="+carry);
					if(c == 0){
						carry = 0;
						C = ((Alast > Blast) ? A.substring(0,i):B.substring(0,i)) + "1" + C;
						System.out.println("4C="+C);
						return;
					}else{
						C = "0" + C;
					}
				}
				if(carry == 1)
				{
					C = "1" + C;
				}
			
			}

		}		
		System.out.println("5C="+C);
		return;
		
	}
	
}