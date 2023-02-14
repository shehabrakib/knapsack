#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n, w;
	cin>> n >> w;

	int weight[n+10], value[n+10];
	int dp[n+10][w+10];

	memset(dp,-1,sizeof(dp));

	for(int i = 0;i<n; i++)cin>>weight[i];

	for(int i = 0; i<n; i++)cin>>value[i];

	for(int i = 0; i<=n; i++)
	{
		for(int j = 0; j<=w; j++)
		{
			if(i==0 || j==0)dp[i][j] = 0;
			else if(weight[i-1]>j)
			{
				dp[i][j] = dp[i-1][j];
			}
			else dp[i][j] = max(dp[i-1][j] , value[i-1] + dp[i-1][j-weight[i-1]]);
		}
	}
	cout<<dp[n][w]<<endl;

	return 0;
}