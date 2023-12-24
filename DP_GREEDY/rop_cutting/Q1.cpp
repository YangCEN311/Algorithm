#include<iostream>
#include<vector>

using namespace std;

vector<int> Input(){
    int input_size;
    cin >> input_size;
    vector<int> input(input_size);
    for(int i = 0; i < input_size; i++){
        cin >> input[i];
    }
    return input;
}

int main(){
    vector<int> length_price = Input();
    int length = length_price.size();

    vector<int> result(length, 0);
    vector<int> seqence(length, 0);
    vector<int> count(length, 0);

    for(int i = 0 ; i < length ; i++){
        int temp = length_price[i];
        seqence[i] = i + 1;
        count[i] = 1;
        for(int j = 0 ; j < i ; j++){
            if(temp < length_price[j] + result[i - j - 1]){
                temp = length_price[j] + result[i - j - 1];
                seqence[i] = j + 1;
                count[i] = count[i-j-1] + 1;
            }
        }
        result[i] = temp;
    }

    cout << result[length - 1] << endl;
    cout << count[length - 1] << endl;
    cout << length << "=";
    while(length > 0){
        cout << seqence[length - 1];
        length -= seqence[length - 1];
        if(length > 0)
            cout << "+";
    }
    return 0;
}