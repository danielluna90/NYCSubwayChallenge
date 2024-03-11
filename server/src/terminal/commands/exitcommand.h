#pragma once

#include <utility>

#include "../command.h"

class ExitCommand : public Command {
public:
    explicit ExitCommand(CommandData data)
        : Command("Exit", std::move(data)) {};

    void executeCommand() override {
        exit(0);
    }
};