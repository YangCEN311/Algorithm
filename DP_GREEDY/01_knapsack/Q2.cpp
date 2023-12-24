#include<iostream>
#include<vector>

using namespace std;

void input(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cin >> v[i];
    }
    return;
}

int find(int item, int wei, int vol, vector<int> &cost, vector<int> &weight, vector<int> &volume, vector<vector<int>> &dp, vector<vector<bool>> &selected){
    if(item == 0){
        return 0;
    }
    if(dp[wei][vol] != -1){
        return dp[wei][vol];
    }
    if(weight[item - 1] > wei || volume[item - 1] > vol){
        return dp[wei][vol] = find(item - 1, wei, vol, cost, weight, volume, dp, selected);
    }
    int dont_take = find(item - 1, wei, vol, cost, weight, volume, dp, selected);
    int take = cost[item - 1] + find(item - 1, wei - weight[item - 1], vol - volume[item - 1], cost, weight, volume, dp, selected);
    
    if(take > dont_take){
        selected[item][wei] = true;
        return dp[wei][vol] = take;
    } else {
        return dp[wei][vol] = dont_take;
    }
}

vector<int> printSelectedItems(vector<vector<bool>> &selected, vector<int> &weight, vector<int> &volume, int n, int W){
    int w = W;
    vector<int> seqence;
    for(int i = n; i > 0; i--){
        if(selected[i][w] == true){
            seqence.push_back(i);
            w = w - weight[i-1];
        }
    }
    return seqence;
}


int main(){

    // Constructing the input
    int num, bag_weight, bag_volume;
    cin >> num >> bag_weight >> bag_volume;
    vector<int> cost(num), weight(num), volume(num);
    input(cost);
    input(weight);
    input(volume);

    vector<vector<int>> dp(bag_weight + 1, vector<int>(bag_volume + 1, -1));
    vector<vector<bool>> selected(num + 1, vector<bool>(bag_weight + 1, false));

    cout << find(num, bag_weight, bag_volume, cost, weight, volume, dp,selected) << endl;

    vector<int> seqence1;
    seqence1 = printSelectedItems(selected, weight, volume, num, bag_weight);
    cout << seqence1.size() << endl << '(';
    for(int i = seqence1.size()-1; i >= 0; i--){
        cout << seqence1[i] ;
        if(i != 0){
            cout << ",";
        }
    }cout << ')' << endl;

}