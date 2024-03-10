#pragma once

#include "parser.h"
#include <cstdio>
#include <cstdlib>

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

class ExitCommand : public Command {
public:
    ExitCommand(CommandData data)
        : Command("Exit", data) {};

    void executeCommand() override {
        exit(1);
    }
};

class StatusCommand : public Command {
public:
    StatusCommand(CommandData data)
        : Command("Status", data) {};

    void executeCommand() override {
        printf("Status\n");
        printf("   API Server: %s\n", true ? "Active" : "Not Active");
        printf("\nOther Information\n");
        printf("  Initialized: %s\n", true ? "Yes" : "No");
        printf("         Mode: %s\n", "Run Mode / Simulation Mode");
    }
};

class HelpCommand : public Command {
public:
    HelpCommand(CommandData data)
        : Command("Help", data) {};

    void executeCommand() override {
        printf("NYC Subway Challenge Server - Command Help\n");

        printf("\nInformation Commands:\n");
        printf("  status              Print the current status of different aspects of the server\n");

        printf("\nControl Commands:\n");
        printf("  enable <subsystem>  Enables a subsystem\n");
        printf("  disable <subsystem> Disables a subsystem\n");
        printf("  setmode <mode>      Sets the mode for the server\n");
    }
};

class UnknownCommand : public Command {
public:
    UnknownCommand(CommandData data)
        : Command("Unknown", data) {};

    void executeCommand() override {
        printf("Unknown command: '%s'\n", getCommandData()->args[0].c_str());
    }
};