/***************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (directui@nokia.com)
**
** This file is part of libdui.
**
** If you have questions regarding the use of this file, please contact
** Nokia at directui@nokia.com.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation
** and appearing in the file LICENSE.LGPL included in the packaging
** of this file.
**
****************************************************************************/

#include "memorybenchmark.h"
#include "memorybenchmark.inl"
#include "mt_duibuttongroup.h"

#include <DuiButton>
#include <DuiButtonGroup>
#include <DuiApplication>

DuiApplication *app;

void Mt_DuiButtonGroup::initTestCase()
{
    int argc = 1;
    char *app_name = (char *) "./mt_duibuttongroup";
    app = new DuiApplication(argc, &app_name);
}

void Mt_DuiButtonGroup::cleanupTestCase()
{
    delete app;
}

void Mt_DuiButtonGroup::memoryBenchmark_data()
{
    QTest::addColumn<int>("buttonCount");

    QTest::newRow("0 buttons") << 0;
    QTest::newRow("1 buttons") << 1;
    QTest::newRow("2 buttons") << 2;
    QTest::newRow("10 buttons") << 10;
    QTest::newRow("20 buttons") << 20;
    QTest::newRow("50 buttons") << 50;
    QTest::newRow("100 buttons") << 100;
}

void Mt_DuiButtonGroup::memoryBenchmark()
{
    QFETCH(int, buttonCount);

    DuiButton **buttons = new DuiButton*[buttonCount];

    beginMemoryBenchmark();

    DuiButtonGroup *buttonGroup = new DuiButtonGroup();

    for (int i = 0; i < buttonCount; ++i) {
        buttons[i] = new DuiButton();
        buttons[i]->setCheckable(true);
        buttonGroup->addButton(buttons[i]);
    }

    outputAllocatedMemorySize();

    for (int i = 0; i < buttonCount; ++i) {
        delete buttons[i];
    }

    delete buttonGroup;

    endMemoryBenchmark();

    delete buttons;
}

QTEST_APPLESS_MAIN(Mt_DuiButtonGroup)

