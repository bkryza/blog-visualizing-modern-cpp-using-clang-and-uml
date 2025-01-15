#include <iostream>
#include <type_traits>

namespace type_list {
template <typename... Types> struct TypeList { };

template <typename T> void PrintType() {
    std::cout << typeid(T).name() << '\n';
}

template <typename TypeList> void PrintTypeList() {
    PrintTypeListHelper(TypeList{});
}

template <typename TypeList, typename T> struct Contains;

template <typename T> struct Contains<TypeList<>, T> : std::false_type { };

template <typename Head, typename... Tail, typename T>
struct Contains<TypeList<Head, Tail...>, T>
    : std::conditional_t<std::is_same_v<Head, T>, std::true_type,
          Contains<TypeList<Tail...>, T>> { };

template <typename TypeList, typename T>
inline constexpr bool Contains_v = Contains<TypeList, T>::value;

template <typename T>
concept IsArithmetic = std::is_arithmetic_v<T>;

struct A { };
struct B { };

template <typename T> void printType() {
    std::cout << typeid(T).name() << " is not arithmetic!\n";
}

template <IsArithmetic T> void printType() {
    std::cout << typeid(T).name() << " is an arithmetic type!\n";
}

template <IsArithmetic... T> struct ArithmeticTypeList : TypeList<T...> {
    void printTypes() { (printType<T>(), ...); }
};

int tmain() {
    ArithmeticTypeList<int, double, char> c;


    c.printTypes();

    return 0;
}
} // namespace type_list