cmake_minimum_required(VERSION 3.8)
set (CMAKE_CXX_STANDARD 14)

project(server_tp)

find_package(Boost)
include_directories(${Boost_INCLUDE_DIRS})

set(SERVER ${PROJECT_SOURCE_DIR}/src/Server)
set(CONNECTION ${PROJECT_SOURCE_DIR}/src/Connection)
set(HANDLERS ${PROJECT_SOURCE_DIR}/src/MainLogic/Handlers)
set(ROUTER ${PROJECT_SOURCE_DIR}/src/MainLogic/Router)
set(REQUEST ${PROJECT_SOURCE_DIR}/src/MainLogic/Request)
set(RESPONSE ${PROJECT_SOURCE_DIR}/src/MainLogic/Response)

add_library(server STATIC ${SERVER}/server.cpp
            ${CONNECTION}/connection.cpp
            ${ROUTER}/router.cpp
            ${REQUEST}/request.cpp
            ${RESPONSE}/response.cpp
            ${HANDLERS}/src/database_handler.cpp
            ${HANDLERS}/src/page_handler.cpp
            ${HANDLERS}/src/theme_handler.cpp
            ${HANDLERS}/src/user_handler.cpp
            )

target_link_libraries(server ${Boost_LIBRARIES})
target_include_directories(server PUBLIC ${SERVER} ${CONNECTION} ${REQUEST} ${RESPONSE} ${ROUTER} ${HANDLERS}/inc)