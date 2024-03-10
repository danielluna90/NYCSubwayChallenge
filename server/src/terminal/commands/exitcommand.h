#pragma once

#include "../command.h"

class ExitCommand : public Command {
public:
    ExitCommand(CommandData data)
        : Command("Exit", data) {};

    void executeCommand() override {
        exit(1);
    }
};