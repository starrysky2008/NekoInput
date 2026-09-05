add_library(NekoInput MODULE
        library.cpp
)

target_link_libraries(NekoInput PRIVATE
        Fcitx5::Core
)

configure_file(
        NekoInput.conf.in
        NekoInput.conf
        @ONLY
)

install(
        TARGETS NekoInput
        DESTINATION "${FCITX_INSTALL_LIBDIR}/fcitx5"
)

install(
        FILES "${CMAKE_CURRENT_BINARY_DIR}/NekoInput.conf"
        DESTINATION "${FCITX_INSTALL_PKGDATADIR}/addon"
)
