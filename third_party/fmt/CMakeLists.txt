
message(STATUS "Looking for fmt dependency")
find_package(fmt 6.1 QUIET CONFIG)
if (fmt_FOUND)
    message(STATUS "Looking for fmt dependency -- found")
    add_custom_target(fmt_dependency)
else ()
    message(STATUS "Looking for fmt dependency -- not found")

    include(ExternalProject)
    ExternalProject_Add(fmt_dependency
            URL
                https://github.com/fmtlib/fmt/archive/7.0.2.tar.gz
            URL_HASH
                MD5=9555419b37f04db786eaf21a073db8e8
            DOWNLOAD_NO_PROGRESS
                1
            UPDATE_COMMAND
                ""
            LOG_CONFIGURE
                1
            LOG_BUILD
                1
            LOG_INSTALL
                1
            CMAKE_ARGS
                -DFMT_INSTALL:BOOL=ON
                -DFMT_TEST:BOOL=OFF
                -DFMT_FUZZ:BOOL=OFF
                -DFMT_DOC:BOOL=OFF
                -DCMAKE_INSTALL_PREFIX:PATH=${DEPENDENCIES_INSTALL_PREFIX}/fmt_dependency
            )

    include(GNUInstallDirs)
    list(APPEND PREFIX_PATH "${DEPENDENCIES_INSTALL_PREFIX}/fmt_dependency")
    set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};${PREFIX_PATH}
            CACHE PATH "append fmt library into the search path"
            FORCE)
endif ()
