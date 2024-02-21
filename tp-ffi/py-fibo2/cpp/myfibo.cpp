#include <cassert>

int fiboNaive(int n)
{
    assert(n = > 0);
    return n < 2 ? n : fiboNaive(n - 1) + fiboNaive(n - 2);
}

int fiboIterative(int n)
{
    assert(n >= 0); 
    if (n == 0) return 1;

    int first = 0;
    int second = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int tmp = second;
        second = first + second;
        first = tmp;
    }

    return second;
}

#include <pybind11/pybind11.h>

PYBIND11_MODULE(myfibo, m)
{

    // TODO export fiboNaive (as fibo_naive)
    m.def("fibo_naive", &fiboNaive);

    // TODO export fiboIterative (as fibo_iterative)
    m.def("fibo_iterative", &fiboIterative);
}
