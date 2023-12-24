#include<iostream>
#include<vector>

using namespace std;

class Event{
    public:
    int start;
    int end;
    Event(int s = 0, int e = 0){
        this->start = s;
        this->end = e;
    }
};

int greedy(int e, int maxEnd, vector<Event> &event_list, vector<bool> &select){
    if(e <= 0)  return 0;
    int next_e = 0;
    int maxStart = 0;

    for(int i = 1 ; i < event_list.size()+1 ; i++){
        Event temp = event_list[i];
        if(select[i] != true && temp.end <= maxEnd && temp.start > maxStart){
            next_e = i;
            maxStart = temp.start;
        }
    }
    if(next_e != 0 && select[next_e] == false)
        select[next_e] = true;

    return greedy(next_e, maxStart, event_list, select) + 1;
}

int main(){
    int NUM;
    cin >> NUM;

    vector<Event> event_list(NUM+1);
    for(int i = 1 ; i < NUM+1 ; i++){
        cin >> event_list[i].start;
    }
    for(int i = 1 ; i < NUM+1 ; i++){
        cin >> event_list[i].end;
    }

    int start = 0;
    for(int i = 1 ; i < NUM+1 ; i++){
        if(event_list[i].start > event_list[start].start)
            start = i;
    }

    vector<bool> select(NUM+1, false);
    select[start] = 1;

    int cnt = greedy(start, event_list[start].start, event_list, select);

    cout << cnt << endl;

    cout << '(';
    for(int i = 1 ; i < NUM+1 ; i++){
        if(select[i]){
            cout << i << ",)"[cnt == 1];
            cnt--;
        }
    }
    
}