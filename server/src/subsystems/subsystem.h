#pragma once

#include <string>
#include <utility>

class Subsystem {
public:
    explicit Subsystem(std::string name)
        : m_Name(std::move(name)) { }
    virtual ~Subsystem() = default;

    void enable() { m_Enabled = enableImpl(); }
    void disable() { m_Enabled = false; disableImpl(); }

    bool isEnabled() { return m_Enabled; }

    std::string getName() const { return m_Name; }

private:
    virtual bool enableImpl() = 0;
    virtual void disableImpl() = 0;

private:
    bool m_Enabled = false;
    std::string m_Name;
};