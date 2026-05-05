# Problema
[Bytelandia's stones](https://codeforces.com/gym/106063/problem/B)

# Dificultad
?

# Solución
Había que analizar las ocurrencias de un elemento del arreglo (i), según las maneras en las que se podía escoger los límites L y R, 
siendo que L se puede escoger de (i) formas diferentes, y R que depende de la elección de L se puede escoger de (n - i + 1) formas diferentes.
Por lo tanto en la suma final, cada término del rango aparecera (i) * (n - i + i) veces y esa cantidad de veces se sumará.

# Autor
Darío
