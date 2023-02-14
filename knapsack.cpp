#include<bits/stdc++.h>
using namespace std;

int weight[105] , value[105];

int knapsack(int index, int weight_left)
{
	if(weight_left==0)return 0;
	if(index<0)return 0;

	int ans = knapsack(index-1,weight_left);//Don't choose item at index

	if(weight_left - weight[index]>=0)
	{
		ans = max(ans , knapsack(index-1,weight_left - weight[index]) ) + value[index];
		//choose item at index
	}
	return ans;
}

int main()
{
	int n, w;
	cin >> n >> w;
	for(int i = 0; i<n; i++)
		cin >> weight[i];

	for(int i = 0; i<n; i++)
		cin >> value[i];

	cout<<knapsack(n-1 , weight)<<endl;

	return 0;
}