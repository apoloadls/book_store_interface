#include "livro.h"

QString Livro::getQuantidade() const
{
    return quantidade;
}

void Livro::setTitulo(const QString &value)
{
    titulo = value;
}

void Livro::setAutor(const QString &value)
{
    autor = value;
}

void Livro::setPreco(const QString &value)
{
    preco = value;
}

void Livro::setQuantidade(const QString &value)
{
    quantidade = value;
}

void Livro::setCodigo(const QString &value)
{
    codigo = value;
}

Livro::Livro( QString t, QString p, QString a ){


    titulo = t.toLower();
    titulo[0]=titulo[0].toUpper();
    preco = p;

    autor = a;

    unsigned long aleatorio = (t.size()+p.size()+a.size())*382334; //define codigo
    codigo = QString::number(aleatorio);

}

Livro::Livro(){


}

QString Livro::getPreco() const
{
    return preco;
}

QString Livro::getAutor() const
{
    return autor;
}

QString Livro::getCodigo() const
{
    return codigo;
}

QString Livro::getTitulo() const
{
    return titulo;
}

