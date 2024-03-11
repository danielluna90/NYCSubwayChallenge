#pragma once

#include <string>

class Subsystem {
public:
    Subsystem(std::string name)
        : m_Name(name) { }
    virtual ~Subsystem() = default;

    virtual void enable() = 0;
    virtual void disable() = 0;

private:
    std::string m_Name;
};