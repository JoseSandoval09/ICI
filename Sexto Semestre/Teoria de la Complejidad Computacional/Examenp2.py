def min_monedas_divide_y_venceras(coins, amount):
    if amount == 0:  # Si la cantidad es cero, no se necesitan monedas
        return 0, []
    res = float('inf')  # Inicializa el resultado con infinito
    used_coins = []  # Lista para almacenar las monedas utilizadas
    for coin in coins:  # Itera sobre cada tipo de moneda
        if coin <= amount:  # Si la moneda es menor o igual a la cantidad
            # Llama recursivamente a la función con la cantidad reducida
            sub_res, sub_used_coins = min_monedas_divide_y_venceras(coins, amount - coin)
            # Si el resultado obtenido es menor que el actual, actualiza el resultado y las monedas utilizadas
            if sub_res + 1 < res:
                res = sub_res + 1
                used_coins = [coin] + sub_used_coins
    return res, used_coins  # Devuelve el número mínimo de monedas y las monedas utilizadas

# Ejemplo de uso
coins = [1, 5, 10, 12 , 20,25]  # Tipos de monedas disponibles
amount = 48  # Cantidad a representar

# Llama a la función principal
num_coins, used_coins = min_monedas_divide_y_venceras(coins, amount)

# Imprime el resultado 
print("Número mínimo de monedas:", num_coins)
print("Monedas utilizadas:", used_coins)



def min_monedas_voraz(coins, amount):
    coins.sort(reverse=True)  # Ordena las monedas de mayor a menor
    num_coins = 0  # Inicializa el contador de monedas utilizadas
    used_coins = []  # Lista para almacenar las monedas utilizadas
    for coin in coins:  # Itera sobre cada tipo de moneda
        while amount >= coin:  # Mientras la cantidad sea mayor o igual que la moneda actual
            amount -= coin  # Resta la moneda actual de la cantidad
            num_coins += 1  # Incrementa el contador de monedas utilizadas
            used_coins.append(coin)  # Agrega la moneda utilizada a la lista
    return num_coins, used_coins  # Devuelve el número mínimo de monedas y las monedas utilizadas

# Ejemplo de uso
coins = [1, 5, 10, 12,20,25]  # Tipos de monedas disponibles
amount = 48  # Cantidad a representar

# Llama a la función principal
num_coins, used_coins = min_monedas_voraz(coins, amount)

# Imprime el resultado
print("Número mínimo de monedas:", num_coins)
print("Monedas utilizadas:", used_coins)


def min_monedas_dp(coins, amount):
    dp = [float('inf')] * (amount + 1)  # Inicializa una lista para almacenar los resultados óptimos
    dp[0] = 0  # Caso base: No se necesitan monedas para representar 0
    used_coins = [[] for _ in range(amount + 1)]  # Lista para almacenar las monedas utilizadas en cada cantidad
    for i in range(1, amount + 1):  # Itera sobre todas las cantidades desde 1 hasta amount
        for coin in coins:  # Itera sobre cada tipo de moneda
            if coin <= i and dp[i - coin] + 1 < dp[i]:  # Si la moneda es menor o igual a la cantidad actual y la cantidad requerida es menor que el valor actual
                dp[i] = dp[i - coin] + 1  # Actualiza el valor mínimo de monedas requeridas
                used_coins[i] = used_coins[i - coin] + [coin]  # Actualiza las monedas utilizadas
    return dp[amount], used_coins[amount]  # Devuelve el número mínimo de monedas y las monedas utilizadas

# Ejemplo de uso
coins = [1, 5, 10,12,20, 25]  # Tipos de monedas disponibles
amount = 48  # Cantidad a representar

# Llama a la función principal
num_coins, used_coins = min_monedas_dp(coins, amount)

# Imprime el resultado
print("Número mínimo de monedas:", num_coins)
print("Monedas utilizadas:", used_coins)
