# Problema
[1858A](https://codeforces.com/problemset/problem/1858/A)

# Dificultad
800

# Tags
Games, greedy, math

# Solución
Clásico juego de suma cero, como First siempre empieza a jugar primero, la clave está en saber si será el último en pulsar el último botón de tipo "c".
De ser así, entonces gana First si tiene más o igual pulsaciones que Second (a>=b), en cambio si Second es el último en pulsar en ¨c¨ entonces gana Second si
tiene más o igual pulsaciones que First (b>=a).
En general el juego óptimo se da cuando primero se acaban los botones que ambos pueden usar y luego se acaban los suyos propios.

# Autor
Darío
