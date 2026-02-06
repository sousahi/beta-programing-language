🟢 Beta Language Studio

Interpretador de linguagem customizada feito em C com uma IDE integrada em Python.
🚀 Como instalar

    Instale as dependências: sudo apt install build-essential python3-tk -y

    Compile o motor: gcc -o beta beta.c -lm

🕹️ Como usar

    Via IDE: python3 app.py

    Via Script de Automação:build.sh

📖 Comandos da Linguagem

    it/: x = 10 -> Cria variáveis

    math/: x = 2 ^ 3 -> Cálculos de potência (math.h)

    time/: t -> Pega o ano atual (time.h)

    say/("Texto") -> Imprime mensagens

    count/:[1000] -> Pausa a execução (ms)

    stop( ) -> Finaliza blocos condicionais
