#include "main.h"

int main() {
    char *dirpath = ".";
    DIR *dir;
    dir = opendir(dirpath);
    struct dirent *entry;
    entry = readdir(dir);

    printf("Statistics for directory: %s\n", dirpath);

    int filesize = 0;

    char dirs[256];
    char files[256];
    
    while (entry = readdir(dir)) {
        if (entry->d_type == DT_DIR) {
            strcat(dirs, "\t");
            strcat(dirs, entry->d_name);
            strcat(dirs, "\n");
        } else {
            strcat(files, "\t");
            strcat(files, entry->d_name);
            strcat(files, "\n");
        }
    }

    printf("Directories:\n");
    printf("%s\n", dirs);
    printf("Files:\n");
    printf("%s\n", files);

    closedir(dir);
    return 0;
}