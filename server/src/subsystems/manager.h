#pragma once

#include "subsystems.h"

#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>

class SubsystemManager {
private:
    static SubsystemManager* m_Instance;
    static std::mutex m_Mutex;

protected:
    SubsystemManager() {};
    ~SubsystemManager() = default;

public:
    SubsystemManager(SubsystemManager& other) = delete;

    void operator=(SubsystemManager const&) = delete;

    static SubsystemManager* GetInstance();

    void registerSubsystem(std::unique_ptr<Subsystem> subsystem);
    Subsystem* getSubsystem(const std::string& subsystem);

    std::unordered_map<std::string, std::unique_ptr<Subsystem>>* getSubsystems() { return &m_Subsystems; }

private:
    std::unordered_map<std::string, std::unique_ptr<Subsystem>> m_Subsystems;
};