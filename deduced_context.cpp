#include <map>
#include <string>

namespace deduced_context {
template <typename T> struct A;
template <typename U> struct A<U &> {
    U &u;
};
template <typename U> struct A<std::map<std::string, U> &> {
    U &u;
};
template <>
struct A<std::map<std::string, std::map<std::string, std::string>> &> { };
template <typename U> struct A<U **> {
    U **u;
};
template <typename U> struct A<U **const *> {
    U ***u;
};
template <typename U> struct A<U const *const volatile> {
    U ***u;
};
template <typename U> struct A<U &&> {
    U &&u;
};
template <typename U> struct A<U const &> {
    U const &u;
};
template <typename M, typename C> struct A<M C::*> {
    C &c;
    M C::*m;
};
template <typename M, typename C> struct A<M C::*&&> {
    C &&c;
    M C::*m;
};
template <typename M, typename C, typename Arg> struct A<M (C::*)(Arg)> {
    C &c;
    M C::*m;
};
} // namespace deduced_context