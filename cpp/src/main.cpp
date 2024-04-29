#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    // 使用 lambda 函数作为 std::for_each() 的参数
    std::for_each(numbers.begin(), numbers.end(), [](int num) {
        std::cout << num << " ";
    });
    std::cout << std::endl;

    // 使用 lambda 函数作为 std::sort() 的比较函数
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a < b;
    });

    // 使用 lambda 函数作为 std::find_if() 的谓词函数
    auto it = std::find_if(numbers.begin(), numbers.end(), [](int num) {
        return num*num > 24;
    });

    if (it != numbers.end()) {
        std::cout << "第一个大于 5 的数是：" << *it << std::endl;
    } else {
        std::cout << "没有找到大于 5 的数。" << std::endl;
    }

    return 0;
}
