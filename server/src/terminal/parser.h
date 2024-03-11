#pragma once

#include <sstream>
#include <string>
#include <vector>

#include "../core/core.h"

enum CommandType {
    COMMAND_EXIT,
    COMMAND_HELP,

    COMMAND_STATUS,

    COMMAND_ENABLE,
    COMMAND_DISABLE,

    COMMAND_UNKNOWN,
};

struct CommandData {
    CommandType type;
    std::vector<std::string> args;
};

class CommandParser {
public:
    CommandData parse(std::string const& str);

private:
    static CommandType getCommandType(std::string const& str);
};