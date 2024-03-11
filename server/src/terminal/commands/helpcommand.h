#pragma once

#include <utility>

#include "../command.h"

class HelpCommand : public Command {
public:
    explicit HelpCommand(CommandData data)
        : Command("Help", std::move(data)) {};

    void executeCommand() override {
        printf("NYC Subway Challenge Server - Command Help\n");

        printf("\nInformation Commands:\n");
        printf("  status              Print the current status of different aspects of the server\n");

        printf("\nControl Commands:\n");
        printf("  enable <subsystem>  Enables a subsystem\n");
        printf("  disable <subsystem> Disables a subsystem\n");
        printf("  setmode <mode>      Sets the mode for the server\n");
    }
};