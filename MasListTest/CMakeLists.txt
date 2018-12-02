file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${MasListTest} ${srcs} ${hdrs})
target_link_libraries(${MasListTest} ${MasListLib} gtest)
