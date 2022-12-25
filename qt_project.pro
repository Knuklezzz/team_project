TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ritual.cpp \
    product.cpp \
    productlist.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ritual.h \
    product.h \
    productlist.h

