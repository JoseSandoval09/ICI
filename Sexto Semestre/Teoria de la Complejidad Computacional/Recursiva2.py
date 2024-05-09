import big_o ##importamos libreria que calcula big o

def recursiva1(n):
    if n <= 1:
        return 1
    else:
        return 2*recursiva1(n-1);




print(big_o.big_o(recursiva1, big_o.datagen.n_, n_repeats=10, min_n=1, max_n=100)[0])