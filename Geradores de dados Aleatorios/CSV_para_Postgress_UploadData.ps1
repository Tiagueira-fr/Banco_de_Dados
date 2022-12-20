# Carregar o arquivo CSV em um array de linhas
$lines = Get-Content -Path "C:\path\to\file.csv"

# Iniciar a string de comando de INSERT
$insertString = "INSERT INTO tabela (coluna1, coluna2, coluna3) VALUES"

# Loop pelas linhas do arquivo CSV
foreach ($line in $lines) {
    # Quebrar a linha em colunas
    $columns = $line -split ","

    # Adicionar os valores das colunas à string de comando de INSERT
    $insertString += "("
    $insertString += "'" + $columns[0] + "',"
    $insertString += "'" + $columns[1] + "',"
    $insertString += "'" + $columns[2] + "'"
    $insertString += "),"
}

# Remover a última vírgula
$insertString = $insertString.Substring(0, $insertString.Length - 1)

# Executar o comando de INSERT no banco de dados
Invoke-Sqlcmd -ServerInstance "server" -Database "database" -Query $insertString
