# Reto 23 - Presupuesto: desvios del gasto acumulado

**Asignatura:** Algoritmos y C  
**Estudiante:** Ronel Catalino Hernandez  
**Matricula:** 20261106

## Descripcion
Solucion en C del Reto 23: Presupuesto: desvios del gasto acumulado.

El programa procesa una matriz de gastos por departamento y semana. Calcula gasto acumulado, eventos, impacto, rachas consecutivas, eventos por columna y prioridad.

## Validacion
- 1 <= N, M <= 30
- 0 <= L <= U <= 1000
- Cada valor de la matriz entre 0 y 1000

Si una restriccion falla, imprime `ERROR` y termina.

## Estructura
- `20261106.c` - solucion del reto.
- `README.md` - descripcion y ejecucion.
- `docs/analisis_y_diseno.md` - analisis, pseudocodigo y pruebas.
- `pruebas/` - casos oficiales y pruebas propias.

## Compilacion
```bash
gcc -std=c11 -Wall -Wextra 20261106.c -o reto
```

## Ejecucion
```bash
./reto < pruebas/caso_01.in
```

## Caso oficial
Entrada:
```text
3 5 5 15
5 15 30 10 25
25 10 5 20 30
10 20 15 5 35
```

Salida esperada:
```text
FILA 1 EVENTOS 2 IMPACTO 15 RACHA 1 INICIO 3
FILA 2 EVENTOS 3 IMPACTO 30 RACHA 2 INICIO 1
FILA 3 EVENTOS 1 IMPACTO 10 RACHA 1 INICIO 5
COLUMNAS 1 1 1 0 3
PRIORIDAD 2
COLUMNA 5
```
