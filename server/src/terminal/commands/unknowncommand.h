#pragma once

#include "../command.h"

class UnknownCommand : public Command {
public:
    UnknownCommand(CommandData data)
        : Command("Unknown", data) {};

    void executeCommand() override {
        printf("Unknown command: '%s'\n", getCommandData()->args[0].c_str());
    }
};