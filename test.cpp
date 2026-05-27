// 加个缩进，看看递归过程
#include <iostream>
#include <vector>
using namespace std;

void permute(vector<int>& nums, int start, int depth) {
    // 打印缩进
    for (int i = 0; i < depth; i++) cout << "  ";
    cout << "进入: start=" << start << endl;
    
    if (start == nums.size() - 1) {
        for (int i = 0; i < depth; i++) cout << "  ";
        for (int num : nums) cout << num << " ";
        cout << " ← 输出" << endl;
        return;
    }
    
    for (int i = start; i < nums.size(); i++) {
        for (int j = 0; j < depth; j++) cout << "  ";
        cout << "交换 nums[" << start << "]和nums[" << i << "]" << endl;
        
        swap(nums[start], nums[i]);
        permute(nums, start + 1, depth + 1);
        swap(nums[start], nums[i]);
        
        for (int j = 0; j < depth; j++) cout << "  ";
        cout << "换回" << endl;
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    permute(nums, 0, 0);
    return 0;
}