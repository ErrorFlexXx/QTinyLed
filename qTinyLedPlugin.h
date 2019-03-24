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

#pragma once

#include <QtUiPlugin/QDesignerCustomWidgetInterface>

/**
 * @brief The QLedPlugin class implements the DesignerCustomWidgetInterface.
 */
class QTinyLedPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetInterface")
    Q_INTERFACES(QDesignerCustomWidgetInterface)
public:
    explicit QTinyLedPlugin(QObject *parent = nullptr);

    /**
     * @brief isContainer returns if this widget can contain other widgets.
     */
    bool isContainer() const override;

    /**
     * @brief isInitialized returns if this widget has been initialized.
     */
    bool isInitialized() const override;

    /**
     * @brief icon returns an icon used by the designer for this widget.
     */
    QIcon icon() const override;

    /**
     * @brief domXml returns the default setting set of this widget.
     */
    QString domXml() const override;

    /**
     * @brief group returns the group this widget shall be shown in the designer.
     */
    QString group() const override;

    /**
     * @brief includeFile returns the include file used for ui files to use this widget.
     */
    QString includeFile() const override;

    /**
     * @brief name returns the widgets QObject name.
     */
    QString name() const override;

    /**
     * @brief toolTip may return a tooltip shown as default.
     */
    QString toolTip() const override;

    /**
     * @brief whatsThis returns a more detailed description of this widget.
     */
    QString whatsThis() const override;

    /**
     * @brief createWidget function to create a widget.
     * @return
     */
    QWidget *createWidget(QWidget *parent) override;

    /**
     * @brief initialize the initializing function for this widget.
     */
    void initialize(QDesignerFormEditorInterface *core) override;

private:
    bool initialized = false; //!< flag to remember if this widget has been initialized.
};
