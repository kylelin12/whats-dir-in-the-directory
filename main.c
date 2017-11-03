#include "main.h"

int main() {
    char *dirpath = ".";
    DIR *dir;
    dir = opendir(dirpath);
    struct dirent *entry;

    printf("Statistics for directory:%s\n", dirpath);

    char dirs[4096];
    char files[4096];
    int filesize = 0;

    while (entry = readdir(dir)) {
        if (entry->d_type != DT_DIR && entry->d_type != 0) {
            strcat(files, "\t");
            strcat(files, entry->d_name);
            strcat(files, "\n");
        } else {
            strcat(dirs, "\t");
            strcat(dirs, entry->d_name);
            strcat(dirs, "\n");
        }
        filesize += entry->d_reclen;
    }
    printf("Total Diectory Size: %d Bytes\n", filesize);
    printf("Directories:\n");
    printf("%s\n", dirs);
    printf("Files:\n");
    printf("%s\n", files);

    closedir(dir);
    return 0;
}