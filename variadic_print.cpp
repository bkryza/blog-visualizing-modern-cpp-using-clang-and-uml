#include <iostream>
#include <string>

namespace variadic_print {

void print() { }

template <typename T, typename... Ts> void print(T head, Ts... tail) {
    std::cout << head << std::endl;
    print(tail...);
}

void tmain() {
    using namespace std::literals::string_literals;

    print(1, 3.14, "clang-uml"s);
}

}
