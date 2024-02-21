import mypackage.myfibo as myfibo

if __name__ == '__main__':

    for i in range (0,10):
        print(f"fibo_naive({i}) = {myfibo.fibo_naive(i)}")
    
    for i in range (0,10):
        print(f"fibo_iterative({i}) = {myfibo.fibo_iterative(i)}")
