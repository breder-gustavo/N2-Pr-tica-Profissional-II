#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    system("chcp 65001 >nul");
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    char nome[50];
    int idade;
    double glicemia, hba1c;
    int cat_glicemia = 0; 
    int cat_hba1c = 0;    

    printf("Digite o nome do paciente: ");
    scanf("%s", nome);

    printf("Digite a idade do paciente: ");
    scanf("%d", &idade);

    printf("Digite a glicemia de jejum (mg/dL): ");
    scanf("%lf", &glicemia);

    printf("Digite a hemoglobina glicada (HbA1c em %%): ");
    scanf("%lf", &hba1c);

    if (glicemia < 0 || hba1c < 0 || hba1c > 100) {
        printf("Erro: Valores inválidos informados.\n");
        return 0;
    }

    if (glicemia < 100) {
        cat_glicemia = 1; 
    } else if (glicemia >= 100 && glicemia <= 125) {
        cat_glicemia = 2; 
    } else {
        cat_glicemia = 3; 
    }

    if (hba1c < 5.7) {
        cat_hba1c = 1; 
    } else if (hba1c >= 5.7 && hba1c <= 6.4) {
        cat_hba1c = 2; 
    } else {
        cat_hba1c = 3; 
    }

    printf("\n--- Resultados Individuais ---\n");
    printf("Paciente: %s, %d anos\n", nome, idade);
    
    printf("Glicemia de jejum (%.2f mg/dL): ", glicemia);
    if (cat_glicemia == 1) {
        printf("Normal\n");
    } else if (cat_glicemia == 2) {
        printf("Pré-diabetes\n");
    } else {
        printf("Diabetes\n");
    }

    printf("HbA1c (%.2f%%): ", hba1c);
    if (cat_hba1c == 1) {
        printf("Normal\n");
    } else if (cat_hba1c == 2) {
        printf("Pré-diabetes\n");
    } else {
        printf("Diabetes\n");
    }

    int maior_categoria = cat_glicemia;
    if (cat_hba1c > maior_categoria) {
        maior_categoria = cat_hba1c;
    }

    printf("\n--- Classificação Geral ---\n");
    if (maior_categoria == 1) {
        printf("Normal\n");
    } else if (maior_categoria == 2) {
        printf("Pré-diabetes\n");
    } else {
        printf("Diabetes\n");
    }

    return 0;
}