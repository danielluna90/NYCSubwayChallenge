#pragma once

#include "../subsystems.h"

class APISubsystem : public Subsystem {
public:
    APISubsystem()
        : Subsystem("API") { }

    void enable() override { }

    void disable() override { }
};