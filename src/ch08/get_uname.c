#include <stdio.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>
#include <sys/types.h>
#include <shadow.h>

#include "ugid_functions.h"

char* userNameFromId(uid_t uid) {
    struct passwd *pwd = getpwuid(uid);
    return pwd == NULL ? NULL : pwd->pw_name;
}

uid_t userIdFromName(const char *name) {
    if (name == NULL || *name == '\0') {
        return -1;
    }

    char *endptr;
    uid_t uid = strtol(name, &endptr, 10);
    if (*endptr == '\0') {
        return uid;
    }
    
    struct passwd *pwd = getpwnam(name);
    return pwd == NULL ? -1 : pwd->pw_uid;
}

char *groupNameFromId(gid_t gid) {
    struct group *grp = getgrgid(gid);
    return grp == NULL ? NULL : grp->gr_name;
}

gid_t groupIdFromName(const char *name) {
    if (name == NULL || *name == '\0') {
        return -1;
    }

    char *endptr;
    gid_t gid = strtol(name, &endptr, 10);
    if (*endptr == '\0') {
        return gid;
    }
    
    struct group *grp = getgrnam(name);
    return grp == NULL ? -1 : grp->gr_gid;
}

int main() {
    struct passwd *pwd;

    while ((pwd = getpwent()) != NULL) {
        printf("%-20s %5ld\n", pwd->pw_name, (long)pwd->pw_uid);
    }
    // getpwent会自动打开密码文件，这里要关闭密码文件
    endpwent();

    puts("=============================");

    struct group *grp;
    while ((grp = getgrent()) != NULL) {
        printf("%-20s %5ld\n", grp->gr_name, (long)grp->gr_gid);
    }
    // getgrent会自动打开密码文件，这里要关闭密码文件
    endgrent();

    puts("=============================");
    
    // 貌似权限问题访问不了
    struct spwd *sp;
    while ((sp = getspent()) != NULL) {
        printf("%-20s %s\n", sp->sp_namp, sp->sp_pwdp);
    }
    return 0;
}