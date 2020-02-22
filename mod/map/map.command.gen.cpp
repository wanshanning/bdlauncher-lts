// Generated by scripts/generate_command_definition.py

#include "map.command.h"

struct mapcommand_0 : Command {
  CommandParameterProxy<std::string> filename;
  virtual void execute(CommandOrigin const &origin, CommandOutput &output) override {
    mapcommand context{origin, output};
    context.oncmd(filename);
  }
};

void register_commands() {
  auto &instance = CustomCommandRegistry::getInstance();
  {
    auto &cmd = instance.registerCommand<mapcommand>();
    {
      auto &ovl = cmd.registerOverload<mapcommand_0>();
      ovl.addParameter<std::string>("filename", false, offsetof(mapcommand_0, filename));
    }
  }
}
