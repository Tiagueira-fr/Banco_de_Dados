#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

/* Gera dados para a Table "servico"

CREATE TABLE servico (
 codservico VARCHAR PRIMARY KEY,
 codterceiro VARCHAR,
 nome VARCHAR,
 descricao VARCHAR
);
*/

const int NUM_RECORDS = 10;

// Gera id aleatorio para o servico oferecido
std::string generateRandomCod(){
    std::string codservico = "";

    // Vetor com os valores de "SXX-"
    std::string prefixos[] = {"S01-", "S02-", "S03-"};

    // Contador para alternar entre os valores de prefixos
    int contador = 0;
    
    for(int i = 0 ; i < 10 ; i++){
        // Incrementa o contador a cada iteração
        contador = (contador + 1) % 3;

        // Concatena o valor do contador atual com o número aleatório
        codservico += prefixos[contador] + std::to_string(rand() % 99 + 1);
    }

    return codservico;
}

// Gera nome aleatorio ao servico prestado
std::string generateRandomNome(){
    std::string nome[] = {"Prestaocao A" , "Prestacao B" , "Prestaca C" , "Prestacao D" , "Prestacao E" , "Prestacao F"};
    return nome[rand() % 6];
}

// Gera descricao aleatoria do servico prestado
std::string generateRandomDescricao(){
    std::string descricao[] = {"Uma descricao X" , "Uma Descricao Y" , "Uma Descricao Z"};
    return descricao [rand() % 3];
}

int main(){
    srand(time(0)); // Inicializa o gerador de numeros aleatorios

        // Tipo do arquivo de saida
    std::ofstream outfile("dados_servico.csv");

        // Loop que prenche o arquivo implementando as funçoes
    for (int i = 0; i < NUM_RECORDS; i++)
    {
        std::string codservico = generateRandomCod();
        std::string nome = generateRandomNome();
        std::string descricao = generateRandomDescricao();
            
        // Tipagem das linhas no arquivo com "dado1" + "," + "dado2" ...
        outfile << codservico << "," << nome << "," << descricao << std::endl;
    }
    

    outfile.close();
    return 0;
}
