#include <fstream>
#include <functional>
#include <iostream>

using logFunc_t = std::function<void(const std::string &)>;

int add3(int n) {
    return n+3;
}

int mul2(int n) {
    return n*2;
}

int mycomputefile(logFunc_t logF, int v0) {
    logF("add3 " + std::to_string(v0));
    const int v1 = add3(v0);
    logF("mul2 " + std::to_string(v1));
    const int v2 = add3(v1);

    return v2;
}

int main() {
    std::cout << "this is log-cpp" << std::endl;

    const auto &res = mycomputefile([](const std::string &text) -> void {
        std::cout << text << std::endl; 
    }, 5);
    std::cout << res << std::endl;

    std::ofstream file("log2.txt");
    const auto &res2 = mycomputefile([&file](const std::string &text) -> void {
        file << text << std::endl;
    }, 5);
    std::cout << res2 << std::endl;

    return 0;
}

