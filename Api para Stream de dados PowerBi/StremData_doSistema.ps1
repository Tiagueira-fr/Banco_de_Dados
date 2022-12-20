$endpoint
"Push URL"

$payload = @{
"data" = "2022-10-27T23 : 23 : 25 .882Z"
"hora" = "2022-10-27T23 : 23 : 25.882Z"
"codpacote" = 98.6
"preco" = 98.6
}

Invoke-RestMethod -Method Post -Uri "$endpoint" -Body
(ConvertTo-Json @($payload))