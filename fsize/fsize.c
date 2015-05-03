#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#define   BUFSIZE       1024
#define   FILENAMESIZE  32

void fsize(char *, int);
void directory(char *, int);

int main(int argc, char *argv[]) {
    char buf[BUFSIZE];

    if (argc == 1) {    /* default: current directory */
        strcpy(buf, ".");
        fsize(buf, 0);
    } else
        while (--argc > 0) {
            strcpy(buf, *++argv);
            fsize(buf, 0);
        }
}

void fsize(char *name, int tab) {  /* print size for name */
    struct stat stbuf;
    int i;

    if (*(name+strlen(name)-1) == '/') *(name+strlen(name)-1) = '\0';
    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't find %s\n", name);
        return;
    }

    printf("%-7lldbytes\t", stbuf.st_size);
    for (i = 0; i < tab; i++) printf("  ");
    printf("%s\n", name);
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        directory(name, tab);
}

void directory(char *name, int tab) {    /* fsize for all files in name */
    struct dirent *dirbuf;
    char *nbp, *nep;
    int i;
    DIR *fd;

    nbp = name + strlen(name);
    *nbp++ = '/';
    if ((fd = opendir(name)) == NULL)
        return;
    while ((dirbuf = readdir(fd)) > 0) {
        if (dirbuf->d_ino == 0)  /* slot not in use */
            continue;
        if (strcmp(dirbuf->d_name, ".") == 0 || strcmp(dirbuf->d_name, "..") == 0)
            continue;   /* skip self and parent */
        for (i = 0, nep = nbp; i < FILENAMESIZE; i++)
            *nep++ = dirbuf->d_name[i];
        *nep++ = '\0';
        fsize(name, tab+1);
    }
    closedir(fd);
    *--nbp = '\0';
}
