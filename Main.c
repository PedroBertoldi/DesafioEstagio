//======================================================================== Include =======================================================================================
#include<stdio.h>
#include<stdlib.h>
#include "Lib/Lib.h"
//======================================================================== Definicoes ====================================================================================
#define BUFFER_SIZE 50
//=========================================================================== Main =======================================================================================
int main(void){
    //Declara variaveis que serao utilizadas
    int num = 0;
    int vet_created = 0;
    int temp_id = 0;
    int temp_age = 0;
    int i,x;
    int found = 0;
    char buffer_input[BUFFER_SIZE];

    Person_t *vet_Person;
    //Solicita ao usuario o numero de pessoas que dever ser alocadas
    while(num<=0){
        system("cls");
        printf("Digite o Numero de Pessoas: ");
        fflush(stdin);
        fgets(buffer_input,BUFFER_SIZE,stdin);

        num = atoi(buffer_input);
        //Verifica se e um numero valido
        if (num <= 0){
            printf("\nNumero invalido!\n");
            system("pause");
        }
    }

    //Aloca na memoria o numero de pessoas solicitadas
    vet_Person = (Person_t *) malloc(sizeof(Person_t)*num);
    //Verifica se foi possivel alocar a memoria
    if(vet_Person == NULL){ 
        printf("\nNao foi possivel alocar memoria - Finalizando programa...\n");
        system("pause");
        exit(1);
    }

    printf("Iniciando gravacao de dados...\n\n");

    for(i=0;i<num;i++){
        printf("Pessoa numero: %03d\n",(i + 1));
        //Inicia o processo para ler o ID da pessoa
        temp_id = 0;
        while(temp_id == 0){
            printf("-> ID: ");
            fflush(stdin);
            fgets(buffer_input,BUFFER_SIZE,stdin);
            temp_id = atoi(buffer_input);
            //Verifica se é um ID valido
            if(temp_id <= 0){
                printf("\nID invalido! - Digite Novamente\n");
                temp_id = 0;
            }else{
                //Verifica se e um ID ja existente
                found = 0;
                for(x=0;x<vet_created;x++){
                    if(temp_id == vet_Person[x].Id){
                        found = 1;
                        break;
                    }
                }
                if(found == 1){
                    printf("\nEsse ID ja existe! - Digite novamente\n");
                    temp_id = 0;
                }else{
                    //Salva o ID na memoria
                    vet_Person[i].Id = temp_id;
                    vet_created++;
                }
                
            }
        }

        printf("-> Nome: ");
        fgets(buffer_input,sizeof(vet_Person[i].Name),stdin);
        strcopy(vet_Person[i].Name,buffer_input);

        //Inicia o processo para ler a idade de uma pessoa
        temp_age = 0;
        while(temp_age == 0){
            printf("-> Idade: ");
            fgets(buffer_input,BUFFER_SIZE,stdin);

            temp_age = atoi(buffer_input);
            //Verifica se é uma idade valida
            if(temp_age <= 0 || temp_age > 110){
                printf("\nIdade Invalida! - Digite novamente\n");
                temp_age = 0;
            }else{
                vet_Person[i].Age = temp_age;
            }
            
        }
    }

    printf("Ordenando...\n");
    //Chama a funcao que ordena o vetor de forma crescente
    if (num>1){
        quick(vet_Person,0,num-1);
    }
    
    for(i=0; i<num;i++){
        printf("\nID: %03d\n",vet_Person[i].Id);
        printf("Nome: %s\n",vet_Person[i].Name);
        printf("Idade: %d\n",vet_Person[i].Age);        
    }
    system("pause");
    free(vet_Person);
}