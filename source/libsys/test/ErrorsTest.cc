/*  Copyright (C) 2012-2020 by László Nagy
    This file is part of Bear.

    Bear is a tool to generate compilation database for clang tooling.

    Bear is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Bear is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "gtest/gtest.h"

#include "Errors.h"

#include <cerrno>

namespace {

    TEST(errors, success)
    {
        auto result = sys::error_string(0);

        EXPECT_STREQ("Success", result.data());
    }

    TEST(errors, ENOENT)
    {
        auto result = sys::error_string(ENOENT);

        EXPECT_STREQ("No such file or directory", result.data());
    }
}