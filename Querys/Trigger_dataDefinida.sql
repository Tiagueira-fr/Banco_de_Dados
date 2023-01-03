CREATE TRIGGER gerar_relatorio AFTER INSERT ON tabela
FOR EACH ROW
BEGIN
    IF (CURDATE() = '2022-01-01') THEN
        INSERT INTO relatorio (soma_ids, cidade, estado)
        SELECT SUM(id), cidade, estado FROM tabela;
    END IF;
END;
