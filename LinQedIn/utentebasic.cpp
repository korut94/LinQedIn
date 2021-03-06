#include "utentebasic.h"

UtenteBasic::UtenteBasic()
{
}


UtenteBasic::UtenteBasic( const QString & username, const Info & info )
                          : Utente( username, info ) {}


UtenteBasic::UtenteBasic( const Utente & utente ) : Utente( utente ) {}


LevelAccess::Type UtenteBasic::typeAccount() const
{
	return LevelAccess::Basic;
}


void UtenteBasic::readXmlFormat( QXmlStreamReader & reader )
{
	QXmlStreamReader::TokenType token = reader.readNext();

	while( !( token == QXmlStreamReader::EndElement && 
			  reader.name() == "Utente"  ) )
	{
		if( token == QXmlStreamReader::StartElement )
		{
			if( reader.name() == "username" )
			{
				token = reader.readNext();

				if( token == QXmlStreamReader::Characters ) 
					setUsername( reader.text().toString() );

				token = reader.readNext();
			}

			if( reader.name() == "Info" )
			{
				readXmlUserData( reader );
			}
		}

		token = reader.readNext();
	}
}


void UtenteBasic::writeXmlFormat( QXmlStreamWriter & writer ) const
{
    writer.writeStartElement( "Utente" ); //Open Utente
    writer.writeAttribute( "type", "Basic" );

    writeXmlUserData( writer );

    writer.writeEndElement(); //Close Utente
}
