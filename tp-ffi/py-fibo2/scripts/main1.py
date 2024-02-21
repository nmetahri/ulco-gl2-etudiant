import myfibo

if __name__ == '__main__':

    for i in range (1,10):
        print (f"fibo_naive({i}) : {myfibo.fibo_naive(i)}")

    for i in range (1,10):
        print (f"fibo_iterative({i}) : {myfibo.fibo_naive(i)}")
