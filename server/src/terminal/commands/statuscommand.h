#pragma once

#include "../command.h"

#include "core/core.h"
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
        printf("  Initialized: %s\n", ServerOptions::GetInstance()->isInitialized() ? "Yes" : "No");
        printf("         Mode: %s\n", "Run Mode / Simulation Mode");
    }
};