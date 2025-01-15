#include <memory>

namespace smart_pointers {
class A { };

class B { };

class C { };

class R {
public:
    std::unique_ptr<A> a;
    std::shared_ptr<B> b;
    std::weak_ptr<C> c;
};
} // namespace smart_pointers