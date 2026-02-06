# 🚀 BETA Language Studio (v1.1)

Olá! Eu sou o Paulo e o BETA é o meu projeto de linguagem de programação simples, desenvolvida totalmente em C com uma interface integrada em Python. Criei este projeto por hobby e para aprender mais sobre como computadores entendem instruções.
## 🛠️ Requisitos e Instalação

Se você está no Linux (Ubuntu/Debian), instale as dependências básicas:
Bash

``` bash
sudo apt install build-essential python3-tk -y
```

Compilando o Motor

Para compilar o núcleo da linguagem (beta.c), use:
Bash

``` bash
gcc -o beta beta.c -lm
```

## 🕹️ Como Usar

Você pode usar o BETA de três formas:

    Via IDE (Python): ```bash python3 app.py(IDE PYTHON DESATIVADO NA VERSAO 1.1MAS CONTEM MODO INTERATIVO E A VERSAO 1.0 E A CORE COM MENOS PREFIXOS MAS COM IDE PYTHON)

    Via Script de Automação:
    Bash

    ./build.sh

    Via Terminal (Interativo):
    Bash

    ./beta

## 📖 Comandos da Linguagem

O **BETA** utiliza prefixos para identificar ações. Aqui estão os principais:

Prefixo	Função	Exemplo:

- it/:	Cria variáveis inteiras	it/: x = 10

- math/:	Cálculos de potência	```math/: x = 2 ^ 3```

- rand/:	Gera números aleatórios	```rand/: d6 = 6```

- time/:	Captura o ano atual	```time/: ano_agora```

- os/:	Comandos do sistema	```os/: "ls"```

- say/(" "):	Imprime mensagens	```say/("Ola Mundo")```

- say/( ):	Imprime valor de variável	```say/(x)```

- count/:	Pausa a execução (ms)	```count/:[1000]```

- stop( ):	Finaliza blocos	stop( )

## 🐞 Bugs e Suporte

Esta é a versão 1.0 E 1.1, então bugs podem acontecer! Se você encontrar algum erro ou quiser apoiar o projeto:

    📧 Email: spierry52@gmail.com

    Autor: Paulo (12 anos)

Eu leio todos os e-mails! Se tiver uma ideia de comando novo, me mande.
> ⚠️ **Licença**: Uso autorizado em projetos de terceiros apenas com créditos ao criador. <br>
> Proibido uso comercial. Projeto de autoria de **Paulo**. ⚠️
