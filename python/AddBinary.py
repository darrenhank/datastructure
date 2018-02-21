#!/usr/bin/python

if __name__ == '__main__':
    A = "11110011001011110111110001010000111110011110101100011111010010001000001101111001000111";
    B =         "111001011011111010001001111001100000101010000101100010101100010010010011011000";
    #answer C =11110100000101010011101011011010110111111111010110100100110100110100100000001100011111
    #          11110100000101010011101011011010110111111111010110100100110100110100100000001100011111
    C = ''
    a = 0;
    b = 0;
    carry = 0;
    i = 1
    while(i <=max(len(A),len(B))):
        a = 0 if ((i > len(A))&(len(A) == min(len(A),len(B)))&(len(A)!=len(B))) else (A[len(A) - i]);
        b = 0 if ((i > len(B))&(len(B) == min(len(A),len(B)))&(len(A)!=len(B))) else (B[len(B) - i]);
        C = (str((int(a)^int(b))^carry) + C) if (carry == 1)else (str((int(a)^int(b))|carry ) + C)
        carry = ((int(a)|int(b))&carry) if (carry == 1) else ((int(a)&int(b))|carry)
        print 'i=',i,' a=',a,'  b=',b,' carry=',carry,' C= ',C
        i += 1 
    if(carry == 1):
        C = "1" + C;
    print '---------i=',i,' a=',a,'  b=',b,' carry=',carry,' C= ',C