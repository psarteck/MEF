cmake_minimum_required(VERSION 3.12)

project(FEM LANGUAGES CXX Fortran)

# Définir la variable CMAKE_BUILD_TYPE sur Debug
# set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../)

# Ajouter d'autres options de compilation selon vos besoins
set(CMAKE_CXX_FLAGS "-I /opt/homebrew/include/eigen3/Eigen")

# Définition des fichiers sources
set(SOURCES
    src/Node.cpp
    src/Element.cpp
    src/Mesh.cpp
    src/Edge.cpp
    src/FEMParameters.cpp
    src/Quadrature.cpp
    src/FEMUtilities.cpp
    src/FEMProblem.cpp
    src/Solver.cpp
    src/FEMIntegrale.cpp
    src/FEMAssembly.cpp
    src/System.cpp
    fortran/affsmd.f
    fortran/affsmo.f
    fortran/affsol.f
    fortran/assmat.f
    fortran/cdesse.f
    fortran/impmpr.f
    fortran/ltlpr.f
    fortran/rsprl.f
    fortran/rspru.f
    fortran/tri.f
    main.cpp
    # testmain.cpp
    # testFortran.cpp
)

# Ajout des fichiers d'en-tête au projet
include_directories(include)

# Création de l'exécutable
add_executable(exeFEM ${SOURCES})

# Vous pouvez également ajouter d'autres configurations ici, par exemple :

# Si vous utilisez C++11 ou une version ultérieure, vous pouvez l'activer ainsi :
target_compile_features(exeFEM PRIVATE cxx_std_17)

# Si vous avez des bibliothèques externes à lier, vous pouvez le faire ainsi :
# target_link_libraries(VotreExecutable VotreBibliothequeExterne)


# Cible pour nettoyer les fichiers générés lors de la compilation
# add_custom_target(clean-all
#     COMMAND ${CMAKE_COMMAND} -P ${CMAKE_BINARY_DIR}/clean-all.cmake
# )

# Fichier CMake pour effectuer le nettoyage
# file(WRITE ${CMAKE_BINARY_DIR}/clean-all.cmake
#     "file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/CMakeFiles)\n"
#     "file(REMOVE ${CMAKE_BINARY_DIR}/CMakeCache.txt)\n"
#     "file(REMOVE ${CMAKE_BINARY_DIR}/Makefile)\n"
# )

# # Ajouter une commande personnalisée pour nettoyer à la fin de la construction
# add_custom_command(TARGET exeFEM POST_BUILD
#     COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean-all
# )


#

# cmake_minimum_required(VERSION 3.12)
# project(FEM)

# # Définir la variable CMAKE_BUILD_TYPE sur Debug
# # set(CMAKE_BUILD_TYPE Debug)

# # Ajouter d'autres options de compilation selon vos besoins
# set(CMAKE_CXX_FLAGS "-I /opt/homebrew/include/eigen3/Eigen")

# # Définition des fichiers sources
# set(SOURCES
#     src/Node.cpp
#     src/Element.cpp
#     src/Mesh.cpp
#     src/Edge.cpp
#     src/FEMParameters.cpp
#     src/Quadrature.cpp
#     src/FEMUtilities.cpp
#     src/FEMProblem.cpp
#     src/Solver.cpp
#     src/FEMIntegrale.cpp
#     testmain.cpp
# )

# # Ajout des fichiers d'en-tête au projet
# include_directories(include)

# # Création de l'exécutable
# add_executable(exeFEM ${SOURCES})

# # Vous pouvez également ajouter d'autres configurations ici, par exemple :

# # Si vous utilisez C++11 ou une version ultérieure, vous pouvez l'activer ainsi :
# target_compile_features(exeFEM PRIVATE cxx_std_11)

# # Si vous avez des bibliothèques externes à lier, vous pouvez le faire ainsi :
# # target_link_libraries(VotreExecutable VotreBibliothequeExterne)

# # Cible pour nettoyer les fichiers générés lors de la compilation
# add_custom_target(clean-all
#     COMMAND ${CMAKE_COMMAND} -P ${CMAKE_BINARY_DIR}/clean-all.cmake
# )

# # Fichier CMake pour effectuer le nettoyage
# file(WRITE ${CMAKE_BINARY_DIR}/clean-all.cmake
#     "file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/CMakeFiles)\n"
#     "file(REMOVE ${CMAKE_BINARY_DIR}/CMakeCache.txt)\n"
#     "file(REMOVE ${CMAKE_BINARY_DIR}/Makefile)\n"
# )

# # Ajouter une commande personnalisée pour nettoyer à la fin de la construction
# add_custom_command(TARGET exeFEM POST_BUILD
#     COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean-all
# )
