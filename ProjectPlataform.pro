TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt



INCLUDEPATH += src



DISTFILES += \
    assets/grass.bmp \
    assets/idle/foxidle1.bmp \
    assets/idle/foxidle1.png \
    assets/idle/foxidle2.bmp \
    assets/idle/foxidle2.png \
    assets/idle/foxidle3.bmp \
    assets/idle/foxidle3.png \
    assets/idle/foxidle4.bmp \
    assets/idle/foxidle4.png \
    assets/idle/foxidle5.bmp \
    assets/idle/foxidle5.png \
    assets/idle/foxidle6.bmp \
    assets/idle/foxidle6.png \
    assets/idle/foxidle7.bmp \
    assets/idle/foxidle7.png \
    assets/idle/foxidle8.bmp \
    assets/idle/foxidle8.png \
    assets/idle/foxidle9.bmp \
    assets/idle/foxidle9.png \
    assets/run/foxrun1.bmp \
    assets/run/foxrun1.png \
    assets/run/foxrun2.bmp \
    assets/run/foxrun2.png \
    assets/run/foxrun3.bmp \
    assets/run/foxrun3.png \
    assets/run/foxrun4.bmp \
    assets/run/foxrun4.png \
    assets/run/foxrun5.bmp \
    assets/run/foxrun5.png \
    assets/run/foxrun6.bmp \
    assets/run/foxrun6.png \
    assets/run/foxrun7.bmp \
    assets/run/foxrun7.png \
    assets/run/foxrun8.bmp \
    assets/run/foxrun8.png


# aqui ficam as bibliotecas
win32: LIBS += -LI:/SDL2-2.0.12Mingw/i686-w64-mingw32/lib/ -lSDL2               #
                                                                                #
INCLUDEPATH += I:/SDL2-2.0.12Mingw/i686-w64-mingw32/include                     #
DEPENDPATH += I:/SDL2-2.0.12Mingw/i686-w64-mingw32/include                      #
                                                                                #
win32: LIBS += -LI:/SDL2_image-2.0.5Mingw/i686-w64-mingw32/lib/ -lSDL2_image    #
                                                                                #
INCLUDEPATH += I:/SDL2_image-2.0.5Mingw/i686-w64-mingw32/include                #
DEPENDPATH += I:/SDL2_image-2.0.5Mingw/i686-w64-mingw32/include                 #

HEADERS += \
    headers/Game/Collider/Collider.h \
    headers/Game/Controller.h \
    headers/Game/Entity.h \
    headers/Game/EntitySpawner.h \
    headers/Game/map.h \
    headers/pptexturemanager.h \
    headers/tools.h

SOURCES += \
    src/GameSrc/Collider/Collider.cpp \
    src/GameSrc/Controller/Controller.cpp \
    src/GameSrc/Map/map.cpp \
    src/GameSrc/Player/Entity.cpp \
    src/main.cpp \
    src/pptexturemanager.cpp \
    src/tools.cpp
