#pragma once

#include <cstdio>
#include <cstdlib>

#include "parser.h"

class Command {
public:
    Command(std::string commandName, CommandData data)
        : m_CommandName(commandName)
        , m_Data(data) {};
    virtual ~Command() = default;

    virtual void executeCommand() = 0;

    CommandData* getCommandData() { return &m_Data; }
    std::string getCommandName() const { return m_CommandName; }

private:
    const std::string m_CommandName;
    CommandData m_Data;
};