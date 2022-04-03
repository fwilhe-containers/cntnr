#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* A simple error-handling function: print an error message based
   on the value in 'errno' and terminate the calling process */
#define errExit(msg)                                                           \
  do {                                                                         \
    perror(msg);                                                               \
    exit(EXIT_FAILURE);                                                        \
  } while (0)

static void usage(char *pname) {
  fprintf(stderr, "Usage: %s [options] program [arg...]\n", pname);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
  int flags;
  flags = 0;
  // flags |= CLONE_NEWCGROUP;
  // flags |= CLONE_NEWIPC;
  // flags |= CLONE_NEWNS;
  // flags |= CLONE_NEWNET;
  // flags |= CLONE_NEWPID;
  // flags |= CLONE_NEWTIME;
  // flags |= CLONE_NEWUTS;
  flags |= CLONE_NEWUSER;

  if (optind >= argc)
    usage(argv[0]);
  if (unshare(flags) == -1)
    errExit("unshare");
  execvp(argv[optind], &argv[optind]);
  errExit("execvp");
}