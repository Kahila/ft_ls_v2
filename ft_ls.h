#ifndef FT_LS_H
#define FT_LS_H

///including allowed libraries
#include "libft/libft.h"
// #include <unistd.h>
#include <time.h>     //working with the time and the ctime functions
#include <dirent.h>   //working with the opendir, readdir and closedir functions
#include <sys/stat.h> //working with the stat function and lstat functions
#include <grp.h> //will be used to get the group
// #include <sys/types.h> //
#include <pwd.h>       //working with the passwd struct;
// #include <uuid/uuid.h> //working with the uuid_t data type
// #include <sys/xattr.h> //working with the listaxttr and the getxattr functions
// #include <stdlib.h>    //working with the malloc, exit and free functions
// #include <string.h>    //working with the strerror function
// #include <stdio.h>     //working with the perror function
// #include <errno.h>
// #define POTENTIAL_FLAG '-'
// #define HIDDEN_FILES 'a'
// #define FILE_DETAILS 'l'
// #define RECURSIVE_LS 'R'
// #define SORT_LAST_MODI 't'
// #define SORT_REV_LEXO 'r'

enum statusCodes
{
    INVALID_FLAG = -1,
    SUCCESS,
    VALID_FLAG,
    IS_FILE,
    IS_FOLDER,
    FAILED,
    FAILED_TO_READ_FILE_INFO
};

typedef struct s_flag_l
{
    int nLinks;
    int dirORfile;
    int sLink;
    int nBytes;
    char *last_modified;
    char *user;
    char *group;
    char *fileName;
    char *permits;
} t_flag_l;

typedef struct s_flags
{
    int l;
    int a;
    int r;
    int t;
    int R;
    int invalid;
    int valid;
    int dir_start;
} t_flags;

#include "stdio.h"//must go

//methods that are used to check the flags, files and dir's passed
//they only focus on error handling
struct s_flags flags_passed(char **argv);
int count_valid(char **argv, struct s_flags *dirs);
char *flag_ret(char **flag);
int check_invalid(char *st);
int valid_file(char *dir);
void order(char **argv);
void check_files(char **argv, struct s_flags dirs);
char **store_invalid(char **argv, struct s_flags dirs);
char **store_valid(char **argv, struct s_flags *dirs);
char **sort_(char **inv);
void check_files_val(char **argv, struct s_flags dirs);
struct s_flags check_errors(char **argv);
struct s_flags flags_help(char *argv, struct s_flags flags);
int count_invalid(char **argv, struct s_flags *dirs);
struct s_flags flags_(char **argv, int argc);
//method for the basic ls function
 struct s_flags sudo_main_basic(int argc, char **argv);
void basic_ls_(char** files, struct s_flags flags);
void basic_ls(int argc);
int check_main(char *file);
char **save_content(char *dir);
//methods that work with flags
void flag_a(char** files, struct s_flags flags);
char **flag_r(char **inv);
int sudo_main_a(int argc, char **argv,  struct s_flags flags);
int sudo_main_flags(int argc, char **argv, struct s_flags flags);
char **flag_t(char **inv);
//methoda for the -l flag
struct s_flag_l flag_l(char *file, char *dir);
void    l_display(char **files, struct s_flags flags, char *path);
char   *last_mod(char *content);
char    *user(char *content);
char  *group(char *content);
char  *permits(char *file);
int get_nLinks(char *content);
int is_file(int nlinks);
int nBytes(char *content);
void folders(struct s_flags flags, char **argv);
void display(char *files, struct s_flag_l props);

#endif