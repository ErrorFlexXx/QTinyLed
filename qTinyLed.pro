# Copyright 2019 Christian Löpke
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

QTDIR_build {
    PLUGIN_TYPE         = designer
    PLUGIN_CLASS_NAME   = QTinyLedPlugin
    load(qt_plugin)
    CONFIG              += install_ok
} else {
    CONFIG              += plugin
    TEMPLATE            = lib

    HEADERS             =   qTinyLedPlugin.h \
                            qTinyLed.h

    SOURCES             =   qTinyLed.cpp \
                            qTinyLedPlugin.cpp

    QMAKE_PROJECT_NAME  =   widgets_qtinyled

    RESOURCES           +=  resources.qrc

    TARGET              = $$qtLibraryTarget($$TARGET)

    target.path         = $$[QT_INSTALL_PLUGINS]/designer

    INSTALLS += target

    unix  {
        headers.path        = /usr/include/QTinyLed
        headers.files       += qTinyLed.h
        INSTALLS            += headers
    }
}
