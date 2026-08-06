/*

typedef long int          off_t;
typedef unsigned int      useconds_t;
typedef unsigned int      uid_t;
typedef unsigned int      gid_t;


extern char **environ;
extern char  *optarg;
extern int    optind, opterr, optopt;


int      write(int __fd, const void *__buf, unsigned long int __n);
long int     read(int __fd, void *__buf, unsigned long int __nbytes);
int          close(int __fd);
off_t        lseek(int __fd, off_t __offset, int __whence);
int        fork(void);
int          execve(const char *__path, char *const __argv[], char *const __envp[]);
unsigned int sleep(unsigned int __seconds);
int          usleep(useconds_t __usec);
int          isatty(int __fd);
char        *getcwd(char *__buf, unsigned long int __size);
int          chdir(const char *__path);
int          unlink(const char *__name);
int          pipe(int __pipedes[2]);
int          dup(int __fd);
int          dup2(int __fd, int __fd2);
void         _exit(int __status);
*/

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 2147483647);
}