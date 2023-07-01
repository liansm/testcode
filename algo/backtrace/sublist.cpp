//
//  sublist.cpp
//  CSPFinal
//
//  Created by liansm on 2023/6/27.
//

/*
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


int list[10];
int n;

std::vector<std::vector<int>> all_list;

void create_list()
{
    cin >> n;
    
    for(int i = 0; i < n; ++i){
        cin >> list[i];
    }
}


void travel_list(std::vector<int> & cur_list, int index)
{
    all_list.push_back(cur_list);

    for(int i = index; i < n; ++i){
//        auto obj_it = find(cur_list.begin(), cur_list.end(), list[i]);
//        if(obj_it == cur_list.end() ){
            cur_list.push_back(list[i]);
            travel_list(cur_list, i+1);
            cur_list.pop_back();
//        }
    }
}

void print_sub_list()
{
    std::cout << "{";
    for(size_t i = 0; i < all_list.size(); ++i){
        std::vector<int> & sub_list =  all_list[i];
        std::cout << "[";
        for(size_t j = 0; j < sub_list.size(); ++j){
            std::cout << sub_list[j] << " ";
        }
        std::cout << "]";
        std::cout << endl;
    }
    std::cout << "}";
}


int main()
{
    create_list();
    std::vector<int> cur_list;
    travel_list(cur_list, 0);
    print_sub_list();
    return 0;
}
*/
