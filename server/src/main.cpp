#include <iostream>
#include <string>

#include "commands/parser.h"

int main() {
    bool shouldExit = false;

    CommandParser commandParser;

    while (!shouldExit) {
        std::string input;

        printf("> ");
        std::getline(std::cin, input);

        Command command = commandParser.parse(input);

        if (command.type == COMMAND_STATUS) {
            printf("Status\n");
            printf("   API Server: %s\n", true ? "Active" : "Not Active");
            printf("\nOther Information\n");
            printf("  Initialized: %s\n", true ? "Yes" : "No");
            printf("         Mode: %s\n", "Run Mode / Simulation Mode");
        } else if (command.type == COMMAND_EXIT) {
            exit(1);
        } else if (command.type == COMMAND_HELP) {
            printf("NYC Subway Challenge Server - Command Help\n");

            printf("\nInformation Commands:\n");
            printf("  status              Print the current status of different aspects of the server\n");

            printf("\nControl Commands\n");
            printf("  enable <subsystem>  Enables a subsystem\n");
            printf("  disable <subsystem> Disables a subsystem\n");
            printf("  setmode <mode>      Sets the mode for the server\n");
        } else {
            printf("Unknown command: '%s'\n", input.c_str());
        }

        printf("\n");
    }

    return 0;
}
