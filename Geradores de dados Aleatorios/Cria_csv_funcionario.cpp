#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

/* Gerar dados para a Table "funcionario"

CREATE TABLE funcionario (
 matricula VARCHAR PRIMARY KEY,
 setor VARCHAR,
 cargo VARCHAR
);

*/

const int NUM_RECORDS = 10;

// Gera matricula aleatoria
std::string generateRandomMatricula(){
    std::string matricula = "MG-";
    for (int i = 0; i < 3 ; i++){
        matricula += std::to_string(rand() % 90 + 10);  // Numero aleatorio entre 10 e 99
    }
    return matricula;
}

// Gera setor aleatorio
std::string generateRandomSetor(){
    std::string setor[] = { "Setor A" , "Setor B" , "Setor C" , "Setor D" , "Setor E" };
    return setor[rand() % 5];
}

// Gera cargo aleatorio
std::string generateRandomCargo(){
    std::string cargo [] = {"Cargo X" , "Cargo Y" , "Cargo Z"};
    return cargo[rand() % 3];
}


int main(){
    srand(time(0)); // Inicia o gerador de numeros aleatorios

    // Tipo do arquivo de saida
    std::ofstream outfile("dados_funcionarios.csv");

    // Loop que preenche o arquivo implementando as funcoes
    for (int i = 0 ; i < NUM_RECORDS; i++){
        std::string matricula = generateRandomMatricula();
        std::string setor = generateRandomSetor();
        std::string cargo = generateRandomCargo();

        // Tipagem das linhas no arquivo com "dado1" + "," + "dado2" ...
        outfile << matricula << "," << setor << "," << cargo << std::endl;
    }

    outfile.close();

    return 0;

}