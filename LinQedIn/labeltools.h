#ifndef LABELTOOLS_H
#define LABELTOOLS_H

#include <QHBoxLayout>
#include <QPushButton>

class LabelTools : public QWidget
{
    Q_OBJECT

    signals:
        void search() const;
        void add() const;
        void remove() const;
        void viewAllUsers() const;
        void save() const;
        void load() const;

    public:
        LabelTools( QWidget * = NULL );
        ~LabelTools();
};

#endif // LABELTOOLS_H
