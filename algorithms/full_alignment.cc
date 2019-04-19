#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    int elements[] = {1, 2, 3, 4};
    const size_t N = sizeof(elements)/sizeof(elements[0]);
    std::cout << "sizeof elements: " << sizeof(elements) << std::endl;
    std::cout << "sizeof elements[0]: " << sizeof(elements[0]) << std::endl;
    std::vector<int> vec(elements, elements + N);
    for (auto i: vec) {
        std::cout << "vec " << i << std::endl;
    }
    int count = 0;
    do
    {
        std::cout << ++count << ": ";
        std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;
    } while (next_permutation(vec.begin(), vec.end()));
}
