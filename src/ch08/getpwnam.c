// 8-2

#include <pwd.h>
#include <stdio.h>
#include <sys/types.h>

struct passwd *mGetpwnam(uid_t uid) {
    static struct passwd *pwd;
    while ((pwd = getpwent()) != NULL) {
        if (pwd->pw_uid == uid) {
            endpwent();
            return pwd;
        }
    }
    endpwent();
    return NULL;
}

int main() {
    struct passwd *pwd = mGetpwnam(1000);
    if (pwd != NULL) {
        printf("%-20s %5ld\n", pwd->pw_name, (long)pwd->pw_uid);
    }
    return 0;
}