cmake_minimum_required (VERSION 3.5)
set(module_name zamp_z1)
project (${module_name})

set(CMAKE_CXX_COMPILER clang++)


set( flags "-std=c++11" )

set( flagsCoverage "${flagsCoverage} -Wall" )
set( flagsCoverage "${flagsCoverage} -pedantic" )
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${flags} ${flagsCoverage}" )

set( flagsLinker "${flagsLinker} -ldl")
set( flagsLinker "${flagsLinker} -lreadline")
set( flagsLinker "${flagsLinker} -ltermcap")
set( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${flagsLinker}" )



# make plugins
add_subdirectory(plugin)

# headers
include_directories(${CMAKE_BINARY_DIR}/inc/)

# plugins
link_directories(${CMAKE_BINARY_DIR}/plugin/obj)


file(GLOB_RECURSE sources
  "src/*.cpp"
)
set(all_sources ${sources})

include_directories(${all_includes_dir})
add_executable(${module_name} ${all_sources})


# link plugins
file(GLOB plugins
  "plugin/src/*.cpp"
)
foreach(s ${plugins})
  get_filename_component(n ${s} NAME_WE)
  set(plugins_names "${plugins_names} ${n}")
  message("plugins : " ${n})
  target_link_libraries(${module_name} ${n})
endforeach(s)
