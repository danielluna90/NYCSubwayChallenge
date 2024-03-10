#pragma once

#include <sstream>
#include <string>
#include <vector>

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
    CommandType getCommandType(std::string const& str);
};