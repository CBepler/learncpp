template <int N>
constexpr int factorial() {
    static_assert(N >= 0);
    int fact{1};
    for(int i = N; i > 1; --i) {
        fact *= i;
    }
    return fact;
}

int main()
{
    static_assert(factorial<0>() == 1);
    static_assert(factorial<3>() == 6);
    static_assert(factorial<5>() == 120);

    factorial<-3>(); // should fail to compile

    return 0;
}
