#pragma once

#include "../subsystems.h"

class APISubsystem : public Subsystem {
public:
    APISubsystem()
        : Subsystem("API") { }

private:
    bool enableImpl() override { return true; }
    void disableImpl() override { }
};