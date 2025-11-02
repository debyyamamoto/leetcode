#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    map <int, int> guarda;
    vector<int> candidados;
    int a = 0, b = 0;
    for(int i = 0; i < nums.size(); i++){
        if(guarda[target - nums[i]] != 0){
            if(guarda[target - nums[i]] == -1){
                guarda[target - nums[i]] = 0;
            }
            return {i, guarda[target - nums[i]]};            
        }
        if(i == 0){
            guarda[nums[0]] = -1;
        }else{
            guarda[nums[i]] = i;
        }
    }
    return {};
    }
};