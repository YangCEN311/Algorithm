#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class node{
public:
    int val;
    int symbol;
    node *left;
    node *right;
    node(int val = 0, int symbol = -1, node *left = NULL, node *right = NULL){
        this->val = val;
        this->symbol = symbol;
        this->left = left;
        this->right = right;
    }
};

//combine the last two element in vector
void select_merge(vector<node*> &n){
    //get the last two node
    node *temp1 = n.back();
    n.pop_back();
    node *temp2 = n.back();
    n.pop_back();
    //merge
    node *temp3 = new node(temp1->val + temp2->val, -1, temp1, temp2);
    n.push_back(temp3);
    return ;
}

//compare function for sort
bool cmt(node *a, node *b){
    if(a->val == b->val)
        return 1;
    return b->val < a->val;
}

void print_code(node *root, string code, vector<string> &huffman_code){
    if(root == NULL)
        return ;
    if(root->symbol != -1){
        huffman_code[root->symbol] = code;
        return ;
    }
    print_code(root->left, code + "0", huffman_code);
    print_code(root->right, code + "1", huffman_code);
    return ;
}

int main(){
    int num;
    cin >> num;
    vector<int> input_list(num);
    vector<node*> nums;
    for(int i = 0 ; i < num ; i++){
        cin >> input_list[i];
        node *temp = new node;
        temp->val = input_list[i];
        temp->symbol = i;
        nums.push_back(temp);
    }

    //build huffman tree
    while(nums.size() > 1){
        sort(nums.begin(), nums.end(), cmt);
        select_merge(nums);
    }

    //calculate huffman code
    node* tree_root = nums[0];
    vector<string> huffman_code(num);
    print_code(tree_root, "", huffman_code);

    cout << num << endl;
    for(int i = 0 ; i < num ; i++){
        cout << huffman_code[i];
        if(i != num - 1)
            cout << " ";
        else
            cout << endl;
    }
    
    return 0;
}