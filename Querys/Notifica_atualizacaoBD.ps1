# Inclui o módulo do PostgreSQL
Import-Module -Name 'Npgsql'

# Define as informações de conexão com o banco de dados
$connString = 'Server=localhost;Port=5432;Database=database;User ID=username;Password=password;'

# Abre uma conexão com o banco de dados
$conn = New-Object 'Npgsql.NpgsqlConnection' $connString
$conn.Open()

# Define a consulta SQL para obter os novos dados
$query = 'SELECT * FROM tabela WHERE data_inclusao > NOW() - INTERVAL ''1 MINUTE'''

# Executa a consulta e armazena os resultados
$cmd = New-Object 'Npgsql.NpgsqlCommand' $query, $conn
$reader = $cmd.ExecuteReader()

# Verifica se foram encontrados novos dados
if ($reader.HasRows) {
    # Exibe a notificação
    New-BurntToastNotification -Text 'Novo dado incluído no banco de dados!'
}

# Fecha a conexão com o banco de dados
$conn.Close()
