#include "userinterface_view.h"

void UserInterface_View::errorLoginMessage( const QString & msgErr )
{
    errorLogin->setVisible( true );
    errorLogin->setText( msgErr );
}


void UserInterface_View::loadLoginPage()
{
    QGroupBox * box = new QGroupBox( "Login" );
    box->setMaximumWidth( 350 );

    QFormLayout * formLogin = new QFormLayout;

    errorLogin = new QLabel();
    errorLogin->setVisible( false );
    editUsername =
        new LineEditValidate( QRegExp( "[A-Z][a-z]*.[A-Z][a-z]*.[0-9]*" ) );

    formLogin->addRow( tr( "Username" ) + ':', editUsername );

    QPushButton * btnLogin = new QPushButton( tr( "Login" ) );

    QHBoxLayout * layoutBtn = new QHBoxLayout;
    layoutBtn->setAlignment( Qt::AlignRight );
    layoutBtn->addWidget( btnLogin );

    QVBoxLayout * layoutBox = new QVBoxLayout;
    layoutBox->setAlignment( Qt::AlignTop );
    layoutBox->addWidget( errorLogin );
    layoutBox->addLayout( formLogin );
    layoutBox->addLayout( layoutBtn );

    box->setLayout( layoutBox );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->setAlignment( Qt::AlignCenter );
    layout->addWidget( box );

    QWidget * container = new QWidget();
    container->setLayout( layout );

    connect( btnLogin,
             SIGNAL( clicked() ),
             this,
             SLOT( login() ) );

    setFrameUtility( container );
}


void UserInterface_View::login()
{
    if( editUsername->check() == QValidator::State::Acceptable )
    {
        QString text = editUsername->text();

        if( !text.isEmpty() ) emit requestLogin( text );
        else emit error( ErrorState::LoginEmpty );
    }

    else emit error( ErrorState::LoginInvalid );
}


void UserInterface_View::setFrameUtility( QWidget * window )
{
    userUtility->setWidget( window );
}


UserInterface_View::UserInterface_View( QWidget * parent )
                                        : editUsername( nullptr ),
                                          errorLogin( nullptr ),
                                          QWidget( parent )
{
    userUtility = new QScrollArea;
    userUtility->setFrameShape( QFrame::NoFrame );
    userUtility->setWidgetResizable( true );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->setMargin( 0 );
    layout->addWidget( userUtility );

    setLayout( layout );
}


UserInterface_View::~UserInterface_View()
{
}
