CREATE TRIGGER gerar_relatorio AFTER INSERT ON tabela
FOR EACH ROW
BEGIN
    INSERT INTO relatorio (soma_ids, cidade, estado)
    SELECT SUM(id), cidade, estado FROM tabela;
END;
