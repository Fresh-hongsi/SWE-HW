#ifndef HW3_H
#define HW3_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

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
Ŭ���� �������:
Ŭ���� ����Լ�:
�ۼ���¥ : 2023/05/31
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
Ŭ���� �������:
Ŭ���� ����Լ�:
�ۼ���¥ : 2023/05/31
�ۼ��� : �ڽ�ȫ
*/
class GeneralClient : public Client
{
private:
	string _rrn; //�Ϲ�ȸ���� �ֹι�ȣ
	vector<RecruitmentInfo*> appliedList;//�ش� ȸ���� ������ ����Ʈ

public:
	
	GeneralClient(int type, string name, string num, string id, string pw); //�Ϲ�ȸ�� ��ü�� ������
	void addApplication(RecruitmentInfo* ri);
	vector<RecruitmentInfo*> getListAppliedInfo();

};




/*
Ŭ���� �̸� : CompanyClient <Entity Ŭ����> : Client Ŭ������ ����� -> ����� ��ȣ �ʵ常 ���� ����
Ŭ���� �������:
Ŭ���� ����Լ�:
�ۼ���¥ : 2023/05/31
�ۼ��� : �ڽ�ȫ
*/
class CompanyClient : public Client
{
private:
	string _bn; //ȸ��ȸ���� ����� ��ȣ
	vector<RecruitmentInfo*> registeredList;
public:
	CompanyClient(int type, string name, string num, string id, string pw); //ȸ��ȸ�� ��ü�� ������
	RecruitmentInfo* addNewRecruitInfo(string _task, int numOfApplicant, string _finishDate); // ä�� ���� �����ϱ�
	string getbn(); // ��������� ��ȯ�ϱ�
	vector<RecruitmentInfo*> getListRegisteredInfo();


};




/*
Ŭ���� �̸� : ClientList <Collection Ŭ����> : ��� Client�鿡 ���� �����͵��� ������
Ŭ���� �������:
Ŭ���� ����Լ�:
�ۼ���¥ : 2023/05/31
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

	//int count(); 


};




/*
Ŭ���� �̸� : GeneralClientList <Collection Ŭ����> : ��� GeneralClient�鿡 ���� �����͵��� ������
			-> ex) �Ϲ�ȸ���� ���, ClientList���� ���ԵǾ��ְ�, GeneralClientList���� ���ԵǾ��ִ�
Ŭ���� �������:
Ŭ���� ����Լ�:
�ۼ���¥ : 2023/05/31
�ۼ��� : �ڽ�ȫ
*/
class GeneralClientList
{
private:
	vector<GeneralClient*> gCList; // GeneralClient ������ �迭
public:

	void addGeneralClient(GeneralClient* C); //GeneralClientList�� attribute�� gCList�� ���� ȸ�������� �Ϲ� ȸ�� ������ �־���
	void destroy(string id); //�ش� id���� ���� GeneralClient ��ü�� gCList���� ����
	GeneralClient* findById(string id);//�ش縮��Ʈ���� id�� �������� ȸ��ã�°�
};


/*
Ŭ���� �̸� : CompanyClientList <Collection Ŭ����> : ��� CompanyClient�鿡 ���� �����͵��� ������
			-> ex) ȸ��ȸ���� ���, ClientList���� ���ԵǾ��ְ�, CompanyClientList���� ���ԵǾ��ִ�
Ŭ���� �������:
Ŭ���� ����Լ�:
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
	CompanyClient* findById(string id);
};


/*
Ŭ���� �̸� : RecruitmentInfo Ŭ����
Ŭ���� �������:
Ŭ���� ����Լ�:
�ۼ���¥ : 2023/05/22
�ۼ��� : �����
*/
class RecruitmentInfo {
private:
	string companyName;
	string bn;
	string task;
	int numOfApplicant;//�����ڼ�
	int expectedApplicantNum;//�����ο�
	string finishDate;

public:
	RecruitmentInfo(string companyName, string bn, string task, int expectedApplicantNum, string finishDate);
	//RecruitmentInfo* getRecruitmentInfoDetails(RecruitmentInfo* ri);�ʿ���µ�?
	
	string getName()const;//compare�ۼ��Ҷ� �б��������θ� ���� �� ����
	string getBn();
	string getTask();
	int getApplicantNum();
	int getExpectedApplicantNum();
	string getFinishDate();
	void addApplicantToRecruitment();
	
};

class RecruitmentInfoList {
private:
	vector<RecruitmentInfo*> rCList; // GeneralClient ������ �迭

public:
	
	
	void setRecruitmentInfo(vector<RecruitmentInfo*> riList);
	//RecruitmentInfoList(vector<RecruitmentInfo*>riList);
	vector<RecruitmentInfo*> getRIList();
	void addNewRecruitmentInfoList(RecruitmentInfo* ri);
	RecruitmentInfo* findByName(string companyName);
	RecruitmentInfo* findByNum(string bn);
	bool compare(const RecruitmentInfo* a, const RecruitmentInfo* b);//�ڽ��� ����Ʈ�� �������� ���ķ� �����ϴ� �Լ�

};

/*
Ŭ���� �̸� : SignInUI <Boundary Ŭ����> : ȸ�� ���԰� ���õ� interface�� ����Ѵ�.
Ŭ���� �������:
Ŭ���� ����Լ�:
�ۼ���¥ : 2023/05/31
�ۼ��� : �ڽ�ȫ
*/
class SignInUI {
private:

	SignIn* pSignIn; //ȸ�� ���԰� ���õ� ��Ʈ�� Ŭ������ ���۷����� attribute�� ������. -> �̸� ���� control Ŭ������ public ����Լ� ȣ�� ����
	int type; //ȸ���� �Է��� ȸ�� type��
	string name; //ȸ���� �Է��� �̸�/ȸ���̸�
	string num;  //ȸ���� �Է��� �ֹι�ȣ/����ڹ�ȣ
	string id; //ȸ���� �Է��� id
	string pw; //ȸ���� �Է��� pw



public:
	SignInUI(SignIn* refSignIn); //�ٿ���� Ŭ������ ������-> ��Ʈ�� Ŭ������ ���۷����� attribute�� ����
	void startInterface(); //ȸ�� ������ ������ �Է��϶�� ȭ���� ������
	void fillInfo(); //�� ȸ������ �ʿ� ������ �Է¹ް�, ��Ʈ�� Ŭ�������� ȸ�������϶�� addNewClient�Լ� ȣ����


};

/*
Ŭ���� �̸� : SignIn <Control Ŭ����> : ȸ�� ���԰� ���õ� control�� ����Ѵ�.
Ŭ���� �������:
Ŭ���� ����Լ�:
�ۼ���¥ : 2023/05/31
�ۼ��� : �ڽ�ȫ
*/
class SignIn {
	SignInUI* pSignInUI; //�ٿ���� Ŭ������ ���۷����� ������ ����
	ClientList* cList; //ȸ������ ������ ���� collection class�� instance
	CompanyClientList* ccList; //ȸ�� ȸ������ ������ ���� collection class�� instance
	GeneralClientList* gcList; //�Ϲ� ȸ������ ������ ���� collection class�� instance

public:
	SignIn(ClientList* list, GeneralClientList* gcList, CompanyClientList* ccList); //��Ʈ�� Ŭ������ ������-> �ٿ���� Ŭ������ ���۷����� attribute�� ����
	void addNewClient(int type, string name, string num, string id, string pw); //�ٿ���� Ŭ�������� �Ű������� ���� ȸ���� ������ �̿��� ȸ�� ����Ʈ�� �����ϰ�, ȸ���� Ÿ�Կ� ���� �Ϲ�ȸ��/ȸ��ȸ���� ����Ʈ�� �����Ѵ�. 
};


/*

Ŭ���� �̸� : LogIn <Control Ŭ����> : �α��ΰ� ���õ� control�� ����Ѵ�.
Ŭ���� �������:
Ŭ���� ����Լ�:
�ۼ���¥ : 2023/05/31
�ۼ��� : �ڽ�ȫ
*/
class LogIn {
private:

	LogInUI* pLogInUI; //�ٿ���� Ŭ������ ���۷����� ������ ����
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
Ŭ���� �������:
Ŭ���� ����Լ�:
�ۼ���¥ : 2023/05/31
�ۼ��� : �ڽ�ȫ
*/
class LogInUI {
private:

	LogIn* pLogIn; //��Ʈ�� Ŭ������ ���۷����� ������ ����
	string id; //ȸ���� �Է��� id
	string pw; //ȸ���� �Է��� pw



public:
	LogInUI(LogIn* refLogIn); //�ٿ���� Ŭ������ ������-> ��Ʈ�� Ŭ������ ���۷����� attribute�� ����
	void startInterface();  //ȸ�� id�� pw�� �Է��϶�� ȭ���� ������
	void fillIDPW(); //�� ȸ������ �ʿ� ������ �Է¹ް�, ��Ʈ�� Ŭ�������� �α��� �õ��϶�� tryLogIn �Լ� ȣ����


};


/*
Ŭ���� �̸� : LogOut <Control Ŭ����> : �α׾ƿ��� ���õ� control�� ����Ѵ�.
Ŭ���� �������:
Ŭ���� ����Լ�:
�ۼ���¥ : 2023/05/31
�ۼ��� : �ڽ�ȫ
*/
class LogOut {
private:

	LogOutUI* pLogOutUI; //�ٿ���� Ŭ������ ���۷����� ������ ����
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
Ŭ���� �������:
Ŭ���� ����Լ�:
�ۼ���¥ : 2023/05/31
�ۼ��� : �ڽ�ȫ
*/
class LogOutUI {
private:

	LogOut* pLogOut; //��Ʈ�� Ŭ������ ���۷����� ������ ����


public:
	LogOutUI(LogOut* refSignOut); //�ٿ���� Ŭ������ ������-> ��Ʈ�� Ŭ������ ���۷����� attribute�� ����
	void startInterface(string id, bool flag); //�α׾ƿ��Ǿ��ٴ� �޼����� ȭ�鿡 ������


};


/*
Ŭ���� �̸� : SignOut <Control Ŭ����> : ȸ��Ż��� ���õ� control�� ����Ѵ�.
Ŭ���� �������:
Ŭ���� ����Լ�:
�ۼ���¥ : 2023/05/31
�ۼ��� : �ڽ�ȫ
*/
class SignOut {
private:

	SignOutUI* pSignOutUI; //�ٿ���� Ŭ������ ���۷����� ������ ����
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
Ŭ���� �������:
Ŭ���� ����Լ�:
�ۼ���¥ : 2023/05/31
�ۼ��� : �ڽ�ȫ
*/
class SignOutUI {
private:

	SignOut* pSignOut;




public:
	SignOutUI(SignOut* refSignOut);  //�ٿ���� Ŭ������ ������-> ��Ʈ�� Ŭ������ ���۷����� attribute�� ����
	void startInterface(string id, bool flag); //ȸ��Ż��Ǿ��ٴ� �޼����� ȭ�鿡 ������


};


/*
Ŭ���� �̸� : RegisterRecruitmentInfo <Control Ŭ����>: ä�� ����� ����մϴ�.
Ŭ���� �������:
Ŭ���� ����Լ�:
�ۼ���¥ : 2023/05/22
�ۼ��� : �����
*/
class RegisterRecruitmentInfo
{
private:
	RegisterRecruitmentInfoUI* registerRecruitmentInfoUI; // �ٿ���� Ŭ������ ���۷����� �����մϴ�.
	CompanyClient* companyClient; // ȸ�� ȸ��
	RecruitmentInfo* registeredList;
	RecruitmentInfoList* recruitmentInfoList;

public:
	RegisterRecruitmentInfo(CompanyClient* companyClient, RecruitmentInfoList* recruitmentInfoList);
	void addNewRecruitmentInfo(string task, int numOfApplicant, string finishDate); // recruitment info�� ������ �߰��մϴ�
	RecruitmentInfoList* getRecruitmentInfoList();
	RecruitmentInfo* getRegisteredList();
};

//this->re.push_back()

/*
Ŭ���� �̸� : RegisterRecruitmentInfoUI <Boundary Ŭ����>: ä�� ����� ����մϴ�.
Ŭ���� �������:
Ŭ���� ����Լ�:
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
	void startInterface(); // �������̽� ����
	void result(string task, int numOfApplicant, string finishDate); // ������� ȭ�鿡 ����� ǥ���մϴ�
	void registerInput(); //���Ͽ��� �Է°��� �޾Ƶ���
};

/*
Ŭ���� �̸� : InquireRecruitmentInfo <Control Ŭ����>: ä�� ��ȸ�� ����մϴ�.
Ŭ���� �������:
Ŭ���� ����Լ�:
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
Ŭ���� �̸� : InquireRecruitmentInfo <Boundary Ŭ����>: ä�� ��ȸ�� ����մϴ�.
Ŭ���� �������:
Ŭ���� ����Լ�:
�ۼ���¥ : 2023/05/22
�ۼ��� : �����
*/
class InquireRecruitmentInfoUI
{
private:
	InquireRecruitmentInfo* inquireRecruitmentInfo;
public:
	InquireRecruitmentInfoUI(InquireRecruitmentInfo* inquireRecruitmentInfo);
	void startInterface(vector<RecruitmentInfo*> riList); // ������� ȸ�� ȸ���� RecruitmentInfo�� �����ݴϴ�.
};


//-------------------------------
// ä�������˻�

class SearchRecruitmentInfoUI {
private:
	SearchRecruitmentInfo* searchRecruitmentInfo;
public:
	SearchRecruitmentInfoUI(SearchRecruitmentInfo* searchRecruitmentInfo);
	void startInterface();


};



class SearchRecruitmentInfo {
private:
	RecruitmentInfoList* riList;
	string companyName;
	RecruitmentInfo* result;
public:
	SearchRecruitmentInfo(RecruitmentInfoList* riList);
	RecruitmentInfo* getResult();
	void setCompanyName(string companyName);
	void searchRecruitmentInfoListByComName(string name);
};
//ä�������˻�

//ä�� ����
/*
*/
class ApplyForRecruitmentInfoUI {
private:
	string bn;
	ApplyForRecruitmentInfo* applyForRecruitmentInfo;
public:
	ApplyForRecruitmentInfoUI(ApplyForRecruitmentInfo* applyForRecruitmentInfo);
	void startInterface(RecruitmentInfoList* riList);
	void applyForRecruitmentInfoByNum(string bn);
};


class ApplyForRecruitmentInfo {
private:
	GeneralClient* gClient; //�����Ϸ����ϴ� �Ϲ� ȸ��
	RecruitmentInfoList* riList; //���� ��ϵ� ä������
	RecruitmentInfo* appliedRecruitmentInfo;//�α����� �Ϲ�ȸ���� ������ ä����	


public:
	ApplyForRecruitmentInfo(GeneralClient* gClient, RecruitmentInfoList* riList);
	void addApplicant(string bn);
};

// ä�� ����

// ���� ���� ��ȸ

class InquireApplicationInfoUI {
private:

public:
	//	InquireApplicationInfoUI();
	void startInterface(vector<RecruitmentInfo*> gcAppliedList);
};



class InquireApplicationInfo {
private:
	GeneralClient* gClient;
	vector<RecruitmentInfo*> gcAppliedList;
public:
	
	InquireApplicationInfo(GeneralClient* gClient);

};


class CompareRecruitmentInfo {//RecruitmentInfo pointer�� ���ϴ� Ŭ����

public:
	bool operator()(const RecruitmentInfo* a, const RecruitmentInfo* b);
};


#endif // !1



