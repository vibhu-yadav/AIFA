#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> matrices;
typedef pair<int,int> matrix;

int mul(matrix a,matrix b)
{
	int ans = 0;

	if(a.second == b.first)
		ans = a.first * a.second * b.second;

	else if(a.first == b.second)
		ans = a.first * a.second * b.first;

	else
		ans = -1;

	return ans;
}


int MCM(matrices list){

	int n = list.size();

	int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){

			int val = INT_MAX;

			for(int k=i;k<=j;k++){

				if(k-i == 1){

					int singular = mul(list[i],list[k]);
					if(singular == -1)
						continue;
					int lookup = dp[k+1][j+1];
					// cost = mul(i,i+1) + dp[i+1:j]; k = i+1;
					val = min(val,singular + lookup);
				}

				else if(j-k == 1){
					
					int singular = mul(list[k],list[j]);
					if(singular == -1)
						continue;

					int lookup = dp[i+1][k+1];
					// cost = dp[i:k] + mul(j-1,j); k = j-1;

					val = min(val,singular + lookup);
				}

				else{
					int lookup = dp[i+1][k+1] + dp[k+1][j+1];
					// cost = dp[i:k] + dp[k:j];
					val = min(val,lookup);
				}
				
			}
				
			dp[i+1][j+1] = val;

		}
	}

	for(int i=0;i<=n;i++){

		for(int j=0;j<=n;j++)
			cout << dp[i][j] << " ";

		cout << endl;
	}

	return dp[n][n];

}

int main()
{
	int N = 3;

	matrices list = {
		{10,30},
		{30,5},
		{5,60}
	};

	cout << MCM(list) << endl;

	return 0;
}