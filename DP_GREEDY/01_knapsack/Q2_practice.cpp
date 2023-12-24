#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class obj{
public:
    int value;
    int weight;
    int volume;
    obj(int value = 0, int weight = 0, int volume = 0){
        this->value = value;
        this->weight = weight;
        this->volume = volume;
    }
};

int take_or_not(int n, int w, int v, vector<obj> &obj_list, vector<vector<int>> &dp, vector<vector<int>> &select){
    if(n < 1)   return 0;
    if(w < obj_list[n].weight || v < obj_list[n].volume)    return take_or_not(n-1, w, v, obj_list, dp, select);
    if(dp[w][v] != -1)
        return dp[w][v];
    
    obj temp = obj_list[n];
    int take = take_or_not(n-1, w - temp.weight, v - temp.volume, obj_list, dp, select);
    int n_take = take_or_not(n-1, w, v, obj_list, dp, select);

    if(take + temp.value > n_take){
        dp[w][v] = take + temp.value;
        select[w][v] = n;
    }
    else{
        dp[w][v] = n_take;
    }

    return dp[w][v];
}

int main(){
    int NUM, WEIGHT, VOLUME;
    cin >> NUM >> WEIGHT >> VOLUME;

    vector<obj> obj_list(NUM+1);
    for(int i = 1 ; i < NUM+1 ; i++){
        cin >> obj_list[i].value;
    }
    for(int i = 1 ; i < NUM+1 ; i++){
        cin >> obj_list[i].weight;
    }
    for(int i = 1 ; i < NUM+1 ; i++){
        cin >> obj_list[i].volume;
    }

    vector<vector<int>> dp(WEIGHT+1, vector<int>(VOLUME+1, -1));
    vector<vector<int>> select(WEIGHT+1, vector<int>(VOLUME+1, 0));

    cout << take_or_not(NUM, WEIGHT, VOLUME, obj_list, dp, select) << endl;

    vector<int> seqence;
    int w = WEIGHT, v = VOLUME;
    while(select[w][v] != 0){
        seqence.push_back(select[w][v]);
        obj temp = obj_list[select[w][v]];
        w -= temp.weight;
        v -= temp.volume;
    }
    sort(seqence.begin(), seqence.end());
    cout << seqence.size() << endl << "(";
    for(int i = 0 ; i < seqence.size() ; i++){
        cout << seqence[i] << ",)"[i == seqence.size()-1];
    }cout << endl;
}