#include "../command/command.h"
#include "../command/parameter.h"

using namespace BDL::CustomCommand;

command_register_function register_commands();

enum class Cancel { cancel };
enum class Ac { ac };
enum class De { de };
enum class Gui { gui };
enum class CmdF { f };
enum class CmdT { t };

class TPACommand : public CustomCommandContext {
public:
  // inline static alias_list aliases  = {"tpa"};
  static constexpr auto cmd_name    = "tpa";
  static constexpr auto description = "Teleport";
  static constexpr auto permission  = CommandPermissionLevel::NORMAL;

  TPACommand(CommandOrigin const &origin, CommandOutput &output) noexcept : CustomCommandContext(origin, output) {}

  void CANCEL(mandatory<Cancel> cmd);
  void AC(mandatory<Ac> cmd);
  void DE(mandatory<De> cmd);
  void GUI(mandatory<Gui> cmd);
  void CMDF(mandatory<CmdF> cmd, mandatory<std::string> target);
  void CMDT(mandatory<CmdT> cmd, mandatory<std::string> target);
};