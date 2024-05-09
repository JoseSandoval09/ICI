def min_monedas_divide_y_venceras(coins, amount):
    if amount == 0:
        return 0, []
    if len(coins) == 0 or amount < 0:
        return float('inf'), []
    
    # Dividir el conjunto de monedas en dos mitades
    mid = len(coins) // 2
    left_coins = coins[:mid]
    right_coins = coins[mid:]
    
    # Calcular la solución óptima para cada mitad
    left_result = min_monedas_divide_y_venceras(left_coins, amount)
    right_result = min_monedas_divide_y_venceras(right_coins, amount)
    
    # Combinar las soluciones de ambas mitades
    if left_result[0] < right_result[0]:
        min_coins = left_result[0]
        used_coins = left_result[1]
    else:
        min_coins = right_result[0]
        used_coins = right_result[1]
    
    return min_coins, used_coins

# Ejemplo de uso
coins = [1, 5, 10, 25]  # Tipos de monedas disponibles
amount = 10  # Cantidad a representar

# Llama a la función principal
num_coins, used_coins = min_monedas_divide_y_venceras(coins, amount)

# Imprime el resultado
print("Número mínimo de monedas:", num_coins)
print("Monedas utilizadas:", used_coins)
