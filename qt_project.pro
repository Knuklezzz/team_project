TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ritual.cpp \
    product.cpp \
    productlist.cpp \
    productinputscreen.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ritual.h \
    product.h \
    productlist.h \
    productinputscreen.h

