#pragma once

#include <cstdio>
#include <cstdlib>
#include <utility>

#include "parser.h"

class Command {
public:
    Command(std::string commandName, CommandData data)
        : m_CommandName(std::move(commandName))
        , m_Data(std::move(data)) {};
    virtual ~Command() = default;

    virtual void executeCommand() = 0;

    CommandData* getCommandData() { return &m_Data; }
    [[nodiscard]] std::string getCommandName() const { return m_CommandName; }

private:
    const std::string m_CommandName;
    CommandData m_Data;
};