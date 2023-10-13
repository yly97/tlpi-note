// TODO：9-3

// #define  _DEFAULT_SOURCE
#include <tlpi_hdr.h>
#include <sys/types.h>
#include <unistd.h>
#include <grp.h>
#include <stdio.h>
#include <linux/limits.h>

#define SG_SIZE (NGROUPS_MAX + 1)

// 根据gid获取组名
char *groupNameFromId(gid_t gid) {
    struct group *grp = getgrgid(gid);
    return grp == NULL ? NULL : grp->gr_name;
}

// 根据组名获取gid
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

void testGetGroups() {
    gid_t gidList[SG_SIZE];
    int numGroups = getgroups(SG_SIZE, gidList);
    if (numGroups == -1) {
        errExit("getgroup");
    }
    
    for (int i = 0; i < numGroups; ++i) {
        struct group *grp = getgrgid(gidList[i]);
        printf("%s (%ld) ", grp == NULL ? "???" : grp->gr_name, (long)gidList[i]);
    }
    printf ("\n");
}

void testSetGroups() {
    size_t sz = 3;
    gid_t grps[3] = {1000, 1001, 1002};
    int ret = setgroups(sz, grps);
    if (ret == -1) {
        errExit("setgroups");
    }
}

void testInitGroups() {
    int ret = initgroups("leaf", 1001);
    if (ret == -1) {
        errExit("initgroups");
    }
}

int myInitGroups(const char *user, gid_t group) {

}

int main () {
    // testSetGroups();
    // testInitGroups();
    testGetGroups();
    printf("按任意键结束\n");
    getchar();
    exit(EXIT_SUCCESS);
}