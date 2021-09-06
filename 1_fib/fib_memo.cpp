    
// MENTOS JINDAGI WITH MEMOIZATION
// Time Complexity : O(n)


    #include "bits/stdc++.h"
    using namespace std;
    #define INF 1000000000000000003
    
    long fib_memo(int n,map<long,long> &memo)
    {   
        
        if(memo.find(n) != memo.end()) // Check if we already have result in map
            return memo[n];
            
        if(n == 1 || n == 2)
            return 1;
            
        
        memo[n] = fib_memo(n-1,memo) + fib_memo(n-2,memo); // Store result in map once calculated.
        
        return memo[n]; // return the calculated value.
    }
    
    int main()
    {
        map<long,long> memo;
        
        cout<<fib_memo(2,memo)<<endl;
        cout<<fib_memo(3,memo)<<endl;
        cout<<fib_memo(8,memo)<<endl;
        cout<<fib_memo(50,memo)<<endl;
        
        return 0;     
    }
    
