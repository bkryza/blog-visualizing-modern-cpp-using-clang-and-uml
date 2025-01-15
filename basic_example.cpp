namespace basic_class {
/// \brief This is class A
class A {
public:
    /// Abstract foo_a
    virtual void foo_a() = 0;

    /// Abstract foo_c
    virtual void foo_c() = 0;
};

/// \brief This is class B
class B : public A {
public:
    void foo_a() override { }
};

class C : public A {
public:
    void foo_c() override { }
};

/// This is class D
/// which is a little like B
/// and a little like C
class D : public B, public C {
public:
    /**
     * Forward foo_a
     */
    void foo_a() override { }

    /**
     * Forward foo_c
     */
    void foo_c() override { }

private:
    /// Pointer to A
    A *as;
};

class E : virtual public B, public virtual C {
public:
    /// Forward foo_a
    void foo_a() override { }

    /// Forward foo_c
    void foo_c() override { }

private:
    /// Pointer to A
    A *as;
};
} // namespace basic_class
