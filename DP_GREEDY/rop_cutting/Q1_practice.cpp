#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> cost(n+1, 0);
    for(int i = 1 ; i < n+1 ; i++)
        cin >> cost[i];

    vector<int> dp(n+1, 0);
    vector<int> pre(n+1,0);
    vector<int> cntPart(n+1, 0);

    for(int i = 1 ; i < n+1 ; i++){
        for(int subLen = 0 ; subLen < i ; subLen++){
            if(dp[subLen] + cost[i-subLen] > dp[i]){
                pre[i] = subLen;
                dp[i] = dp[subLen] + cost[i-subLen];
                cntPart[i] = cntPart[subLen] + 1;
            }
        }
    }

    cout << dp[n] << endl;
    cout << cntPart[n] << endl;
    cout << n << '=' ;
    int t = n;
    while(t > 0){
        cout << t - pre[t] << "+\n"[pre[t] == 0] ;
        t = pre[t];
    }
}