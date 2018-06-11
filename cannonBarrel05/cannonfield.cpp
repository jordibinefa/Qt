 /****************************************************************************
 **
 ** Copyright (C) 2005-2008 Nokia Corporation and/or its subsidiary(-ies). All rights reserved.
 **
 ** This file is part of the documentation of the Qt Toolkit.
 **
 ** Licensees holding a valid Qt License Agreement may use this file in
 ** accordance with the rights, responsibilities and obligations
 ** contained therein.  Please consult your licensing agreement or
 ** contact qt-sales@nokia.com if any conditions of this licensing
 ** agreement are not clear to you.
 **
 ** Further information about Qt licensing is available at:
 ** http://trolltech.com/products/appdev/licensing.
 **
 ** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 ** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 **
 ****************************************************************************/

 #include <QPainter>

 #include "cannonfield.h"

 CannonField::CannonField(QWidget *parent)
     : QWidget(parent)
 {
     currentAngle = 45;
     setPalette(QPalette(QColor(250, 250, 200)));
     setAutoFillBackground(true);
 }

 void CannonField::setAngle(int angle)
 {
     if (angle < 5)
         angle = 5;
     if (angle > 70)
         angle = 70;
     if (currentAngle == angle)
         return;
     currentAngle = angle;
     update();
     emit angleChanged(currentAngle);
 }

 void CannonField::paintEvent(QPaintEvent * /* event */)
 {
     QPainter painter(this);

     painter.setPen(Qt::NoPen);
     painter.setBrush(Qt::blue);

     painter.translate(0, rect().height());
     painter.drawPie(QRect(-35, -35, 70, 70), 0, 90 * 16);
     painter.rotate(-currentAngle);
     painter.drawRect(QRect(30, -5, 20, 10));
 }
 
