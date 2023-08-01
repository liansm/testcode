#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int dp[n];
    memset(dp, sizeof(int)*n, 0);
    int max_val = 1;
    dp[0] = 1;
    for(int i = 1; i < n; ++i){
        for(int j = i -1; j >= 0; --j){
            if(a[j] > a[i]){
                dp[i] = dp[j] + 1;

                if(dp[i] > max_val){
                    max_val = dp[i];
                }
                break;
            }
        }
    }

    cout << max_val;

    return 0;
}