#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void input(vector<int> &v){
    for(int i = 1; i < v.size(); i++){
        cin >> v[i];
    }
    return;
}

int greedy(int act, vector<int> &s, vector<int> &e, vector<int> &is_SE){
    if(act <= 0)    return 0;
    is_SE[act] = 2;
    int next_act = 0;
    int maxStart = 0;
    for(int i = 1; i < s.size(); i++){
        if(is_SE[i] == 1 && e[i] > s[act]){
            is_SE[i] = 0;
        }
        
        if(is_SE[i] == 1 && s[i] >= maxStart){
            maxStart = s[i];
            next_act = i;
        }
    }
    return greedy(next_act, s, e, is_SE) + 1;
}

int main(){
    int num;
    cin >> num;
    vector<int> start(num+1);
    vector<int> end(num+1);
    input(start);
    input(end);
    vector<int> is_selected(num+1, 1);

    //find largest starting time
    int maxStart = 0;
    int act = 0;
    for(int i = 1; i < start.size(); i++){
        if(start[i] >= maxStart){
            maxStart = start[i];
            act = i;
        }
    }
    
    int cnt = greedy(act, start, end, is_selected);
    cout << cnt << endl;

    cout << '(';
    for(int i = 1; i <= num; i++){
        if(is_selected[i] == 2){
            cout << i;
            cnt--;
            if(cnt != 0){
                cout << ",";
            }
        }
    }
    cout << ')';
}