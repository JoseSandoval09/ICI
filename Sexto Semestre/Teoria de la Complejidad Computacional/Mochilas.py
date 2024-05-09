import random

def knapsack_greedy(values, weights, capacity):
    n = len(values)
    items = list(range(n))
    random.shuffle(items)  # Mezcla aleatoriamente los índices de los objetos

    total_value = 0
    total_weight = 0
    knapsack = []

    for index in items:
        if total_weight + weights[index] <= capacity:
            total_value += values[index]
            total_weight += weights[index]
            knapsack.append(index)
            print(f"Objeto {index }: Valor = {values[index]}, Peso = {weights[index]}")
        if total_weight == capacity:
            break

    return total_value, knapsack

# Generar valores y pesos aleatorios para los objetos
num_objects = 20
values = [random.randint(10, 100) for _ in range(num_objects)]
weights = [random.randint(5, 30) for _ in range(num_objects)]
capacity = 100

total_value, selected_items = knapsack_greedy(values, weights, capacity)
print("\nValor total en la mochila:", total_value)
print("Objetos seleccionados:", selected_items)
