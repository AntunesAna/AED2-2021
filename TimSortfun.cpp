//Código elaborado pelos alunos
//ANA JESSYE ALMEIDA ANTUNES - 1615310046
//BRUNO DE OLIVEIRA FREIRE - 1615310030
//KYLCIANE CRISTINY LOPES FREITAS - 1615310052


#include<iostream> //biblioteca para utilizar scanf e printf
#include <time.h> //biblioteca para utilizar as funções de cálculo do tempo
#include <stdlib.h> //biblioteca para utilizar a função de rand
using namespace std;
const int RUN = 64;  //o tamanho do run vai ser sempre 64
 
// Esta função classifica a matriz do índice esquerdo 
// para o índice da direita que é de tamanho máximo RUN
void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++) //faz o laço para percorrer o subvetor começar da segunda posiçao do vetor
    {
        int temp = arr[i]; //pega um variável auxiliar para guardar o elemento da posição atual do vetor
        int j = i - 1; //variável para iniciar a comparação desde o primeiro elemento
        while (j >= left && arr[j] > temp) //comparação de qua elemento é menor
        {
            arr[j+1] = arr[j]; //troca elementos de posição
            j--;
        }
        arr[j+1] = temp;
    }
}
 
// A função de mesclagem, mescla as execuções classificadas
void merge(int arr[], int l, int m, int r)
{
     
    // A matriz original está dividida em duas partes
    // matriz esquerda e direita
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++) //organiza o vetor em submatriz esquerda
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++) //organiza o vetor em submatriz da direita
        right[i] = arr[m + 1 + i];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    // Depois de comparar, mesclamos essas duas matrizes em uma submatriz maior
    while (i < len1 && j < len2) //percorre a submatriz da esquerda e da direita
    {
        if (left[i] <= right[j]) //compara os elementos das duas submatrizes, se o elemento da matriz esquerda for menor ou igual ao da matriz direita
        {
            arr[k] = left[i]; //novo vetor recebe elemento da matriz esquerda
            i++;
        }
        else
        {
            arr[k] = right[j]; //senão, novo vetor recebe elemento da matriz direita
            j++;
        }
        k++;
    }
 
    // Copia os elementos restantes da esquerda, se houver
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
 
    // Copia os elementos restantes da direita, se houver
    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}
 
// Função Timsort para classificar a matriz
void timSort(int arr[], int n)
{
     
    // Classifica submatrizes individuais de tamanho RUN
    for (int i = 0; i < n; i+=RUN)
        insertionSort(arr, i, min((i+RUN-1), (n-1))); //chamada da função insertionSort
 
    // Comece a mesclar a partir do tamanho RUN. Ele irá se fundir para formar o tamanho 64.
    for (int size = RUN; size < n; size = 2*size){
         
        // escolha o ponto inicial da submatriz esquerda. Vamos mesclar arr [left..left + size-1] e arr [left + size, left + 2 * size-1] Após cada mesclagem, aumentamos o tamanho 2 * à esquerda
        for (int left = 0; left < n; left += 2*size){
             
            // encontrar o ponto final da submatriz esquerda, mid + 1 é o ponto inicial da submatriz direita
            int mid = left + size - 1;
            int right = min((left + 2*size - 1),(n-1));
 
            // mesclar submatriz arr [esquerda ..... mid] e arr [mid + 1 .... right]
              if(mid < right)
                merge(arr, left, mid, right);
        }
    }

}
 
// Função para imprimir o vetor
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) //percorre o vetor todo
        printf("%d  ", arr[i]); //mostra cada elemento do vetor
    printf("\n");
}


//Função para criar vetor aleatório
void arrayAleatorio(int vet[], int tam){
	for (int i=0; i<tam; i++){ //percorre o vetor todo
        	vet[i] = rand() % tam + 1; //cada posição do vetor recebe um elemento aleatório
    }
}
 
//Função para criar vetor decrescente
void arraydecresc(int vet[], int vet3[], int tam){
	int aux  = tam; // variável auxiliar a ser decrementada
    	for (int i=0; i<tam; i++){ //percorre p vetor todo
		vet3[i] = vet[aux-1]; //vetor decrescente recebe elemento do vetor crescente, de trás para frente
		aux--;
	 }

}
 
//Função para criar vetor crescente e decrescente
void arraycrescdecre(int vet[], int vet5[], int tam){
    int aux5 = tam; //variável auxiliar a ser decrementada
    int meio = tam/2; // variável para dividir o vetor em dois
    for (int i=0; i<meio; i++){ //percorre o vetor até o meio
        vet5[i] = vet[i]; //novo vetor recebe elementos do vetor crescente
    }
    for (int i=meio; i<tam; i++){ //percorre o vetor do meio ao final
        vet5[i] = vet[aux5-1]; //novo vetor recebe elementos a partir do meio de forma decrescente
        aux5--;
    }

}
 
//Função para criar vetor decrescente e crescente
void arraydecrecresc(int vet[],int vet4[], int tam){
    int aux2 = tam, meio = tam/2, aux3 = meio; // variável auxiliar a ser decrementada, variável para receber o meio e variável auxiliar a ser decrementada
    for (int i=0; i<meio; i++){ //percorre o vetor até o meio
        vet4[i] = vet[aux3-1]; //novo vetor recebe valores do vetor crescente de forma decrescente
        aux3--;
    }
    for (int i=meio; i<tam; i++){ // percorre o vetor do meio ao final
        vet4[i] = vet[i]; //novo vetor recebe vetor crescente do meio até o fim
        aux2--;
    }

}
 

int main(){
    //variavel para designar tamanho do vetor inserida pelo usuário
    int tam;
    printf ("Digite o tamanho do vetor: ");
    scanf ("%i", &tam);
    
    clock_t t, t2, t3, t4, t5; //variáveis para armazenar tempo
    int vet[tam], vet2[tam], vet3[tam], vet4[tam], vet5[tam]; //vetores para ordenação
     
    
    
    //cria vetor aleatório
    arrayAleatorio(vet, tam); //chamada da função criar vetor aleatório
    printf("Vetor aleatóio: ");
    printArray(vet, tam);
 
    // Chamada da função TimSort
    //Verificando tempo de execução do timSort
    t = clock(); //armazena tempo
    timSort(vet, tam);
    t = clock() - t; //tempo final - tempo inicial
    
    //imprime o tempo na tela
    printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double
    
    
    
    // vetor crescente
    printf("Vetor crescente: ");
    printArray(vet, tam);
    
    // Chamada da função TimSort
    //Verificando tempo de execução do TimSort
    t2 = clock(); //armazena tempo
    timSort(vet, tam);
    t2 = clock() - t2; //tempo final - tempo inicial
    
    //imprime o tempo na tela
    printf("Tempo de execucao: %lf \n", ((double)t2)/((CLOCKS_PER_SEC/1000))); //conversão para double
    
    
    
    //chamada da função para criar vetor decrescente
    arraydecresc(vet, vet3, tam);
    printf("Vetor decrescente: ");
    printArray(vet3, tam);
    
    // Chamada da função
    //Verificando tempo de execução do TimSort
    t3 = clock(); //armazena tempo
    timSort(vet3, tam);
    t3 = clock() - t3; //tempo final - tempo inicial
    
    //imprime o tempo na tela
    printf("Tempo de execucao: %lf \n", ((double)t3)/((CLOCKS_PER_SEC/1000))); //conversão para double
    
    
    
    
    //chamada da funlçao para criar Vetor metade decrescente, metade crescente
    arraydecrecresc(vet, vet4, tam);
    printf("Vetor metade decrescente, metade crescente: ");
    printArray(vet4, tam);
    
    // Chamada da função TimSort
    //Verificando tempo de execução do TimSort
    t4 = clock(); //armazena tempo
    timSort(vet4, tam);
    t4 = clock() - t4; //tempo final - tempo inicial
    
    //imprime o tempo na tela
    printf("Tempo de execucao: %lf \n", ((double)t4)/((CLOCKS_PER_SEC/1000))); //conversão para double
    
    
    
    //chamada da função cria Vetor metade crescente, metade decrescente
    arraycrescdecre( vet, vet5, tam);
    printf("Vetor metade crescente, metade decrescente: ");
    printArray(vet5, tam);
    
    // Chamada da função
    //Verificando tempo de execução do TimSort
    t5 = clock(); //armazena tempo
    timSort(vet5, tam);
    t5 = clock() - t5; //tempo final - tempo inicial
    
    //imprime o tempo na tela
    printf("Tempo de execucao: %lf \n", ((double)t5)/((CLOCKS_PER_SEC/1000))); //conversão para double
    
    return 0;
}
