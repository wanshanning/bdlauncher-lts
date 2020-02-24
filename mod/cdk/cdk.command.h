#include "../command/command.h"
#include "../command/parameter.h"

using namespace BDL::CustomCommand;

command_register_function register_commands();

enum class Use { use };
enum class Reload { reload };

struct CdkCommand : CustomCommandContext
{
public:
    static constexpr auto cmd_name = "cdk";
    static constexpr auto description = "Using a cdkey";
    static constexpr auto permission = CommandPermissionLevel::NORMAL;

    CdkCommand(CommandOrigin const &origin, CommandOutput &output) noexcept : CustomCommandContext(origin, output) {}

    void usecmd(mandatory<Use> cmd, mandatory<std::string> cdk);
    void reload(mandatory<Reload> cmd);
};