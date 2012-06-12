/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtSensors module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QObject>
#include <QtPlugin>
#include <QStringList>
#include <QTimer>

#include "qtestrecognizerdup.h"
#include "qtest2recognizerdup.h"

#include "qtestsensorgestureplugindup.h"

#include <qsensorgestureplugininterface.h>
#include <qsensorgesturerecognizer.h>
#include <qsensorgesturemanager.h>


QTestSensorGestureDupPlugin::QTestSensorGestureDupPlugin()
{
}

QTestSensorGestureDupPlugin::~QTestSensorGestureDupPlugin()
{
}

/*!
  Describes this gesture's possible gesture signals.
handled through the detected(const QString &) signal.
  */
QStringList QTestSensorGestureDupPlugin::gestureSignals() const
{
    QStringList list;
    Q_FOREACH (const QSensorGestureRecognizer* rec,recognizersList) {
        list.append(rec->gestureSignals());
    }
    return list;
}

QList <QSensorGestureRecognizer *> QTestSensorGestureDupPlugin::createRecognizers()
{
    QSensorGestureRecognizer *sRec = new QTestRecognizerDup(this);
    recognizersList.append(sRec);

    QSensorGestureRecognizer *sRec2 = new QTest2RecognizerDup(this);
    recognizersList.append(sRec2);

    return recognizersList;
}

QStringList QTestSensorGestureDupPlugin::supportedIds() const
{
    QStringList list;
    list << "QtSensors.test.dup";
    list << "QtSensors.test.dup";

    return list;
}

QList<QSensorGestureRecognizer*> QTestSensorGestureDupPlugin::recognizers() const
{
    return recognizersList;
}

QString QTestSensorGestureDupPlugin::name() const
{
    return "TestGesturesDup";
}
