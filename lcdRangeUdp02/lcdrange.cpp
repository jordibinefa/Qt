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

 #include <QLCDNumber>
 #include <QSlider>
 #include <QVBoxLayout>

 #include "lcdrange.h"

 LCDRange::LCDRange(QWidget *parent)
     : QWidget(parent)
 {
     QLCDNumber *lcd = new QLCDNumber(2);
     lcd->setSegmentStyle(QLCDNumber::Filled);

     slider = new QSlider(Qt::Horizontal);
     slider->setRange(0, 99);
     slider->setValue(0);

     connect(slider, SIGNAL(valueChanged(int)),
             lcd, SLOT(display(int)));
     connect(slider, SIGNAL(valueChanged(int)),
             this, SIGNAL(valueChanged(int)));

     QVBoxLayout *layout = new QVBoxLayout;
     layout->addWidget(lcd);
     layout->addWidget(slider);
     setLayout(layout);

     setFocusProxy(slider);
 }

 int LCDRange::value() const
 {
     return slider->value();
 }

 void LCDRange::setValue(int value)
 {
     slider->setValue(value);
 }

 void LCDRange::setRange(int minValue, int maxValue)
 {
     if (minValue < 0 || maxValue > 99 || minValue > maxValue) {
         qWarning("LCDRange::setRange(%d, %d)\n"
                  "\tRange must be 0..99\n"
                  "\tand minValue must not be greater than maxValue",
                  minValue, maxValue);
         return;
     }
     slider->setRange(minValue, maxValue);
 }
 
