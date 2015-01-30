#include "moduleid.h"

QStringList ModuleID::insertNumDay()
{
    QStringList list;

    for( int day = 1; day < 32; day ++ )
    {
        list.push_back( QString::number( day ) );
    }

    return list;
}


QStringList ModuleID::insertNameMonth()
{
    QStringList list;

    list.push_back( tr( "January" ) );
    list.push_back( tr( "February" ) );
    list.push_back( tr( "March" ) );
    list.push_back( tr( "April" ) );
    list.push_back( tr( "May" ) );
    list.push_back( tr( "June" ) );
    list.push_back( tr( "July" ) );
    list.push_back( tr( "August" ) );
    list.push_back( tr( "September" ) );
    list.push_back( tr( "October" ) );
    list.push_back( tr( "November" ) );
    list.push_back( tr( "December" ) );

    return list;
}


QStringList ModuleID::insertNumYear()
{
    QStringList list;

    for( int year = 1910; year < QDate::currentDate().year() + 1; year++ )
    {
        list.push_back( QString::number( year ) );
    }

    return list;
}


ModuleID::ModuleID( QWidget * parent ) : QWidget( parent )
{
    editName = new LineEditValidate( QRegExp( "[A-Z][a-z]*" ) );

    editSurname = new LineEditValidate(
                                QRegExp( "[A-Z][a-z]*" ) );

    editPrefixNumber = new LineEditValidate( QRegExp( "[0-9]*" ) );
    editPrefixNumber->setFixedWidth( 40 );
    editPrefixNumber->setMaxLength( 3 );
    editNumber = new LineEditValidate( QRegExp( "[0-9]*" ) );

    editData_Day = new QComboBox();
    editData_Day->setStyleSheet( "combobox-popup: 0;" );
    editData_Day->addItems( insertNumDay() );
    editData_Month = new QComboBox();
    editData_Month->setStyleSheet( "combobox-popup: 0;" );
    editData_Month->addItems( insertNameMonth() );
    editData_Year = new QComboBox();
    editData_Year->setStyleSheet( "combobox-popup: 0;" );
    editData_Year->addItems( insertNumYear() );

    QFormLayout * layoutForm = new QFormLayout;
    layoutForm->setHorizontalSpacing( 50 );

    layoutForm->addRow( tr( "Name" ) + ':', editName );
    layoutForm->addRow( tr( "Surname" ) + ':', editSurname );

    QHBoxLayout * layoutNumber = new QHBoxLayout;
    layoutNumber->addWidget( new QLabel( "+" ) );
    layoutNumber->addWidget( editPrefixNumber );
    layoutNumber->addWidget( editNumber );

    layoutForm->addRow( tr( "Number" ) + ':', layoutNumber );

    QHBoxLayout * layoutData = new QHBoxLayout;
    layoutData->addWidget( editData_Day );
    layoutData->addWidget( editData_Month );
    layoutData->addWidget( editData_Year );

    layoutForm->addRow( tr( "Data" ) + ':', layoutData );

    QWidget * container = new QWidget();
    container->setMaximumWidth( 400 );
    container->setLayout( layoutForm );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( container );

    setLayout( layout );
}


ModuleID::~ModuleID()
{
    delete editName;
    delete editSurname;
    delete editPrefixNumber;
    delete editNumber;
    delete editData_Day;
    delete editData_Month;
    delete editData_Year;
}


bool ModuleID::checkError() const
{
    return(
                ( editName->text().isEmpty() ||
                  editName->check() == QValidator::Acceptable ) &&
                ( editSurname->text().isEmpty() ||
                  editSurname->check() == QValidator::Acceptable ) &&
                ( editPrefixNumber->text().isEmpty() ||
                  editPrefixNumber->check() == QValidator::Acceptable ) &&
                ( editNumber->text().isEmpty() ||
                  editNumber->check() == QValidator::Acceptable )
           );
}


Personal ModuleID::getDataPersonal() const
{
    Personal risult;

    risult.setNome( editName->text() );
    risult.setCognome( editSurname->text() );

    QString fullNumber = editPrefixNumber->text() + '-' + editNumber->text();

    risult.setNumTelefono( fullNumber );

    risult.setDate( QDate( editData_Day->currentIndex() + 1,
                           editData_Month->currentIndex() + 1,
                           editData_Year->currentIndex() + 1 ) );

    return risult;
}


void ModuleID::reset()
{
    editData_Day->setCurrentIndex( 0 );
    editData_Month->setCurrentIndex( 0 );
    editData_Year->setCurrentIndex( 0 );
    editName->clear();
    editNumber->clear();
    editPrefixNumber->clear();
    editSurname->clear();
}


