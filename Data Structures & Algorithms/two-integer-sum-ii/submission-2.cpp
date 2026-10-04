class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        for(int i =0 ;i<numbers.size();i++){
            int a = numbers[i];
            int b = target-a;
            
            auto it = upper_bound(numbers.begin()+i,numbers.end(),b);
            if(it == numbers.begin()) continue;
            it--;
            int indi = it-numbers.begin();
            if(indi>i && b == *it) return {i+1,indi+1};
        }
        return {};
    }
};
