#include "manager.h"

#include <cstdio>

SubsystemManager* SubsystemManager::m_Instance { nullptr };
std::mutex SubsystemManager::m_Mutex;

SubsystemManager* SubsystemManager::GetInstance() {
    std::lock_guard<std::mutex> lock(m_Mutex);
    if (m_Instance == nullptr) {
        m_Instance = new SubsystemManager();
    }
    return m_Instance;
}

void SubsystemManager::registerSubsystem(std::unique_ptr<Subsystem> subsystem) {
    printf("Registering '%s' Subsystem\n", subsystem->getName().c_str());
    m_Subsystems.emplace(subsystem->getName(), std::move(subsystem));
}

Subsystem* SubsystemManager::getSubsystem(const std::string &subsystem) {
    try {
        return m_Subsystems.at(subsystem).get();
    } catch (const std::out_of_range &e) {
        return nullptr;
    }
}