cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME 381706-1-Karin-AllLabs) #Создаем обычную локальную переменную с именем проекта (имя solution)
project(${PROJECT_NAME}) # Название проекта

set(Vector Vector) #Переменная с именем библиотеки
set (VectorLib VectorLib)
set (vectorTest vectorTest)

set (Stack Stack)
set (StackLib StackLib)
set (StackTest StackTest)

set (Queue Queue)
set (QueueLib QueueLib)
set (QueueTest QueueTest)

set (List List)
set (ListLib ListLib)
set (ListTest ListTest)

set (StOnList StOnList)
set (StOnListLib StOnListLib)
set (StOnListTest StOnListTest)

set (MStack MStack)
set (MStackLib MStackLib)
set (MStackTest MStackTest)

set (MasList MasList)
set (MasListLib MasListLib)
set (MasListTest MasListTest)



set (Exeption Exeption)


set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()


 #Создаем проект с именем из переменной ${PROJECT_NAME}, в него добавляются файлы из переменных ${srcs} и ${hdrs}
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/VectorLib ${CMAKE_CURRENT_SOURCE_DIR}/StackLib ${CMAKE_CURRENT_SOURCE_DIR}/QueueLib ${CMAKE_CURRENT_SOURCE_DIR}/ListLib ${CMAKE_CURRENT_SOURCE_DIR}/StOnListLib ${CMAKE_CURRENT_SOURCE_DIR}/MStackLib ${CMAKE_CURRENT_SOURCE_DIR}/MasListLib ${CMAKE_CURRENT_SOURCE_DIR}/Exeption ${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(Vector) #Собираем проект в поддиректории lib1
add_subdirectory(VectorLib)
add_subdirectory(VectorTest)

add_subdirectory(Stack)
add_subdirectory(StackLib)
add_subdirectory(StackTest)

add_subdirectory (Queue)
add_subdirectory (QueueLib)
add_subdirectory (QueueTest)

add_subdirectory (List)
add_subdirectory (ListLib)
add_subdirectory (ListTest)

add_subdirectory (StOnList)
add_subdirectory (StOnListLib)
add_subdirectory (StOnListTest)

add_subdirectory (MStack)
add_subdirectory (MStackLib)
add_subdirectory (MStackTest)

add_subdirectory (MasList)
add_subdirectory (MasListLib)
add_subdirectory (MasListTest)



add_subdirectory (Exeption)
add_subdirectory(gtest)
#target_link_libraries(${PROJECT_NAME} ${MyLib1}) #Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}