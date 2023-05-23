#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

#define _TRUE            1
#define _FALSE           0
#define STDIN            0
#define STDOUT           1
#define STDERR           2
#define NON_INTERACTIVE  0
#define INTERACTIVE      1
#define PERMISSIONS      1
#define NON_PERMISSIONS -1
#define _FILE            10
#define NON_FILE         -10
#define _ENOENT          "No such file or directory"
#define _EACCES          "Permission denied"
#define _CMD_NOT_EXISTS  "not found"
#define _ILLEGAL_NUMBER  "Illegal number"
#define _CODE_ENOENT           3
#define _CODE_EACCES           13
#define _CODE_CMD_NOT_EXISTS   132
#define _CODE_ILLEGAL_NUMBER   133

extern char **environ;

typedef struct __attribute__((__packed__))
{
	int argc;
	char **argv;           
	int mode;
	int error_code;            
	char *command;
	int n_commands;
	char *value_path; 
	int is_current_path; 
	int status_code;
	char *buffer;
	char **arguments;
	char *environment;
	int pid;
} general_t;

typedef struct __attribute__((__packed__))
{
	char *message;            /* Error message */
	int code;                 /* Error code for identify the error message */
} error_t;

typedef struct __attribute__((__packed__))
{
	char *command;            /* arguments[0] = cmd */
	void (*func)(general_t *info, char **arguments);
} builtin_t;

char *message_selector(general_t info);
void error(general_t *info);
void error_extra(general_t *info, char *extra);
void analyze(char **arguments, general_t *info, char *buff);
int is_executable(char *filename);
int is_file(char *command);
char *_getenv(const char *name);
char *which(char *filename, general_t *info);
void is_current_path(char *path, general_t *info);
void get_full_env(void);
void execute(char *commands, char **arguments, general_t *info, char *buff);
int current_directory(char *cmd, char **arguments, char *buff, general_t *info);
int builtins(general_t *info, char **arguments);
int check_builtin(general_t *info, char **arguments);
void bin_exit(general_t *info, char **arguments);
int number_controller(general_t *info, char *number);
void bin_env(general_t *info, char **arguments);
void bin_echo(general_t *info, char **arguments);
void echo_printer(int index, char *text, char **arguments);
void free_memory_p(void *ptr);
void free_memory_pp(void **ptr);
void *_realloc(void *ptr, size_t old_size, size_t new_size);
void start(general_t *info);
void start_prompt(general_t *info);
void prompt(general_t *info);
char *read_prompt();
void sigintHandler(int sig_num);
int _strlen(char *msg);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *str1, char *str2);
char *to_string(int number);
int is_numerical(unsigned int n);
int _atoi(char *s);
int contains_letter(char *s);
int _putchar_to_fd(char l, int fd);
int print_to_fd(char *msg, int fd);
int _putchar(char c);
int print(char *msg);
int print_err(char *msg);
char **split_words(char *line, const char *sep);
char *join_words(char *word1, char *word2, char *word3, const char *sep);
void analyze_patterns(general_t *info, char **arguments);
char *pattern_handler(general_t *info, char *string);
char *replace_value(general_t *info, int *index, char *string);
char *replacement(general_t *info, int *index, char *string);
char *replace_env(general_t *info, char *environment);
#endif /* SHELL_H */