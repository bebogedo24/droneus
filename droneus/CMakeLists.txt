cmake_minimum_required(VERSION 2.8.3)
project(droneus)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  sensor_msgs
  std_msgs
  tf
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES droneus
#  CATKIN_DEPENDS cv_bridge image_transport roscpp sensor_msgs std_msgs
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(image_converter src/image_converter.cpp)
target_link_libraries(image_converter 
  ${catkin_LIBRARIES}
)
add_dependencies(image_converter droneus_generate_messages_cpp)

add_executable(arTracker src/arTracker.cpp)
target_link_libraries(arTracker
  ${catkin_LIBRARIES}
)

add_executable(testz src/testz.cpp)
target_link_libraries(testz 
  ${catkin_LIBRARIES}
)
add_dependencies(testz droneus_generate_messages_cpp)

add_executable(test25 src/test25.cpp)
target_link_libraries(test25 
  ${catkin_LIBRARIES}
)
add_dependencies(test25 droneus_generate_messages_cpp)

add_executable(test1 src/test1.cpp)
target_link_libraries(test1 
  ${catkin_LIBRARIES}
)
add_dependencies(test1 droneus_generate_messages_cpp)

add_executable(test5 src/test5.cpp)
target_link_libraries(test5 
  ${catkin_LIBRARIES}
)
add_dependencies(test5 droneus_generate_messages_cpp)

add_executable(testRet src/testRet.cpp)
target_link_libraries(testRet 
  ${catkin_LIBRARIES}
)
add_dependencies(testRet droneus_generate_messages_cpp)

