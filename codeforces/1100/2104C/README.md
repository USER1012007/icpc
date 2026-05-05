# Problema
[2104C](https://codeforces.com/problemset/problem/2104/C)

# Tags
Brute force, constructive algorithms, games, greedy, math

# Solución
Mi solución se basa en que independientemente quien empiece, hay dos condiciones que determinan al ganador:
- Ganas si tienes la última carta y la primera
- Ganas si tienes las últimas dos cartas

`ABBB` -> Gana Bob, tiene las últimas dos\
`BBBAAA` -> Gana Alice, tiene las últimas dos.

Si estás en cualquiera de estas dos condiciones, eres inmortal.

> Si ninguno de los dos es inmortal entonces (y dado que Alice siempre es la primera en voltear su carta)
es posible determinar las únicas dos condiciones ganadoras de Bob.

- Bob gana si tiene la última carta y una más en algún lugar.
- Bob gana si tiene la primer carta y alguna más en algún lugar.

Sabiendo esto, si Bob no tiene una condición ganadora, entonces pierde.

# Autor
Darío
