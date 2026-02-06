#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#define MAX_VARS 128

typedef struct {
    char name[32];
    int value;
} Var;

Var vars[MAX_VARS];
int var_count = 0;

// --- FUNÇÕES AUXILIARES ---

char* trim(char* str) {
    char* end;
    while(isspace((unsigned char)*str)) str++;
    if(*str == 0) return str;
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
    return str;
}

int get_var(char *name) {
    char *n = trim(name);
    for (int i = 0; i < var_count; i++) {
        if (strcmp(vars[i].name, n) == 0) return vars[i].value;
    }
    return 0;
}

void set_var(char *name, int value) {
    char *n = trim(name);
    for (int i = 0; i < var_count; i++) {
        if (strcmp(vars[i].name, n) == 0) { vars[i].value = value; return; }
    }
    if (var_count < MAX_VARS) {
        strncpy(vars[var_count].name, n, 31);
        vars[var_count].value = value;
        var_count++;
    }
}

// --- NÚCLEO DO INTERPRETADOR ---

void process_line(char *line) {
    char *ptr = trim(line);
    if (*ptr == '\0' || *ptr == '#') return;

    // Prefixo it/: (Variáveis)
    if (strncmp(ptr, "it/:", 4) == 0) {
        char name[32]; int val;
        if (sscanf(ptr + 4, " %s = %d", name, &val) == 2) set_var(name, val);
    }
    // Prefixo say/: (Strings e Variáveis)
    else if (strncmp(ptr, "say/(\"", 6) == 0) {
        char *start = ptr + 6; char *end = strrchr(start, '"');
        if (end) { *end = '\0'; printf("%s\n", start); }
    }
    else if (strncmp(ptr, "say/(", 5) == 0) {
        char name[32];
        if (sscanf(ptr + 5, "%[^)]", name) == 1) printf("%d\n", get_var(name));
    }
    // Prefixo math/: (Potência)
    else if (strncmp(ptr, "math/:", 6) == 0) {
        char name[32]; int base, exp;
        if (sscanf(ptr + 6, " %s = %d ^ %d", name, &base, &exp) == 3) {
            set_var(name, (int)pow(base, exp));
        }
    }
    // Prefixo time/: (Ano atual)
    else if (strncmp(ptr, "time/:", 6) == 0) {
        char name[32];
        if (sscanf(ptr + 6, " %s", name) == 1) {
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            set_var(name, tm.tm_year + 1900);
        }
    }
    // NOVO: Prefixo rand/: (Aleatórios) -> rand/: x = 100
    else if (strncmp(ptr, "rand/:", 6) == 0) {
        char name[32]; int limit;
        if (sscanf(ptr + 6, " %s = %d", name, &limit) == 2) {
            set_var(name, rand() % limit);
        }
    }
    // NOVO: Prefixo os/: (Comandos do Sistema) -> os/: "clear"
    else if (strncmp(ptr, "os/:", 4) == 0) {
        char cmd[128];
        if (sscanf(ptr + 4, " \"%[^\"]\"", cmd) == 1) system(cmd);
    }
    // Comando stop
    else if (strcmp(ptr, "exit") == 0 || strcmp(ptr, "stop") == 0) {
        exit(0);
    }
}

// --- MAIN (Híbrido: Arquivo ou Interativo) ---

int main(int argc, char *argv[]) {
    srand(time(NULL));
    char line[256];

    if (argc < 2) {
        // MODO INTERATIVO (REPL)
        printf("\033[1;32mBETA\033[0m Studio Engine [Modo Interativo]\n");
        printf("Digite 'exit' para sair.\n");

        while (1) {
            printf(">>> ");
            if (!fgets(line, sizeof(line), stdin)) break;
            process_line(line);
        }
    } else {
        // MODO ARQUIVO
        FILE *f = fopen(argv[1], "r");
        if (!f) { perror("Erro ao abrir arquivo"); return 1; }

        while (fgets(line, sizeof(line), f)) {
            process_line(line);
        }
        fclose(f);
    }

    return 0;
}
