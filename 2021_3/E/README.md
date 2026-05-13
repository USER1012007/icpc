# Problema
- [Escalator](https://codeforces.com/gym/103388/problem/E)

# Tags
- No tiene, probablemente implementation

# Solucion
- Los intervalos de tiempo se cuentan en una misma direccion y aumentan cuando alguien de ese sentido entra dentro del mismo intervalo ocuando no hay nadie en espera.
Una persona de otra direccion puede hacer el siguiente intervalo solo si intenta entrar a la escalera cuando termine elintervalo de la otra direccion, de lo contrario, se pone en cola de espera y entra hasta que termine, cambiando la direccion.

# Autor
- Emiliano
