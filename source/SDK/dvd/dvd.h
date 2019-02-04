#pragma once

#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "../../libs/sfd/sfd.h"
#include "../os/os.h"

namespace DVD {
    int32_t DVDInit (void); // 80337de8
}