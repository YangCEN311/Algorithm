#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class edge{
public:
    int head;
    int end;
    float cost;
    edge(int head, int end, float cost){
        this->head = head;
        this->end = end;
        this->cost = cost;
    };    
};

bool cmp(const edge &a, const edge &b){
    return a.cost > b.cost;
}

//output format
void coutParentCost(vector<int> parent, vector<float> cost){
    for(int i = 1; i < cost.size(); i++){
        cout << cost[i];
        if(i != cost.size()-1)
            cout << " ";
        else
            cout << endl;
    }
    for(int i = 1; i < parent.size(); i++){
        cout << parent[i];
        if(i != parent.size()-1)
            cout << " ";
        else
            cout << endl;
    }
}

int main(){
    int POINT_NUM, EDGE_NUM;
    cin >> POINT_NUM >> EDGE_NUM;

    vector<vector<edge>> ADJ(POINT_NUM+1);
    for(int i = 0 ; i < EDGE_NUM; i++){
        int start, end;
        float cost;
        cin >> start >> end >> cost;
        ADJ[start].push_back(edge(start, end, cost));
    }

    int root;
    cin >> root;

    vector<int> parent(POINT_NUM+1, -1);
    vector<float> cost(POINT_NUM+1, 1000000);
    vector<bool> visited(POINT_NUM+1, false);
    cost[root] = 0;
    parent[root] = 0;

    vector<edge> edge_list;
    for(int i = 0 ; i < ADJ[root].size(); i++){
        edge_list.push_back(ADJ[root][i]);
    }

    while(edge_list.size() != 0){
        //sort the edge_list by cost
        sort(edge_list.begin(), edge_list.end(), cmp);

        //get the edge which has the smallest cost
        edge e = edge_list.back();
        edge_list.pop_back();

        //if the cost to visited the point with this edge is larger than the cost of the end point, skip it
        if(e.cost + cost[e.head] >= cost[e.end])    continue;

        //else, update the cost and parent
        cost[e.end] = e.cost + cost[e.head];
        parent[e.end] = e.head;

        //if the end point is not visited, push all the edge which start from the end point into the edge_list
        if(visited[e.end] == false){
            for(int i = 0 ; i < ADJ[e.end].size(); i++)
                edge_list.push_back(ADJ[e.end][i]);
            visited[e.end] = true;
        }

    }

    coutParentCost(parent, cost);
    return 0;
}