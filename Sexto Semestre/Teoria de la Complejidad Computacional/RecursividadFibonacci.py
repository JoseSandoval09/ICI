import big_o ##importamos libreria que calcula big o

def fibo(n):
  if n < 2:
    return n
  else:
    return fibo(n-1) + fibo(n-2)

for x in range(9):
  print(fibo(x))

print(big_o.big_o(fibo, big_o.datagen.n_, n_repeats=9, min_n=2, max_n=100)[0])

