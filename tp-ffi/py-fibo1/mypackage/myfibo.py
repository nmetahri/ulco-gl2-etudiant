
def fibo_naive(n: int):
    assert n >= 0
    return n if n < 2 else fibo_naive(n-1) + fibo_naive(n-2)

def fibo_iterative(n: int):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        n0 = 0
        n1 = 1
        for i in range(n-1):
            tmp = n1
            n1 = n0 + n1
            n0 = tmp
        return n1

