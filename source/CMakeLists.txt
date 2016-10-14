cmake_minimum_required (VERSION 3.5)
set(module_name zamp_z1)
project (${module_name})

set(CMAKE_CXX_COMPILER clang++)

file(GLOB_RECURSE headers
  "inc/*.hh"
)
set(all_headers ${headers})

set (all_includes_dir)
foreach (_headerFile ${headers})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND all_includes_dir ${_dir})
endforeach()
list(REMOVE_DUPLICATES all_includes_dir)

file(GLOB_RECURSE sources
  "src/*.cpp"
)
set(all_sources ${sources})

add_custom_target(custom
  MESSAGE("custom target----")
  )


include_directories(${all_includes_dir})
add_executable(${module_name} ${all_sources})
