cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wpedantic -g3 -ggdb -lpqxx -lpq")

project(db_social_network)

find_package(Boost)
include_directories(${Boost_INCLUDE_DIRS})

find_package(Wt REQUIRED Wt HTTP)

set(LOGIC ${PROJECT_SOURCE_DIR}/BackendServer/BackendLogic)
set(CREATOR ${PROJECT_SOURCE_DIR}/BackendServer/CommandCreator)
set(HANDLER ${PROJECT_SOURCE_DIR}/BackendServer/CommandHandler)
set(COMMANDS ${PROJECT_SOURCE_DIR}/BackendServer/Commands)
set(CONTROLLER ${PROJECT_SOURCE_DIR}/BackendServer/Controller)
set(DATABASE ${PROJECT_SOURCE_DIR}/BackendServer/Database)
set(MANAGERS ${PROJECT_SOURCE_DIR}/BackendServer/Managers)


add_library(back STATIC ${LOGIC}/BackendLogic.cpp
                        ${CREATOR}/CommandCreator.cpp
                        ${HANDLER}/CommandHandler.cpp
                        ${CONTROLLER}/Controller.cpp
                        ${DATABASE}/DataBaseConnection.cpp
                        ${MANAGERS}/CommentManager.cpp
                        ${MANAGERS}/UserManager.cpp
                        ${MANAGERS}/PostManager.cpp
                        ${COMMANDS}/AddComment.cpp
                        ${COMMANDS}/AddPost.cpp
                        ${COMMANDS}/AddUser.cpp
                        ${COMMANDS}/DeleteComment.cpp
                        ${COMMANDS}/DeletePost.cpp
                        ${COMMANDS}/DeleteUser.cpp
                        ${COMMANDS}/GetPost.cpp
                        ${COMMANDS}/GetTopPosts.cpp
                        ${COMMANDS}/GetUser.cpp
                        ${COMMANDS}/GetUserPosts.cpp
                        ${COMMANDS}/UpdatePostRating.cpp)

target_link_libraries(back ${Boost_LIBRARIES} Wt::Wt Wt::HTTP -lpqxx -lpq)
target_include_directories(back PUBLIC ${LOGIC} ${CREATOR} ${HANDLER} ${CONTROLLER}
                            ${DATABASE} ${MANAGERS} ${COMMANDS})