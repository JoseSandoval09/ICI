import re

tokens = [
    ('NUM', r'\d+'),
    ('PL', r'\('),
    ('PR', r'\)'),
    ('VAR', r'\b([a-z]|[A-Z])\b'),
    ('SKIP', r'(\s|\t)'),
    ('OP', r'\w'),
]


def match_token(word):
    for token_type, pattern in tokens:
        if re.match(pattern, word):
            return token_type
    return None


def tokenizar(entrada):
    texto = entrada.split()

    texto_tokenizado = []
    for palabra in texto:
        texto_tokenizado.append((match_token(palabra), palabra))

    return texto_tokenizado
