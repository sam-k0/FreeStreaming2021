TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        database.cpp \
        film.cpp \
        main.cpp \
        mediafile.cpp \
        serie.cpp

HEADERS += \
    database.h \
    film.h \
    main.h \
    mediafile.h \
    serie.h

DISTFILES += \
    database.txt
