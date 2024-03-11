#pragma once

#include "subsystems.h"

#include <memory>
#include <string>
#include <unordered_map>

class SubsystemManager {
public:
    SubsystemManager() = default;

    void registerSubsystem(std::unique_ptr<Subsystem> subsystem);

private:
    std::unordered_map<std::string, std::unique_ptr<Subsystem>> m_Subsystems;
};