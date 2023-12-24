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

    friend bool operator< (const edge a, const edge b){
        return a.cost > b.cost;
    }
};

int main(){
    int POINT_NUM, EDGE_NUM;
    cin >> POINT_NUM >> EDGE_NUM;

    vector<vector<edge>> graph(POINT_NUM+1);
    for(int i = 0 ; i < EDGE_NUM ; i++){
        edge* temp = new edge;
        cin >> temp->start >> temp->end >> temp->cost;
        graph[temp->start].push_back(*temp);
    }

    int root;
    cin >> root;

    vector<int> parent(POINT_NUM+1, -1);
    vector<int> cost(POINT_NUM+1, 100000);
    vector<bool> visited(POINT_NUM+1, false);
    parent[root] = 0;
    cost[root] = 0;
    visited[root] = true;

    priority_queue<edge> edge_list;
    for(int i = 0 ; i < graph[root].size() ; i++){
        edge_list.push(graph[root][i]);
    }

    while(edge_list.empty() == false){
        edge temp = edge_list.top();
        edge_list.pop();

        if(temp.cost + cost[temp.start] >= cost[temp.end])  continue;

        cost[temp.end] = temp.cost + cost[temp.start];
        parent[temp.end] = temp.start;

        if(visited[temp.end] == true)   continue;

        for(int i = 0 ; i < graph[temp.end].size() ; i++)
            edge_list.push(graph[temp.end][i]);
        visited[temp.end] = true;
    }

    for(int i = 1 ; i < cost.size() ; i++)
        cout << cost[i] << " \n"[i == cost.size()-1];
    
    for(int i = 1 ; i < parent.size() ; i++)
        cout << parent[i] << " \n"[i == parent.size()-1];

    return 0;
}