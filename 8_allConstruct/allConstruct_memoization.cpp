#include "bits/stdc++.h"
using namespace std;


string suffix(string source,int minusLen)
{
    string retStr="";
    for(int i=minusLen;i<source.length();i++)
        retStr = retStr + source[i];
    
    return retStr;
}

vector<vector<string>> allConstruct(string arr[], int n, string target,map<string,vector<vector<string>>> &memo)
{

    if(memo.find(target) != memo.end())
        return memo[target];

    vector<vector<vector<string>>> _3d;

    if(target == "")
    {
        vector<vector<string>> v(1,vector<string>(1,""));
        v.pop_back();
        return v;
    }
    
    for(int i=0;i<n;i++)
    {
        
        int pos = target.find(arr[i]);
        
        if(pos == 0)
        {
            string newTarget = suffix(target,arr[i].length());
            vector<vector<string>> _2d;

            _2d = allConstruct(arr,n,newTarget,memo);
            
            if(_2d.capacity() != 0)
            {
                if(_2d.size()==0)
                {
                    vector<string> push;
                    push.push_back(arr[i]);
                    _2d.push_back(push);
                }
                else
                {
                    for(int j=0;j<_2d.size();j++)
                    {
                        _2d[j].push_back(arr[i]);
                    }
                }
                _3d.push_back(_2d);
                //_2d.clear();
            }
        }
    }
    
    vector<vector<string>> _2dRet;

    if(_3d.size() != 0)
    {
        for(int i=0;i<_3d.size();i++)
        {
            for(int j=0;j<_3d[i].size();j++)
                _2dRet.push_back(_3d[i][j]);
        }
    }

    memo[target] = _2dRet;
    return _2dRet;
}


int main() {
	// your code goes here
	
	int n;
	cin>>n;
	vector<vector<string>> result;
    map<string,vector<vector<string>>> memo;

	string arr[n],target;
	
	for(int i=0;i<n;i++)
	    cin>>arr[i];
	
	cin>>target;
	
	result = allConstruct(arr,n,target,memo);
	
	if(result.size()==0)
	    cout<<"Not possible"<<endl;
	else
	{
        cout<<"Possible Combinations are "<<endl;
	    for(int i=0;i<result.size();i++)
	    {
	        for(int j=result[i].size()-1;j>=0;j--)
	        {
	            cout<<result[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	}


    cout<<"map size is "<<memo.size()<<endl;
	return 0;
}
