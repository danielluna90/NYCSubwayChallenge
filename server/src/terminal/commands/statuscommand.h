#pragma once

#include "../command.h"

class StatusCommand : public Command {
public:
    explicit StatusCommand(CommandData data)
        : Command("Status", std::move(data)) {};

    void executeCommand() override {
        printf("Subsystems:\n");
        printf("   API Server: %s\n", true ? "Active" : "Not Active");
        printf("\nOther Information\n");
        printf("  Initialized: %s\n", true ? "Yes" : "No");
        printf("         Mode: %s\n", "Run Mode / Simulation Mode");
    }
};