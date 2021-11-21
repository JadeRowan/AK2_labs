#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <iostream>

void help()
{
    std::cout <<
        "Program options:\n"
            "-a or --alpha                       - Prints \"Argument: alpha\"\n"
            "-b or --bravo                       - Prints \"Argument: alpha\"\n"
            "-c or --charlee                     - Prints \"Argument: alpha\"\n"   
            "-h or --help                        - Avaliable Args.\n"
    << std::endl;
}

int main(int argc, char **argv) {

    const char *options_short = "abch";
    
    static const struct option options_long[] {
        { "alpha", no_argument, nullptr, 'a'},
        { "bravo", no_argument, nullptr, 'b'},
        { "charlee", no_argument, nullptr, 'c'},
        { "help", no_argument, nullptr, 'h'},
        {nullptr, no_argument, nullptr, 0}
    };

    bool a_bool, b_bool, c_bool, h_bool = false;
    
    int index, code;

    while ((code = getopt_long(argc, argv, options_short, options_long, &index)) != -1) {
        switch (code) {
            case 'a': {
                if (!a_bool) {
                    a_bool = true;
                    printf("%s\n", "Argument: alpha");
                }
                break;
            }
            case 'b': {
                if (!b_bool) {
                    b_bool = true;
                    printf("%s\n", "Argument: bravo");
                }
                break;
            }
            case 'c': {
                if (!c_bool) {
                    c_bool = true;
                    printf("%s\n", "Argument: charlee");
                }
                break;
            }
            case 'h': {
                if (!h_bool) {
                    h_bool = true;
                    help();
                }
                break;
            }
            default: {
                printf("Invalid Argument!\n");
                return 0;
            }
        }
    }
    return 0;
}