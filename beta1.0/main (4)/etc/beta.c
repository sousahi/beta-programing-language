#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h> 
#include <time.h>   
#include <math.h>   // Biblioteca de Matemática do C

#define MAX_VARS 128

typedef struct {
    char name[32];
    int value;
} Var;

Var vars[MAX_VARS];
int var_count = 0;

// Funções auxiliares (trim, get_var, set_var) continuam as mesmas...
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
    for (int i = 0; i < var_count; i++) {
        if (strcmp(vars[i].name, name) == 0) return vars[i].value;
    }
    return 0; 
}

void set_var(char *name, int value) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(vars[i].name, name) == 0) { vars[i].value = value; return; }
    }
    if (var_count < MAX_VARS) {
        strncpy(vars[var_count].name, name, 31);
        vars[var_count].value = value;
        var_count++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("\033[1;32mBETA\033[0m Studio Engine\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) { perror("Erro"); return 1; }

    srand(time(NULL)); 
    char line[256];
    int skip_block = 0;

    while (fgets(line, sizeof(line), f)) {
        char *ptr = trim(line);
        if (*ptr == '\0' || *ptr == '#') continue;

        if (strncmp(ptr, "stop(", 5) == 0) { skip_block = 0; continue; }
        if (skip_block) continue;

        // COMANDOS ORIGINAIS...
        if (strncmp(ptr, "it/:", 4) == 0) {
            char name[32]; int val;
            if (sscanf(ptr + 4, " %s = %d", name, &val) == 2) set_var(name, val);
        }
        else if (strncmp(ptr, "say/(\"", 6) == 0) {
            char *start = ptr + 6; char *end = strrchr(start, '"');
            if (end) { *end = '\0'; printf("%s\n", start); }
        }

        // --- NOVOS COMANDOS USANDO LIBRARIES DO C ---

        // math/: var = base ^ exp (Usa math.h)
        else if (strncmp(ptr, "math/:", 6) == 0) {
            char name[32]; int base, exp;
            if (sscanf(ptr + 6, " %s = %d ^ %d", name, &base, &exp) == 3) {
                int res = (int)pow(base, exp); // Função pow da math.h
                set_var(name, res);
            }
        }

        // time/: var (Usa time.h para pegar o ano atual)
        else if (strncmp(ptr, "time/:", 6) == 0) {
            char name[32];
            if (sscanf(ptr + 6, " %s", name) == 1) {
                time_t t = time(NULL);
                struct tm tm = *localtime(&t);
                set_var(name, tm.tm_year + 1900); // Salva o ano na variável
            }
        }
        
        else if (strncmp(ptr, "say/(", 5) == 0) {
            char name[32];
            if (sscanf(ptr + 5, "%[^)]", name) == 1) printf("%d\n", get_var(trim(name)));
        }
    }
    fclose(f);
    return 0;
}
