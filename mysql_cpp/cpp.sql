-- Usar o banco de dados 'cpp' que já foi criado
USE cpp;

-- Criar a tabela 'usuarios' caso não exista
CREATE TABLE IF NOT EXISTS usuarios (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    email VARCHAR(100) NOT NULL
);

-- Inserir dados de exemplo
INSERT INTO usuarios (nome, email) VALUES
('Alice Silva', 'alice.silva@example.com'),
('Bob Oliveira', 'bob.oliveira@example.com'),
('Carlos Souza', 'carlos.souza@example.com');
