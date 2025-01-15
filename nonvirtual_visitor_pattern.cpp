#include <iostream>
#include <string>

namespace nonvirtual_visitor_pattern {
template <typename Derived> struct Visitable {
    template <typename Visitor> void accept(Visitor &v) {
        v.visit(static_cast<Derived &>(*this));
    }
};

struct Foo : public Visitable<Foo> {
    int fooValue{0xF00};
};

struct Bar : public Visitable<Bar> {
    std::string barValue{"BAR"};
};

struct PrintVisitor {
    void visit(Foo &foo) {
        std::cout << "Visiting Foo: " << foo.fooValue << std::endl;
    }

    void visit(Bar &bar) {
        std::cout << "Visiting Bar: " << bar.barValue << std::endl;
    }
};

int tmain() {
    Foo foo;
    Bar bar;

    PrintVisitor visitor;

    foo.accept(visitor);
    bar.accept(visitor);

    return 0;
}
} // namespace nonvirtual_visitor_pattern