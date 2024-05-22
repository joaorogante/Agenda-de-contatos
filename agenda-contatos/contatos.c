#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include "contatos.h"

int validarEmail(const char *email) {
    // Simplificando a expressão regular para validação de email
    regex_t regex;
    const char *pattern = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";
    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
        return 0;
    }
    int result = regexec(&regex, email, 0, NULL, 0);
    regfree(&regex);
    return result == 0;
}
