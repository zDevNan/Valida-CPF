/******************************************************************************
ex 51(cpf), pag 27
Escreva um programa contendo, entre outras, uma classe com métodos para:
a) Validar CPF;
b) Recuperar o estado de um CPF;

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
//declarando variaveis
    char cpf [12];
    int icpf[12];
    int i, somador = 0,digito1,result1,result2,digito2,valor;
    
    printf("Digite o CPF:");
    scanf(" %s",cpf);
// primeiro digito
    for(i = 0;i<11;i++){
        icpf[i]=cpf[i]-48;
    }
    
    for(i=0;i<9;i++){
        somador+=icpf[i]*(10-i);
    }
    
    result1 = somador%11;
    
    if( (result1==0) || (result1==1) ){
        digito1 = 0;
    }
    
    else{
        digito1 = 11 - result1;
    }
//segundo digito
    somador = 0;
    
    for(i=0;i<10;i++){
        somador+=icpf[i]*(11-i);
    }
    
    valor = (somador/11)*11;
    result2= somador - valor;
    
    if( (result2==0) || (result2==1) ){
        digito2 = 0;
    }
    
    else{
        digito2 = 11-result2;
    }
    
//resultado da validação
    if( (digito1==icpf[9]) && (digito2==icpf[10]) ){
        printf("\nCPF %s VALIDO.\n\n",cpf);
    }
    else{
        printf("\nCPF %s INVALIDO.\n",cpf);
    }
//verificador de estado de origem
    printf("Estado De Origem Do CPF é: ");
    switch(icpf[8]){
    
    case 0:
    printf("Rio Grande Do Sul");
    break;
    
    case 1 :
        printf("Distrito Federal, Goiás, Mato Grosso, Mato Grosso do Sul e Tocantins");
        break;
            case 2 :
                printf("Amazonas, Pará, Roraima, Amapá, Acre e Rondônia");
                break;
                    case 3:
                        printf("Ceará, Maranhão e Piauí");
                        break;
                            case 4:
                                printf("Paraíba, Pernambuco, Alagoas e Rio Grande do Norte");
                                break;
                                    case 5:
                                        printf("Bahia e Sergipe");
                                        break;
                                            case 6:
                                                printf("Minas Gerais");
                                                break;
                                                    case 7:
                                                        printf("Rio de Janeiro e Espírito Santo");
                                                        break;
                                                            case 8:
                                                                printf("São Paulo");
                                                                break;
                                                                    case 9:
                                                                        printf("Paraná e Santa Catarina");
                                                                        break;
    }
}