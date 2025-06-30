# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/Users/masonjohnson/Projects/Cpp/MPC/build/_deps/readerwriterqueue-src")
  file(MAKE_DIRECTORY "/Users/masonjohnson/Projects/Cpp/MPC/build/_deps/readerwriterqueue-src")
endif()
file(MAKE_DIRECTORY
  "/Users/masonjohnson/Projects/Cpp/MPC/build/_deps/readerwriterqueue-build"
  "/Users/masonjohnson/Projects/Cpp/MPC/build/_deps/readerwriterqueue-subbuild/readerwriterqueue-populate-prefix"
  "/Users/masonjohnson/Projects/Cpp/MPC/build/_deps/readerwriterqueue-subbuild/readerwriterqueue-populate-prefix/tmp"
  "/Users/masonjohnson/Projects/Cpp/MPC/build/_deps/readerwriterqueue-subbuild/readerwriterqueue-populate-prefix/src/readerwriterqueue-populate-stamp"
  "/Users/masonjohnson/Projects/Cpp/MPC/build/_deps/readerwriterqueue-subbuild/readerwriterqueue-populate-prefix/src"
  "/Users/masonjohnson/Projects/Cpp/MPC/build/_deps/readerwriterqueue-subbuild/readerwriterqueue-populate-prefix/src/readerwriterqueue-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/masonjohnson/Projects/Cpp/MPC/build/_deps/readerwriterqueue-subbuild/readerwriterqueue-populate-prefix/src/readerwriterqueue-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/masonjohnson/Projects/Cpp/MPC/build/_deps/readerwriterqueue-subbuild/readerwriterqueue-populate-prefix/src/readerwriterqueue-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
