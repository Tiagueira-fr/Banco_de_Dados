#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

/*  Gerar dados para a Table "pessoa"

CREATE TABLE pessoa (
 id_cliente VARCHAR PRIMARY KEY,
 cpf VARCHAR,
 nome VARCHAR,
 rua VARCHAR,
 telefone INT NOT NULL,
 endereco VARCHAR
);

*/

const int NUM_RECORDS = 10;

// Gera id_Aleatoria do cliente
std::string generateRandomID(){
    std::string id_cliente = "BR#";
    for (int i = 0; i < 2; i++){
        id_cliente += std::to_string(rand() % 100);  // Numero aleatório entre 0 e 99
    }
    return id_cliente;
}

// Gera CPF aleatorio
std::string generateRandomCPF() {
  std::string cpf = "";
  for (int i = 0; i < 11; i++) {
    cpf += std::to_string(rand() % 10);
  }
  return cpf;
}

// Gera nomes
std::string generateRandomNome() {
  std::string nomes[] = {"João", "Maria", "José", "Ana", "Pedro", "Lucas", "Julia", "Mateus", "Rafael", "Isabela"};
  return nomes[rand() % 10];
}

// Gera numero de telefone aleatorio com ddd
std::string generateRandomtelefone() {
    //DDD
  std::string telefone = "(";
  telefone += std::to_string(rand() % 9 + 2);  // DDD entre 2 e 9
  telefone += ") ";
  
  //Primeiros numeros do telefone
  for (int i = 0; i < 4; i++) {
    telefone += std::to_string(rand() % 10);
  }
  // Segunda parte do telefone
  telefone += "-";
  for (int i = 0; i < 4; i++) {
    telefone += std::to_string(rand() % 10);
  }
  return telefone;
}

// Gera um endereco composto por Rua Bairro e Cidade
std::string generateRandomEndereco() {
  std::string enderecoes[] = {"Rua A", "Rua B", "Rua C", "Rua D", "Rua E", "Rua F", "Rua G", "Rua H", "Rua I", "Rua J"};
  std::string endereco = enderecoes[rand() % 10];
  endereco += " ";
  endereco += std::to_string(rand() % 100 + 1);  // Numero entre 1 e 100
  endereco += ", Bairro ";
  endereco += std::to_string(rand() % 10 + 1);  // Bairro entre 1 e 10
  endereco += ", Cidade XYZ, Estado ABC";
  return endereco;
}

int main() {
  srand(time(0));  // Inicializa o gerador de numeros aleatorios

    // Tipo do arquivo de saida
  std::ofstream outfile("dados2.csv");

    // Loop que prenche o arquivo implementando as funçoes
  for (int i = 0; i < NUM_RECORDS; i++) {
    std::string id_cliente = generateRandomID();
    std::string cpf = generateRandomCPF();
    std::string nome = generateRandomNome();
    std::string telefone = generateRandomtelefone();
    std::string endereco = generateRandomEndereco();

    // Tipagem das linhas no arquivo com "dado1" + "," + "dado2" ...
    outfile << id_cliente << "," << cpf << "," << nome << "," << telefone << "," << endereco << std::endl;
  }

  outfile.close();

  return 0;
}
