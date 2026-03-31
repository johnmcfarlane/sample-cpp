module;

#include <fmt/printf.h>

export module fmt;

namespace fmt
{
    // Assumption: Clang-Tidy doesn't handle modules perfectly yet.
    // NOLINTNEXTLINE(misc-unused-using-decls)
    export using fmt::print;
}
