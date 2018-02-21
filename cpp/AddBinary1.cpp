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
    //          11110100000101010011101011011010110111111111010110100100110100110100100000001100011111
    //string A = "1111111";
    //string B =     "111";
    string C = "";
    int a = 0;
    int b = 0;
    int Alen = A.size();
    int Blen = B.size();
    int carry = 0;
    int i = 1;
    while(i <= Alen || i <= Blen){
        a = (i > Alen)?0:(A[Alen - i]-'0');
        b = (i > Blen)?0:(B[Blen - i]-'0');
        C.insert((string::size_type)0,1,((a + b + carry)%2 + '0'));
        carry = (a + b + carry)/2 ;
        cout<<"  a="<<a<<"  i="<<i<<"  b="<<b<<"  C="<<C<<endl;
        i++;
    }
    if(carry == 1) C = "1" + C;
    cout<<"----C= "<<C<<endl;
    return 0;
}