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
//push the edge connected to the newHead into the edge_list
void PushEdge(vector<edge> &edge_list, vector<vector<edge>> ADJ, int newHead){
    for(int i = 0 ; i < ADJ[newHead].size(); i++){
        edge_list.push_back(ADJ[newHead][i]);
    }
    return;
}
//update the parent and total_cost
void Update(vector<int> &parent, float &total_cost, edge e){
    parent[e.end] = e.head;
    total_cost += e.cost;
    return;
}
//output format
void coutMST(vector<int> parent, float total){
    for(int i = 1; i < parent.size(); i++){
        cout << parent[i];
        if(i != parent.size()-1)
            cout << " ";
        else
            cout << endl;
    }
    cout << total << endl;
}
int main(){
    int POINT_NUM, EDGE_NUM;
    cin >> POINT_NUM >> EDGE_NUM;

    vector<vector<edge>> ADJ(POINT_NUM+1);
    for(int i = 0; i < EDGE_NUM; i++){
        int start, end;
        float cost;
        cin >> start >> end >> cost;
        ADJ[start].push_back(edge(start, end, cost));
        ADJ[end].push_back(edge(end, start, cost));
    }

    int root;
    cin >> root;

    vector<int> parent(POINT_NUM+1, -1);
    vector<bool> visited(POINT_NUM+1, false);
    vector<edge> edge_list;
    float total_cost = 0;
    parent[root] = 0;
    visited[root] = true;
    for(int i = 0 ; i < ADJ[root].size(); i++){
        edge_list.push_back(ADJ[root][i]);
    }

    int i = 1;
    while(i < POINT_NUM){
        //sort the edge_list to find the edge which has the smallest cost
        sort(edge_list.begin(), edge_list.end(), cmp);

        //if the edge's end is already visited, pop it
        if(parent[edge_list.back().end] != -1){
            edge_list.pop_back();
        }
        //else, update the parent and total_cost
        else{
            edge temp = edge_list.back();
            edge_list.pop_back();

            Update(parent, total_cost, temp);
            PushEdge(edge_list, ADJ, temp.end);
            i++;
        }
    }

    coutMST(parent, total_cost);
    return 0;
}