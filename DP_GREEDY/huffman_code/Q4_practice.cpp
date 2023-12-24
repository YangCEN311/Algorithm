#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class node{
public:
    int val;
    int id;
    node* left;
    node* right;
    node(int val = 0, int id = -1, node* left = NULL, node* right = NULL){
        this->val = val;
        this->id = id;
        this->left = left;
        this->right = right;
    }
};

bool cmp(const node* a, const node* b){
    if(a->val == b->val)
        return 1;
    return a->val > b->val;
}

void get_huffmanTree(node* root, string pattern, vector<string> &ans){
    if(root == NULL)   
        return;
    if(root->id != -1){
        ans[root->id] = pattern;
        return;
    }
    get_huffmanTree(root->left, pattern + "0", ans);
    get_huffmanTree(root->right, pattern + "1", ans);
    return;
}

int main(){
    int NUM;
    cin >> NUM;

    vector<node*> node_list;
    for(int i = 0 ; i < NUM ; i++){
        int val;
        cin >> val;
        node *temp = new node;
        temp->val = val;
        temp->id = i;
        node_list.push_back(temp);
    }

    while(node_list.size() > 1){
        sort(node_list.begin(), node_list.end(), cmp);

        node* temp = new node;
        temp->left = node_list.back();
        node_list.pop_back();
        temp->right = node_list.back();
        node_list.pop_back();
        temp->val = temp->left->val + temp->right->val;
        node_list.push_back(temp);
    }

    node* root = node_list[0];
    vector<string> ans(NUM);
    get_huffmanTree(root, "", ans);

    cout << NUM << endl;
    for(int i = 0 ; i < NUM ; i++){
        cout << ans[i] << " \n"[i == NUM-1];
    }
}