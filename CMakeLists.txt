cmake_minimum_required(VERSION 3.10)
project(mini-blockchain)

# TODO: Définir la version C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# TODO: Options de compilation
# - D pour les définitions
# - O2 pour l'optimisation en release
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# TODO: Inclure les répertoires source
include_directories(
    ${CMAKE_SOURCE_DIR}/core
    ${CMAKE_SOURCE_DIR}/network
    ${CMAKE_SOURCE_DIR}/explorer
)

# TODO: Sources core
set(CORE_SOURCES
    core/blockchain.cpp
    core/block.cpp
    core/transaction.cpp
    core/wallet.cpp
    core/pow.cpp
)

# TODO: Sources network
set(NETWORK_SOURCES
    network/node.cpp
    network/peer.cpp
)

# TODO: Sources explorer
set(EXPLORER_SOURCES
    explorer/app.cpp
)

# TODO: Sources tests
set(TEST_SOURCES
    tests/test_blockchain.cpp
    tests/test_pow.cpp
    tests/test_wallet.cpp
)

# TODO: Trouver les bibliothèques nécessaires
# OpenSSL pour la cryptographie
find_package(OpenSSL REQUIRED)

# TODO: Trouver d'autres bibliothèques si nécessaires
# - JSON (nlohmann/json, rapidjson)
# - HTTP (cpp-httplib, crow)
# - Threading (inclut dans C++17)

# TODO: Bibliothèques à linker
set(LIBS
    ${OPENSSL_LIBRARIES}
    # Ajouter d'autres bibliothèques ici
)

# TODO: Créer l'exécutable principal (nœud)
add_executable(node
    main.cpp  # TODO: Créer ce fichier avec la fonction main
    ${CORE_SOURCES}
    ${NETWORK_SOURCES}
)

target_link_libraries(node ${LIBS})

# TODO: Créer l'exécutable explorer
add_executable(explorer
    explorer/main.cpp  # TODO: Créer ce fichier
    ${CORE_SOURCES}
    ${EXPLORER_SOURCES}
)

target_link_libraries(explorer ${LIBS})

# TODO: Créer les tests (optionnel, selon votre framework de test)
# Exemple avec Google Test:
# find_package(GTest REQUIRED)
# add_executable(tests
#     ${TEST_SOURCES}
#     ${CORE_SOURCES}
# )
# target_link_libraries(tests ${LIBS} GTest::GTest GTest::Main)

# TODO: Configuration Release/Debug
# Par défaut, CMAKE_BUILD_TYPE est vide
# Pour compiler en Release: cmake -DCMAKE_BUILD_TYPE=Release ..
# Pour compiler en Debug: cmake -DCMAKE_BUILD_TYPE=Debug ..

