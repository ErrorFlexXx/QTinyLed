# Copyright 2019 Christian Loepke
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

QT += widgets uiplugin

INCLUDEPATH += include

QTDIR_build {
    PLUGIN_TYPE         = designer
    PLUGIN_CLASS_NAME   = QTinyLedPlugin
    load(qt_plugin)
    CONFIG              += install_ok
} else {
    CONFIG              += plugin
    TEMPLATE            = lib

    HEADERS             =   include/qTinyLedPlugin.h \
                            include/qTinyLed.h

    SOURCES             =   src/qTinyLed.cpp \
                            src/qTinyLedPlugin.cpp

    QMAKE_PROJECT_NAME  =   widgets_qtinyled

    RESOURCES           +=  resources.qrc

    TARGET              = $$qtLibraryTarget($$TARGET)

    target.path         = $$[QT_INSTALL_PLUGINS]/designer

    headers.path        = $$[QT_INSTALL_HEADERS]/QTinyLed
    headers.files       += include/qTinyLed.h

    INSTALLS += target headers
}
