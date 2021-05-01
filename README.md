# Prova1Arquivos

## Como usar:
### Primeira questão
* Lê um arquivo texto diz quantas palavras e quantas linhas tem nele
* Depois de compilar o codigo, execute no formato "./Questao1 'arquivo.dat'

### Segunda questão
* Lê um arquivo com registro de tamanho fixo que está com uma falha de registros repetidos e cria um segundo arquivo sem essa falha
* Depois de compilar o codigo, execute no formato "./Questao2 'arquivo.dat'

### Terceira questão
* Lê dois arquivos com registros de tamanho fixo e escreve o email das pessoas que estão nos dois arquivos simultaneamente
* Depois de compilar o codigo, execute no formato "./Questao1 'arquivo.dat'

OBS: Estrutura do arquivo de tamanho fixo

struct Registro {

  int id_inscricao;
  
  char curso[20];
  
  char cpf[15];
  
  char dataNacimento[11];
  
  char sexo;
  
  char email[40];
  
  char opcaoQuadro;
  
};
