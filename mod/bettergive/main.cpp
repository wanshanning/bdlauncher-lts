#include "../base/base.h"
#include "../base/utils.h"
#include "bgive.command.h"
#include "logger.h"

const char meta[] __attribute__((used, section("meta"))) =
    "name:bettergive\n"
    "version:20200222\n"
    "author:thirteenc13\n"
    "depend:base@20200121,command@20200121\n";

extern "C"
{
    BDL_EXPORT void mod_init(std::list<string> &modlist);
}
extern void load_helper(std::list<string> &modlist);

void givecommand::oncmd(mandatory<std::string> target, mandatory<int> id, mandatory<int> data, mandatory<int> count)
{
    ItemStack* newitem = createItemStack(id, data, count);
    auto tgplayer = getplayer_byname2(target);
    if(tgplayer)
    {
        giveItem(*tgplayer, newitem);
        getOutput().success("Gave " + target + " item, ID:" + std::to_string(id) + ":" + std::to_string(data) + ":" + std::to_string(count));
    } else
    {
        getOutput().error("Failed");
    }
}

void mod_init(std::list<string> &modlist)
{
    load_helper(modlist);
    do_log("bettercommand v1.0.0 loaded");
    register_commands();
}