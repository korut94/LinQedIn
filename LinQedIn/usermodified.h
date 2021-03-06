#ifndef USERMODIFIED_H
#define USERMODIFIED_H

#include <iostream>
#include <QPushButton>
#include <QWidget>

#include "info.h"
#include "line.h"
#include "smartptr_utente.h"
#include "usereditpage.h"

class UserModified : public UserEditPage
{
    Q_OBJECT

    public:
        UserModified( const smartptr_utente &, QWidget * = nullptr );
        ~UserModified();
};

#endif // USERMODIFIED_H
