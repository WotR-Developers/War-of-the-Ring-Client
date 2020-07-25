/* This file is to provide an easy logging utility throughout the program. */

#ifndef FOURTH_AGE_CLIENT_LOGGER
#define FOURTH_AGE_CLIENT_LOGGER

/* For logging. */
#include <stdio.h>

/* Logs an info with the given text and information. */
void    LOG_info    (const char*    text, const char*   infoText);

/* Logs an error with the given text and error message. */
void    LOG_error   (const char*    text, const char*   errorText);

#endif
