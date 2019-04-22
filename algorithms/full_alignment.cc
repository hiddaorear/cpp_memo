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
    // 打印vector的方法
    // iterator
    for (auto i = vec.begin(); i != vec.end(); ++i) {
        std::cout << "vec " << *i << std::endl;
    }

    for (const auto& i: vec) {
        std::cout << "vec " << i << std::endl;
    }
    std::for_each(vec.begin(), vec.end(), [] (const int i) {std::cout << "for_each vec: " << i << std::endl;});
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, "std::copy and ostream_iterator"));
    std::cout << std::endl;
    int count = 0;
    do
    {
        std::cout << ++count << ": ";
        std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;
    } while (next_permutation(vec.begin(), vec.end()));
}
