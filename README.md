# Book Store 2018.2 
### Código exemplo da aplicação desenvolvida em [QT](http://www.qt.io) para sistema de dados de livraria

A aplicação deve permitir que o usuário cadastre livros com as seguintes informações: título, preço, quantidade, autor e código. Dessas, o título o preço e a quantidade são obrigatórias por parte do usuário, mas o autor não. O código não é definido pelo usuário mas gerado automaticamente pelo próprio algoritmo.

É possível modificar diretamente os valores na tabela. 

![](figura 1.png)
![](figura 2.png)
![](figura 3.png)
![](figura 4.png)
![](figura 5.png)
![](figura 6.png)

Pode-se também ordenar os livros já cadastrados de acordo com seu nome ou preço. 

![](figura 7.png)
![](figura 8.png)

Pode-se salvar seu valores ou carregar valores já existentes em um arquivo de texto .txt.
Dentro do arquivo de texto, deve-se seguir a ordem: titulo, preço, quantidade, autor, código. Após as informações de cada livro, pula-se uma linha. 


![](figura 9.png)

A aplicação também conta com um sistema de estastistica do acervo. Será exibido a quantidade de livros bem como o livro mais barato e o mais caro.

![](figura 10.png)

Outra funcionalidade é a possibilidade de pesquisar por um livro cadastrado anteriormente no acervo de forma dinâmica.
Apenas os livros que possuem semelhança ao que o usuário estará digitando serão exibidos na tabela.

![](figura 11.png)
![](figura 12.png)
![](figura 13.png)

# Os componentes básicos do QT (basic widgets)

## Labels

A todo, a aplicação possui labels e estes são os "textos" fixos que mostram algum tipo de informação mas o usuário não pode modificar diretamente. Foram usados labels 

![](figura 14.png)

As labels são importantes pois passam informações sobre outros *widgets* ao usuário. Apesar de serem fixas para o usuário as Labels podem ter o seu texto alterado via código.

### Labels no QT Creator 

Para inserir labels no QT Creator basta estar no modo de edição da interface gráfica (basta dar um duplo clique no arquivo mainwindow.ui) procurar no lado esquerdo da tela pelos *Display Widgets* e a label será o primeiro elemento, basta então clicar e arrastar a label para a posição que você desejar na sua interface. No lado direito da tela você vai encontrar as propriedades da sua label, como o texto que ela vai exibir, o tipo de fonte usada, o tamanho da fonte e uma infinidade de outras opções. Lembre-se de sempre mudar o *objectName* do seu widget para que você possa manipular ela no código. A Figura abaixo ilustra a tela do QT Creator e onde encontrar a label e mudar o seu *objectName*.

![](figura 15.png)

Se você criar uma label como o *objectName* de `lbl_media` por exemplo, dentro do código C++ você pode mudar o texto que ela exibe com o seguinte comando `ui->lbl_media->setText("Oi mundo");` 

### Dica

Digamos que você tenha uma váriavel `float media = 85` e deseja exibir ela através de uma label você tem que lembrar de primeiro converter ela para uma `QString` antes de passar para a sua label. Para fazer isso o QT disponibiliza dentro da classe `QString` um método estático chamado `number`para fazer conversão de números para texto. [link para documentação do QT](http://doc.qt.io/qt-5/qstring.html#number-6).

Então usando o método estático `number` da classe `QString` podemos mostrar a váriavel `media` na nossa label da seguinte forma `ui->lbl_media->setText(QString::number(media));` 

## Line Edits

Os *Line edits* são os campos editáveis de um formulário e funcionam como uma das formas de obter algum tipo de informação do usuário. Como o próprio nome diz eles só comportam um linha de texto.

![](figura 16.png)
![](figura 17.png) 

### Line Edits no QT Creator 

Os *Line edits* ficam dentro dos *Input Widgets* no QT Creator e da mesma forma que os labels basta clicar e arrastar para a posição que você desejar dentro do seu *form*. Como qualquer outro *widget* é sempre importante mudar o *objectName* para um nome que você possa facilmente referenciar dentro do seu código.

![](figura 18.png)

Caso você tenha criado o um *line edit* com o nome de `le_titulo`, no código para acessar o conteúdo dentro que houver dentro do *line edit* basta utilizar o comando `ui->le_titulo->text()`.

### Dica

Os *line edits* podem ser utilizados para obter os mais variados tipos de informações dos usuários, como nomes, idades, endereços, datas, preços, unidades e muitos outros. Por isso os *line edits* sempre consideram que o seu conteúdo é uma *QString* deixando a cargo do desenvolvedor fazer qualquer tipo de conversão de dados, felizmente dentro do QT converter uma *QString* para outros tipos de dados é bem fácil, já que a própria classe possui uma série de métodos que fazem conversão entre tipos. [Link para a documentação do QT](http://doc.qt.io/qt-5/qstring.html#toDouble). Então se você tiver um *line edit* e quiser salvar o seu conteúdo em outro tipo de váriavel que não seja uma *QString* basta fazer como algum dos exemplos abaixo:

+ `QString  = ui->le_nome->text();` (*QString* => *QString*)
+ `int idade = ui->le_idade->text().toInt();` (*QString* => *int*)
+ `float media = ui->le_media->text().toFloat();` (*QString* => *float*)
+ `std::string rua = ui->le_endereco->text().toStdString();` (*QString* => *string* padrão do C++)
+ `QString titulo = ui->le_titulo->text().toLower();` (*QString* => *QString* minúscula)

## Push Buttons

Os *Push Buttons* são os botões mais simples no QT Creator, são muito utilizados quando o usuário quer iniciar ou completar alguma ação na interface.

![](figura 19.png)

Da mesma forma que nos outros *widgets* os *push buttons* quando criados dentro do QT Creator também possuem um *objectName* que você pode e deve modificar para expressar qual é o inteção do botão na tela.

Uma das características importantes dos botões é que eles emitem _sinais_ para o QT quando são manipulados, então devemos associar esses sinais a métodos especiais que são chamados de _slots_ dentro do QT, basicamente isso significa que quando um _sinal_ é emitido para que algo aconteça é necessário ter um _slot_ associado. Por ser um ação muito comum para botões o QT Creator facilita a criação de _slots_ para os *push buttons*. Para associar as ações (_signal_) do seu botão a um método (_slot_) específico, basta clicar com o botão direito do mouse no seu *push button* e selecionar a opção *Go to slot...* no menu.

![](figura 20.png)

Quando você selecionar essa opção deve aparecer um menu como o da imagem abaixo com os _signals_ que o seu botão pode emitir, o mais útil para nós por enquanto é o *clicked()*.

![](figura 21.png)

Ao escolher a opção *clicked( )* o QT Creator irá automaticamente criar um método na sua *mainWindow* para ser responsável pelo clique no seu botão.

![](figura 22.png)

O nome do método gerado segue uma lógica bem simples, digamos que você tenha alterado o *objectName* do seu botão para *btn_inserir* então o QT Creator irá criar um método *void on_btn_inserir_clicked()* para associar ao *signal clicked* do seu botão. No método criado você pode fazer a ação que desejar, copiar um valor de um *line edit* para uma *label*, abrir uma janela nova, salvar um arquivo e etc.

##QTableWidget

A classe QTableWidget fornece uma exibição de tabela baseada em um item com modelo padrão. 
Widgets de tabela fornecem recursos de exibição de tabela padrão para aplicativos. Os itens em um QTableWidget são fornecidos pelo QTableWidgetItem. 
Se você quiser uma tabela que usa seu próprio modelo de dados, você deve usar o QTableView em vez desta classe. 
 
Os widgets de tabela podem ser construídos com o número necessário de linhas e colunas: 
tableWidget = new QTableWidget (12, 3, isso); 
Como alternativa, as tabelas podem ser construídas sem um determinado tamanho e redimensionadas posteriormente: 

tableWidget = new QTableWidget (este); 
tableWidget-> setRowCount (10); 
tableWidget-> setColumnCount (5); 
 
Itens são criados fora da tabela (sem nenhum widget pai) e inseridos na tabela com setItem (): 
 
QTableWidgetItem * newItem = new QTableWidgetItem (tr ("% 1"). 
(linha + 1) * (coluna + 1))); 
tableWidget-> setItem (linha, coluna, novoItem); 
Se você quiser ativar a ordenação em seu widget de tabela, faça-o após preenchê-lo com itens, caso contrário, a classificação poderá interferir na ordem de inserção. 
O número de linhas na tabela pode ser encontrado com rowCount () e o número de colunas com columnCount (). A tabela pode ser apagada com a função clear (). 

![](figura 24.png)
![](figura 25.png)
![](figura 26.png)

##Connect

Sinais e slots são usados ​​para comunicação entre objetos. O mecanismo de sinais e slots é uma característica central do Qt e provavelmente a parte que mais difere dos recursos fornecidos por outros frameworks.

    connect(ui->actionCarregar,SIGNAL(triggered()), this, SLOT(carregar()));
    connect(ui->actionSalvar,SIGNAL(triggered()), this, SLOT(salvar()));

![](figura 27.png)
![](figura 28.png)
![](figura 29.png)
![](figura 30.png)
![](figura 31.png)

Obs: Somente consegui fazer com que se editase na tabela principal. Fica para um futuro próximo fazer com que se possa editar na tabela de pesquisa.



