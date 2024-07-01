#include "../include/cub.h"

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        validate(argv[1]);
        init_game(argv[1]);
    }
}
