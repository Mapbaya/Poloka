cmake_minimum_required(VERSION 3.10)
project(mini-blockchain)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

include_directories(
    ${CMAKE_SOURCE_DIR}/core
    ${CMAKE_SOURCE_DIR}/network
    ${CMAKE_SOURCE_DIR}/explorer
)

set(CORE_SOURCES
    core/blockchain.cpp
    core/block.cpp
    core/transaction.cpp
    core/wallet.cpp
    core/pow.cpp
)

set(NETWORK_SOURCES
    network/node.cpp
    network/peer.cpp
)

set(EXPLORER_SOURCES
    explorer/app.cpp
)

set(TEST_SOURCES
    tests/test_blockchain.cpp
    tests/test_pow.cpp
    tests/test_wallet.cpp
)

find_package(OpenSSL REQUIRED)

set(LIBS
    ${OPENSSL_LIBRARIES}
)

add_executable(node
    main.cpp
    ${CORE_SOURCES}
    ${NETWORK_SOURCES}
)

target_link_libraries(node ${LIBS})

add_executable(explorer
    explorer/main.cpp
    ${CORE_SOURCES}
    ${EXPLORER_SOURCES}
)

target_link_libraries(explorer ${LIBS})

