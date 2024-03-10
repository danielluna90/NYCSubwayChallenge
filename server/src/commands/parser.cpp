#include "parser.h"
#include <string>

char const DELIMITER = ' ';

CommandData CommandParser::parse(std::string const& str) {
    bool isFirst = true;
    size_t pos = 0;

    std::stringstream ss(str);
    std::string token;

    CommandData command;
    command.type = COMMAND_UNKNOWN;
    command.args = {};

    while (std::getline(ss, token, DELIMITER)) {
        if (isFirst) {
            command.type = getCommandType(token);

            if (command.type == COMMAND_UNKNOWN) {
                command.args.push_back(token);
                break;
            }

            isFirst = false;
        } else {
            command.args.push_back(token);
        }
    }

    return command;
}

CommandType CommandParser::getCommandType(std::string const& str) {
    if (str == "exit") {
        return CommandType::COMMAND_EXIT;
    } else if (str == "help") {
        return CommandType::COMMAND_HELP;
    } else if (str == "status") {
        return CommandType::COMMAND_STATUS;
    } else if (str == "enable") {
        return CommandType::COMMAND_ENABLE;
    } else if (str == "disable") {
        return CommandType::COMMAND_DISABLE;
    }

    return CommandType::COMMAND_UNKNOWN;
}