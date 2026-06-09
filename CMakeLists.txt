cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

include(FetchContent)

# Fetch OpenBootloader Middleware
FetchContent_Declare(
    openbootloader
    GIT_REPOSITORY git@github.com:STMicroelectronics/stm32-mw-openbl.git
    GIT_TAG v6.1.2
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/ext/openbootloader
)
FetchContent_MakeAvailable(openbootloader)

# Set the project name
set(CMAKE_PROJECT_NAME alim-controller-bl)

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
    ext/openbootloader/Core/openbl_core.c
    ext/openbootloader/Modules/Mem/openbl_mem.c
    ext/openbootloader/Modules/I2C/openbl_i2c_cmd.c
    ext/openbootloader/Interfaces/Patterns/COMMON/common_interface.c
    ext/openbootloader/Interfaces/Patterns/FLASH/flash_interface.c
    ext/openbootloader/Interfaces/Patterns/I2C/i2c_interface.c
    ext/openbootloader/Interfaces/Patterns/IWDG/iwdg_interface.c
    "ext/openbootloader/Interfaces/Patterns/OPTION BYTES/optionbytes_interface.c"
    #ext/openbootloader/Interfaces/Patterns/OTP/otp_interface.c
    ext/openbootloader/Interfaces/Patterns/RAM/ram_interface.c
    "ext/openbootloader/Interfaces/Patterns/SYSTEM MEMORY/systemmemory_interface.c"
    OpenBootloader/Src/app_openbootloader.c
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
    ext/openbootloader/Core/
    ext/openbootloader/Modules/Mem
    ext/openbootloader/Modules/I2C
    ext/openbootloader/Interfaces/Patterns/COMMON
    ext/openbootloader/Interfaces/Patterns/FLASH
    ext/openbootloader/Interfaces/Patterns/I2C
    ext/openbootloader/Interfaces/Patterns/IWDG
    "ext/openbootloader/Interfaces/Patterns/OPTION BYTES"
    #ext/openbootloader/Interfaces/Patterns/OTP
    ext/openbootloader/Interfaces/Patterns/RAM
    "ext/openbootloader/Interfaces/Patterns/SYSTEM MEMORY"
    OpenBootloader/Inc
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Remove wrong libob.a library dependency when using cpp files
list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx

    # Add user defined libraries
)
