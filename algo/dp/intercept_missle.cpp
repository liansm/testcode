#include <iostream>
#include <algorithm>
using namespace std;

int dp[1005];
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        dp[i] = 1;
    }

    int max_val = 1;
    dp[0] = 1;
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j){
            if(a[j] > a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
                if(dp[i] > max_val){
                    max_val = dp[i];
                }
            }
        }
    }

    cout << max_val;
    return 0;
}