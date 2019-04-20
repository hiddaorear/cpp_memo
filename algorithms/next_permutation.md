# next permutation

## 题目

来源：leetcode

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

`1,2,3` →  `1,3,2`
`3,2,1` →  `1,2,3`
`1,1,5` →  `1,5,1`


## 实现

``` c++
#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int>::iterator i, vector<int>::iterator j) {
    while (j < j) {
        *i ^= *j;
        *j ^= *i;
        *i ^= *j;
        i++;
        j++;
    }
}

vector<int> next_permutation(vector<int> &nums) {
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    if (i < 0) {
        reverse(nums.begin(), nums.end() - 1);
    } else {
        int j = i + 2;
        while (j < nums.size() && nums[j] > nums[i]) {
            j++;
        }
        j--;

        nums[i] ^= nums[j];
        nums[j] ^= nums[i];
        nums[i] ^= nums[j];

        reverse(nums.begin() + i + 1, nums.end() - 1);
    }
    return nums;
}

int main() {
    int elements[] = {1, 2, 3, 4};
    const size_t N = sizeof(elements)/sizeof(elements[0]);
    vector<int> vec(elements, elements + N);

    cout << "before: " << endl;
    for_each(vec.begin(), vec.end(), [] (const int i) {cout << i << ", ";});
    cout << " " << endl;

    next_permutation(vec);

    cout << "after: " << endl;
    for_each(vec.begin(), vec.end(), [] (const int i) {cout << i << ", " ;});
    cout << " " << endl;

}

```


## 参考资料

- [31. Next Permutation](https://leetcode.com/problems/next-permutation/)

- [LeetCode题解 #31 Next Permutation](https://www.tianmaying.com/tutorial/LC31)

- [std::next_permutation Implementation Explanation](https://stackoverflow.com/questions/11483060/stdnext-permutation-implementation-explanation)

- [std::next_permutation](http://www.cplusplus.com/reference/algorithm/next_permutation/)

- [Next Permutation](https://algorithm.yuanbin.me/zh-hans/exhaustive_search/next_permutation.html)

- [下一个排列  Next Permutation](https://www.jiuzhang.com/solution/next-permutation/#tag-highlight-lang-cpp)


## change log

- 2019/4/20 新建文档，收集资料
- 2019/4/21 完成C++的next permuration初步实现
