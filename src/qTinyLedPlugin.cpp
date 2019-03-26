/* Copyright 2019 Christian Löpke
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "QTinyLed/qTinyLed.h"
#include "QTinyLed/qTinyLedPlugin.h"
#include <QtPlugin>

QTinyLedPlugin::QTinyLedPlugin(QObject *parent)
    : QObject(parent)
{
}

void QTinyLedPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (initialized)
        return;

    initialized = true;
}

bool QTinyLedPlugin::isInitialized() const
{
    return initialized;
}

QWidget *QTinyLedPlugin::createWidget(QWidget *parent)
{
    return new QTinyLed(parent);
}

QString QTinyLedPlugin::name() const
{
    return QStringLiteral("QTinyLed");
}

QString QTinyLedPlugin::group() const
{
    return QStringLiteral("Display Widgets");
}

QIcon QTinyLedPlugin::icon() const
{
    return QIcon(":/images/QTinyLed.ico");
}

QString QTinyLedPlugin::toolTip() const
{
    return QString();
}

QString QTinyLedPlugin::whatsThis() const
{
    return QString("A Led indicator widget to display a boolean value.");
}

bool QTinyLedPlugin::isContainer() const
{
    return false;
}

QString QTinyLedPlugin::domXml() const
{
    return "<ui language=\"c++\">\n"
           " <widget class=\"QTinyLed\" name=\"qTinyLed\">\n"
           "  <property name=\"geometry\">\n"
           "   <rect>\n"
           "    <x>0</x>\n"
           "    <y>0</y>\n"
           "    <width>50</width>\n"
           "    <height>50</height>\n"
           "   </rect>\n"
           "  </property>\n"
           "  <property name=\"toolTip\" >\n"
           "   <string>A led indicator</string>\n"
           "  </property>\n"
           "  <property name=\"whatsThis\" >\n"
           "   <string>The QTinyLed indicates boolean values.</string>\n"
           "  </property>\n"
           " </widget>\n"
           "</ui>\n";
}

QString QTinyLedPlugin::includeFile() const
{
    return QStringLiteral("QTinyLed/qTinyLed.h");
}
