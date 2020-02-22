#include "../command/command.h"
#include "../command/parameter.h"

using namespace BDL::CustomCommand;

command_register_function register_commands();

class mapcommand : public CustomCommandContext
{
public:
    static constexpr auto cmd_name = "map";
    static constexpr auto description = "Create a customize map";
    static constexpr auto permission = CommandPermissionLevel::OP;

    mapcommand(CommandOrigin const &origin, CommandOutput &output) noexcept : CustomCommandContext(origin, output) {}

    void oncmd(mandatory<std::string> filename);
};