#include "Nextion.h"

NexNumber n0 = NexNumber(0, 8, "n0");

char buffer[100] = {0};

NexTouch *nex_listen_list[] =
{
&n0,
NULL
};

void n0PopCallback(void *ptr)
{
dbSerialPrintln("n0PopCallback");
n0.setValue(50);
}

void setup()
{
nexInit();
n0.attachPop(n0PopCallback);
}

void loop(void)
{
n0.setValue(90);
nexLoop(nex_listen_list);
}
