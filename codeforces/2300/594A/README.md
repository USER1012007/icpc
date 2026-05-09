# Problema
[594A](https://codeforces.com/problemset/problem/594/A)

# Dificultad
2300

# Tags
Games

# Solución
Dado que n siempre es par, existen exactamente nC2 soluciones, de las cuales no se llega nunca a todas. Teniendo la entrada ordenada, Vova siempre quitara
el número que genere la distancia más larga con otro, y por su parte Lesha siempre quitara el que maximice una brecha entre otros dos.

Para un n pequeño, por ejemplo `n = 4`, hay $4C2 = 6$ soluciones posibles, y analizando las distancias entre cada uno de los 6 pares, si juegan óptimo
siempre queda el par con la menor distancia que curiosamente siempre está a una distancia de n/2 entre sí, e ahí el patrón.

# Autor
Darío
