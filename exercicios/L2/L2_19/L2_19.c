#include <stdio.h>

int main() {
    int qntDeleg, deleg, notaDelegF, notaDelegM;
    int notaMelhorDelegM = -1, notaMelhorDelegF = -1;
    int melhorDelegM = 0, melhorDelegF = 0;
    int nota1MaiorF, nota2MaiorF, nota3MaiorF;
    int nota1MenorF, nota2MenorF, nota3MenorF;
    int nota1MaiorM, nota2MaiorM, nota3MaiorM;
    int nota1MenorM, nota2MenorM, nota3MenorM;
    int melhorM, melhorF, piorM, piorF;
    int atleta, nota, nota3, nota2, nota1;
    char genero = 0;

    scanf("%d", &qntDeleg);
    scanf("%*[^\n]");
    scanf("%*c");

    //LOOP DAS DELEGAÇÕES:
    for (deleg = 1; deleg <= qntDeleg; deleg++) {
        nota1MaiorF = -1;
        nota2MaiorF = -1;
        nota3MaiorF = -1;
        nota1MenorF = 11;
        nota2MenorF = 11;
        nota3MenorF = 11;
        nota1MaiorM = -1;
        nota2MaiorM = -1;
        nota3MaiorM = -1;
        nota1MenorM = 11;
        nota2MenorM = 11;
        nota3MenorM = 11;
        melhorM = 0;
        piorM = 0;
        melhorF = 0;
        piorF = 0;
        notaDelegF = 0;
        notaDelegM = 0;

        scanf("%d", &atleta);
        scanf("%*c");

        //LOOP DOS ATLETAS:
        while (atleta != -1) {
            nota3 = 0;
            nota2 = 0;
            nota1 = 0;

            scanf("%c", &genero);
            scanf("%d %d %d", &nota3, &nota2, &nota1);
            scanf("%*[^\n]");
            scanf("%*c");

            //ALGORÍTIMO QUE ORDENA AS NOTAS (NOTA3<NOTA2<NOTA1)
            if (nota3 > nota1) {
                nota3 = nota3 + nota1;
                nota1 = nota3 - nota1;
                nota3 = nota3 - nota1;
            }
            if (nota3 > nota2) {
                nota3 = nota3 + nota2;
                nota2 = nota3 - nota2;
                nota3 = nota3 - nota2;
            }
            if (nota2 > nota1) {
                nota2 = nota2 + nota1;
                nota1 = nota2 - nota1;
                nota2 = nota2 - nota1;
            }

            //ATRIBUIÇÃO DO MELHOR E PIOR ATLETA DA DELEGAÇÃO (M/F)
            if (genero == 'M') {

                //SOMATORIO NOTA DA DELEGAÇÃO
                notaDelegM += nota1;

                //ATRIBUIÇÃO DA MELHOR NOTA(MELHOR ATLETA)
                if (nota1 > nota1MaiorM) {
                    melhorM = atleta;
                    nota1MaiorM = nota1;
                    nota2MaiorM = nota2;
                    nota3MaiorM = nota3;
                } else if (nota1 == nota1MaiorM) {
                    //EMPATE NA PRIMEIRA NOTA
                    if (nota2 > nota2MaiorM) {
                        melhorM = atleta;
                        nota2MaiorM = nota2;
                        nota3MaiorM = nota3;
                    } else if (nota2 == nota2MaiorM) {
                        //EMPATE NA SEGUNDA NOTA
                        if (nota3 > nota3MaiorM) {
                            melhorM = atleta;
                            nota3MaiorM = nota3;
                        } else if (nota3 == nota3MaiorM) {
                            //EMPATE NA TERCEIRA NOTA
                            if (atleta < melhorM) {
                                melhorM = atleta;
                            }
                        }
                    }
                }

                //ATRIBUIÇÃO DA PIOR NOTA(PIOR ATLETA)
                if (nota1 < nota1MenorM) {
                    piorM = atleta;
                    nota1MenorM = nota1;
                    nota2MenorM = nota2;
                    nota3MenorM = nota3;
                } else if (nota1 == nota1MenorM) {
                    //EMPATE NA PRIMEIRA NOTA
                    if (nota2 < nota2MenorM) {
                        piorM = atleta;
                        nota2MenorM = nota2;
                        nota3MenorM = nota3;
                    } else if (nota2 == nota2MenorM) {
                        //EMPATE NA SEGUNDA NOTA
                        if (nota3 < nota3MenorM) {
                            piorM = atleta;
                            nota3MenorM = nota3;
                        } else if (nota3 == nota3MenorM) {
                            //EMPATE NA TERCEIRA NOTA
                            if (atleta > piorM) {
                                piorM = atleta;
                            }
                        }
                    }
                }
            } else if (genero == 'F') {
                //SOMATORIO NOTA DELEGAÇÃO
                notaDelegF += nota1;

                //ATRIBUIÇÃO DA MELHOR NOTA(MELHOR ATLETA)
                if (nota1 > nota1MaiorF) {
                    melhorF = atleta;
                    nota1MaiorF = nota1;
                    nota2MaiorF = nota2;
                    nota3MaiorF = nota3;
                } else if (nota1 == nota1MaiorF) {
                    //EMPATE NA PRIMEIRA NOTA
                    if (nota2 > nota2MaiorF) {
                        melhorF = atleta;
                        nota2MaiorF = nota2;
                        nota3MaiorF = nota3;
                    } else if (nota2 == nota2MaiorF) {
                        //EMPATE NA SEGUNDA NOTA
                        if (nota3 > nota3MaiorF) {
                            melhorF = atleta;
                            nota3MaiorF = nota3;
                        } else if (nota3 == nota3MaiorF) {
                            //EMPATE NA TERCEIRA NOTA
                            if (atleta < melhorF) {
                                melhorF = atleta;
                            }
                        }
                    }
                }

                //ATRIBUIÇÃO DA PIOR NOTA(PIOR ATLETA)
                if (nota1 < nota1MenorF) {
                    piorF = atleta;
                    nota1MenorF = nota1;
                    nota2MenorF = nota2;
                    nota3MenorF = nota3;
                } else if (nota1 == nota1MaiorF) {
                    //EMPATE NA PRIMEIRA NOTA
                    if (nota2 < nota2MenorF) {
                        piorF = atleta;
                        nota2MenorF = nota2;
                        nota3MenorF = nota3;
                    } else if (nota2 == nota2MenorF) {
                        //EMPATE NA SEGUNDA NOTA
                        if (nota3 < nota3MenorF) {
                            piorF = atleta;
                            nota3MenorF = nota3;
                        } else if (nota3 == nota3MenorF) {
                            //EMPATE NA TERCEIRA NOTA
                            if (atleta > piorF) {
                                piorF = atleta;
                            }
                        }
                    }
                }
            }
            scanf("%d", &atleta);
            scanf("%*c");
        }

        if (notaMelhorDelegM < notaDelegM) {
            melhorDelegM = deleg;
            notaMelhorDelegM = notaDelegM;
        }
        if (notaMelhorDelegF < notaDelegF) {
            melhorDelegF = deleg;
            notaMelhorDelegF = notaDelegF;
        }
        printf("MELHORES ATLETAS DA DELEGACAO %d\n", deleg);
        printf("MASCULINO: %d FEMININO: %d\n", melhorM, melhorF);
        printf("PIORES ATLETAS DA DELEGACAO %d\n", deleg);
        printf("MASCULINO: %d FEMININO: %d\n\n", piorM, piorF);
        //printf("NOTA DELEGAÇÃO M: %d\n", notaDelegM);
        //printf("NOTA DELEGAÇÃO F: %d\n", notaDelegF);
    }
    if (qntDeleg) {
        printf("DELEGACAO CAMPEA:\n");
        printf("MASCULINO: %d FEMININO: %d\n", melhorDelegM, melhorDelegF);
    }

    return 0;
}
