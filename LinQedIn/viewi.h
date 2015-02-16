#ifndef VIEWI_H
#define VIEWI_H

#include "viewbase.h"

class ViewI : public ViewBase
{
    public slots:
        void loadMainPage( const smartptr_utente & );

    public:
        ViewI( QWidget * = nullptr );
};

#endif // VIEWI_H
