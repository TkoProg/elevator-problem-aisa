cmake_minimum_required(VERSION 3.25)
project(AiSA_Projekat LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AiSA_Projekat
        "src/main.cpp"
)

set_target_properties(AiSA_Projekat PROPERTIES LINKER_LANGUAGE CXX)

# Debug-only flags (symbols + DWARF-4 for LLDB)
target_compile_options(AiSA_Projekat PRIVATE
        $<$<CONFIG:Debug>:-O0 -g -gdwarf-4 -fno-omit-frame-pointer>
)

target_include_directories(AiSA_Projekat PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)
