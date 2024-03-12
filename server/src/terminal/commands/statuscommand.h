#pragma once

#include "../command.h"

#include "subsystems/subsystems.h"

class StatusCommand : public Command {
public:
    explicit StatusCommand(CommandData data)
        : Command("Status", std::move(data)) {};

    void executeCommand() override {
        printf("Subsystems:\n");

        SubsystemManager* subsystems = SubsystemManager::GetInstance();

        for (auto const& subsystem : *subsystems->getSubsystems()) {
            printf("  %s: %s\n", subsystem.second->getName().c_str(), subsystem.second->isEnabled() ? "Active" : "Not Active");
        }

        printf("\nOther Information\n");
        printf("  Initialized: %s\n", true ? "Yes" : "No");
        printf("         Mode: %s\n", "Run Mode / Simulation Mode");
    }
};