from inter_esp.analisis_lexico import tokenizar


def palabra_signo(palabra):
    if palabra == 'mas':
        return '+'
    elif palabra == 'menos':
        return '-'
    elif palabra == 'por':
        return '*'
    elif palabra == 'entre':
        return '/'
    elif palabra == 'igual':
        return '='
    else:
        return "No definido"


def precedence(op):
    if op in ('+', '-'):
        return 1
    if op in ('*', '/'):
        return 2
    return 0


def interpretar(entrada):
    texto = tokenizar(entrada)

    pila = []
    salida = []

    for token, palabra in texto:
        if token == 'NUM':
            salida.append(palabra)
        elif token == 'PL':
            pila.append('(')
        elif token == 'PR':
            while pila and pila[-1] == '(':
                salida.append(pila.pop())
            pila.pop()
        elif token == 'OP':

            simbolo = palabra_signo(palabra)

            while pila and precedence(pila[-1]) >= precedence(simbolo):
                salida.append(pila.pop())
            pila.append(simbolo)
        else:
            return "Instruccion no reconcida"

    while pila:
        salida.append(pila.pop())

    return salida
