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
