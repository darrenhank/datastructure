/**
 * Given two binary strings, return their sum (also a binary string).
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 * 
 * Tags: Math, String
 */
 
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	string A = "11110011001011110111110001010000111110011110101100011111010010001000001101111001000111";
    string B =         "111001011011111010001001111001100000101010000101100010101100010010010011011000";
    //answer C =11110100000101010011101011011010110111111111010110100100110100110100100000001100011111
    //          
	//string A = "1111001";
	//string B =     "111";
	string C = "";
	int a = 0;
	int b = 0;
	int carry = 0;
	int i = 0;		
	while(i++ < std::max(A.size(),B.size())){
			a = ((i > A.size())&(A.size() == std::min(A.size(),B.size()))&(A.size()!=B.size()))?0:(A[A.size() - i]-'0');
			b = ((i > B.size())&(B.size() == std::min(A.size(),B.size()))&(A.size()!=B.size()))?0:(B[B.size() - i]-'0');
			C.insert((string::size_type)0,1,(carry == 1)?((a^b)^carry + '0'):((a^b)|carry + '0'));
			carry = (carry == 1)?((a|b)&carry):((a&b)|carry);
			cout<<"  a="<<a<<"  i="<<i<<"  b="<<b<<"  t="<<t<<endl;
	}
	if(carry == 1) C = "1" + C;
	cout<<"C= "<<C<<endl;
	return 0;
}