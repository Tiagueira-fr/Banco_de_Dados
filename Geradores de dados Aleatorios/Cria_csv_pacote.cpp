#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <ctime>

/* Gera dados para a Table "pacote"

CREATE TABLE pacote (
 codpacote VARCHAR PRIMARY KEY,
 preco FLOAT,
 data TIMESTAMP
);

*/

// Gera id do pacote aleatoria
std::string generateRandomCodpacote(){
    std::string codpacote = "";

    // Prefixo para o código do pacote
    std::string prefixo = "PAC-";

    // Gera um número aleatório de 1 a 100
    int numero_pac = rand() % 100 + 1;

    // Converte o número para string e concatena com o prefixo
    codpacote = prefixo + std::to_string(numero_pac);

    return codpacote;
}


// Gera preco aleatorio 
std::string generateRandomPreco(){
    
    // Gera um número aleatório de 1 a 10000
    int numero = rand() % 10000 + 1;

    // Adiciona 4000 ao número aleatório
    int preco = numero + 4000;

    // Converte o preço para string
    std::string preco_string = std::to_string(preco);

    return preco_string;
}


// Gera data aleatoria
std::string generateRandomData(){
    std::string data = "";

    // Obtém a hora atual
    time_t now = time(0);

    // Estrutura para armazenar a hora atual
    tm *ltm = localtime(&now);

    // Gera um valor aleatório para os minutos (de 0 a 59)
    int minutos = rand() % 60;

    // Gera um valor aleatório para as horas (de 0 a 23)
    int horas = rand() % 24;

    // Atualiza os minutos e horas na estrutura "ltm"
    ltm->tm_min = minutos;
    ltm->tm_hour = horas;

    // Converte a estrutura "ltm" para string no formato "dd/mm/yyyy hh:mm"
    char buffer[20];
    strftime(buffer, 20, "%d/%m/%Y %H:%M", ltm);
    data = buffer;

    return data;
}



const int NUM_RECORDS = 10;

int main(){
    srand(time(0)); // Inicia o gerador de numeros aleatorios

    // Tipo do arquivo de saida
    std::ofstream outfile("dados_pacote.csv");

    // Loop que preenche o arquivo implementando as funcoes
    for (int i = 0; i < NUM_RECORDS; i++){
        std::string codpacote = generateRandomCodpacote();
        std::string preco = generateRandomPreco();
        std::string data = generateRandomData();

         // Tipagem das linhas no arquivo com "dado1" + "," + "dado2" ...
         outfile << codpacote << "," << preco << "," << data << std::endl;
    }

    outfile.close();
    return 0;
}