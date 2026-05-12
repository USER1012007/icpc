# Problema
[2155B](https://codeforces.com/problemset/problem/2155/B)

# Tags
constructive algorithms
graphs 

# Solución
solamente no se podia cumplir los requisitos cuando k era igual a n*n-1, entonces en esos casos imprimia 'NO', en cualquier otro caso, a partir de kera la cantidad de salidas de la matriz, entonces cuando k era >= a n, imprimia puros 'U' n veces, esto simulando toda la primer fila, despues le restaba k y cuando era igual a n-1, significaba q iba a imprimir n-1 'U' y al final un 'D', al mismo tiempo igualaba k a 0 por que ya habia cumplido el requisito del problema, entonces en el otro caso, imprimia k veces 'U' y n - 1 - k 'R' y al final una 'L', esto para que ciclara los caminos de derecha a izquiera, la nt estuvo bn insano este, pero divertido 

# Autor
emilio
