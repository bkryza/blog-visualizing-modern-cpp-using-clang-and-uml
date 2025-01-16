#include <iostream>
#include <type_traits>

/// Base on
/// https://www.scs.stanford.edu/~dm/blog/param-pack.html#recursive-types-through-inheritance

namespace recursive_list {
template <typename... T> struct HList;

template <> struct HList<> {
    static constexpr bool isEmpty() noexcept { return true; }
};

template <typename T0, typename... TRest>
struct HList<T0, TRest...> : HList<TRest...> {
    using head_type = T0;
    using tail_type = HList<TRest...>;

    static constexpr bool isEmpty() noexcept { return false; }

    [[no_unique_address]] head_type value_{};

    constexpr HList() = default;
    template <typename U0, typename... URest>
    constexpr HList(U0 &&u0, URest &&...urest)
        : tail_type(std::forward<URest>(urest)...)
        , value_(std::forward<U0>(u0)) { }

    head_type &head() & { return value_; }
    const head_type &head() const & { return value_; }
    head_type &&head() && { return value_; }

    tail_type &tail() & { return *this; }
    const tail_type &tail() const & { return *this; }
    tail_type &&tail() && { return *this; }
};

template <typename... T> HList(T...) -> HList<T...>;

template <typename T>
concept IsArithmetic = std::is_arithmetic_v<T>;

template <IsArithmetic... T> struct Arithmetic : HList<T...> {

    using HList<T...>::HList;

public:
    constexpr double sum() const { return sumImpl(*this); }

private:
    static constexpr double seed() { return 100.0; }

    template <typename L> static constexpr double sumImpl(const L &list) {
        if constexpr (L::isEmpty()) {
            return seed();
        } else {
            return static_cast<double>(list.head()) + sumImpl(list.tail());
        }
    }
};

int tmain() {
    constexpr Arithmetic<int, float, double> a{11, 12, 13};

    return a.sum();
}
} // namespace recursive_list