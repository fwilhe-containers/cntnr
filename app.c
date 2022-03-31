#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

int main(int argc, char *argv[]) {
    char hostname[10];
    gethostname(hostname, 10);
    printf("args    : %d\n", argc);
    printf("uid     : %d\n", getuid());
    printf("username: %s\n", getpwuid(getuid())->pw_name);
    printf("hostname: %s\n", hostname);
    return 0;
}