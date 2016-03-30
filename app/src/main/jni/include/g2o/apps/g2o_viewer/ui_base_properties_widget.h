/********************************************************************************
** Form generated from reading UI file 'base_properties_widget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASE_PROPERTIES_WIDGET_H
#define UI_BASE_PROPERTIES_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BasePropertiesWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnApply;
    QPushButton *btnOK;
    QPushButton *btnCancel;

    void setupUi(QWidget *BasePropertiesWidget)
    {
        if (BasePropertiesWidget->objectName().isEmpty())
            BasePropertiesWidget->setObjectName(QString::fromUtf8("BasePropertiesWidget"));
        BasePropertiesWidget->resize(543, 443);
        verticalLayout = new QVBoxLayout(BasePropertiesWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(BasePropertiesWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(428, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnApply = new QPushButton(BasePropertiesWidget);
        btnApply->setObjectName(QString::fromUtf8("btnApply"));

        horizontalLayout->addWidget(btnApply);

        btnOK = new QPushButton(BasePropertiesWidget);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));

        horizontalLayout->addWidget(btnOK);

        btnCancel = new QPushButton(BasePropertiesWidget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnCancel->sizePolicy().hasHeightForWidth());
        btnCancel->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(BasePropertiesWidget);
        QObject::connect(btnCancel, SIGNAL(clicked()), BasePropertiesWidget, SLOT(close()));

        QMetaObject::connectSlotsByName(BasePropertiesWidget);
    } // setupUi

    void retranslateUi(QWidget *BasePropertiesWidget)
    {
        BasePropertiesWidget->setWindowTitle(QApplication::translate("BasePropertiesWidget", "Properties", 0, QApplication::UnicodeUTF8));
        btnApply->setText(QApplication::translate("BasePropertiesWidget", "Apply", 0, QApplication::UnicodeUTF8));
        btnOK->setText(QApplication::translate("BasePropertiesWidget", "OK", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("BasePropertiesWidget", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BasePropertiesWidget: public Ui_BasePropertiesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASE_PROPERTIES_WIDGET_H
