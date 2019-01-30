#include <stdio.h>

#include "os/os.h"
#include "db/db.h"

int main(int argc, char *argv[]) {
    OS::OSReport("Hello World!\n", NULL);

    __int32_t u1 = NULL;    // TODO: call to function "80005340"    args (void)
                            // TODO: call to function "8000541c"    args (u1)
                            // TODO: call to function "8000535c"    args (void)

    DB::DBInit();
                            // TODO: call to function "80342fc8"    args (void)
                            
                            // TODO: call to function "check_pad3"  args (void)
    return 0;
}