#include "manager.h"

#include <cstdio>

void SubsystemManager::registerSubsystem(std::unique_ptr<Subsystem> subsystem) {
    printf("Registering '%s' Subsystem\n", subsystem->getName().c_str());
    m_Subsystems.emplace(subsystem->getName(), std::move(subsystem));
}