#include<iostream>
#include<vector>

using namespace std;

int main(){
    int Pnum, Enum;
    cin >> Pnum >> Enum;

    vector<vector<int>> dp(Pnum+1, vector<int>(Pnum+1, 100000));
    for(int i = 1 ; i <= Pnum ; i++)
        dp[i][i] = 0;
    for(int i = 0 ; i < Enum ; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        dp[start][end] = cost;
    }

    for(int k = 1 ; k <= Pnum ; k++){
        for(int i = 1 ; i <= Pnum ; i++){
            for(int j = 1 ; j <= Pnum ; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for(int i = 1 ; i <= Pnum ; i++){
        for(int j = 1 ; j <= Pnum ; j++){
            if(dp[i][j] == 100000)
                cout << "N" << " \n"[j == Pnum];
            else
                cout << dp[i][j] << " \n"[j == Pnum];
        }
    }

    return 0;
}