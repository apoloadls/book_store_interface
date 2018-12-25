#ifndef ACERVO_H
#define ACERVO_H

#include "livro.h"
#include <QVector>
#include <algorithm>

class Acervo
{
private:
    QVector<Livro> acervo;

public:
    Acervo();
    void inserirLivro( Livro aux );
    QString maisCaro();
    QString maisBarato();
    int size();
    void ordenarPorTitulo();
    Livro operator []( const int i );
    void ordenarPorPreco();
    void clear();
    void inserirNewList( QVector<Livro> newlist );
    void editInfo( QString aux, int row, int column );



};

bool maxElement( Livro a, Livro b );
bool minElement( Livro a, Livro b );
bool auxOrdenarPorTitulo( Livro a, Livro b );
bool auxOrdenarPorPreco( Livro a, Livro b );


#endif // ACERVO_H
