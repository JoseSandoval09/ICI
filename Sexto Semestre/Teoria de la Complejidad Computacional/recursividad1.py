import big_o ##importamos libreria que calcula big o

def recursiva1(n):
    if n <= 1:
        return 1
    else:
        return recursiva1(n-1) + recursiva1 (n-1);

for x in range(10):
  print(recursiva1(x))


print(big_o.big_o(recursiva1, big_o.datagen.n_, n_repeats=10, min_n=1, max_n=11)[0])