#ifndef TABLEUSERS_H
#define TABLEUSERS_H

#include <QScrollArea>
#include <QWidget>

#include "info.h"
#include "useritem.h"

class TableUsers : public QWidget
{
    public:
        TableUsers( QWidget * = NULL );
        ~TableUsers();
};

#endif // TABLEUSERS_H
