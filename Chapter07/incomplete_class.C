class Base {
    public:
    Base() : i_() {}
    virtual void increment(long v) { i_ += v; }
    private:
    long i_;
};

class Derived : public Base {
    public:
    Derived() : Base(), j_() {}
    void increment(long v) { j_ += v; Base::increment(v); }
    // This does not compile even though multiply() is not used: 
    // Derived is not a template
    void multiply(long v) { j_ *= v; Base::multiply(v); }
    private:
    long j_;
};

int main() {
    Derived d;
    d.increment(5);
}
