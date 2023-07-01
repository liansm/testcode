#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap(int list[], int j, int i){
    int sw = list[j];
    list[j] = list[i];
    list[i] = sw;
}

void Selecting_sort(int list[],int len){
    int maxn;
    for(int i = 0; i < len; i++){
        maxn = i;
        for(int j = i; j < len; j++){
            if(list[j] > list[maxn]){
                maxn = j;
            }
        }
        swap(list,maxn,i);
    }
}

int main(){
    int len,val,x;
    cin >> len;

    std::vector<int> all_scores;
    all_scores.reserve(len);
    
    for(int i = 0; i < len; i++){
        cin >> x;
        all_scores.push_back(x);
    }
    cin >> x;
    val = all_scores[x-1];
    
    sort(all_scores.begin(), all_scores.end());

//    cout << val << endl;
    int cnt = 1;
    int a = 0;
    for(int i = 0; i < len; i++){
        if(all_scores[i] == val){
            cout << cnt;
            break;
        }
        if(all_scores[i] != a){
            cnt ++;
            a = all_scores[i];
        }
    }
}