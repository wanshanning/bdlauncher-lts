#include <stdio.h>
#include "../base/base.h"
#include "../base/utils.h"
#include "Loader.h"
#include <thread>
#include "logger.h"

const char meta[] __attribute__((used, section("meta"))) =
    "name:moeclean\n"
    "version:20200222\n"
    "author:thirteenc13\n"
    "depend:base@20200121\n";

extern "C"
{
    BDL_EXPORT void mod_init(std::list<string> &modlist);
}
extern void load_helper(std::list<string> &modlist);

int sec = 0;
int min = 0;

class cleantime
{
public:
    void clock()
    {
        sec++;
        // printf("sec=%d\n", sec);
        if(sec == 60)
        {
            sec = 0;
            min++;
            // printf("min=%d\n", min);
            run(min);
            if (min == 60)
            {
                min == 0;
            }
        }
    }
private:
    void run(int min)
    {
        if(getPlayerCount() > 5) return;// not action when the player count less than 5
        if(min == 9)
        {
            // printf("run()\n");
            broadcastText("§a[MoeClean] I will clean items on the ground after 1 minute.");
            return;
        }
        if(min == 10) clean();
    }

    void clean()
    {
        // printf("clean()\n");
        broadcastText("§a[MoeClean] Start cleanning items on the ground.");
        runcmd("kill @e[type=item]");
    }
};


static int tkl;
THook(void *, _ZN5Level4tickEv, Level &a) {
  tkl++;
  if (tkl % 20 == 0) cleantime().clock();
  return original(a);
}

void mod_init(std::list<string> &modlist)
{
    do_log("MoeClean loaded");
    load_helper(modlist);
}