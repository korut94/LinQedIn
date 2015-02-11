#ifndef MODULEEDUCATION_H
#define MODULEEDUCATION_H

#include <algorithm>
#include <iostream>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

#include "experience.h"
#include "info.h"
#include "lineeditvalidate.h"

class ModuleEducation : public QWidget
{
    Q_OBJECT

    private:
        class ModuleStudio : public QWidget
        {
            private:
                LineEditValidate * editSchool;
                QLineEdit * editTitle;
                QLineEdit * editDurata;
                QTextEdit * editDescrizione;

            public:
                ModuleStudio( const Experience & = Experience(),
                              QWidget * = nullptr );
                ~ModuleStudio();

                bool checkError() const;
                bool complete() const;

                Experience getEducation() const;

                void reset();
        };

    private:
        QVector<ModuleStudio*> listaStudio;

    public:
        ModuleEducation( QWidget * = nullptr );
        ~ModuleEducation();

        bool checkError() const;
        bool complete() const;

        QVector<Experience> getEducations() const;

        void addEducation( const Experience & = Experience() );
        void reset();
        void setContent( const QVector<Experience> & );
};

#endif // MODULEEDUCATION_H