CREATE SCHEMA [Main_DataBase]
GO
CREATE TABLE [Pessoa] (
 [ID_Cliente] varcharacter PRIMARY KEY,
 [CPF] string,
 [Nome] varcharacter,
 [Rua] string,
 [Telefone] nvarchar(255) NOT NULL CHECK ([Telefone] IN ('Celular1', 'Celular2',
'Telefone_Residencial')),
 [Endereco] nvarchar(255) NOT NULL CHECK ([Endereco] IN ('Rua', 'Numero', 'Bairro',
'Cidade', 'Estado', 'CEP', 'Complemento'))
)
GO
CREATE TABLE [Funcionario] (
 [Matricula] string PRIMARY KEY,
 [Setor] string,
 [Cargo] string
)
GO
CREATE TABLE [Terceiro] (
 [CodTerceiro] varcharacter PRIMARY KEY
)
GO
CREATE TABLE [Cliente] (
 [Nro_Cliente] int
)
GO
CREATE TABLE [Servico] (
 [CodServico] varcharacter PRIMARY KEY,
 [CodTerceiro] varcharacter,
 [Nome] string,
 [Descricao] varcharacter
)
GO
CREATE TABLE [Pacote] (
 [CodPacote] string PRIMARY KEY,
 [Preco] float,
 [Data] datetime
)
GO
CREATE TABLE [Transporte] (
 [Id_Passagem] varcharacter PRIMARY KEY,
 [Disponibilidade] boolean
)
GO
CREATE TABLE [Aviao] (
 [Cod_Voo] varcharacter PRIMARY KEY,
 [Aeroporto_Embarque] varcharacter,
 [Assento] string,
 [Companhia] string
)
GO
CREATE TABLE [Onibus] (
 [Cod_Onibus] varcharacter,
 [Assento] string,
 [Viacao] string,
 [Rodoviaria_Embarque] varcharacter
)
GO
CREATE TABLE [Destino] (
 [CodDestino] string PRIMARY KEY,
 [Cidade] varcharacter,
 [Estado] char
)
GO
CREATE TABLE [Hospedagem] (
 [CodHospedagem] string PRIMARY KEY,
 [Nome_Hospedagem] varcharacter,
 [Ocupacao] string,
 [Disponibilidade] boolean,
 [Endereco] nvarchar(255) NOT NULL CHECK ([Endereco] IN ('Rua', 'Bairro', 'Numero',
'Complemento'))
)
GO
CREATE TABLE [Ponto_Turistico] (
 [CodPontoT] string PRIMARY KEY,
 [Nome_Ponto] varcharacter,
 [Descricao] varcharacter,
 [Referencia_Foto] varcharacter
)
GO
ALTER TABLE [Cliente] ADD CONSTRAINT [Funcionario_Atende_Cliente] FOREIGN KEY 
([Nro_Cliente]) REFERENCES [Funcionario] ([Matricula])
GO
ALTER TABLE [Pacote] ADD CONSTRAINT [Cliente_Compra_Pacote] FOREIGN KEY 
([CodPacote]) REFERENCES [Cliente] ([Nro_Cliente])
GO
ALTER TABLE [Aviao] ADD CONSTRAINT [Transporte_Disjuncao_Aviao] FOREIGN KEY 
([Cod_Voo]) REFERENCES [Transporte] ([Id_Passagem])
GO
ALTER TABLE [Onibus] ADD CONSTRAINT [Transporte_Disjuncao_Onibus] FOREIGN KEY 
([Cod_Onibus]) REFERENCES [Transporte] ([Id_Passagem])
GO
ALTER TABLE [Hospedagem] ADD CONSTRAINT [Destino_Possui_Hospedagem] FOREIGN KEY 
([CodHospedagem]) REFERENCES [Destino] ([CodDestino])
GO
ALTER TABLE [Ponto_Turistico] ADD CONSTRAINT [Destino_Possui_PntTuristico] FOREIGN
KEY ([CodPontoT]) REFERENCES [Destino] ([CodDestino])
GO
ALTER TABLE [Servico] ADD CONSTRAINT [Terceiro_Realiza_Servico] FOREIGN KEY 
([CodServico]) REFERENCES [Terceiro] ([CodTerceiro])
GO
ALTER TABLE [Terceiro] ADD CONSTRAINT [Terceiro_Disjuncao_Pessoa] FOREIGN KEY 
([CodTerceiro]) REFERENCES [Pessoa] ([ID_Cliente])
GO
ALTER TABLE [Funcionario] ADD CONSTRAINT [Funcionario_Disjuncao_Pessoa] FOREIGN KEY 
([Matricula]) REFERENCES [Pessoa] ([ID_Cliente])
GO
ALTER TABLE [Destino] ADD CONSTRAINT [Pacote_Destino] FOREIGN KEY ([CodDestino])
REFERENCES [Pacote] ([CodPacote])
GO
ALTER TABLE [Transporte] ADD CONSTRAINT [Pacote_Transporte] FOREIGN KEY 
([Id_Passagem]) REFERENCES [Pacote] ([CodPacote])
GO