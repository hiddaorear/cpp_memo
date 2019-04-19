# elementary

## 编译与调试

### Mac 编译 C++ 11

`g++ -std=c++11`

为了方便，设置zsh 别名：`alias g++='g++ -std=c++11'`

### 调试

#### 打印vector

``` c++
int elements[] = {1, 2, 3, 4};
const size_t N = sizeof(elements)/sizeof(elements[0]);

std::vector<int> vec(elements, elements + N);

// iterator
for (auto i = vec.begin(); i != vec.end(); ++i) {
    std::cout << "vec " << *i << std::endl;
}

for (const auto& i: vec) {
    std::cout << "vec " << i << std::endl;
}
// for_each
std::for_each(vec.begin(), vec.end(), [] (const int i) {std::cout << "for_each vec: " << i << std::endl;});

// copy
std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, "std::copy and ostream_iterator"));

```
