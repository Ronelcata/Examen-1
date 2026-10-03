# Analisis y diseno del algoritmo

## Problema
Para cada fila se calcula el gasto acumulado hasta cada semana. En la posicion k, existe evento cuando `AC < k*L || AC > k*U`. El impacto es la distancia al limite que se incumple.

## Resultados
Por fila se obtiene cantidad de eventos, impacto total, mayor racha horizontal de eventos y comienzo de esa racha. Por columna se cuentan los eventos.

La prioridad compara: mayor racha, luego mayor impacto, luego mayor cantidad de eventos y finalmente menor numero de fila. La columna destacada es la de mayor cantidad de eventos y, en empate, la menor columna.

## Pseudocodigo
```text
LEER N, M, L, U
VALIDAR dimensiones y limites
SI hay error: IMPRIMIR ERROR y terminar

LEER matriz y validar cada valor
INICIALIZAR eventos_columna en 0

PARA cada fila
    AC = 0
    eventos = impacto = actual = mejor = 0
    PARA cada columna
        k = columna + 1
        AC = AC + matriz[fila][columna]
        evento = AC < k*L O AC > k*U
        SI evento
            incrementar eventos y contador de columna
            calcular impacto
            incrementar racha actual
            actualizar mejor racha e inicio
        SI NO
            actual = 0

DETERMINAR fila prioritaria
DETERMINAR columna destacada
SI no hubo eventos: prioridad = 0 y columna = 0
IMPRIMIR resultados
```

## Complejidad
Tiempo: `O(N*M)`. Espacio: `O(N*M)` por la matriz fija de maximo 30x30.

## Prueba oficial
```text
Entrada
3 5 5 15
5 15 30 10 25
25 10 5 20 30
10 20 15 5 35

Salida
FILA 1 EVENTOS 2 IMPACTO 15 RACHA 1 INICIO 3
FILA 2 EVENTOS 3 IMPACTO 30 RACHA 2 INICIO 1
FILA 3 EVENTOS 1 IMPACTO 10 RACHA 1 INICIO 5
COLUMNAS 1 1 1 0 3
PRIORIDAD 2
COLUMNA 5
```

## Prueba propia 1: empate
Entrada:
```text
2 3 10 10
0 0 0
0 0 0
```
Salida esperada:
```text
FILA 1 EVENTOS 3 IMPACTO 60 RACHA 3 INICIO 1
FILA 2 EVENTOS 3 IMPACTO 60 RACHA 3 INICIO 1
COLUMNAS 2 2 2
PRIORIDAD 1
COLUMNA 1
```

## Prueba propia 2: sin eventos
Entrada:
```text
1 5 0 1000
1000 0 500 1000 1
```
Salida esperada:
```text
FILA 1 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
COLUMNAS 0 0 0 0 0
PRIORIDAD 0
COLUMNA 0
```

## Prueba de validacion
Entrada: `0 5 5 15`

Salida: `ERROR`
