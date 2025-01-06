from inter_esp.analisis_semantico import interpretar


def evaluar(entrada):
    expression = interpretar(entrada)
    stack = []
    for token in expression:
        if token.isdigit():
            stack.append(int(token))
        else:
            b = stack.pop()
            a = stack.pop()
            if token == '+':
                stack.append(a + b)
            elif token == '-':
                stack.append(a - b)
            elif token == '*':
                stack.append(a * b)
            elif token == '/':
                stack.append(a / b)
    return stack.pop()


# Ejemplo de uso
expression = [
    "2 mas 1",
    "6 por 12 entre 9 mas 1",
]

for texto in expression:
    result = evaluar(texto)
    print(f'El resultado de la expresión "{texto}" es: {result}')
