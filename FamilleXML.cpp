///////////////////////////////////////////////////////////////////////////////
//
// Nom : FamilleXML.cpp
//
// Description :
//		Exemple de création d'un document XML à l'aide des classes XML de Qt.
//
///////////////////////////////////////////////////////////////////////////////

#include <QtXml>
#include <QFile>
#include <QDebug>
#include <QVector>

int famille()
{
    // ouverture du fichier XML
    QString nomFichierXML = "famille.xml";
    QFile FichierXML(nomFichierXML);

    if (!FichierXML.open(QIODevice::WriteOnly))
    {
        qDebug() << "--- Erreur : probleme ouverture fichier XML";
        return 1;
    }
    qDebug() << "> Ouverture du fichier: " << nomFichierXML;

    // déclaration du "writer" xml sur le fichier ouvert précédemment
    QXmlStreamWriter writer(&FichierXML);

    // pour les éléments avec attributs
    QXmlStreamAttributes attributs;		// hérite de QVector

    // écriture du début du document (la première ligne)
    writer.writeStartDocument();

    // écriture d'un commentaire
    writer.writeComment("document famille.xml");

    // écriture de la balise d'ouverture <famille>
    writer.writeStartElement("Famille");

    // écriture de l'élément <Père>
    writer.writeStartElement("Père");
    writer.writeCharacters("Paul");
    writer.writeEndElement();

    // écriture de l'élément <Mère>
    // noter que l'élément Père aurait pu aussi s'écrire ainsi
    writer.writeTextElement("Mère","Marie");

    //l'élément enfant "Marine" et ses attributs
    attributs.append("nom","Marine");
    attributs.append("sexe","Fille");
    attributs.append("dateNaiss","22/10/2015");
    writer.writeStartElement("Enfant");
    writer.writeAttributes(attributs);

    //element enfant paul
    attributs.clear();
    attributs.append("nom","Paul");
    attributs.append("sexe","Garçons");
    attributs.append("dateNaiss","12/05/2008");
    writer.writeStartElement("Enfant");
    writer.writeAttributes(attributs);

    writer.writeEndElement();
    // fin de l'élément famille
    writer.writeEndElement();

    // fin du document
    writer.writeEndDocument();

    return 0;
}
int films()
{
    QString nomFichierXML = "../XML_Qt/films.xml";
    QFile fichierXML(nomFichierXML);

    struct Realisateur
    {
        QString nom;
        QString prenom;
        QString annee_naissance;
    };

    struct Film{
        QString Titre;
        QString annee;
        QString genre;
        Realisateur realisateur;
        QString resume;
    };

    QVector<Film> Films;


    return 0;
}


int main()
{

    //famille();
    films();


    return 0;
}
