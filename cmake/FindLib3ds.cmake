# - Find lib3ds
# Find the lib3ds model access library
#
#  Lib3ds::Lib3ds - Imported target to use
#  Lib3ds_FOUND - True if lib3ds was found.
#
# Original Author:
# 2019 Ryan Pavlik <ryan.pavlik@collabora.com> <ryan.pavlik@gmail.com>
#
# Copyright 2019, Collabora, Ltd.
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)
#
# SPDX-License-Identifier: BSL-1.0

set(Lib3ds_ROOT_DIR
    "${Lib3ds_ROOT_DIR}"
    CACHE PATH "Directory to search for lib3ds")
find_path(
    Lib3ds_INCLUDE_DIR
    NAMES lib3ds/types.h
    PATHS "${Lib3ds_ROOT_DIR}")
find_library(
    Lib3ds_LIBRARY
    NAMES 3ds 3ds-1
    PATHS "${Lib3ds_ROOT_DIR}")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Lib3ds DEFAULT_MSG Lib3ds_INCLUDE_DIR
                                  Lib3ds_LIBRARY)

if(Lib3ds_FOUND)
    if(NOT TARGET Lib3ds::Lib3ds)
        add_library(Lib3ds::Lib3ds UNKNOWN IMPORTED)
        set_target_properties(
            Lib3ds::Lib3ds
            PROPERTIES IMPORTED_LOCATION "${Lib3ds_LIBRARY}"
                       INTERFACE_INCLUDE_DIRECTORIES "${Lib3ds_INCLUDE_DIR}")
    endif()
    set(Lib3ds_INCLUDE_DIRS ${Lib3ds_INCLUDE_DIR})
    set(Lib3ds_LIBRARIES ${Lib3ds_LIBRARY})
    mark_as_advanced(Lib3ds_ROOT_DIR)
endif()

mark_as_advanced(Lib3ds_INCLUDE_DIR Lib3ds_LIBRARY)
