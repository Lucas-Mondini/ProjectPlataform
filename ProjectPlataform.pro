TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/pptexturemanager.cpp \
    src/GameSrc/Map/map.cpp \
           src/main.cpp \
           src/tools.cpp \

win32: LIBS += -LF:/SDL2-2.0.12Mingw/i686-w64-mingw32/lib/ -lSDL2

INCLUDEPATH += src

INCLUDEPATH += F:/SDL2-2.0.12Mingw/i686-w64-mingw32/include
DEPENDPATH += F:/SDL2-2.0.12Mingw/i686-w64-mingw32/include


HEADERS += headers/tools.h \
    headers/Game/map.h \
    headers/pptexturemanager.h\

DISTFILES += \
    assets/grass.bmp
