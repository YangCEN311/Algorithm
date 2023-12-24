#include<iostream>
#include<vector>

using namespace std;

int main(){
    int POINT_NUM, EDGE_NUM;
    cin >> POINT_NUM >> EDGE_NUM;

    vector<vector<float>> dp(POINT_NUM+1, vector<float>(POINT_NUM+1, 1000000));
    for(int i = 1; i < POINT_NUM+1; i++)
        dp[i][i] = 0;
    for(int i = 0; i < EDGE_NUM; i++){
        int start, end;
        float cost;
        cin >> start >> end >> cost;
        dp[start][end] = cost;
    }

    for(int k = 1 ; k < POINT_NUM+1; k++){
        for(int i = 1; i < POINT_NUM+1; i++){
            for(int j = 1; j < POINT_NUM+1; j++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    for(int i = 1 ; i < POINT_NUM+1; i++){
        for(int j = 1; j < POINT_NUM+1; j++){
            if(dp[i][j] == 1000000)
                cout << "N";
            else
                cout << dp[i][j];
            if(j != POINT_NUM)
                cout << " ";
            else
                cout << endl;
        }
    }

    return 0;
}
