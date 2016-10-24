

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/obj)
file(GLOB sources
  "src/*.cpp"
)
set(all_sources ${sources})

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}/inc
  ${CMAKE_SOURCE_DIR}/inc
)


message(---sources---)
foreach(s ${sources})
  get_filename_component(n ${s} NAME_WE)
  message(${n})
  add_library(${n} SHARED ${s})
endforeach(s)
message(===sources===)
