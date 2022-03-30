#include <stdio.h>
#include <unistd.h>

int main() {
    char hostname[10];
    gethostname(hostname, 10);
    printf("uid: %d\n", getuid());
    printf("hostname: %s\n", hostname);
    return 0;
}