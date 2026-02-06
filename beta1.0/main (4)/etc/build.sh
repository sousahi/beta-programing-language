#!/bin/bash

# 1. Compilar o Beta com suporte a bibliotecas matemáticas
echo "🔨 Compilando o motor Beta com Math Lib..."

if ! gcc -o beta beta.c -lm; then
    echo "❌ Erro na compilação! Verifique seu código C."
    echo ""
    read -p "Pressione [Enter] para sair..."
    exit 1
fi

echo "✅ Motor compilado com sucesso!"
echo "🔍 Procurando arquivos .bt no sistema..."
echo "------------------------------------------"

# 2. Criar uma lista de arquivos .bt
mapfile -t arquivos < <(find ~ -name "*.bt" 2>/dev/null)

if [ ${#arquivos[@]} -eq 0 ]; then
    echo "🚫 Nenhum arquivo .bt encontrado."
    read -p "Pressione [Enter] para sair..."
    exit 1
fi

# 3. Criar o menu de escolha
echo "Escolha qual script deseja rodar:"
PS3="Digite o número (ou Ctrl+C para sair): "

select script in "${arquivos[@]}"; do
    if [ -n "$script" ]; then
        echo "🚀 Rodando: $script"
        echo "------------------------------------------"
        ./beta "$script"
        echo "------------------------------------------"
        echo "✅ Execução finalizada."
        # ESTA LINHA ABAIXO SEGURA A JANELA ABERTA
        read -p "Pressione [Enter] para fechar esta janela..."
        break
    else
        echo "Opção inválida!"
    fi
done
