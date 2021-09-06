// howSum Mentos Jindagi (memoization)

#include "bits/stdc++.h"
using namespace std;


vector<int> howSum(int arr[], int n, int targetSum, map<int,vector<int>> &memo)
{
    
    if(memo.find(targetSum) != memo.end())
        return memo[targetSum];
    
    int rem;
    vector<int> ret;
    
    if(targetSum == 0)
    {
        vector<int> v(1);
        return v;
    }
    else if(targetSum<0)
    {
        vector<int> v;
        return v;
    }
    
    for(int i = 0;i<n;i++)
    {
        rem = targetSum - arr[i];
        ret = howSum(arr,n,rem,memo);
        
        if(ret.capacity() != 0)
        {
            ret.push_back(arr[i]);
            memo[targetSum] = ret;
            return memo[targetSum];
        }
        
    }
    
    vector<int> v;
    memo[targetSum] = v; // This targetSum is not possible by given no's and this info should also be stored in map.
    return v;
}


int main()
{
    int n,targetSum;
    vector<int> result;
    map<int,vector<int>> memo;
    
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cin>>targetSum;
    
    result = howSum(arr,n,targetSum,memo);
    
    if(result.size() == 0)
    {
        cout<<"Not Possible"<<endl;
        return 0;
    }
    
    for(int i = 0;i<result.size();i++)
        cout<<result[i]<<" ";
        
    cout<<endl;
    
    // for(auto i = memo.begin();i!=memo.end();i++)
    // {
    //     cout<<i->first<<" -> { ";
        
    //     for(auto j = i->second.begin();j!=i->second.end();j++)
    //         cout<<*j<<", ";
    //     cout<<" }"<<endl;
    // }
    
}




// Alternative soln with approach similar to seiveOfErathosthenes

// CPP program to find if we can get given
// sum using elements of given array.

// #include <bits/stdc++.h>
// using namespace std;

// // maximum size of x
// const int MAX = 1000;

// // to check whether x is possible or not
// int ispossible[MAX];

// void check(int arr[], int N)
// {
// 	ispossible[0] = 1;
// 	sort(arr, arr + N);

// 	for (int i = 0; i < N; ++i)
// 	{
// 		int val = arr[i];

// 		// if it is already possible
// 		if (ispossible[val])
// 			continue;

// 		// make 1 to all it's next elements
// 		for (int j = 0; j + val < MAX; ++j)
// 		{
// 			if (ispossible[j]!=0)
// 			{
// 				ispossible[j + val] = 1;
// 			}
// 		}
// 		cout<<endl;
// 	}
// }

// // Driver code
// int main()
// {
// 	int arr[] = { 5,3 };
// 	int N = sizeof(arr) / sizeof(arr[0]);

// 	check(arr, N);
// 	int x = 11;
// 	if (ispossible[x])
// 		cout << x << " is possible."<<endl;
// 	else
// 		cout << x << " is not possible."<<endl;
	
// 	return 0;
// }








