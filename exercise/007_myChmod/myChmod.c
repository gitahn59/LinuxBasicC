#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/errno.h>

extern int errno;

int main(int argc, char **argv){
    struct stat buf;

    if(argc!=2){
        printf("Usage : myChmod filename");
        exit(1);
    }

    if(access(argv[1],F_OK) == -1 && errno == ENOENT){
        printf("%s : File not exist.\n", argv[1]);
        exit(1);
    }

    stat(argv[1], &buf);

    printf("Inode = %d\n", (int)buf.st_ino);
    printf("Mode = %o\n", (unsigned int)buf.st_mode);
    printf("Nlink = %o\n",(unsigned int) buf.st_nlink);
    printf("UID = %d\n", (int)buf.st_uid);
    printf("GID = %d\n", (int)buf.st_gid);
    printf("SIZE = %d\n", (int)buf.st_size);
    printf("Atime = %d\n", (int)buf.st_atime);
    printf("Mtime = %d\n", (int)buf.st_mtime);
    printf("Ctime = %d\n", (int)buf.st_ctime);
    printf("Blksize = %d\n", (int)buf.st_blksize);
    printf("Blocks = %d\n", (int)buf.st_blocks);

    chmod(argv[1], 0700);
    return 0;
}