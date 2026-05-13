# Problema
[M. Monarchy in Vertigo](https://codeforces.com/gym/103388/problem/M)

# Tags
No tiene pero es de árboles y recorrido preorden

# Solución
La linea de sucesion sigue la estructura de un recorrido en preorden de un árbol, construyo las listas de adyacencia y luego las recorro en preorden
(guardo en un arreglo), despues empiezo a ver quienes mueren y si el monarca actual muere avanzo en la linea de sucesión, si el siguiente heredero está
muerto también, sigues avanzando.

# Autor
Darío
