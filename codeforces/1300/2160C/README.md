# Problema
[2160C. Reverse XOR](https://codeforces.com/problemset/problem/2160/C)

# Dificultad
1300

# Tags
Bitmask

# Solución
Para que un número n cumpla con la regla que pide el problema, debe ser un palindromo en binario, esto se debe a las propiedades de XOR:
si un numero dado x le haces XOR con su reverso f(x), el resultado SIEMPRE es un palindromo. Pero hay exepciones, si la longitud del palindromo es
impar, entonces el bit central de n debe ser 0. XOR nunca podra generar un 1 en un bit central. Ej:

`001 0100 = 0110 0111 XOR 0111 0011` Nota que el bit central siempre conservara su valor, y al hacer XOR quedara en cero.

Nota: Se pueden agregar tantos ceros a la izquierda hasta que n sea palindromo, en el código más bien quito primero todos los ceros a la derecha:
`101 = 100 XOR 001` aunque no hace falta buscar x y f(x), basta con comprobar que n sea palindromo sin sus ceros de la derecha y que tenga longitud par, si
tiene longitud impar entonces el bit central debe ser cero.

# Autor
Darío
