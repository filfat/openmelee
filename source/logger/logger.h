#pragma once

#include <iostream>
#include <stdarg.h>

namespace Logger {
    void Info (const char *scope, const char *out, va_list args);
}