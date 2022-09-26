#include <stdio.h>
#include <string.h>
struct Carrinho{
int codProd, quantidade;
float valor;
};
struct Produtos{
char nome[30];
int codProd, estoq;
float valor, quant_carb;};
void additem(struct Produtos item[], int num);
void remoitem(int codprod, int total, struct Produtos item[]);
void remocart(struct Carrinho cart[], int codProd, int num2);
void altitem(int codProd, struct Produtos item[]);
void dash(struct Produtos item[], int num);
void dash2(struct Carrinho cart[], int num2);
void busca(struct Produtos item[], int num);
void fechar(struct Carrinho cart[], struct Produtos item[], int num2);
void main(){

struct Produtos item[5];
struct Carrinho cart[5];
int num=0, num2=0,codProd , i, resp1=1, resp2=1, quant;
char esc1, esc2;
 printf("___ ___ _ _ _ _ _ \
n");
 printf("| \\/ | | | | | (_) | | (_) \n");
 printf("| . . | ___| |_ __ _| |_ _ _ __ __ _ _ __ _ | |_ _ __ ___ ___ _ _ __ _ __ 
___ __ _ ___ ___ \n");
 printf("| |\\/| |/ _ \\ __/ _` | | | | | '__/ _` | |/ _` | | __| '__/ _ \\/ __| | | '__| '_ ` _ \\ / _` |/ 
_ \\/ __|\n");
 printf("| | | | __/ || (_| | | |_| | | | (_| | | (_| | | |_| | | __/\\__ \\ | | | | | | | | | (_| | (_) \\
__ \\\n");
 printf("\\_| |_/\\___|\\__\\__,_|_|\\__,_|_| \\__, |_|\\__,_| \\__|_| \\___||___/ |_|_| |
_| |_| |_|\\__,_|\\___/|___/\n");
 printf(" __/ | \n");
 printf(" |___/ \n");
 
 while(resp1==1){
 printf("-----------------------------\n");
 printf("| Escolha o tipo de usuário |\n");
 printf("-----------------------------\n");
 printf("| 1- Cliente |\n| 2- ADM |\n| 3- Sair |\
n");

 printf("-----------------------------\n");
 printf("-> ");
 scanf("%d", &esc1);
 printf("\n");
 if(esc1 == 1){
 while(resp2==1){
 printf("\nBem vindo à loja dos três irmãos\n\n");
 printf("----------------------\n");
 printf("|Opções: \n----------------------\n| 1- Ver itens\n| 2- Busca 
personalizada e filtro\n| 3- Adicionar ao carrinho\n| 4- Remover do carrinho\n| 5- 
Ver itens no carrinho\n| 6- Comprar itens do carrinho\n| 0- Voltar\
n----------------------\n -> ");
 scanf("%d", &esc2);
 switch(esc2){
 case 0:
 resp2 = 0;
 break;
 case 1:
 dash(item, num);
 break;
 case 2:
 busca(item, num);
 break;
 case 3:
 printf("Digite o código do produto -> ");

 scanf("%d", &codProd);
 for(i=0;i<num;i++){
 if(item[i].codProd == codProd){
 printf("Digite a quantidade -> ");
 scanf("%d", &quant);
 if(quant>item[i].estoq){
 printf("Desculpe, não temos essa quantidade em nosso 
estoque");
 }else{
 cart[num2].codProd = codProd;
 cart[num2].quantidade = quant;
 cart[num2].valor = quant * item[i].valor;
 num2++;
 printf("\nItem adicionado com sucesso\n\n");
 }
 }
 }
 break;
 case 4:
 printf("Digite o código do produto -> ");
 scanf("%d", &codProd);
 remocart(cart, codProd, 5);
 num2--;
 break;
 case 5:
 dash2(cart, num2);
 break;

 case 6:
 fechar(cart, item, num2);
 resp2 = 0;
 break;
 default:
 printf("Opção inválida, tente novamente");
 break;
 }
 }
 resp2 = 1;
 }
 else if(esc1 == 2){
 
 while (resp2==1){
 printf("Bem vindo ADM !!\n\n");
 printf("------------------------------\n");
 printf("| Escolha uma opção abaixo: |\n");
 printf("------------------------------\n");
 printf("| 1- Adicionar item |\n| 2- Remover item |\n| 3- Editar
item |\n| 4- Ver produtos |\n| 5- Sair da conta ADM |\n");
 printf("------------------------------\n");
 printf("-> ");
 scanf("%d", &esc2);
 printf("\n");
 if(esc2==1){
 additem(item, num);

 num++;
 }
 else if(esc2==2){
 printf("Digite o código do produto que deseja remover -> ");
 scanf("%d", &codProd);
 remoitem(codProd, num, item);
 num--;
 }
 else if(esc2==3){
 printf("Digite o código do produto que deseja alterar -> ");
 scanf("%d", &codProd);
 altitem(codProd, item);
 }
 else if(esc2==4){
 dash(item, num);
 }
 else if(esc2==5){
 resp2 = 0;
 printf("saindo da conta de ADM\n\n");
 }else{
 printf("Opção inválida, tente novamente\n\n");
 }
 }
 resp2 = 1;
 }

 else if(esc1==3){
 resp1 = 0;
 printf("Saindo ...\n\n");
 }else{
 printf("Opção inválida, tente novamente\n\n");
 }
 
 }
}
void additem(struct Produtos item[], int num){
 printf("__________________________________");
 printf("\n| Preencha as informações abaixo |\n|");
 printf("_________________________________\n");
 printf("\n| Digite o nome do produto -> ");
 scanf("%s", &item[num].nome);
 printf("__________________________________\n");
 printf("\n| Digite a quantidade em estoque -> ");
 scanf("%d", &item[num].estoq);

 printf("__________________________________\n");
 printf("\n| Digite o valor do produto -> R$ ");
 scanf("%f", &item[num].valor);
 printf("__________________________________\n");
 item[num].codProd = num;
 printf("\n| Escreva a quantidade de carbono emitida(Litros) -> ");
 scanf("%f", &item[num].quant_carb);
 printf("__________________________________\n");
 printf("|\n| Produto adicionado com sucesso |\n");
 printf("----------------------------------\n\n");
}
void remoitem(int codProd, int num, struct Produtos item[]){
 int i;
 for(i=codProd+1; i<num; ++i) item[i-1] = item[i];
 
 printf("\n________________________________\n");
 printf("| Produto removido com sucesso |");
 printf("\n--------------------------------\n\n");
}
void altitem(int codProd, struct Produtos item[]){
 int opc;
 printf("\n___________________________________\n");

 printf("| Escolha qual item deseja alterar:\n");
 printf("\n-----------------------------------\n");
 printf("| 1- Alterar o nome\n| 2- Alterar a quantidade no estoque\n| 3- Alterar 
valor\n| 4- Alterar quantidade de carbono emitida");
 printf("\n-----------------------------------\n");
 printf("[_> ");
 scanf("%d", &opc);
 
 switch(opc){
 
 case 1:
 printf("\nNome antigo : %s\n\n", item[codProd].nome);
 printf("Digite o novo nome para o produto -> ");
 scanf("%s", &item[codProd].nome);
 break;
 case 2:
 printf("\nQuantidade de estoque antiga : %d\n\n", item[codProd].estoq);
 printf("Digite a nova quantidade no estoque -> ");
 scanf("%d", &item[codProd].estoq);
 break;
 case 3:
 printf("\nValor antigo : %.2f\n\n", item[codProd].valor);
 printf("Digite o novo valor do produto -> ");
 scanf("%f", &item[codProd].valor);
 break;
 case 4:
 printf("\nQuantidade de carbono antiga : %.2f\n\n", 
item[codProd].quant_carb);

 printf("Digite a nova quantidade de carbono emitido -> ");
 scanf("%f", &item[codProd].quant_carb);
 break;
 default:
 printf("O valor digitado é inválido\n\n");
 }
}
void dash(struct Produtos item[], int num){
 int i;
 for(i=0;i<num;i++){
 printf("\n\n----------------\n");
 printf("|%s", item[i].nome);
 printf("\n------------------\n");
 printf("| Valor: %.2f\n| Estoque: %d\n| Código do produto : %d\n| Quantidade 
de carbono(Litros): %.2f\n", item[i].valor, item[i].estoq, item[i].codProd, 
item[i].quant_carb);
 printf("------------------\n\n");
 }
}
void busca(struct Produtos item[], int num){
 int opc, i, cod;
 float val;
 char nome[20];
 printf("\n___________________________________\n");

 printf("| Escolha como relizar a busca:\n");
 printf("-----------------------------------\n");
 printf("| 1- Pelo nome\n| 2- Pelo código\n| 3- Filtrar por preço\n| 0- Voltar");
 printf("\n-----------------------------------\n");
 printf("-> ");
 scanf("%d", &opc);
 if(opc==1){
 printf("Digite o nome -> ");
 gets(nome);
 for(i=0;i<num;i++){
 if(item[i].nome == nome){
 printf("\n\n----------------\n");
 printf("|%s", item[i].nome);
 printf("\n------------------\n");
 printf("| Valor: %.2f\n| Estoque: %d\n| Código do produto : %d\n| 
Quantidade de carbono(Litros): %.2f\n", item[i].valor, item[i].estoq, item[i].codProd, 
item[i].quant_carb);
 printf("------------------\n\n");
 }else{
 printf("Item não encontrado\n\n");
 }
 }
 }
 else if(opc==2){
 printf("Digite o código -> ");
 scanf("%d", &cod);

 for(i=0;i<num;i++){
 if(item[i].codProd == cod){
 printf("\n\n----------------\n");
 printf("|%s", item[i].nome);
 printf("\n------------------\n");
 printf("| Valor: %.2f\n| Estoque: %d\n| Código do produto : %d\n| 
Quantidade de carbono(Litros): %.2f\n", item[i].valor, item[i].estoq, item[i].codProd, 
item[i].quant_carb);
 printf("------------------\n\n");
 }else{
 printf("Item não encontrado\n\n");
 }
 }
 }
 else if(opc==3){
 printf("Digite o valor máximo que um produto deve ter -> ");
 scanf("%f", &val);
 for(i=0;i<num;i++){
 if(item[i].valor <= val){
 printf("\n\n----------------\n");
 printf("|%s", item[i].nome);
 printf("\n------------------\n");
 printf("| Valor: %.2f\n| Estoque: %d\n| Código do produto : %d\n| 
Quantidade de carbono(Litros): %.2f\n", item[i].valor, item[i].estoq, item[i].codProd, 
item[i].quant_carb);
 printf("------------------\n\n");
 }else{
 printf("O valor máximo digitado é muito baixo. Os produtos tem um 

preço um pouco maior\n\n");
 }
 }
 }else{
 printf("Opção inválida, tente novamente");
 }
}
void dash2(struct Carrinho cart[], int num2){
 int i;
 for(i=0;i<num2;i++){
 printf("\n------------------\n");
 printf("| Quantidade: %d\n| Código do produto : %d\n| Valor: %.2f", 
cart[i].quantidade, cart[i].codProd, cart[i].valor);
 printf("\n------------------\n\n");
 }
}
void remocart(struct Carrinho cart[], int codProd, int num2){
 int i;
 for(i=codProd+1; i<num2; ++i) cart[i-1] = cart[i];
 
 printf("\n________________________________\n");
 printf("| Produto removido com sucesso |");
 printf("\n--------------------------------\n\n");
}

void fechar(struct Carrinho cart[], struct Produtos item[], int num2){
 int i;
 float tot=0;
 printf("\n#############################\n");
 for(i=0;i<num2;i++){
 printf("Item - %s\tQuantidade - %d\tValor unitário - %.2f\n\n", 
item[cart[i].codProd].nome, cart[i].quantidade, item[cart[i].codProd].valor);
 tot = tot + cart[i].valor;
 }
 printf("\n#############################\n");
 printf("Total a pagar: %.2f\n\n", tot);
 printf("Compra concluída com sucesso\n\n");
}