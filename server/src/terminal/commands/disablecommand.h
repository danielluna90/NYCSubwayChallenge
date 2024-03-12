#pragma once

#include "../command.h"

#include "subsystems/manager.h"
#include "subsystems/subsystem.h"

class DisableCommand: public Command {
public:
    explicit DisableCommand(CommandData data) : Command("Disable", std::move(data)) {}

    void executeCommand() override {
        Subsystem* subsystem = SubsystemManager::GetInstance()->getSubsystem(getCommandData()->args[0]);

        if (subsystem == nullptr) {
            printf("`%s` is not a valid subsystem\n", getCommandData()->args[0].c_str());
        } else if (!subsystem->isEnabled()) {
            printf("`%s` is not an active subsystem\n", getCommandData()->args[0].c_str());
        } else {
            subsystem->disable();
        }
    }
};