file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${vectorTest} ${srcs} ${hdrs})
target_link_libraries(${vectorTest} ${vectorLib} gtest)
