////////////////////////////////
/// Inclusão das bibliotecas ///
////////////////////////////////
#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
#ifdef __WIN32
	#include <mysql.h>
#else

///////////////////
/// Protótipos ////
///////////////////
void exibeMenu(); 
void desconectar();
void verCompromissos();
void mostrarErroDoMysql();
void adicionarCompromisso();
void excluirCompromisso ();
void editarCompromisso ();

/////////////////////////////
/// Variáveis globais X<( ///
/////////////////////////////

/**
 * Contém a conexão com o banco de dados
 */
MYSQL *connexao;
bool conectado = false;

if (true) {
	std :: cout << "Conectado ao Mysql" << std :: endl;}
else {
	std :: cout << "Não conectado ao Mysql" << std :: endl;
}


//////////////////
/// Constantes ///
//////////////////

const unsigned int ADICIONAR_COMPROMISSO = 1; 
const unsigned int REMOVER_COMPROMISSO = 2;
const unsigned int MOSTRAR_COMPROMISSO = 3;
const unsigned int EDITAR_COMPROMISSO = 4;
const unsigned int SAIR = 5;

/**
 * Função principal
 */
int main(int argc, char **argv) {

	// Exibe a mensagem de boas vindas
	std::cout << "Boas vindas da agenda!" << std::endl;

	exibeMenu();

/**
 * Exibe um menu para o usuário
 */
void exibeMenu() {
	std::cout << "Escolha uma opção:" << std::endl;
	std::cout << ADICIONAR_COMPROMISSO << " - Adicionar compromisso" << std::endl;
	std::cout << REMOVER_COMPROMISSO << " - Remover compromisso" << std::endl;
	std::cout << MOSTRAR_COMPROMISSO << " - Mostrar compromisso" << std::endl;
	std::cout << EDITAR_COMPROMISSO << " - Editar compromisso" << std::endl;
	std::cout << SAIR << " - SAIR" << std::endl;
}

	// Guarda a opção escolhida
	int opcao;

	// Entra em um loop infinito perguntando
	// o que o usuário deseja fazer
	while (true) {

		// Pergunta a opção do usuário
		std::cin >> opcao;

		// Executa a ação escolhida
		switch (opcao) {
			case ADICIONAR_COMPROMISSO:
				adicionarCompromisso();
				break;
			case REMOVER_COMPROMISSO:
				excluirCompromisso ();
				break;
			case MOSTRAR_COMPROMISSO:
				verCompromissos();
				break;
			case EDITAR_COMPROMISSO:
				editarCompromisso ();
				break;
		}

		// Exibe o menu novamente
		exibeMenu();
	}

	desconectar();
	return 0;
}



/**
 * Conecta no banco de dados
 * @return - true: Conectou, false: Falha ao conectar
 */
bool conectar() {

	if (conectado) return true;

	connexao = mysql_init(NULL);
	if (!mysql_real_connect(connexao, "127.0.0.1", "root", "1234", "Agenda", 3306, NULL, 0)) {
		mostrarErroDoMysql(connexao);

		conectado = false;
		return false;
	}

	conectado = true;
	return true;
}

void mostrarErroDoMysql(MYSQL *mysql) {
	printf("Erro: (%d) [%s] \"%s\"", mysql_errno(mysql), mysql_sqlstate(mysql), mysql_error(mysql));
	mysql_close(mysql);
	exit(-1); 
}

/**
 * Desconecta do banco de dados
 */
void desconectar() {
	mysql_close(connexao);
	conectado = false;
}

/**
 * Adiciona um compromisso
 */
void adicionarCompromisso() {

	// Verifica se a conexÃ£o foi realizada com sucesso
	if (!conectar()) {
		std::cout << "Falha ao conectar ao banco de dados!" << std::endl;
		return;
	}
	
	void mostrarErroDoMysql(MYSQL *mysql) {
	printf("Erro: (%d) [%s] \"%s\"", mysql_errno(mysql), mysql_sqlstate(mysql), mysql_error(mysql));
	mysql_close(mysql);
	exit(-1); 
} 

	// VariÃ¡veis usadas para montar o query
	std::string nome, dia, mes, ano, descricao;
	
	std ::cout<<"Informe o nome do compromisso:" << std :: endl;

	// Solicita o dia do compromisso
	std::cout << "Informe o dia:";
	std::cin >> dia;

	// Solicita o mês do compromisso
	std::cout << "Informe o mês:";
	std::cin >> mês;

	// Solicita o ano do compromisso
	std::cout << "Informe o ano:";
	std::cin >> ano;

	// Solicita a descrição do compromisso
	std::cout << "Descreva o compromisso:";
	std::cin >> descrição;

	// Monta a query
	std::string sql = "insert into Compromisso (nome, data, descricao)values ('" nome '\n' + ano + "-" + mes + "-" + dia + "','" + descricao + "')";

	// Executa a query
	int Execucao = mysql_query(connexao, sql.data());

	// Verifica se deu tudo certo
	if (Execucao == 0) {
		// Deu certo!
		std::cout << "Compromisso inserido" << std::endl;
	} else {
		// Algo deu errado!
		mostrarErroDoMysql(connexao);
		std::cout << "Falha ao inserir compromisso!" << std::endl;
	}
	
void mostrarErroDoMysql(MYSQL *mysql) {
	printf("Erro: (%d) [%s] \"%s\"", mysql_errno(mysql), mysql_sqlstate(mysql), mysql_error(mysql));
	mysql_close(mysql);
	exit(-1); 
} 
}


void verCompromissos() {
	
	std :: cout << "Checando compromisso"
	// Verifica se a conexão foi realizada com sucesso
	if (!conectar()) {
		std::cout << "Falha ao conectar ao banco de dados!" << std::endl;
		return;
		
void mostrarErroDoMysql(MYSQL *mysql) {
	printf("Erro: (%d) [%s] \"%s\"", mysql_errno(mysql), mysql_sqlstate(mysql), mysql_error(mysql));
	mysql_close(mysql);
	exit(-1); 
	}
}
	// Guarda um registro
	MYSQL_ROW registro;

	// Guarda todos os registros retornados
	MYSQL_RES *resultados;

	// Executa a query
	int Execucao = mysql_query(connexao, "SELECT cod, nome, data, descricao FROM Compromisso");

	// Verifica se deu tudo certo
	if (Execucao == 0) {

		// Deu certo! Recupera os registros retornados;
		resultados = mysql_store_result(connexao);

		// Mostra os registros retornados
		while ((registro = mysql_fetch_row(resultados))) {
			std::cout << registro[0] << "\t" << registro[1] << "\t" << registro[2] << std::endl;
		}
	} else {
		// Algo deu errado!
		mostrarErroDoMysql(connexao);
		std::cout << "Falha ao recuperar os registros!" << std::endl;
		
	void mostrarErroDoMysql(MYSQL *mysql) {
	printf("Erro: (%d) [%s] \"%s\"", mysql_errno(mysql), mysql_sqlstate(mysql), mysql_error(mysql));
	mysql_close(mysql);
	exit(-1); 
	}
}

void excluirCompromisso () {
	
	const sim = 1;
	const não = 2;
	
	char compromisso; 
	
		std :: cout << "Informe o compromisso que deseja excluir." << std :: endl;
	std:: cin >> compromisso;
		
			std :: cout << "Deseja mesmo excluir este compromisso?" << std :: endl;
	std :: cout << sim << "- Sim" << std:: endl;
	std :: cout << não << "- Não" << std :: endl;
		
	int escolha;

	while (true) {

		std::cin >> escolha;

		// Executa a ação escolhida
		switch (opcao) {
			case sim: 
			std::string sql = "Delete Compromisso (nome, data, descricao)values ('" nome '\n' + ano + "-" + mes + "-" + dia + "','" + descricao + "')";
			
			case não:
			return;
		}
		if (Execucao == 0) {
		// Deu certo!
		std::cout << "Compromisso inserido" << std::endl;
	} else {
		// Algo deu errado!
		mostrarErroDoMysql(connexao);
		std::cout << "Falha ao inserir compromisso!" << std::endl;
	}
	
void mostrarErroDoMysql(MYSQL *mysql) {
	printf("Erro: (%d) [%s] \"%s\"", mysql_errno(mysql), mysql_sqlstate(mysql), mysql_error(mysql));
	mysql_close(mysql);
	exit(-1); 
} 
}
	
 
void editarCompromisso ();

	std::string nome, nomeN, dia, mes, ano, descricao;
	
	std ::cout<<"Informe o nome do compromisso que deseja editar:" << std :: endl;
	std :: cin >> nome;
	
	std :: cout <<"Informe o novo nome para esse compromisso:" << std ::endl;
	std :: cin >> nomeN;

	
	std::cout << "Informe o dia:";
	std::cin >> dia;


	std::cout << "Informe o mês:";
	std::cin >> mês;


	std::cout << "Informe o ano:";
	std::cin >> ano;


	std::cout << "Descreva o compromisso:";
	std::cin >> descrição;


	std::string sql = "insert into Compromisso (nome, data, descricao)values('" nomeN \n + ano + "-" + mes + "-" + dia + "','" + descricao + "')";

	// Executa a query
	int Execucao = mysql_query(connexao, sql.data());

	// Verifica se deu tudo certo
	if (Execucao == 0) {
		// Deu certo!
		std::cout << "Compromisso inserido" << std::endl;
	} else {
		// Algo deu errado!
		mostrarErroDoMysql(connexao);
		std::cout << "Falha ao inserir compromisso!" << std::endl;
	}
	
void mostrarErroDoMysql(MYSQL *mysql) {
	printf("Erro: (%d) [%s] \"%s\"", mysql_errno(mysql), mysql_sqlstate(mysql), mysql_error(mysql));
	mysql_close(mysql);
	exit(-1); 
} 
}
 
