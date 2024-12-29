#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }
    int step = 0;
    while(nums.size() > 1) {
        vector<int> new_nums;
        int pos = 1;
        for(int i = 0; i < nums.size(); i++) {
            bool to_delete = false;
            if(step % 3 == 0) {
                if(pos % 2 == 0) to_delete = true;
            } else if(step % 3 == 1) {
                if(pos % 2 == 1) to_delete = true;
            } else if(step % 3 == 2) {
                if(pos % 3 == 0) to_delete = true;
            }
            if(!to_delete) new_nums.push_back(nums[i]);
            pos++;
        }
        nums = new_nums;
        step++;
    }
    cout << nums[0] << endl;
    return 0;
}