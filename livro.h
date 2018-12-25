#ifndef LIVRO_H
#define LIVRO_H

#include <QObject>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QDebug>

class Livro
{

private:

    QString titulo;
    QString autor;
    QString preco;
    QString quantidade;
    QString codigo;

public:
    Livro( QString t, QString p, QString a );
    Livro();

    QString getTitulo() const;
    QString getPreco() const;
    QString getAutor() const;
    QString getCodigo() const;
    QString getQuantidade() const;

    void setTitulo(const QString &value);
    void setAutor(const QString &value);
    void setPreco(const QString &value);
    void setQuantidade(const QString &value);
    void setCodigo(const QString &value);
};

#endif // LIVRO_H
