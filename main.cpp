// Crie um programa que permita ao usuário adicionar, pesquisar, atualizar e excluir contatos de uma agenda telefônica. 
// Os contatos podem incluir informações como nome, número de telefone e endereço.

#include <iostream>
#include <string>
#include <list>

using namespace std;

// criar classe para contatos
// numero, email, nome/sobrenome, e se é numero de empresa.
class Contact{
private:
  string numero;
  string sobrenome;
  string email;
  string nome;
  // string contato[10000];
  bool empresarial;

  void set_Nome(string no){
    this->nome = no;
  }
  void set_Numero(string no){
    this->numero = no;
  }
  void set_Sobrenome(string sn){
    this->sobrenome = sn;
  }
  void set_Email(string em){
    this->email = em;
  }
  void set_Empresarial(bool emp){
    this->empresarial = emp;
  }

public:


  string get_Nome() const{
    return nome;
  }
  string get_Sobrenome() const{
    return sobrenome;
  }
  string get_Email() const{
    return email;
  }
  string get_Numero() const{
    return numero;
  }
  bool get_Empresario() const{
    return empresarial;
  } 

  Contact(string nome, string sobrenome, string email, string numero, bool empresarial){
    set_Nome(nome);
    set_Sobrenome(sobrenome);
    set_Email(email);
    set_Numero(numero);
    set_Empresarial(empresarial);
  }
  friend ostream& operator<<(ostream& os, const Contact& contact) {
    os << "Nome: " << contact.get_Nome() << endl;
    os << "Sobrenome: " << contact.get_Sobrenome() << endl;
    os << "Numero: " << contact.get_Numero() << endl;
    os << "Email: " << contact.get_Email() << endl;
    os << "empresarial: " << (contact.get_Empresario() ? "Sim" : "Não") << endl << endl;
    return os;
  }
};

void options();

void view_contacts(const list<Contact>& contacts);


int main(){
  // TESTE  
  // Contact contato1{"Roberto", "Almeida", "Feijao@gmail.com", "+5588999999999", false};
  // cout << contato1.get_Nome() << " " << contato1.get_Sobrenome() << endl << contato1.get_Numero() << endl << contato1.get_Email() << endl << contato1.get_Empresario() << endl << endl;
  // SOLICITAR DADOS AO USUARIO;
  
  list<Contact> contacts;

  string tmp_nome, tmp_numero, tmp_email, tmp_sobrenome;
  char sn;
  bool tmp_empresarial;
  int opc, qt_contacts = 0; 

  while(1){
    options();
    cin >> opc;
    getchar();

    switch(opc){
      case 1:
        system("clear");
        cout << "Nome: ";
        cin >> tmp_nome;
        cout << endl << "Sobrenome: ";
        cin >> tmp_sobrenome;
        cout << endl << "Numero: ";
        cin >> tmp_numero;
        cout << endl << "Email: ";
        cin >> tmp_email;
        cout << endl << "Numero empresarial? [s/n]: ";
        cin >> sn;
        try{
          if(sn == 's'){
            tmp_empresarial = true;
          }
          else if(sn == 'n'){
            tmp_empresarial = false;
          }
          else{
            throw(sn);
          }
        }
        catch(char mySn){
          cout << "Voce não digitou uma opção aceitavel!!" << endl;
          cout << "Opção digitada: ";
        }
        contacts.push_back(Contact{tmp_nome, tmp_sobrenome, tmp_email, tmp_numero, tmp_empresarial});
        qt_contacts++;
        system("clear");
        cout << "Contato adicionado com sucesso!" << endl;
        break;
        // Contact  contato1{tmp_nome, tmp_sobrenome, tmp_email, tmp_numero, tmp_empresarial};
      case 2:
        system("clear");
        view_contacts(contacts);
        break;
      case 3:
        cout << "-- Saindo do sistema! -- ";
        return 0;
        break;
    }
  }
  

  return 0;
}


void options(){
  system("clear");
  cout << "Escolha uma opção: " << endl << "1. Adicionar contato " << endl << "2. Contatos " << endl << "3. Sair " << endl << "Command >> ";
}

void view_contacts(const list<Contact>& contacts){
  system("clear");

  if(!contacts.empty()){
    for (const auto& contact : contacts){
      cout << "Contato: " << endl << contact;
    }
  }
  else{
    cout << "Nenhum contato foi adicionado! " << endl;
  }

  cout << endl <<"Aperte enter para continuar: ";
  getchar();
}
