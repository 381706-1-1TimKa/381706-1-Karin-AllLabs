file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${StOnListTest} ${srcs} ${hdrs})
target_link_libraries(${StOnListTest} ${StOnListLib} gtest)
