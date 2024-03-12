#pragma once

#include "../command.h"

#include "subsystems/subsystems.h"

class EnableCommand: public Command {
public:
    explicit EnableCommand(CommandData data) : Command("Enable", std::move(data)) {};

    void executeCommand() override {
        Subsystem* subsystem = SubsystemManager::GetInstance()->getSubsystem(getCommandData()->args[0]);

        if (subsystem == nullptr) {
            printf("`%s` is not a valid subsystem\n", getCommandData()->args[0].c_str());
        } else {
            subsystem->enable();

            if (!subsystem->isEnabled()) {
                printf("Could not enable `%s` subsystem\n", subsystem->getName().c_str());
            }
        }
    }
};
