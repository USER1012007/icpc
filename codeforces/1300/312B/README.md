# Problema
[312B. Archer](https://codeforces.com/problemset/problem/312/B)

# Dificultad
1300

# Tags
Probabilities, math

# Solución
La probabilidad de tener un éxito en k eventos independientes está modelado por la distribución geométrica, y en este problema en concreto se pide
la probabilidad acumulada de tener éxito, dado que mis turnos son los impares, eso es calcular $P = P(K=1) + P(K=3) + ...$, desarrollando la suma se
puede observar una serie geométrica, cuya suma está dada por la fórmula:

$S = a / (1 - r)$

# Autor
Darío
