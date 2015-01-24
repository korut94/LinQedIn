#include "usersearch.h"

void UserSearch::recapInfo()
{
    Info info( editName->text(), "Mantovani", "", "" );

    emit searchUser( info );
}


UserSearch::UserSearch( QWidget * parent ) : QWidget( parent )
{
    QLabel * lblName = new QLabel( tr( "Name" ) + ':' );
    editName = new LineEditValidate( QRegExp( "[a-zA-Z]" ) );

    QLabel * lblSurname = new QLabel( tr( "Surname" ) + ':' );
    editSurname = new LineEditValidate( QRegExp( "[A-Za-z]" ) );

    QLabel * lblTelephone = new QLabel( tr( "Number" ) + ':' );
    editPrefixNumber = new LineEditValidate( QRegExp( "+[0-9]{1,4}" ) );
    editPrefixNumber->setFixedWidth( 40 );
    editPrefixNumber->setMaxLength( 5 );
    editNumber = new LineEditValidate( QRegExp( "[0-9]*-[0-9]*" ) );

    QLabel * lblData = new QLabel( tr( "Data" ) + ':' );
    QLabel * slash[2] = { new QLabel( QString( '/' ) ),
                          new QLabel( QString( '/' ) ) };
    editData_Day = new LineEditValidate( QRegExp( "[1-3]{0,1}[1-9]" ) );
    editData_Day->setAlignment( Qt::AlignRight );
    editData_Day->setMaxLength( 2 );
    editData_Month = new LineEditValidate( QRegExp( "[0-1][1-9]" ) );
    editData_Month->setAlignment( Qt::AlignRight );
    editData_Month->setMaxLength( 2 );
    editData_Year = new LineEditValidate( QRegExp( "[1-9][0-9]{3}" ) );
    editData_Year->setAlignment( Qt::AlignRight );
    editData_Year->setMaxLength( 4 );

    QPushButton * btmReset = new QPushButton( tr( "Reset" ) );
    QPushButton * btmSearch = new QPushButton( tr( "Search" ) );

    QScrollArea * areaForm = new QScrollArea();
    areaForm->setFrameShape( QFrame::NoFrame );
    areaForm->setWidgetResizable( true );

    QLabel * line = new QLabel();
    line->setFrameStyle( QFrame::HLine | QFrame::Plain );
    line->setLineWidth( 1 );

    QVBoxLayout * layoutLabel = new QVBoxLayout;
    layoutLabel->addWidget( lblName );
    layoutLabel->addWidget( lblSurname );
    layoutLabel->addWidget( lblTelephone );
    layoutLabel->addWidget( lblData );


    QVBoxLayout * layoutInput = new QVBoxLayout;
    layoutInput->setAlignment( Qt::AlignLeft );
    layoutInput->addWidget( editName );
    layoutInput->addWidget( editSurname );

    QHBoxLayout * layoutNumber = new QHBoxLayout;
    layoutNumber->addWidget( editPrefixNumber );
    layoutNumber->addWidget( editNumber );

    layoutInput->addLayout( layoutNumber );

    QHBoxLayout * layoutData = new QHBoxLayout;
    layoutData->addWidget( editData_Day );
    layoutData->addWidget( slash[0] );
    layoutData->addWidget( editData_Month );
    layoutData->addWidget( slash[1] );
    layoutData->addWidget( editData_Year );

    layoutInput->addLayout( layoutData );

    QHBoxLayout * layoutForm = new QHBoxLayout;
    layoutForm->setAlignment( Qt::AlignTop );
    layoutForm->addLayout( layoutLabel );
    layoutForm->addLayout( layoutInput );


    QWidget * container = new QWidget();
    container->setMaximumWidth( 400 );
    container->setLayout( layoutForm );

    areaForm->setWidget( container );


    QHBoxLayout * layoutButton = new QHBoxLayout;
    layoutButton->setAlignment( Qt::AlignRight );
    layoutButton->addWidget( btmSearch );
    layoutButton->addWidget( btmReset );


    QVBoxLayout * layoutTop = new QVBoxLayout;
    layoutTop->setAlignment( Qt::AlignTop );
    layoutTop->addWidget( areaForm );


    QVBoxLayout * layoutBottom = new QVBoxLayout;
    layoutBottom->setAlignment( Qt::AlignBottom );
    layoutBottom->addWidget( line );
    layoutBottom->addLayout( layoutButton );


    QVBoxLayout * layout = new QVBoxLayout;
    layout->addLayout( layoutTop );
    layout->addLayout( layoutBottom );

    setLayout( layout );

    connect( btmSearch, SIGNAL( clicked() ), this, SLOT( recapInfo() ) );
}


UserSearch::~UserSearch()
{
    delete editName;
    delete editSurname;
    delete editPrefixNumber;
    delete editNumber;
    delete editData_Day;
    delete editData_Month;
    delete editData_Year;
}
