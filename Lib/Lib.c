//Estrutura do tipo Person_t
typedef struct{
    unsigned short Id;
    char Name[32];
    unsigned char Age;
}Person_t;

void strcopy(char *s1,char *s2){
    int i;
    for(i=0;s2[i] != '\0' && s2[i] != '\n';i++){
        s1[i] = s2[i];
    }
    s1[i] = '\0';
}

void quick(Person_t *lista,int esquerdo,int direito){     
    register int i,j;
    int x;
    Person_t y;
    i = esquerdo; 
    j = direito;
    x = lista[(esquerdo+direito)/2].Age;
    do{
        while(lista[i].Age>x && i<direito) i++;
        while(x>lista[j].Age && j>esquerdo) j--;
        if(i<=j){
            y = lista[i];
            lista[i] = lista[j];
            lista[j] = y;
            i++; 
            j--;
        }
    }while(i<=j);
    if(esquerdo<j){
        quick(lista,esquerdo,j);
    }
    if(i<direito){
        quick(lista,i,direito);   
    }  
}