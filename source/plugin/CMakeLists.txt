

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/obj)
file(GLOB plugins
  "src/*.cpp"
)

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}/inc
  ${CMAKE_SOURCE_DIR}/inc
)


message(---names of plugins---)
foreach(s ${plugins})
  get_filename_component(n ${s} NAME_WE)
  message(${n})
  add_library(${n} SHARED ${s})
endforeach(s)
message(===names of plugins===)
