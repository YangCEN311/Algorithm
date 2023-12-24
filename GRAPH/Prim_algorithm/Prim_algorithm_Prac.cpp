#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class edge{
public:
    int start;
    int end;
    int cost;
    edge(int start = 0, int end = 0, int cost = 0){
        this->start = start;
        this->end = end;
        this->cost = cost;
    }

    friend bool operator < (const edge a, const edge b){
        return a.cost > b.cost;
    }
};

int main(){
    int POINT_NUM, EDGE_NUM;
    cin >> POINT_NUM >> EDGE_NUM;

    vector<vector<edge>> ADJ(POINT_NUM+1);
    for(int i = 0 ; i < EDGE_NUM ; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        ADJ[start].push_back(edge(start, end, cost));
        ADJ[end].push_back(edge(end, start, cost));
    }

    int root;
    cin >> root;

    priority_queue<edge> edge_list;
    for(int i = 0 ; i < ADJ[root].size() ; i++){
        edge_list.push(ADJ[root][i]);
    }

    vector<bool> visited(POINT_NUM+1, false);
    vector<int> parent(POINT_NUM+1, -1);

    visited[root] = true;
    parent[root] = 0;
    int total_cost = 0;
    int Included_point = 1;
    while(Included_point < POINT_NUM){

        edge temp = edge_list.top();
        edge_list.pop();

        if(parent[temp.end] != -1){
            continue;
        }

        total_cost += temp.cost;
        parent[temp.end] = temp.start;
        Included_point++;
        for(int i = 0 ; i < ADJ[temp.end].size() ; i++){
            edge_list.push(ADJ[temp.end][i]);
        }
            
    }

    for(int i = 1 ; i < parent.size() ; i++){
        cout << parent[i] << " \n"[i == parent.size()-1];
    }
    cout << total_cost << endl;

    return 0;
}