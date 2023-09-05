#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void list_dir(const char *dirname) {
    // 打开目录
    DIR *dp;
    dp = opendir(dirname);

    // 遍历目录
    struct dirent *dirp;
    while ((dirp = readdir(dp)) != NULL) {
        // 判断是否为目录
        if (dirp->d_type & DT_DIR) {
            // 是目录，递归访问
            //
            if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0) {
                continue;
            }
            char full_dir_path[1024];
            snprintf(full_dir_path, sizeof(full_dir_path), "%s/%s", dirname, dirp->d_name);
            list_dir(full_dir_path);
        } else {
            // 不是目录，打印文件名
            printf("%s\n", dirp->d_name);
        }
    }

    // 关闭目录
    closedir(dp);
}

int main(int argc, char ** argv) {
    if(argc != 2){
        printf("usage: ./scandir dir_full_name\n");
        exit(-1);
    }

    list_dir(argv[1]);
    return 0;
}
