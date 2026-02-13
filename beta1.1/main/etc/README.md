# BETA Language Studio (v1.1)

Ola! Eu sou o Paulo e o BETA e meu projeto de linguagem de programacao simples, desenvolvido em C com interface em Python.

## Requisitos

No Linux (Ubuntu/Debian):

```bash
sudo apt install build-essential python3-tk -y
```

## Compilar

```bash
gcc -o beta beta.c -lm
```

## Como Usar

- Modo interativo:

```bash
./beta
```

- Rodar script `.bt`:

```bash
./beta script.bt
```

- Script de automacao:

```bash
./build.sh
```

- IDE Python:

```bash
python3 app.py
```

## Comandos

- `it/: x = 10`  
  Cria/atualiza variavel inteira.

- `say/("Ola Mundo")`  
  Imprime string.

- `say/(x)`  
  Imprime valor da variavel.

- `math/: pot = 2 ^ 3`  
  Potencia inteira.

- `time/: ano_agora`  
  Salva ano atual em variavel.

- `rand/: d6 = 6`  
  Gera aleatorio entre `0` e `limite-1` (limite deve ser maior que 0).

- `count/:[1000]` ou `count/: 1000`  
  Pausa em milissegundos.

- `os/: "ls"`  
  Executa comando do sistema (use com cuidado).

- `stop`, `stop()`, `stop( )` ou `exit`  
  Finaliza execucao.

## Suporte

Se encontrar bugs ou quiser sugerir comandos novos:

- Email: `spierry52@gmail.com`
- Autor: Paulo

> Licenca: uso permitido apenas para fins educacionais e nao comerciais, com creditos ao autor.
