//////////////////////////////////////////////////////////
// Reto 23: Presupuesto - desvios del gasto acumulado   //
// Estudiante: Ronel Catalino Hernandez                 //
// Matricula: 20261106                                  //
// Asignatura: Algoritmos y C                           //
// Fecha: 2026-10-03                                    //
//////////////////////////////////////////////////////////

#include <stdio.h>

int main(void) {
    int n, m, L, U;
    int matriz[30][30];
    int eventos_fila[30], impacto_fila[30], racha_fila[30], inicio_fila[30];
    int eventos_columna[30];
    int i, j;

    if (scanf("%d %d %d %d", &n, &m, &L, &U) != 4) {
        printf("ERROR\n");
        return 0;
    }

    if (n < 1 || n > 30 || m < 1 || m > 30) {
        printf("ERROR\n");
        return 0;
    }

    if (L < 0 || U < 0 || L > U || L > 1000 || U > 1000) {
        printf("ERROR\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (scanf("%d", &matriz[i][j]) != 1) {
                printf("ERROR\n");
                return 0;
            }

            if (matriz[i][j] < 0 || matriz[i][j] > 1000) {
                printf("ERROR\n");
                return 0;
            }
        }
    }

    for (j = 0; j < m; j++) {
        eventos_columna[j] = 0;
    }

    for (i = 0; i < n; i++) {
        int ac = 0;
        int eventos = 0;
        int impacto = 0;
        int actual = 0;
        int mejor = 0;
        int inicio_mejor = 0;
        int inicio_actual = 0;

        for (j = 0; j < m; j++) {
            int evento;
            int impacto_actual = 0;
            int k = j + 1;

            ac += matriz[i][j];

            evento = (ac < k * L || ac > k * U);

            if (evento) {
                eventos++;
                eventos_columna[j]++;

                if (ac < k * L) {
                    impacto_actual = k * L - ac;
                } else {
                    impacto_actual = ac - k * U;
                }
                impacto += impacto_actual;

                if (actual == 0) {
                    inicio_actual = k;
                }
                actual++;

                if (actual > mejor) {
                    mejor = actual;
                    inicio_mejor = inicio_actual;
                }
            } else {
                actual = 0;
            }
        }

        eventos_fila[i] = eventos;
        impacto_fila[i] = impacto;
        racha_fila[i] = mejor;
        inicio_fila[i] = inicio_mejor;
    }

    for (i = 0; i < n; i++) {
        printf("FILA %d EVENTOS %d IMPACTO %d RACHA %d INICIO %d\n",
               i + 1, eventos_fila[i], impacto_fila[i],
               racha_fila[i], inicio_fila[i]);
    }

    printf("COLUMNAS");
    for (j = 0; j < m; j++) {
        printf(" %d", eventos_columna[j]);
    }
    printf("\n");

    {
        int prioridad = 0;
        int hay_eventos = 0;

        for (i = 0; i < n; i++) {
            if (eventos_fila[i] > 0) {
                hay_eventos = 1;

                if (prioridad == 0 ||
                    racha_fila[i] > racha_fila[prioridad - 1] ||
                    (racha_fila[i] == racha_fila[prioridad - 1] &&
                     impacto_fila[i] > impacto_fila[prioridad - 1]) ||
                    (racha_fila[i] == racha_fila[prioridad - 1] &&
                     impacto_fila[i] == impacto_fila[prioridad - 1] &&
                     eventos_fila[i] > eventos_fila[prioridad - 1])) {
                    prioridad = i + 1;
                }
            }
        }

        if (!hay_eventos) {
            prioridad = 0;
        }

        printf("PRIORIDAD %d\n", prioridad);

        {
            int columna = 0;

            if (hay_eventos) {
                for (j = 0; j < m; j++) {
                    if (eventos_columna[j] > eventos_columna[columna]) {
                        columna = j;
                    }
                }
                columna++;
            }

            printf("COLUMNA %d\n", columna);
        }
    }

    return 0;
}
