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

#include <QtWidgets>
#include "qTinyLed.h"

QTinyLed::QTinyLed(QWidget *parent)
    : QWidget(parent)
    , isOn(false)
    , isClickable(false)
    , shape(Elipse)
{
    blink.timer.connect(&blink.timer, SIGNAL(timeout()), this, SLOT(blinkTimeout()));
    blink.timer.setInterval(500);
}

void QTinyLed::toggle()
{
    isOn = !isOn;
    repaint();
}

void QTinyLed::blinkTimeout()
{
    blink.value = !blink.value;
    repaint();
}

void QTinyLed::paintEvent(QPaintEvent *)
{
    const QColor& paintColor = colors.get(blink.value && isOn);

	QPainter painter(this);
	QColor black(0, 0, 0);
    QPoint center(width() / 2, height() / 2);

    QRadialGradient grad;
    if(shape != Triangle)
        grad = QRadialGradient(QPointF(width() / 3, height() / 3), center.x() / 2);
    else //Triangle exception: 1/3 light reflex would be out of led here. So here is the 1/2 tri exception.
        grad = QRadialGradient(QPointF(width() / 2, height() / 2), center.x() / 2);

    grad.setColorAt(0.f, paintColor.lighter(150));
    grad.setColorAt(1.f, paintColor);

    painter.setPen(black);
    painter.setBrush(grad);

    switch(shape)
    {
    case Elipse:
    {
        painter.drawEllipse(center, center.x() - 1, center.y() - 1);
        break;
    }
    case Rect:
    {
        painter.drawRect(0, 0, width(), height());
        break;
    }
    case RoundRect:
    {
        painter.drawRoundRect(0, 0, width(), height(), 25, 25);
        break;
    }
    case Triangle:
    {
        QRectF rect = QRectF(0, 0, width(), height());
        QPainterPath path;

        path.moveTo(rect.left() + (rect.width() / 2), rect.top());
        path.lineTo(rect.bottomLeft());
        path.lineTo(rect.bottomRight());
        path.lineTo(rect.left() + (rect.width() / 2), rect.top());

        painter.fillPath(path, QBrush(grad));
        break;
    }
    }
}

void QTinyLed::mousePressEvent(QMouseEvent *event)
{
    if(isClickable && event->button() == Qt::MouseButton::LeftButton)
        toggle();
}
