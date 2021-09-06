
// GRID TRAVELLER MENTOS JINDAGI (memoization)

#include "bits/stdc++.h"
using namespace std;

// Try to think of recursive soln such that after every call we move to a call of smaller problem recursive func.

// i.e go from higher value like fun(5,6) to lower value fun(4,5) something.


int gridTraveller(int m, int n, map <string,int> &memo)
{
    string key = to_string(m)+""+to_string(n);
    
    if(memo.find(key) != memo.end())
        return memo[key];
    
    if(m==1 && n==1)
    {
        memo[key] = 1;
        return 1;
    }
    else if(m<=0 || n<=0)
    {
        return 0;
    }    
    
    memo[key] = (gridTraveller(m-1,n,memo) + gridTraveller(m,n-1,memo));
    
    return memo[key];
    
}

int main()
{

    map <string,int> memo;
    cout<<gridTraveller(3,0,memo)<<endl;
	cout<<gridTraveller(1,1,memo)<<endl;
	cout<<gridTraveller(0,3,memo)<<endl;
	cout<<gridTraveller(2,1,memo)<<endl;
	cout<<gridTraveller(3,3,memo)<<endl;
	cout<<gridTraveller(2,3,memo)<<endl;
	cout<<gridTraveller(50,50,memo)<<endl;	

	return 0;
}

