#include <stdio.h>
#include <stdlib.h>

void valores_tipicos(){
    const char *arquivo = "tabela.tex";

    FILE * fp = fopen(arquivo, "wt");
    if (fp == NULL)
        return;

    fprintf(fp,"\\begin{table}[ht]\n");
    fprintf(fp,"\\centering\n");
    fprintf(fp,"\\begin{tabular}{|c|c|c|}\n");

    fprintf(fp,"\\hline\n");

    int Q[] = {120, 90, 60, 30, 20, 10, 6, 3, 0, -3, -6, -10, -20, -30, -60, -120};
    float P[] = {10, 10, 10 , 10, 10, 10, 4, 2, 1, 0.5, 0.25, 10, 10, 10, 10, 10 };
    int power[] = {12, 9, 6, 3, 2, 1, -1, -2, -3, -6, -12};
    float V[] = {1000000, 31600, 1000, 31.6, 10, 3.16, 2, 1.414, 1, 0.707, 0.5, 0.316, 0.1, 0.0316, 0.001, 0.000001};
    int i_pow = 0;
    for (int i = 0; i < 17; i++)
    {
        if (i == 0){
            fprintf(fp,"$Q_{(db)}$ & $P_1$/$P_2$ & $V_1$/$V_2$\\\\\n");
            fprintf(fp,"\\hline\n");
        }
        else{
            if (i == 1 || i == 2 || i == 3 || i == 5 || i == 7 || i == 9){
                if (i < 7 || i > 11){
                    fprintf(fp,"%d & $%.0f^{%d}$ & %.0f\\\\\n", Q[i-1], P[i-1], power[i_pow], V[i-1]);
                    i_pow++;
                }
                else{
                    fprintf(fp,"%d & %.2f & %.0f\\\\\n", Q[i-1], P[i-1], V[i-1]);
                }
            }
            else{
                if (i == 16){
                    fprintf(fp,"%d & $%.0f^{%d}$ & $10^{-6}$\\\\\n", Q[i-1], P[i-1], power[i_pow]);

                }
                else{
                    if (i < 7 || i > 11){
                        fprintf(fp,"%d & $%.0f^{%d}$ & %.4f\\\\\n", Q[i-1], P[i-1], power[i_pow], V[i-1]);
                        i_pow++;
                    }
                    else{
                        fprintf(fp,"%d & %.2f & %.4f\\\\\n", Q[i-1], P[i-1], V[i-1]);
                    }
                }
            }
        }
    }//for

    fprintf(fp,"\\hline\n");

    fprintf(fp,"\\end{tabular}\n");
    fprintf(fp,"\\caption{valores típicos \\cite{bel1}}\n");
    fprintf(fp,"\\end{table}\n");

    fclose(fp);
}//valores_tipicos

void niveis_sonoros(){
    const char *arquivo = "tabela2.tex";

    FILE * fp = fopen(arquivo, "wt");
    if (fp == NULL)
        return;

    fprintf(fp,"\\begin{table}[ht]\n");
    fprintf(fp,"\\centering\n");
    fprintf(fp,"\\begin{tabular}{|c|c|c|}\n");
    fprintf(fp,"\\hline\n");

    char fontes_de_ruido[8][31] = {"limite da dor", "jato", "britadeira", "via movimentada", "barulho de escritório", "escritório privado residencia", "estúdio de rádio operando", "limite da audição"};

    int intensidade_pow[] = {2,0,-2,-4,-6,-8,-10,-12};
    int db[] ={140, 120, 100, 80, 60, 40, 20, 0};

    for (int i = 0; i < 9; i++){
        if (i == 0){
            fprintf(fp,"Fontes de ruído & Intensidade (Watt/$m^{2}$) & dB\\\\\n");
            fprintf(fp,"\\hline\n");
        }//if

        else{
            fprintf(fp,"%s & $10^{%d}$ & %d\\\\\n", fontes_de_ruido[i -1], intensidade_pow[i -1], db[i -1]);

        }//else

    }//for

    fprintf(fp,"\\hline\n");
    fprintf(fp,"\\end{tabular}\n");
    fprintf(fp,"\\caption{Níveis sonoros}\n");
    fprintf(fp,"\\end{table}\n");

    fclose(fp);




}//niveis_sonoros


int main(void){
    valores_tipicos();

    niveis_sonoros();

    return 0;

}

