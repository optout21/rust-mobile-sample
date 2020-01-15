cmake_minimum_required (VERSION 3.4)
project (rust-greet-cpp)

# Include dirs:
# ${WALLET_CORE}/include -- public TrustWalletCore includes
# ${WALLET_CORE}/src -- internal TrustWalletCore files, for signer protobuf messages
# ${WALLET_CORE}/build/local/include) -- for protobuf includes
include_directories (${CMAKE_SOURCE_DIR}/../rustgreet/src)
link_directories (${CMAKE_SOURCE_DIR}/../rustgreet/target/debug)

find_library(GREET_LIB_FILE rustgreet PATH ${CMAKE_SOURCE_DIR}/../rustgreet/target/debug)
if (NOT GREET_LIB_FILE)
    message (FATAL_ERROR "Rust library not found.")
else ()
    message ("Rust library found  (${GREET_LIB_FILE})")
endif ()

# Create all libraries and executables in the root binary dir
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if (NOT CMAKE_BUILD_TYPE)
	set (CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif ()

if (WIN32)
	add_definitions (-D_WIN32_WINNT=0x0600
					-D_CRT_SECURE_NO_WARNINGS
					-DWINVER=0x0600
					-DWIN32_LEAN_AND_MEAN)
else ()
	add_compile_options (-Werror=switch)
endif ()

if (APPLE)
	set (PLATFORM_LINK_FLAGS "-framework Foundation -framework OpenCL")
elseif (WIN32)
	set (PLATFORM_LINK_FLAGS "/STACK:8000000") #provides 8MB default stack size for linux on windows
else ()
	set (PLATFORM_LINK_FLAGS "-static-libgcc -static-libstdc++")
endif ()

SET (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${PLATFORM_LINK_FLAGS}")

# sources of this exec
add_executable (rust-greet-cpp sample.cpp)

# link with our library, and default platform libraries
target_link_libraries (rust-greet-cpp rustgreet ${PLATFORM_LIBS})
