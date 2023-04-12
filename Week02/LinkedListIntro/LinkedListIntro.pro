TEMPLATE = app
CONFIG += cmdline
CONFIG += c++17
CONFIG += strict_c++
CONFIG += no_include_pwd
CONFIG -= app_bundle
CONFIG -= qt
CONFIG -= debug_and_release

QMAKE_CXXFLAGS += -pedantic
QMAKE_CXXFLAGS += -pedantic-errors

#prevent warning from pragma used to suppress warnings from doctest.h
QMAKE_CXXFLAGS += -Wno-unknown-pragmas

QMAKE_CXXFLAGS += -Wmissing-include-dirs
QMAKE_CXXFLAGS += -Wfloat-equal
QMAKE_CXXFLAGS += -Wredundant-decls
QMAKE_CXXFLAGS += -Winit-self
QMAKE_CXXFLAGS += -Wshadow
QMAKE_CXXFLAGS += -Wconversion

#------------------------------

SOURCES += main.cpp

HEADERS += \
    Node.h

DISTFILES += \
    list.txt \
    nodeBasics.txt

