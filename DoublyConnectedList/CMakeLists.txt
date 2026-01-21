cmake_minimum_required (VERSION 3.10)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("DoublyConnectedList")

add_executable (DoublyConnectedList "TestTreiber.cpp"
        DoublyConnectedList.cpp
        DoublyConnectedList.h)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  target_compile_definitions(DoublyConnectedList PRIVATE _DEBUG)
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DoublyConnectedList PROPERTY CXX_STANDARD 20)
endif()
