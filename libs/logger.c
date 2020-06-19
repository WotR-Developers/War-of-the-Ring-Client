#include "logger.h"


void    LOG_info    (const char*    text, const char*   infoText) {
    printf("[INFO]\t%s: \t%s\n", text, infoText);
}

void    LOG_error   (const char*    text, const char*   errorText) {
    printf("[ERROR]\t%s\n", text);
    printf("[ERROR]\t%s\n", errorText);
}
