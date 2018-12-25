#include "acervo.h"

Acervo::Acervo()
{

}

void Acervo::inserirLivro( Livro aux )
{
    acervo.push_back( aux );


}

QString Acervo::maisCaro()
{

    Livro *aux = std::max_element( acervo.begin(), acervo.end(), maxElement);
    return aux->getTitulo() + " -- Preço: " + aux->getPreco() + " $ -- Cód: " + aux->getCodigo();

}
QString Acervo::maisBarato()
{
    Livro *aux = std::min_element( acervo.begin(), acervo.end(), minElement);
    return aux->getTitulo() + " -- Preço: " + aux->getPreco() + " $ -- Cód: " + aux->getCodigo();
}

bool maxElement( Livro a, Livro b )
{
    float a1 = a.getPreco().toFloat();
    float b1 = b.getPreco().toFloat();
    return a1<b1;

}

bool minElement( Livro a, Livro b )
{
    float a1 = a.getPreco().toFloat();
    float b1 = b.getPreco().toFloat();
    return a1<b1;

}

int Acervo::size()
{

    return acervo.size();

}

void Acervo::ordenarPorTitulo()
{
    std::sort( acervo.begin(), acervo.end(), auxOrdenarPorTitulo );

}

bool auxOrdenarPorTitulo( Livro a, Livro b )
{
    return a.getTitulo()<b.getTitulo();
}

Livro Acervo::operator []( const  int i  )
{

    return acervo[i];

}

void Acervo::ordenarPorPreco()
{
    std::sort( acervo.begin(), acervo.end(), auxOrdenarPorPreco );

}

bool auxOrdenarPorPreco( Livro a, Livro b )
{
    return (a.getPreco()).toFloat()<(b.getPreco()).toFloat();
}

void Acervo::clear()
{
    acervo.clear();
}

void Acervo::inserirNewList( QVector<Livro>newlist )  //modifica valores do acervo
{
    for( int i=0; i<newlist.size(); i++ ){

        acervo = newlist;

    }
}

void Acervo::editInfo( QString aux, int row, int column )  //edita determinado valor do acervo
{
    switch (column){

    case 0:
        acervo[row].setTitulo(aux);
        break;
    case 1:
        acervo[row].setPreco(aux);
        break;
    case 2:
        acervo[row].setQuantidade(aux);
        break;
    case 3:
        acervo[row].setAutor(aux);
        break;
    case 4:
        acervo[row].setCodigo(aux);

    }
}

