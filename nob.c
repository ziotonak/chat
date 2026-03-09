#define NOB_IMPLEMENTATION
#include "nob.h"

#define BUILD_FOLDER "build/"
#define SRC_FOLDER "src/"

int main(int argc, char **argv) {
    NOB_GO_REBUILD_URSELF(argc, argv);

    if (!nob_mkdir_if_not_exists(BUILD_FOLDER))
        return 1;

    Nob_Cmd cmd = {0};

    nob_cmd_append(&cmd, "cc", "-Wall", "-Wextra", "-lm", "-o", BUILD_FOLDER "main",
            SRC_FOLDER "main.c", SRC_FOLDER "sqlite3.c", SRC_FOLDER "sqlite-vec.c");

    if (!nob_cmd_run(&cmd))
        return 1;

    return 0;
}
