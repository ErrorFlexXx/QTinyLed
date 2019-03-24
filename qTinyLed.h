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

#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>
#include <QTimer>

class QDESIGNER_WIDGET_EXPORT QTinyLed : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(bool value READ getValue WRITE setValue)

    Q_PROPERTY(Shape shape READ getShape WRITE setShape)

    Q_PROPERTY(QColor onColor READ getOnColor WRITE setOnColor)

    Q_PROPERTY(QColor offColor READ getOffColor WRITE setOffColor)

    Q_PROPERTY(bool blinking READ getBlinking WRITE setBlinking)

    Q_PROPERTY(int blinkCycleMS READ getBlinkCycleMS WRITE setBlinkCycleMS)

    Q_PROPERTY(bool clickable READ getClickable WRITE setClickable)

public:
    QTinyLed(QWidget *parent = 0);

    enum Shape
    {
        Elipse = 0,
        Rect,
        RoundRect,
        Triangle
    };

    Q_ENUM(Shape)

    /**
     * @brief The StateColors struct contains all colors this object can have.
     */
    struct StateColors
    {
        /**
         * @brief get returns the current color for a given state.
         * @param state input state argument.
         * @return QColor const reference
         */
        const QColor& get(bool state) { if(state) return on; else return off; }

        QColor on  = QColor(0, 255, 0); //!< On Color component.
        QColor off = QColor(0, 50, 0);  //!< Off Color component.
    };

    /**
     * @brief The Blink struct contains variables required for the blink feature.
     */
    struct Blink
    {
        bool   value = true;    //!< Flag stating if blinking is currently enabled.
        QTimer timer;           //!< Timer used to change the led state after a setupped interval.
    };

    /**
     * @brief getValue getter for the current led state.
     * @return true, if the led is on, false otherwise.
     */
    bool getValue() const { return isOn; }

    /**
     * @brief setValue setter for the current led state.
     * @param value true, if the led shall be lit, false otherwise.
     */
    void setValue(const bool value) { isOn = value; repaint(); }

    /**
     * @brief toggle toggles the leds state.
     */
    void toggle();

    Shape getShape() const { return shape; }

    void setShape(Shape value) { shape = value; }

    /**
     * @brief getOnColor getter for the on color component.
     * @return QColor const reference of the on color.
     */
    const QColor& getOnColor() const { return colors.on; }

    /**
     * @brief setOnColor setter for the on color component.
     * @param onColor QColor to set as new on color.
     */
    void setOnColor(const QColor& onColor) { colors.on = onColor; }

    /**
     * @brief getOffColor getter for the off color component.
     * @return QColor const reference of the off color.
     */
    const QColor& getOffColor() const { return colors.off; }

    /**
     * @brief setOffColor setter for the off color component.
     * @param offColor QColor to set as new off color.
     */
    void setOffColor(const QColor& offColor) { colors.off = offColor; }

    /**
     * @brief getBlinking getter for the blink feature component.
     * @return true, if the led is blinking in lit state.
     */
    bool getBlinking() const { return blink.timer.isActive(); }

    /**
     * @brief setBlinking setter to control the blink feature of this led.
     * @param value true to activate, false to deactivate.
     */
    void setBlinking(bool value)
    {
        if(value)
        {
            blink.timer.setInterval(blink.timer.interval());
            blink.timer.start();
        }
        else
        {
            blink.timer.stop();
        }
        blink.value = value;
    }

    /**
     * @brief getBlinkCycleMS getter for the current blink cycle time.
     * @return milliseconds of one lit or unlit cycle.
     */
    int getBlinkCycleMS() const { return blink.timer.interval(); }

    /**
     * @brief setBlinkCycleMS setter for the curent blink cycle time.
     * @param cycleTimeMS milliseconds of one lit or unlit cycle.
     */
    void setBlinkCycleMS(int cycleTimeMS) { blink.timer.setInterval(cycleTimeMS); }

    /**
     * @brief getClickable returns if the led state can be changed with a mouse click.
     * @return true if enabled, false otherwise.
     */
    bool getClickable() const { return isClickable; }

    /**
     * @brief setClickable setter to enable led state toggle with a mouse click.
     * @param value true to enable click control, false otherwise.
     */
    void setClickable(bool value) { isClickable = value; }

protected:
    bool isOn;          //!< flag stating if the led shall signal the lit state.
    bool isClickable;   //!< flag stating if the led state can be toggled with mouse clicks.
    StateColors colors; //!< the color set of this led.
    Blink blink;        //!< struct with variables to implement the blink feature.
    Shape shape;        //!< shape of the led.

    /**
     * @brief paintEvent responsible to actually paint the led on the ui.
     * @param event QPaintEvent pointer.
     */
    void paintEvent(QPaintEvent *event) override;

    /**
     * @brief mousePressEvent mousePress Handler to react on mouse clicks and do something, if the feature is enabled.
     * @param event QMouseEvent structure containing information regarding the click (e.g. the MouseButton)
     */
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    /**
     * @brief blinkTimeout slot dealing with the blink timer timout to toggle the leds state.
     */
    void blinkTimeout();
};
