import tkinter as tk
from tkinter import scrolledtext
import subprocess
import os

def rodar_beta():
    # 1. Pega o código escrito no editor
    codigo = txt_edit.get("1.0", tk.END)
    
    # 2. Salva em um arquivo temporário
    with open("script.bt", "w") as f:
        f.write(codigo)
    
    # 3. Executa o seu interpretador C
    try:
        # Chama ./beta passando o arquivo temporário
        processo = subprocess.run(['./beta', 'temp_script.bt'], 
                                   capture_output=True, text=True)
        
        # 4. Mostra a saída (ou erro) no console do app
        output_console.config(state=tk.NORMAL)
        output_console.delete("1.0", tk.END)
        
        if processo.returncode == 0:
            output_console.insert(tk.END, processo.stdout)
        else:
            output_console.insert(tk.END, "ERRO NO BETA:\n" + processo.stderr)
            
        output_console.config(state=tk.DISABLED)
    except Exception as e:
        output_console.config(state=tk.NORMAL)
        output_console.insert(tk.END, f"Erro ao chamar o interpretador: {e}")
        output_console.config(state=tk.DISABLED)

# --- Configuração da Janela ---
root = tk.Tk()
root.title("Beta Studio 1.0")
root.geometry("600x500")
root.configure(bg="#2c3e50")

# Título
label = tk.Label(root, text="BETA LANGUAGE EDITOR", fg="white", bg="#2c3e50", font=("Arial", 14, "bold"))
label.pack(pady=10)

# Editor de Texto
txt_edit = scrolledtext.ScrolledText(root, width=70, height=15, font=("Courier New", 12))
txt_edit.pack(padx=10, pady=5)
txt_edit.insert(tk.END, "# Escreva seu código Beta aqui\nsay/(\"Ola do App!\")\nit/: x = 10\nsay/(x)")

# Botão Rodar
btn_run = tk.Button(root, text="▶ RODAR SCRIPT", command=rodar_beta, bg="#27ae60", fg="white", font=("Arial", 10, "bold"))
btn_run.pack(pady=10)

# Console de Saída
output_console = scrolledtext.ScrolledText(root, width=70, height=8, bg="black", fg="#00ff00", font=("Courier New", 10))
output_console.config(state=tk.DISABLED)
output_console.pack(padx=10, pady=10)

root.mainloop()
