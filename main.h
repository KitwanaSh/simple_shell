#ifndef MAIN_H
#define MAIN_H

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <signal.h>

#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAD -1

#define min(n, m) (((n) < (m)) ? (n) : (m))

/**
 * struc org - the structure the organizes the command to the function
 * @name_of_com: name of the command
 * @fc: the funtion that exectutes that spacific command
 */
typedef struct org
{
	char *name_of_command;
	void (*fc)(char **command);
} fc_org;

extern char **environ;
extern char *line;
extern char **commands;
extern char *name_of_shell;
extern int status;

/* main prototypes */
extern void initializer(char **curr_command, in type_command);
extern void uniteractive(void);
/* Used funtions */
void parse_command(char *);
void execute_command(char **, int);
void (*get_func(char *))(char **);
void *_getenv(char *);

/* Pillar functions */
char *_strtok(char *, char *, char **);
int _atoi(char *);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void handler(int);
void remove_comment(char *);

/* Built in prototypes */
void env(char **);
void quit(char **);
#endif
