
set (NAME Headless)
set (PLUGIN_NAME RenderSystem_${NAME})

file (GLOB SRC_FILES src/*.cpp)
file (GLOB H_FILES include/*.h)

ogre_add_library (${PLUGIN_NAME} ${OGRE_LIB_TYPE} ${SRC_FILES} ${H_FILES})

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries (${PLUGIN_NAME} OgreMain)

if (NOT OGRE_STATIC)
  set_target_properties (${PLUGIN_NAME} PROPERTIES COMPILE_DEFINITIONS "${PLUGIN_NAME}_EXPORTS")
endif ()

ogre_config_plugin (${PLUGIN_NAME})

install (FILES ${HEADER_FILES} DESTINATION include/OGRE/RenderSystems/${NAME})
