*Este projeto foi criado como parte do currículo da 42 por victde-s e jode-cas.*

# 🐚 Minishell - 42 Project

> **"As beautiful as a shell"**
> Um clone simplificado do Bash desenvolvido em C para entender os meandros de processos, pipes, sinais e redirecionamentos no Unix.

---

## 🚀 Descrição

O **Minishell** é o primeiro grande desafio em dupla do currículo da 42. O objetivo é recriar o funcionamento básico de um interpretador de comandos, lidando com a complexidade de gerenciar processos filhos, manipular descritores de arquivos e garantir a limpeza total de memória (zero leaks).

### 🛠️ Principais Tecnologias e Conceitos
* **Linguagem C** (Seguindo a Norma da 42)
* **Processos:** `fork`, `wait`, `waitpid`, `execve`
* **Pipes e Redirecionamentos:** `pipe`, `dup`, `dup2`
* **Sinais:** `sigaction`, `signal`
* **Gerenciamento de Memória:** Alocação dinâmica e limpeza de estruturas complexas.

---

## ⚙️ Funcionalidades Implementadas

### 🔹 Obrigatórias
- [x] **Prompt funcional:** Exibe um prompt à espera de comandos.
- [x] **Histórico:** Navegação entre comandos anteriores (setas para cima/baixo).
- [x] **Execução de Binários:** Busca comandos no `PATH` ou caminhos relativos/absolutos.
- [x] **Aspas (Quotes):** - `' '` (Aspas simples): Inibe interpretação de metacaracteres.
    - `" "` (Aspas duplas): Inibe quase tudo, exceto o símbolo `$`.
- [x] **Redirecionamentos:**
    - `<` redireciona entrada.
    - `>` redireciona saída (overwrite).
    - `<<` heredoc (lê entrada até o delimitador).
    - `>>` redireciona saída (append).
- [x] **Pipes (`|`):** Onde a saída de um comando vira a entrada do próximo.
- [x] **Variáveis de Ambiente:** Expansão de `$VAR` e do status de saída `$?`.
- [x] **Sinais:**
    - `Ctrl-C`: Exibe um novo prompt em uma linha vazia.
    - `Ctrl-D`: Sai do shell (EOF).
    - `Ctrl-\`: Não executa nenhuma ação (SIGQUIT ignorado).

### 🔹 Built-ins (Comandos Internos)
O shell executa os seguintes comandos sem depender de binários externos:
- `echo` (com opção `-n`)
- `cd` (apenas com caminhos relativos ou absolutos)
- `pwd`
- `export`
- `unset`
- `env`
- `exit`

---

## 🏗️ Arquitetura do Projeto

O Minishell foi estruturado em 4 etapas principais:

1. **Lexer:** Divide a entrada do usuário em "tokens" (palavras, pipes, operadores).
2. **Parser:** Organiza os tokens em estruturas de comandos, identificando redirecionamentos e argumentos.
3. **Expander:** Substitui variáveis de ambiente e trata as aspas.
4. **Executor:** Gerencia os `forks`, cria os `pipes` e executa os comandos via `execve` ou built-ins.

---

## 🛠️ Instruções

**Dependência:** O projeto utiliza a biblioteca `readline`. Certifique-se de tê-la instalada em seu sistema.

```bash
# Clone o repositório
git clone git@github.com:Cadavanaugh/42-Project-Minishell.git minishell

# Entre na pasta
cd minishell

# Compile o projeto
make

# Execute o shell
./minishell

## 🧪 Testes

-------------------------------------------------------------------------------------------------------------

## 📚 Recursos

Acompanhe a versão completa pelo notion: https://www.notion.so/Minishell-2fc1a6c6214c811aab29c9ce6abb0c3e
