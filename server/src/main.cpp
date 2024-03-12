#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

#include "core/core.h"
#include "subsystems/manager.h"
#include "terminal/terminal.h"

int main() {
    CommandParser commandParser;
    SubsystemManager* subsystemManager = SubsystemManager::GetInstance();

    printf("Running Base Initialization\n");
    printf("\nRegistering Subsystems:\n");

    subsystemManager->registerSubsystem(std::make_unique<APISubsystem>());

    printf("\nReading Configuration from: %s\n", " ");
    printf("================================================\n");

    while (true) {
        std::string input;

        printf("> ");
        std::getline(std::cin, input);

        CommandData commandData = commandParser.parse(input);

        std::unique_ptr<Command> command = std::make_unique<UnknownCommand>(commandData);

        if (commandData.type == COMMAND_STATUS) {
            command = std::make_unique<StatusCommand>(commandData);
        } else if (commandData.type == COMMAND_ENABLE) {
            command = std::make_unique<EnableCommand>(commandData);
        } else if (commandData.type == COMMAND_EXIT) {
            command = std::make_unique<ExitCommand>(commandData);
        } else if (commandData.type == COMMAND_HELP) {
            command = std::make_unique<HelpCommand>(commandData);
        }

        command->executeCommand();

        printf("\n");
    }
}
