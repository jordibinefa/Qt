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

 #ifndef LCDRANGE_H
 #define LCDRANGE_H

 #include <QWidget>

 class QSlider;

 class LCDRange : public QWidget
 {
     Q_OBJECT

 public:
     LCDRange(QWidget *parent = 0);

     int value() const;

 public slots:
     void setValue(int value);
     void setRange(int minValue, int maxValue);

 signals:
     void valueChanged(int newValue);

 private:
     QSlider *slider;
 };

 #endif
 
