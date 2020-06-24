cmake_minimum_required(VERSION 3.16)
project(blockchain)

set(CMAKE_CXX_STANDARD 20)
include_directories(/usr/include/openssl/)
link_libraries(ssl)
link_libraries(crypto)
link_libraries(pthread)


add_executable(blockchain main.cpp block.cpp block.h blockchain.cpp blockchain.h hash.cpp hash.cpp hash.h transaction.cpp transaction.h user.cpp user.h miner.cpp miner.h semaphore.h)
