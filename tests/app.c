#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

int main(int argc, char *argv[]) {
    char hostname[10];
    gethostname(hostname, 10);
    char* username = getpwuid(getuid())->pw_name;

    printf("{\n");
    printf("  \"args\"    : \"%d\",\n", argc);
    printf("  \"uid\"     : \"%d\",\n", getuid());
    printf("  \"username\": \"%s\",\n", username);
    printf("  \"hostname\": \"%s\"\n", hostname);
    printf("}\n");

    return 0;
}