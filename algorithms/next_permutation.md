# next permutation

## 题目

来源：leetcode

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

- `1,2,3` →  `1,3,2`

- `3,2,1` →  `1,2,3`

- `1,1,5` →  `1,5,1`

## 缘起

读陈硕先生的《Linux 多线程服务端编程：使用 muduo C++ 网络库》,在“用STL algorithm轻松解决几道算法面试题”，举例的第一道题，就是此题。我正在学习泛型，看到这个题目很有趣，就拿来练手。我更想知道标准库里是怎么实现的next permuation。查资料发现这是leetcode上的一道题目。且发现C++文档上给出例子，正好是陈硕这个例子。在这个瞬间，失望之意，难以言表。当然，作者可能是查文档，也恰好看到这个例子，觉得有趣，就摘录下来了。

看中英文资料，中文资料很多人的实现和理解，要么语焉不详，要么代码不可读。英文资料，质量要好些。但也较少有人能清晰点出关键。


## 关键点

`a1, a2, a3, a4...an`有`a1 < a2 => a3 => a4... => an`，即以a1开头的全排列，此排列最大。现在需要寻找，下一个全排列。此时，存在`aj => a1 => ak`，其中`j >= 2`，`k <= j <= n`。交换a1与aj，此时，以aj开头的所有的排列，都要大于上一个排列，即以a1开头的排列。

此时我们需要找出其中最小的排列。显然，之前以a1开头的排列，从已经是最大的，我们逆序即可得到最小的排列。

1. 整理成易于用算法实现的数学表达。`ax < ax+1 => ax+2 => ax+3... => an`，

2. 将ax替换为`ax+1, ax+2...an`系列中大于ax中的最小的。

3. 此时，依照我们的设定，`a1, a2...ax-1`，无需变化。然后将剩下的从小到大排列即可。

查资料的时候，看到有人处理3的是，直接重新用sort排序。初次看，云里雾里。看来一个平凡的算法，如果不去理解原理，乱写一气，真是啥实现都有。

## 其他例子

来源：geeksforgeeks

``` c++
using namespace std;

void swap(char *a,char *b)
{
    if( *a == *b )
        return;
    *a^=*b;
    *b^=*a;
    *a^=*b;
}
void rev(string& s,int l,int r)
{
    while(l<r)
        swap(&s[l++],&s[r--]);
}

int bsearch (string& s,int l,int r,int key)
{
    int index = -1;
    while(l<=r)
    {
        int mid = l+(r-l)/2;
        if(s[mid]<=key)
            r=mid-1;
        else
        {
            l=mid+1;
            if(index = -1 || s[index]<=s[mid])
                index = mid;
        }
    }
return index;
}

bool nextpermutation(string& s)
{
    int len = s.length(), i=len-2;
    while(i>=0 && s[i]>=s[i+1])
       --i;
    if(i<0)
        return false;
    else
    {
        int index=bsearch(s,i+1,len-1,s[i]);
        swap(&s[i],&s[index]);
        rev(s,i+1,len-1);
        return true;
    }
}

// Driver code
int main ()
{
    string s = {"gfg"};
    bool val = nextpermutation(s);
    if (val == false)
        cout << "No Word Possible" << endl;
    else
        cout << s << endl;
    return 0;
}
// This code is contributed by Mysterious Mind

```


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

- 2019/4/21 半夜，完成C++的next permuration初步实现

- 2019/4/21 1点半完成next permuration文章
