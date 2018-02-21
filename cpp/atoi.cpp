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
#include <string>
#include <iostream>
using namespace std;

int test(string  A){
   int Alen = A.size();
   int sign = 1;
   long t = 0;
   int i = 0;
   int c = 0;
   int b = 0;
  
   while(i < Alen&& b < 11){
       c = A[i] - '0';
       cout<<"i = "<<i<<"  c="<<A[i]<<"  b="<<b<<"  t= "<<(int)t<<endl;
       i++;
       if((c+'0')==' '){
           continue;
       }else if((c+'0')=='+'){
           sign = 1;
           continue;
       }else if((c+'0')=='-'){
           sign = -1;
           continue;
       }else if(c>=0&&c<=9){
           //if(std::isalnum(c+'0') ) {cout<<"c is al num"<<endl;}
           //if(std::isdigit(c+'0') ) {cout<<"c is digit"<<endl;}
           t = 10*t + c;
           cout<<"in while i = "<<i<<"  c="<<A[i]<<"  b="<<b<<"  t= "<<(int)t<<endl;
           b++;
       }else{
           break;
       }
   }
   if(sign*t <= 2147483647 || sign*t >=-2147483648)
       cout<<"-------  t= "<<(int)(sign*t)<<endl;
   else
       cout<<"-------out int range  t= 0"<<endl;
   return 0;
}
 int main(){
       string A = "   -789";
       test(A);
       return 0;
}
 