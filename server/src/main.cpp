#include <iostream>
#include <memory>
#include <string>

#include "core/core.h"
#include "terminal/command.h"
#include "terminal/commands.h"
#include "terminal/parser.h"

int main() {
    CommandParser commandParser;
    OptionsState optionsState;

    while (true) {
        std::string input;

        printf("> ");
        std::getline(std::cin, input);

        CommandData commandData = commandParser.parse(input);
        commandData.optionsState = &optionsState;

        std::unique_ptr<Command> command = std::make_unique<UnknownCommand>(commandData);

        if (commandData.type == COMMAND_STATUS) {
            command = std::make_unique<StatusCommand>(commandData);
        } else if (commandData.type == COMMAND_EXIT) {
            command = std::make_unique<ExitCommand>(commandData);
        } else if (commandData.type == COMMAND_HELP) {
            command = std::make_unique<HelpCommand>(commandData);
        }

        command->executeCommand();

        printf("\n");
    }

    return 0;
}
