#!/usr/bin/python
def test(A):
    A = A.strip()
    if((A[0] != '+') and  (A[0] != '-') and not (A[0].isdigit())):
        return  0
    i = 1    
    while(i < len(A) ):
#        print 'i=',i,'  A[i]=',A[i]
        if(not (A[i].isdigit())):
            break
        i = i + 1
        
    print '----i=',i,'  A[0:i]=',A[0:i]

if __name__ == '__main__':
    test('  -780465766666666666666666666666666666601a')
