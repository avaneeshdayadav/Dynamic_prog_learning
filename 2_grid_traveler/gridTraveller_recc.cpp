
// GRID TRAVELLER AAM JINDAGI (recurssion)

#include "bits/stdc++.h"
using namespace std;

// Try to think of recursive soln such that after every call we move to a call of smaller problem recursive func.

// i.e go from higher value like fun(5,6) to lower value fun(4,5) something.


int gridTraveller(int m, int n)
{
    if(m==1 && n==1)
        return 1;
    else if(m<=0 || n<=0)
        return 0;
    
    
    return (gridTraveller(m-1,n) + gridTraveller(m,n-1));
    
}

int main() {
	// your code goes here
	
	cout<<gridTraveller(3,0)<<endl; // 0
	cout<<gridTraveller(1,1)<<endl; // 1
	cout<<gridTraveller(0,3)<<endl; // 0
	cout<<gridTraveller(2,1)<<endl; // 1
	cout<<gridTraveller(3,3)<<endl; // 6
	cout<<gridTraveller(2,3)<<endl; // 3
	cout<<gridTraveller(3,4)<<endl; // 10
	cout<<gridTraveller(4,4)<<endl; // 20

	return 0;
}
