    
// RECURRSION KI AAM JINDAGI 
// Time Complexity : O(2^n)

    #include "bits/stdc++.h"
    using namespace std;
    #define INF 1000000000000000003
    
    
    int fib_recc(int n)
    {   
        if(n == 1 || n == 2)
            return 1;
        
        return fib_recc(n-1) + fib_recc(n-2);
    }
    
    int main()
    {
        cout<<fib_recc(2)<<endl;
        cout<<fib_recc(3)<<endl;
        cout<<fib_recc(8)<<endl;
        return 0;     
    }
    
