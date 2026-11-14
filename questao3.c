#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    system("chcp 65001 >nul");
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int vagas[2][3];
    int i, j;
    int ocupadas = 0, livres = 0;

    printf("Informe a situacao de cada vaga (0 para livre, 1 para ocupada):\n");

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("Fileira %d, Vaga %d: ", i + 1, j + 1);
            scanf("%d", &vagas[i][j]);

            if (vagas[i][j] == 1) {
                ocupadas++;
            } else {
                livres++;
            }
        }
    }

    printf("\n--- Mapa do Estacionamento ---\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", vagas[i][j]);
        }
        printf("\n");
    }

    printf("\nTotal de vagas ocupadas: %d\n", ocupadas);
    printf("Total de vagas livres: %d\n", livres);

    
    return 0;
}