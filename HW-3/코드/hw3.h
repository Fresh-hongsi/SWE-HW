#ifndef HW3_H
#define HW3_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <map>

using namespace std;

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt" //�Է� ���� �̸� ����
#define OUTPUT_FILE_NAME "output.txt" //��� ���� �̸� ����


static ifstream fin; //���� �Է� ���� ��������
static ofstream fout; //���� ��� ���� ��������

//ä�� ���� �ý��۰� ���õ� Ŭ�������� ���漱���Ѵ�.
class System;
class SignInUI;
class SignIn;
class SignOut;
class SignOutUI;
class LogIn;
class LogInUI;
class LogOut;
class LogOutUI;
class RegisterRecruitmentInfo;
class RegisterRecruitmentInfoUI;
class InquireRecruitmentInfo;
class InquireRecruitmentInfoUI;
class CancelApplicationInfoUI;
class CancelApplicationInfo;
class ViewStatisticsOfRegisteredRecruitmentInfo;
class ViewStatisticsOfRegisteredRecruitmentInfoUI;
class ViewStatisticsOfAppliedInfo;
class ViewStatisticsOfAppliedInfoUI;
class Client;
class ClientList;
class GeneralClientList;
class CompanyClientList;
class GeneralClient;
class CompanyClient;
class RecruitmentInfo;
class SearchRecruitmentInfoUI;
class SearchRecruitmentInfo;
class ApplyForRecruitmentInfoUI;
class ApplyForRecruitmentInfo;

/*
Ŭ���� �̸� : System
Ŭ���� ��� ����:  -

��� : ä�� ���� �ý��ۿ� ���� ������ ���� ����� ������


	< public ����Լ� >
	 1. void doTask()
	   -> ���Ͽ��� �Է¹��� ������ ���� ������ ��ɵ��� �����Ѵ�.


�ۼ���¥ : 2023/05/31
�ۼ��� : �ڽ�ȫ
*/
class System
{
public:
	void doTask();

};



/*
Ŭ���� �̸� : Client <Entity Ŭ����>
Ŭ���� �������: int type / string id / string pw / bool isLogIn
Ŭ���� ����Լ�: 
				Client(int type, string name, string id, string pw);  //ȸ�� ��ü�� ������
				string getId(); //ȸ���� id�� ��ȯ
				string getPw(); //ȸ���� pw�� ��ȯ
				bool getLogInStatus(); //ȸ���� �α��� ���°� ��ȯ : true �Ǵ� false
				void changeLogInStatus(); //ȸ���� �α��� ���°� �ٲ��ֱ� : true->false / false->true
				int getType(); //ȸ���� type�� ��ȯ : 1->ȸ��ȸ�� 2->�Ϲ�ȸ��
				string getName(); //ȸ���� �̸� ��ȯ
�ۼ���¥ : 2023/05/21
�ۼ��� : �ڽ�ȫ
*/
class Client
{
private:
	int type; //ȸ���� type-> 1. ȸ��ȸ�� / 2. �Ϲ�ȸ��
	string id;//ȸ���� id
	string pw;//ȸ���� pw 
	string name;//ȸ���� �̸�
	//string _num;//ȸ���� ���� ��ȣ -> ȸ��ȸ��:����ڹ�ȣ / �Ϲ�ȸ��: �ֹι�ȣ
	bool isLogIn; //ȸ���� login ���� ���� -> true: �α��� ���� / false: �α׾ƿ� ����

public:
	Client(int type, string name, string id, string pw);  //ȸ�� ��ü�� ������
	string getId(); //ȸ���� id�� ��ȯ
	string getPw(); //ȸ���� pw�� ��ȯ
	bool getLogInStatus(); //ȸ���� �α��� ���°� ��ȯ : true �Ǵ� false
	void changeLogInStatus(); //ȸ���� �α��� ���°� �ٲ��ֱ� : true->false / false->true
	//void destroy();
	int getType(); //ȸ���� type�� ��ȯ : 1->ȸ��ȸ�� 2->�Ϲ�ȸ��
	string getName(); //ȸ���� �̸� ��ȯ
};




/*
Ŭ���� �̸� : GeneralClient <Entity Ŭ����> : Client Ŭ������ ����� -> �ֹι�ȣ �ʵ常 ���� ����
Ŭ���� �������: string rrn / vector<RecruitmentInfo*> appliedList
Ŭ���� ����Լ�: GeneralClient(int type, string name, string num, string id, string pw); //�Ϲ�ȸ�� ��ü�� ������
				void addApplication(RecruitmentInfo* ri);
				vector<RecruitmentInfo*> getListAppliedInfo();//������� �۾��ϱ�
				void subApplication(string bn);
				
�ۼ���¥ : 2023/05/21
�ۼ��� : �ڽ�ȫ
*/
class GeneralClient : public Client
{
private:
	string rrn; //�Ϲ�ȸ���� �ֹι�ȣ
	vector<RecruitmentInfo*> appliedList;//�ش� �Ϲ�ȸ���� ������ ä����� ���

public:
	
	GeneralClient(int type, string name, string num, string id, string pw); //�Ϲ�ȸ�� ��ü�� ������
	void addApplication(RecruitmentInfo* ri);
	vector<RecruitmentInfo*> getListAppliedInfo();//������� �۾��ϱ�
	void subApplication(string bn);

};




/*
Ŭ���� �̸� : CompanyClient <Entity Ŭ����> : Client Ŭ������ ����� -> ����� ��ȣ �ʵ常 ���� ����
Ŭ���� �������: string bn / vector<RecruitmentInfo*> registeredList;
Ŭ���� ����Լ�:
				CompanyClient(int type, string name, string num, string id, string pw); //ȸ��ȸ�� ��ü�� ������
				RecruitmentInfo* addNewRecruitInfo(string _task, int expectedApplicantNum, string _finishDate); // ä�� ���� �����ϱ�
				string getbn(); // ��������� ��ȯ�ϱ�
				vector<RecruitmentInfo*> getListRegisteredInfo(); //ȸ��ȸ���� �ø� ä������ ��ȯ�ϱ�
�ۼ���¥ : 2023/05/21
�ۼ��� : �ڽ�ȫ
*/
class CompanyClient : public Client
{
private:
	string bn; //ȸ��ȸ���� ����� ��ȣ
	vector<RecruitmentInfo*> registeredList; //ȸ��ȸ���� ����� ä������ ����Ʈ
public:
	CompanyClient(int type, string name, string num, string id, string pw); //ȸ��ȸ�� ��ü�� ������
	RecruitmentInfo* addNewRecruitInfo(string _task, int expectedApplicantNum, string _finishDate); // ä�� ���� �����ϱ�
	string getbn(); // ��������� ��ȯ�ϱ�
	vector<RecruitmentInfo*> getListRegisteredInfo(); //ȸ��ȸ���� �ø� ä������ ��ȯ�ϱ�


};




/*
Ŭ���� �̸� : ClientList <Collection Ŭ����> : ��� Client�鿡 ���� �����͵��� ������
Ŭ���� �������: vector<Client*> cList
Ŭ���� ����Լ�:
				void addClient(Client* C); //ClientList�� attribute�� cList�� ���� ȸ�������� ȸ�� ������ �־���
				int size(); //cList�� ���� ũ�� ��ȯ
				vector<Client*> getClientList(); //cList�� ���� ��� client��ü���� ����Ʈ�� ��ȯ
				void destroy(int idx); //�ش� �ε����� client ��ü�� cList���� ����
�ۼ���¥ : 2023/05/21
�ۼ��� : �ڽ�ȫ
*/
class ClientList
{
private:
	vector<Client*> cList; //Client ������ �迭

public:
	void addClient(Client* C); //ClientList�� attribute�� cList�� ���� ȸ�������� ȸ�� ������ �־���

	int size(); //cList�� ���� ũ�� ��ȯ

	vector<Client*> getClientList(); //cList�� ���� ��� client��ü���� ����Ʈ�� ��ȯ

	void destroy(int idx); //�ش� �ε����� client ��ü�� cList���� ����

};




/*
Ŭ���� �̸� : GeneralClientList <Collection Ŭ����> : ��� GeneralClient�鿡 ���� �����͵��� ������
			-> ex) �Ϲ�ȸ���� ���, ClientList���� ���ԵǾ��ְ�, GeneralClientList���� ���ԵǾ��ִ�
Ŭ���� �������: vector<GeneralClient*> gCList
Ŭ���� ����Լ�:
				void addGeneralClient(GeneralClient* C); //GeneralClientList�� attribute�� gCList�� ���� ȸ�������� �Ϲ� ȸ�� ������ �־���
				void destroy(string id); //�ش� id���� ���� GeneralClient ��ü�� gCList���� ����
				GeneralClient* findById(string id); //�Ϲ�ȸ�� ����Ʈ���� id���� �������� �Ϲ�ȸ���� ã�Ƽ� ��ȯ�Ѵ�.
�ۼ���¥ : 2023/05/21
�ۼ��� : �ڽ�ȫ
*/
class GeneralClientList
{
private:
	vector<GeneralClient*> gCList; // GeneralClient ������ �迭
public:

	void addGeneralClient(GeneralClient* C); //GeneralClientList�� attribute�� gCList�� ���� ȸ�������� �Ϲ� ȸ�� ������ �־���
	void destroy(string id); //�ش� id���� ���� GeneralClient ��ü�� gCList���� ����
	GeneralClient* findById(string id); //�Ϲ�ȸ�� ����Ʈ���� id���� �������� �Ϲ�ȸ���� ã�Ƽ� ��ȯ�Ѵ�.
};


/*
Ŭ���� �̸� : CompanyClientList <Collection Ŭ����> : ��� CompanyClient�鿡 ���� �����͵��� ������
			-> ex) ȸ��ȸ���� ���, ClientList���� ���ԵǾ��ְ�, CompanyClientList���� ���ԵǾ��ִ�
Ŭ���� �������: vector<CompanyClient*> cCList; // CompanyClient ������ �迭
Ŭ���� ����Լ�:
				void addCompanyClient(CompanyClient* C);  //CompanyClientList�� attribute�� cCList�� ���� ȸ�������� ȸ�� ȸ�� ������ �־���
				void destroy(string id); //�ش� id���� ���� CompanyClient ��ü�� cCList���� ����
				CompanyClient* findById(string id); ȸ��ȸ���� id���� �������� ȸ��ȸ���� ����Ʈ���� ȸ��ȸ���� ã�� ��ȯ�Ѵ�.
�ۼ���¥ : 2023/05/31
�ۼ��� : �ڽ�ȫ
*/
class CompanyClientList
{
private:
	vector<CompanyClient*> cCList; // CompanyClient ������ �迭
public:
	void addCompanyClient(CompanyClient* C);  //CompanyClientList�� attribute�� cCList�� ���� ȸ�������� ȸ�� ȸ�� ������ �־���
	void destroy(string id); //�ش� id���� ���� CompanyClient ��ü�� cCList���� ����
	CompanyClient* findById(string id); //ȸ��ȸ���� id���� �������� ȸ��ȸ���� ����Ʈ���� ȸ��ȸ���� ã�� ��ȯ�Ѵ�.
};


/*
Ŭ���� �̸� : RecruitmentInfo <Entity Ŭ����> ä��������ü
Ŭ���� �������: string companyName / string bn / string task / int numOfApplicant / int expectedApplicantNum / string finishDate
Ŭ���� ����Լ�: RecruitmentInfo(string companyName, string bn, string task, int expectedApplicantNum, string finishDate)
				 string getName()const//compare > �ۼ��Ҷ� �б��������θ� ���� �� ����
				 string getBn()
				 string getTask()
				 int getApplicantNum()
				 int getExpectedApplicantNum()
				 string getFinishDate()
				 void addApplicantToRecruitment()
				 void subApplicantToRecruitment()
�ۼ���¥ : 2023/05/22
�ۼ��� : �����
*/
class RecruitmentInfo {
private:
	string companyName;
	string bn;
	string task;
	int numOfApplicant;
	int expectedApplicantNum;
	string finishDate;

public:
	RecruitmentInfo(string companyName, string bn, string task, int expectedApplicantNum, string finishDate);
	string getName()const;
	string getBn();
	string getTask();
	int getApplicantNum();
	int getExpectedApplicantNum();
	string getFinishDate();
	void addApplicantToRecruitment();
	void subApplicantToRecruitment();
};

/*
Ŭ���� �̸� : RecruitmentInfoList <Collection Ŭ����> : ��� RecruitmentInfo�� ���� �����͵� ����
Ŭ���� �������: vector<RecruitmentInfo*> rCList > GeneralClient ������ �迭
Ŭ���� ����Լ�: void setRecruitmentInfo(vector<RecruitmentInfo*> riList)
				 vector<RecruitmentInfo*> getRIList()const
				 void addNewRecruitmentInfoList(RecruitmentInfo* ri)
				 RecruitmentInfo* findByName(string companyName)
				 RecruitmentInfo* findByNum(string bn)
�ۼ���¥ : 2023/05/22
�ۼ��� : �����
*/
class RecruitmentInfoList {
private:
	vector<RecruitmentInfo*> rCList;

public:
	void setRecruitmentInfo(vector<RecruitmentInfo*> riList);
	vector<RecruitmentInfo*> getRIList()const;
	void addNewRecruitmentInfoList(RecruitmentInfo* ri);
	RecruitmentInfo* findByName(string companyName);
	RecruitmentInfo* findByNum(string bn);
};

/*
Ŭ���� �̸� : SignInUI <Boundary Ŭ����> : ȸ�� ���԰� ���õ� interface�� ����Ѵ�.
Ŭ���� �������: SignIn* signIn / int type / string name / string num / string id / string pw
Ŭ���� ����Լ�:
				SignInUI(SignIn* signIn); //�ٿ���� Ŭ������ ������-> ��Ʈ�� Ŭ������ ���۷����� attribute�� ����
				void startInterface(); //ȸ�� ������ ������ �Է��϶�� ȭ���� ������
				void fillInfo(); //�� ȸ������ �ʿ� ������ �Է¹ް�, ��Ʈ�� Ŭ�������� ȸ�������϶�� addNewClient�Լ� ȣ����
�ۼ���¥ : 2023/05/21
�ۼ��� : �ڽ�ȫ
*/
class SignInUI {
private:

	SignIn* signIn; //ȸ�� ���԰� ���õ� ��Ʈ�� Ŭ������ ���۷����� attribute�� ������. -> �̸� ���� control Ŭ������ public ����Լ� ȣ�� ����
	int type; //ȸ���� �Է��� ȸ�� type��
	string name; //ȸ���� �Է��� �̸�/ȸ���̸�
	string num;  //ȸ���� �Է��� �ֹι�ȣ/����ڹ�ȣ
	string id; //ȸ���� �Է��� id
	string pw; //ȸ���� �Է��� pw



public:
	SignInUI(SignIn* signIn); //�ٿ���� Ŭ������ ������-> ��Ʈ�� Ŭ������ ���۷����� attribute�� ����
	void startInterface(); //ȸ�� ������ ������ �Է��϶�� ȭ���� ������
	void fillInfo(); //�� ȸ������ �ʿ� ������ �Է¹ް�, ��Ʈ�� Ŭ�������� ȸ�������϶�� addNewClient�Լ� ȣ����


};

/*
Ŭ���� �̸� : SignIn <Control Ŭ����> : ȸ�� ���԰� ���õ� control�� ����Ѵ�.
Ŭ���� �������: SignInUI* signInUI / ClientList* cList / CompanyClientList* ccList / GeneralClientList* gcList
Ŭ���� ����Լ�:
				SignIn(ClientList* list, GeneralClientList* gcList, CompanyClientList* ccList); 
				//��Ʈ�� Ŭ������ ������-> �ٿ���� Ŭ������ ���۷����� attribute�� ����
				void addNewClient(int type, string name, string num, string id, string pw); 
				//�ٿ���� Ŭ�������� �Ű������� ���� ȸ���� ������ �̿��� ȸ�� ����Ʈ�� �����ϰ�, ȸ���� Ÿ�Կ� ���� �Ϲ�ȸ��/ȸ��ȸ���� ����Ʈ�� �����Ѵ�. 

�ۼ���¥ : 2023/05/21
�ۼ��� : �ڽ�ȫ
*/
class SignIn {
	SignInUI* signInUI; //�ٿ���� Ŭ������ ���۷����� ������ ����
	ClientList* cList; //ȸ������ ������ ���� collection class�� instance
	CompanyClientList* ccList; //ȸ�� ȸ������ ������ ���� collection class�� instance
	GeneralClientList* gcList; //�Ϲ� ȸ������ ������ ���� collection class�� instance

public:
	SignIn(ClientList* list, GeneralClientList* gcList, CompanyClientList* ccList); //��Ʈ�� Ŭ������ ������-> �ٿ���� Ŭ������ ���۷����� attribute�� ����
	void addNewClient(int type, string name, string num, string id, string pw); //�ٿ���� Ŭ�������� �Ű������� ���� ȸ���� ������ �̿��� ȸ�� ����Ʈ�� �����ϰ�, ȸ���� Ÿ�Կ� ���� �Ϲ�ȸ��/ȸ��ȸ���� ����Ʈ�� �����Ѵ�. 
};


/*
Ŭ���� �̸� : LogIn <Control Ŭ����> : �α��ΰ� ���õ� control�� ����Ѵ�.
Ŭ���� �������: LogInUI* logInUI / ClientList* cList / CompanyClientList* ccList / GeneralClientList* gcList / Client* curLogInClient
Ŭ���� ����Լ�:
				LogIn(ClientList* list, GeneralClientList* gcList, CompanyClientList* ccList); 
				//��Ʈ�� Ŭ������ ������-> �ٿ���� Ŭ������ ���۷����� attribute�� ����

				void tryLogIn(string id, string pw); 
				//�α����� ������ ���, client�� isLogIn�ʵ带 false���� true�� �ٲ��ش�

				Client* getLogInClient(); 
				//���� �α��ε� ȸ���� �������� ��ȯ���ִ� �Լ�
�ۼ���¥ : 2023/05/21
�ۼ��� : �ڽ�ȫ
*/
class LogIn {
private:

	LogInUI* logInUI; //�ٿ���� Ŭ������ ���۷����� ������ ����
	ClientList* cList; //ȸ������ ������ ���� collection class�� instance
	CompanyClientList* ccList; //ȸ�� ȸ������ ������ ���� collection class�� instance
	GeneralClientList* gcList; //�Ϲ� ȸ������ ������ ���� collection class�� instance
	Client* curLogInClient; //���� �α��ε� ȸ���� reference�� ���� ����

public:
	LogIn(ClientList* list, GeneralClientList* gcList, CompanyClientList* ccList); //��Ʈ�� Ŭ������ ������-> �ٿ���� Ŭ������ ���۷����� attribute�� ����
	void tryLogIn(string id, string pw); //�α����� ������ ���, client�� isLogIn�ʵ带 false���� true�� �ٲ��ش�
	Client* getLogInClient(); //���� �α��ε� ȸ���� �������� ��ȯ���ִ� �Լ�
};


/*
Ŭ���� �̸� : LogInUI <Boundary Ŭ����> : �α��ΰ� ���õ� interface�� ����Ѵ�.
Ŭ���� �������: LogIn* logIn / string id / string pw
Ŭ���� ����Լ�: 
				LogInUI(LogIn* logIn); //�ٿ���� Ŭ������ ������-> ��Ʈ�� Ŭ������ ���۷����� attribute�� ����
				void startInterface();  //ȸ�� id�� pw�� �Է��϶�� ȭ���� ������
				void fillIDPW(); //�� ȸ������ �ʿ� ������ �Է¹ް�, ��Ʈ�� Ŭ�������� �α��� �õ��϶�� tryLogIn �Լ� ȣ����
�ۼ���¥ : 2023/05/21
�ۼ��� : �ڽ�ȫ
*/
class LogInUI {
private:

	LogIn* logIn; //��Ʈ�� Ŭ������ ���۷����� ������ ����
	string id; //ȸ���� �Է��� id
	string pw; //ȸ���� �Է��� pw



public:
	LogInUI(LogIn* logIn); //�ٿ���� Ŭ������ ������-> ��Ʈ�� Ŭ������ ���۷����� attribute�� ����
	void startInterface();  //ȸ�� id�� pw�� �Է��϶�� ȭ���� ������
	void fillIDPW(); //�� ȸ������ �ʿ� ������ �Է¹ް�, ��Ʈ�� Ŭ�������� �α��� �õ��϶�� tryLogIn �Լ� ȣ����


};


/*
Ŭ���� �̸� : LogOut <Control Ŭ����> : �α׾ƿ��� ���õ� control�� ����Ѵ�.
Ŭ���� �������: LogOutUI* logOutUI / ClientList* cList / CompanyClientList* ccList / GeneralClientList* gcList / Client* curLogInClient
Ŭ���� ����Լ�: 
				private: void changeLogInStatus(Client* client); //���� �α��εǾ��ִ� ������ �α׾ƿ� ��Ű�� ����� ��
				LogOut(ClientList* list, GeneralClientList* gcList, CompanyClientList* ccList, Client* client); //��Ʈ�� Ŭ������ ������-> �ٿ���� Ŭ������ ���۷����� attribute�� ����
�ۼ���¥ : 2023/05/21
�ۼ��� : �ڽ�ȫ
*/
class LogOut {
private:

	LogOutUI* logOutUI; //�ٿ���� Ŭ������ ���۷����� ������ ����
	ClientList* cList; //ȸ������ ������ ���� collection class�� instance
	CompanyClientList* ccList; //ȸ�� ȸ������ ������ ���� collection class�� instance
	GeneralClientList* gcList; //�Ϲ� ȸ������ ������ ���� collection class�� instance
	Client* curLogInClient; //�α��� ��ü�� �Ű������� �������� ���� �α��� �� client������ ������ ����
	void changeLogInStatus(Client* client); //���� �α��εǾ��ִ� ������ �α׾ƿ� ��Ű�� ����� ��

public:
	LogOut(ClientList* list, GeneralClientList* gcList, CompanyClientList* ccList, Client* client); //��Ʈ�� Ŭ������ ������-> �ٿ���� Ŭ������ ���۷����� attribute�� ����


};


/*
Ŭ���� �̸� : LogOutUI <Boundary Ŭ����> : �α׾ƿ��� ���õ� interface�� ����Ѵ�.
Ŭ���� �������: LogOut* logOut
Ŭ���� ����Լ�:
				LogOutUI(LogOut* signOut); //�ٿ���� Ŭ������ ������-> ��Ʈ�� Ŭ������ ���۷����� attribute�� ����
				void startInterface(string id, bool flag); //�α׾ƿ��Ǿ��ٴ� �޼����� ȭ�鿡 ������
�ۼ���¥ : 2023/05/21
�ۼ��� : �ڽ�ȫ
*/
class LogOutUI {
private:

	LogOut* logOut; //��Ʈ�� Ŭ������ ���۷����� ������ ����


public:
	LogOutUI(LogOut* signOut); //�ٿ���� Ŭ������ ������-> ��Ʈ�� Ŭ������ ���۷����� attribute�� ����
	void startInterface(string id, bool flag); //�α׾ƿ��Ǿ��ٴ� �޼����� ȭ�鿡 ������


};


/*
Ŭ���� �̸� : SignOut <Control Ŭ����> : ȸ��Ż��� ���õ� control�� ����Ѵ�.
Ŭ���� �������: SignOutUI* signOutUI / ClientList* cList / CompanyClientList* ccList / GeneralClientList* gcList / Client* curLogInClient
Ŭ���� ����Լ�:
				private: void destroy(Client* client); //�α��� �Ǿ��ִ� �ش� ȸ���� Ż���Ŵ
				SignOut(ClientList* list, GeneralClientList* gcList, CompanyClientList* ccList, Client* client);  
				//��Ʈ�� Ŭ������ ������-> �ٿ���� Ŭ������ ���۷����� attribute�� ����
�ۼ���¥ : 2023/05/31
�ۼ��� : �ڽ�ȫ
*/
class SignOut {
private:

	SignOutUI* signOutUI; //�ٿ���� Ŭ������ ���۷����� ������ ����
	ClientList* cList; //ȸ������ ������ ���� collection class�� instance
	CompanyClientList* ccList; //ȸ�� ȸ������ ������ ���� collection class�� instance
	GeneralClientList* gcList; //�Ϲ� ȸ������ ������ ���� collection class�� instance
	Client* curLogInClient; //�α��� ��ü�� �Ű������� �������� ���� �α��� �� client������ ������ ����
	void destroy(Client* client); //�α��� �Ǿ��ִ� �ش� ȸ���� Ż���Ŵ

public:
	SignOut(ClientList* list, GeneralClientList* gcList, CompanyClientList* ccList, Client* client);  //��Ʈ�� Ŭ������ ������-> �ٿ���� Ŭ������ ���۷����� attribute�� ����

};


/*
Ŭ���� �̸� : SignOutUI <Boundary Ŭ����> : ȸ��Ż��� ���õ� interface�� ����Ѵ�.
Ŭ���� �������: SignOut* signOut
Ŭ���� ����Լ�:
			SignOutUI(SignOut* signOut);  //�ٿ���� Ŭ������ ������-> ��Ʈ�� Ŭ������ ���۷����� attribute�� ����
			void startInterface(string id, bool flag); //ȸ��Ż��Ǿ��ٴ� �޼����� ȭ�鿡 ������	
�ۼ���¥ : 2023/05/21
�ۼ��� : �ڽ�ȫ
*/
class SignOutUI {
private:

	SignOut* signOut;


public:
	SignOutUI(SignOut* signOut);  //�ٿ���� Ŭ������ ������-> ��Ʈ�� Ŭ������ ���۷����� attribute�� ����
	void startInterface(string id, bool flag); //ȸ��Ż��Ǿ��ٴ� �޼����� ȭ�鿡 ������


};


/*
Ŭ���� �̸� : RegisterRecruitmentInfo <Control Ŭ����>: ä�� ����� ����մϴ�.
Ŭ���� �������: RegisterRecruitmentInfoUI* registerRecruitmentInfoUI > �ٿ���� Ŭ������ ���۷����� �����մϴ�.
				 CompanyClient* companyClient > ȸ�� ȸ��
				 RecruitmentInfo* registeredList
				 RecruitmentInfoList* recruitmentInfoList
Ŭ���� ����Լ�: RegisterRecruitmentInfo(CompanyClient* companyClient, RecruitmentInfoList* recruitmentInfoList)
				 void addNewRecruitmentInfo(string task, int expectedApplicantNum, string finishDate) > recruitment info�� ������ �߰��մϴ�.
				 RecruitmentInfoList* getRecruitmentInfoList()
				 RecruitmentInfo* getRegisteredList()
�ۼ���¥ : 2023/05/22
�ۼ��� : �����
*/
class RegisterRecruitmentInfo
{
private:
	RegisterRecruitmentInfoUI* registerRecruitmentInfoUI;
	CompanyClient* companyClient;
	RecruitmentInfo* registeredList;
	RecruitmentInfoList* recruitmentInfoList;

public:
	RegisterRecruitmentInfo(CompanyClient* companyClient, RecruitmentInfoList* recruitmentInfoList);
	void addNewRecruitmentInfo(string task, int expectedApplicantNum, string finishDate);
	RecruitmentInfoList* getRecruitmentInfoList();
	RecruitmentInfo* getRegisteredList();
};


/*
Ŭ���� �̸� : RegisterRecruitmentInfoUI <Boundary Ŭ����>: ä�� ����� ����մϴ�.
Ŭ���� �������: RegisterRecruitmentInfo* registerRecruitmentInfo
				 CompanyClient* companyClient
Ŭ���� ����Լ�: RegisterRecruitmentInfoUI(RegisterRecruitmentInfo* registerRecruitmentInfo, CompanyClient* companyClient)
				 void startInterface() > �Է°��� �о���Դϴ�.
				 void result(string task, int expectedApplicantNum, string finishDate) > ������� ȭ�鿡 ����� ǥ���մϴ�.
				 void registerInput() > ���Ͽ��� �Է°��� �޾Ƶ��Դϴ�.
�ۼ���¥ : 2023/05/21
�ۼ��� : �����
*/
class RegisterRecruitmentInfoUI
{
private:
	RegisterRecruitmentInfo* registerRecruitmentInfo;
	CompanyClient* companyClient;

public:
	RegisterRecruitmentInfoUI(RegisterRecruitmentInfo* registerRecruitmentInfo, CompanyClient* companyClient);
	void startInterface(); 
	void result(string task, int expectedApplicantNum, string finishDate); 
	void registerInput(); 
};

/*
Ŭ���� �̸� : InquireRecruitmentInfo <Control Ŭ����>: ä�� ��ȸ�� ����մϴ�.
Ŭ���� �������:CompanyClient* companyClient
Ŭ���� ����Լ�:InquireRecruitmentInfo(CompanyClient* companyClient)
�ۼ���¥ : 2023/05/22
�ۼ��� : �����
*/
class InquireRecruitmentInfo
{
private:
	CompanyClient* companyClient;
public:
	InquireRecruitmentInfo(CompanyClient* companyClient);

};

/*
Ŭ���� �̸� : InquireRecruitmentInfoUI <Boundary Ŭ����>: ä�� ��ȸ�� ����մϴ�.
Ŭ���� �������: InquireRecruitmentInfo* inquireRecruitmentInfo > �ٿ���� Ŭ������ ���۷����� ������ �����Դϴ�.
Ŭ���� ����Լ�: InquireRecruitmentInfoUI(InquireRecruitmentInfo* inquireRecruitmentInfo)
				 void startInterface(vector<RecruitmentInfo*> riList) > ������� ȸ�� ȸ���� RecruitmentInfo�� �����ݴϴ�.
�ۼ���¥ : 2023/05/22
�ۼ��� : �����
*/
class InquireRecruitmentInfoUI
{
private:
	InquireRecruitmentInfo* inquireRecruitmentInfo;
public:
	InquireRecruitmentInfoUI(InquireRecruitmentInfo* inquireRecruitmentInfo);
	void startInterface(vector<RecruitmentInfo*> riList);
};



/*
Ŭ�����̸�:
Ŭ���� �������:
	SearchRecruitmentInfo* searchRecruitmentInfo: ControlŬ������ Reference
	string companyName; ȸ���� �Է��� ȸ���̸�
Ŭ���� ����Լ�:
	void startInterface(): �˻�â�� �Է��� ȭ���� �����ִ� �Լ�
	void fillInput(): �˻��� �޴� �Լ�
�ۼ� ��¥: 2023/05/22
�ۼ���: ������
*/

class SearchRecruitmentInfoUI {
private:
	SearchRecruitmentInfo* searchRecruitmentInfo;
	string companyName;
public:
	SearchRecruitmentInfoUI(SearchRecruitmentInfo* searchRecruitmentInfo);
	void startInterface();
	void fillInput();


};
/*
Ŭ�����̸� : SearchRecruitmentInfo <Control Ŭ����>: ä�������˻��� �����.
Ŭ���� �������: 
	RecruitmentInfoList *riList; ���� ���ǿ��� ��ϵ� ä�������
	string companyName: ȸ���� �˻��� ȸ���̸�
	RecruitmentInfo* result: ȸ���� �˻��� ȸ���� ä����
Ŭ���� ����Լ�:
	RecruitmentInfo* getResult(): �˻� ��� RecruitmentInfo�� ��ȯ�ϴ� �Լ�
	void searchRecruitmentInfoListByComName(string name): ��ϵ� ä������� �˻��� ȸ���̸����� ä����� ã�� �Լ�
�ۼ� ��¥: 2023/05/22
�ۼ���: ������
*/
class SearchRecruitmentInfo {
private:
	RecruitmentInfoList* riList;
	string companyName;
	RecruitmentInfo* result;
	SearchRecruitmentInfoUI* searchRecruitmentInfoUI;
public:
	SearchRecruitmentInfo(RecruitmentInfoList* riList);
	RecruitmentInfo* getResult();
	void searchRecruitmentInfoListByComName(string name);
};
	

/*
Ŭ���� �̸�: ApplyForRecruitmentInfoUI <Boundary> Ŭ����: ä�� ������ �����
Ŭ���� �������:
	string bn; ȸ���� ������ ȸ���� ����� ��ȣ
	ApplyForRecruitmentInfo* applyForRecruitmentInfo: Control Class�� Reference
Ŭ���� ����Լ�:
	void startInterface(RecruitmentInfoList* riList); ��ϵ� ä������ ����Ʈ�� �����ִ� �Լ�
	void fillComName(); �Ϲ� ȸ���� ������ ȸ���� ����� ��ȣ�� �Է��ϴ� �Լ�
*/
class ApplyForRecruitmentInfoUI {
private:
	string bn;
	ApplyForRecruitmentInfo* applyForRecruitmentInfo;
public:
	ApplyForRecruitmentInfoUI(ApplyForRecruitmentInfo* applyForRecruitmentInfo);
	void startInterface(RecruitmentInfoList* riList);
	void fillComName();
};

/*
Ŭ�����̸�: ApplyForRecruitmentInfo <Control> Ŭ���� : ä�� ������ �����
Ŭ���� �������:
	GeneralClient* gClient: �����Ϸ����ϴ� �Ϲ� ȸ��
	RecruitmentInfoList* riList: ���� ��ϵ� ä�� ���� ���
	RecruitmentInfo* appliedRecruitmentInfo: �α����� �Ϲ�ȸ���� ������ ä�����

Ŭ���� ����Լ�:
	void addApplicant(string bn): bn�� ����ڹ�ȣ�� ���� ä����� �����ϴ� ���
�ۼ���¥: 2023/05/23
�ۼ���: ������
*/

class ApplyForRecruitmentInfo {
private:
	GeneralClient* gClient;
	RecruitmentInfoList* riList;
	RecruitmentInfo* appliedRecruitmentInfo;
	ApplyForRecruitmentInfoUI* applyForRecruitmentInfoUI;

public:
	ApplyForRecruitmentInfo(GeneralClient* gClient, RecruitmentInfoList* riList);
	void addApplicant(string bn);
};

/*
Ŭ���� �̸�: InquireApplicationInfoUI <Boundary> Ŭ����: �������� ��ȸ�� �����
Ŭ���� �������:
Ŭ���� ����Լ�:
	void startInterface(vector<RecruitmentInfo*> gcAppliedList); �Ϲ�ȸ���� ������ �������� ����� ��������
�ۼ���¥: 2023/05/23
�ۼ���: ������
*/

class InquireApplicationInfoUI {
private:
	
public:
	
 	void startInterface(vector<RecruitmentInfo*> gcAppliedList);
};

/*
Ŭ���� �̸�: InquireApplicationInfo <Control>Ŭ���� ���� ���� ��ȸ�� �����.
Ŭ���� �������:
	GeneralClient* gClient; ���� ������ ��ȸ�� �Ϲ� ȸ��
	vector<RecruitmentInfo*> gcAppliedList; �Ϲ�ȸ���� ������ ȸ�� ��� ����Ʈ
Ŭ���� ����Լ�:

�ۼ� ��¥: 2023/05/23
�ۼ���: ������
*/

class InquireApplicationInfo {
private:
	GeneralClient* gClient;
	vector<RecruitmentInfo*> gcAppliedList;
	InquireApplicationInfoUI* inquireApplicationInfoUI;
public:
	InquireApplicationInfo(GeneralClient* gClient);
};

/*
Ŭ���� �̸�: CompareRecruitmentInfo ��� : RecruitmentInfo�� pointer�� ���ϴ� Ŭ����
Ŭ���� ��� ����: ����
Ŭ���� ��� �Լ�: bool operator()(const RecruitmentInfo* a, const RecruitmentInfo* b): �� RecruitmentInfo�� ���ϴ� oeprator
�ۼ� ��¥: 2023/05/23
�ۼ���: ������
*/


class CompareRecruitmentInfo {//RecruitmentInfo pointer�� ���ϴ� Ŭ����

public:
	bool operator()(const RecruitmentInfo* a, const RecruitmentInfo* b);
};

/*
Ŭ���� �̸� : CancelApplicationInfoUI <Boundary Ŭ����>: ���� ��Ҹ� ����մϴ�.
Ŭ���� �������: CancelApplicationInfo* cancelApplicationInfo > �ٿ���� Ŭ������ ���۷����� ������ �����Դϴ�.
Ŭ���� ����Լ�: CancelApplicationInfoUI(CancelApplicationInfo* cancelApplicationInfo)
				 void startInterface(RecruitmentInfoList* riList)
�ۼ���¥ : 2023/05/22
�ۼ��� : �����
*/
class CancelApplicationInfoUI
{
private:
	CancelApplicationInfo* cancelApplicationInfo;
	
public:
	CancelApplicationInfoUI(CancelApplicationInfo* cancelApplicationInfo);
	void startInterface(RecruitmentInfoList* riList);
};

/*
Ŭ���� �̸� : CancelApplicationInfo <Control Ŭ����>: ���� ��Ҹ� ����մϴ�.
Ŭ���� �������: GeneralClient* gClient > ���� ����Ϸ��� �Ϲ�ȸ���Դϴ�.
				 RecruitmentInfoList* riList > ���� ��ϵǾ��ִ� ä��������Դϴ�.
				 vector<RecruitmentInfo*> gcRiList > �Ϲ�ȸ���� ������ ä����� ����Դϴ�.
				 RecruitmentInfo* toCancelRecruitmentInfo > ������ ������ ��Ҹ� ���ϴ� ä�� �����Դϴ�.
				 CancelApplicationInfoUI* cancelApplicationInfoUI > ��Ʈ�� Ŭ������ ���۷����� ������ �����Դϴ�.
				 string bn > �Ϲ�ȸ���� ����Ϸ��� ä�� ������ ����ڹ�ȣ�Դϴ�.
Ŭ���� ����Լ�: CancelApplicationInfo(GeneralClient* gClient, RecruitmentInfoList* riList)
				 void cancelApplication(string bn)
�ۼ���¥ : 2023/05/22
�ۼ��� : �����
*/
class CancelApplicationInfo
{
private:
	GeneralClient* gClient;//���� ����Ϸ��� �Ϲ�ȸ��
	RecruitmentInfoList* riList;//���� ��ϵǾ��ִ� ä�������]
	vector<RecruitmentInfo*> gcRiList;//�Ϲ�ȸ���� ������ ä����� ���
	RecruitmentInfo* toCancelRecruitmentInfo;//������ ������, ����Ϸ���, ä�� ����
	CancelApplicationInfoUI* cancelApplicationInfoUI;
	string bn;//�Ϲ�ȸ���� ����Ϸ��� bn


public:
	CancelApplicationInfo(GeneralClient* gClient, RecruitmentInfoList* riList);
	void cancelApplication(string bn);
};

/*
Ŭ���� �̸� : ViewStatisticsOfRegisteredRecruitmentInfo <Control Ŭ����>: ȸ��ȸ�� ��踦 ����մϴ�.
Ŭ���� �������: 
	CompanyClient*cClient -> ȸ�� ȸ������ ������ ���� CompanyClient ��ü
	ViewstatisticsOfRegisteredRecruitmentInfo*viewStatisticsOfRegisteredRecruitmentInfo -> �ٿ���� Ŭ������ ���۷����� ������ ����
Ŭ���� ����Լ�:
	printStatisticsInfo(CompanyClient *cClient) -> ��� ä�������� ���� ������ ������ ���� �����ش�.
�ۼ���¥ : 2023/05/22
�ۼ��� : ��ä��
*/
class ViewStatisticsOfRegisteredRecruitmentInfo{
private:
	CompanyClient* cClient;
	ViewStatisticsOfRegisteredRecruitmentInfo* viewStatisticsOfRegisteredRecruitmentInfo;
public:
	ViewStatisticsOfRegisteredRecruitmentInfo(CompanyClient *cClient);
	void printStatisticsInfo(CompanyClient *cClient);
};

/*
Ŭ���� �̸� : ViewStatisticsOfRegisteredRecruitmentInfo <Boundary Ŭ����>: ȸ��ȸ�� ��踦 ����մϴ�.
Ŭ���� �������:
	ViewstatisticsOfRegisteredRecruitmentInfo*viewStatisticsOfRegisteredRecruitmentInfo -> ��Ʈ�� Ŭ������ ���۷����� ������ ����
Ŭ���� ����Լ�:
�ۼ���¥ : 2023/05/22
�ۼ��� : ��ä��
*/
class ViewStatisticsOfRegisteredRecruitmentInfoUI{
private:
	ViewStatisticsOfRegisteredRecruitmentInfo* viewStatisticsOfRegisteredRecruitmentInfo;
public:
};

/*
Ŭ���� �̸� : ViewStatisticsOfAppliedInfo <Control Ŭ����>: �Ϲ�ȸ�� ��踦 ����մϴ�.
Ŭ���� �������:
	GeneralClient *gClient -> �Ϲ� ȸ������ ������ ���� GeneralClient ��ü
	ViewStatisticsOfAppliedInfo *viewStatisticsOfAppliedInfo -> �ٿ���� Ŭ������ ���۷����� ������ ����
Ŭ���� ����Լ�:
	printStatisticsInfo(GeneralClient *gClient) -> ��� ���������� ���� ������ ���� Ƚ���� �����ش�.
�ۼ���¥ : 2023/05/22
�ۼ��� : ��ä��
*/
class ViewStatisticsOfAppliedInfo{
private:
	GeneralClient *gClient;
	ViewStatisticsOfAppliedInfo *viewStatisticsOfAppliedInfo;
public:
	ViewStatisticsOfAppliedInfo(GeneralClient *gClient);
	void printStatisticsInfo(GeneralClient *gClient); 
};

/*
Ŭ���� �̸� : ViewStatisticsOfAppliedInfo <Boundary Ŭ����>: �Ϲ�ȸ�� ��踦 ����մϴ�.
Ŭ���� �������: 
	ViewStatisticsOfAppliedInfo* viewStatisticsOfAppliedInfo -> ��Ʈ�� Ŭ������ ���۷����� ������ ����
Ŭ���� ����Լ�:
�ۼ���¥ : 2023/05/22
�ۼ��� : ��ä��
*/
class ViewStatisticsOfAppliedInfoUI{
private:
	ViewStatisticsOfAppliedInfo* viewStatisticsOfAppliedInfo;
public:
};

#endif // !1



