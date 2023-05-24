#include "hw3.h"


/*
   �Լ��̸�: System::doTask
   ���: ���Ͽ��� �Է¹��� ��ȣ �ΰ��� ���� ���� ������ ����� �����ϵ��� �Ѵ�.
   �Ű�����: ����
   ��ȯ��: ����

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
void System::doTask()
{
    int menu_level_1 = 0, menu_level_2 = 0; //input.txt���Ͽ��� �о���� �ΰ��� ���� �ʱ�ȭ
    int is_program_exit = 0; //���α׷� ���� �ڵ� -> 0: ��� ���α׷� ���� / 1: ���α׷� ����
    ClientList* clientList = new ClientList(); //Client��ü���� ������ ClientList��ü ���� -> �� ��ü�� reference���� �� ����� �����϶�� controller �������� �Ű������� �� ����
    GeneralClientList* gcList = new GeneralClientList(); // GeneralClient��ü���� ������ GeneralClientList��ü ����->�� ��ü�� reference���� �� ����� �����϶�� controller �������� �Ű������� �� ����
    CompanyClientList* ccList = new CompanyClientList(); // CompanyClient��ü���� ������ CompanyClientList��ü ����->�� ��ü�� reference���� �� ����� �����϶�� controller �������� �Ű������� �� ����

    RecruitmentInfoList* rcList = new RecruitmentInfoList(); // ��� ä�������� ��� ����Ʈ
    Client* curLogInClient = 0; //���� �α��εǾ� �ִ� Client ��ü�� �����ϱ� ���� -> �� ���� �����ϴ� ���, �α��ε� client�� �� ������ ����Ǿ��ְ�, �� ��ü�� ������ �ʿ��� control Ŭ������ �����ڿ� �Ű������� �־��ش�.
    LogIn* logIn = 0; //���� curLogInClient ��ü�� logIn ����� Ŭ������ getLogInClient() ȣ���� ���� �� ���̹Ƿ� logIn ��Ʈ�ѷ��� �����ϱ� ���ϵ��� ���� switch�� �ۿ� �̸� �����س��´�.

    fin.open(INPUT_FILE_NAME); //input.txt ���� ����
    fout.open(OUTPUT_FILE_NAME); //output.txt ���� ����


    while (!is_program_exit)
    {
        // �Է����Ͽ��� �޴� ���� 2���� �б�
        fin >> menu_level_1;
        fin >> menu_level_2;

        // �޴� ���� �� �ش� ���� ����
        switch (menu_level_1)
        {
        case 1:
        {
            switch ((menu_level_2))
            {
            case 1:
            {
                fout << "1.1. ȸ������" << endl;
                SignIn* signIn = new SignIn(clientList, gcList, ccList); //ȸ������ ��Ʈ�� Ŭ���� ����

                break;
            }

            case 2:
            {
                fout << "1.2. ȸ��Ż��" << endl;

                if (logIn != nullptr) //LogIn��Ʈ�� Ŭ������ �����Ǳ⵵ ���� ȸ��Ż�� �õ��ϴ� ���������� ������ ���� ���� -> LogIn ControlŬ������ �����Ǿ��ٸ�
                {
                    curLogInClient = logIn->getLogInClient(); //�α��ε� ������ ��ȸ�Ѵ�
                    if (curLogInClient != nullptr) //�α��ε� ������ null�� �ƴ� ��쿡�� ȸ��Ż�� �õ�
                    {
                        SignOut* signOut = new SignOut(clientList, gcList, ccList, curLogInClient); //ȸ�� Ż�� ��Ʈ�� Ŭ���� ����

                    }
                }
                else //LogIn ��Ʈ�� Ŭ�������ѹ��� ������ ���� ���� ���
                {
                    cout << "ȸ��Ż�� �� �� �����ϴ�" << endl;
                }
                //curLogInClient = logIn->getLogInClient(); //�α��ε� ������ �˾ƿ´�                
                //SignOut* signOut = new SignOut(clientList, gcList, ccList, curLogInClient);
                break;
            }

            }
            break;
        }

        case 2:
        {
            switch (menu_level_2)
            {
            case 1:
            {
                fout << "2.1. �α���" << endl;
                //LogIn* logIn = new LogIN(clientList, gcList, ccList);
                logIn = new LogIn(clientList, gcList, ccList); //switch�� �ۿ� �̸� �������� logIn������ LogIn ��Ʈ�� Ŭ���� ��ü�� ��´�.
                //cout << clientList->count();
                break;


            }
            case 2:
            {
                fout << "2.2. �α׾ƿ�" << endl;
                if (logIn != nullptr) //LogIn��Ʈ�� Ŭ������ �����Ǳ⵵ ���� ȸ��Ż�� �õ��ϴ� ���������� ������ ���� ���� -> LogIn ControlŬ������ �����Ǿ��ٸ�
                {
                    curLogInClient = logIn->getLogInClient(); //�α��ε� ������ ��ȸ�Ѵ�
                    if (curLogInClient != nullptr) //�α��ε� ������ �ִ� ��쿡�� �α׾ƿ� �õ�
                    {
                        LogOut* logOut = new LogOut(clientList, gcList, ccList, curLogInClient); //�α׾ƿ� ��Ʈ�� Ŭ���� ���� 

                    }
                }

                else //LogIn ��Ʈ�� Ŭ�������ѹ��� ������ ���� ���� ��� 
                {
                    cout << "�α׾ƿ� �� �� �����ϴ�" << endl;
                }
                //curLogInClient = logIn->getLogInClient();
                //LogOut* logOut = new LogOut(clientList, gcList, ccList,curLogInClient);

                break;
            }
            }
            break;
        }

        case 3: {
            switch (menu_level_2)
            {
            case 1: // "3.1. ä�� ���� ��ϡ� �޴� �κ�
            {
                fout << "3.1. ä�� ���� ���" << endl;
                if (logIn != nullptr) //�Ѹ��̶� �α����� �Ǿ��ִ� ��쿡�� ����
                {

                    curLogInClient = logIn->getLogInClient();
                    string tmpid = curLogInClient->getId();
                    CompanyClient* tmpCompanyClient = ccList->findById(tmpid);
                    int tmp = curLogInClient->getType();
                    // int tmp = curLogInClient.getType();
                    if (tmp == 2) {
                        cout << "�Ϲ� ȸ���� ä������ ����� �Ұ����մϴ�.\n";
                    }
                    else {
                        //CompanyClient *companyClient = findByID(�α��ε� ��ü�� id)

                        RegisterRecruitmentInfo* registerRecruitmentInfo = new RegisterRecruitmentInfo(tmpCompanyClient, rcList);
                        //Control ���ο��� ��� ����� ä�������� ���� �������� �ݿ��ϴ� �۾��� �ʿ���


                    }
                }
                else //�α��εǾ��ִ� ����� ���� ��� 
                {
                    cout << "ä�� ������ ����� �� �����ϴ�." << endl;
                }
                break;
            }
            case 2: // "3.2. ä�� ���� ��ȸ�� �޴� �κ�
            {
                fout << "3.2. ä�� ���� ��ȸ" << endl;
                if (logIn != nullptr) //�Ѹ��̶� �α����� �Ǿ��ִ� ��쿡�� ����
                {
                    curLogInClient = logIn->getLogInClient();
                    string tmpid = curLogInClient->getId();
                    CompanyClient* tmpCompanyClient = ccList->findById(tmpid);
                    InquireRecruitmentInfo* inquireRecruitmentInfo = new InquireRecruitmentInfo(tmpCompanyClient);
                }
                else //�α��εǾ��ִ� ����� ���� ��� 
                {
                    cout << "ä�� ������ ��ȸ�� �� �����ϴ�." << endl;
                }
                break;
            }
            }
            break;

        }
        case 4: {
            switch (menu_level_2) {
            case 1: {//ä�� ���� �˻�
                fout << "4.1. ä������ �˻�\n";
                if (logIn != nullptr) {
                    SearchRecruitmentInfo* searchRecruitmentInfo = new SearchRecruitmentInfo(rcList);
                }
                else {
                    cout << "�Ϲ�ȸ������ �α����ϰ� ���ʽÿ�.\n";
                }
                break;
            }
            case 2: {//ä�� ����
                fout << "4.2. ä�� ����\\n";
                if (logIn != nullptr) {
                    curLogInClient = logIn->getLogInClient();
                    string tmpid = curLogInClient->getId();
                    GeneralClient* tmpGeneralClient = gcList->findById(tmpid);
                    ApplyForRecruitmentInfo* applyForRecruitmentInfo = new ApplyForRecruitmentInfo(tmpGeneralClient,rcList);
                }
                else {
                    cout << "�Ϲ�ȸ������ �α����ϰ� ���ʽÿ�.\n";
                }
                break;
            }
            case 3: {//���� ���� ��ȸ
                fout << "4.3. ���� ���� ��ȸ\n";
                if (logIn != nullptr) {
                    curLogInClient = logIn->getLogInClient();
                    string tmpid = curLogInClient->getId();
                    GeneralClient* tmpGeneralClient = gcList->findById(tmpid);
                    InquireApplicationInfo* inquireApplicationInfo = new InquireApplicationInfo(tmpGeneralClient);
                }
                else {
                    cout << "�Ϲ� ȸ������ �α����ϰ� ��õ� �Ͻʽÿ�.\n";
                }
                break;
            }
            case 4: {// ���� ���
                fout << "4.4. ���� ���\n";
                if (logIn != nullptr) { //
                    curLogInClient = logIn->getLogInClient(); //���� �α��ε� ȸ���� �˾ƿ´�
                    string tmpid = curLogInClient->getId();
                    GeneralClient* tmpGeneralClient = gcList->findById(tmpid); 
                    CancelApplicationInfo* cancelApplicationInfo = new CancelApplicationInfo(tmpGeneralClient, rcList);
                }
                else {
                    cout << "���� ��Ұ� �Ұ����մϴ�.\n";
                }
                break;

            }
            }
            break;
        }

        case 6: {
            switch (menu_level_2)
            {
            case 1: // "6.1. ���ᡰ �޴� �κ�
            {
                fout << "6.1.����" << endl << endl; 
                is_program_exit = 1;  //���� �ڵ带 1�� ����
                break;
            }
            }
            break;
        }
        }
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
/*
   �Լ��̸�: ��ƼƼ Ŭ���� Client�� ������
   ���: ȸ���� �����ϱ� ���� Ŭ������ �����ڷμ� �����
   �Ű�����: type: ȸ�� ���� / name: ȸ�� �̸� /id: ȸ�� id / pw: ȸ�� ��й�ȣ
   ��ȯ��: ����

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
Client::Client(int type, string name, string id, string pw)
{
    this->type = type;
    this->name = name;
    this->id = id;
    this->pw = pw;
    // this->_num = num;
    this->isLogIn = false;
}


/*
   �Լ��̸�: Client::getId
   ���: �ش� ȸ���� id�� ��ȯ�Ѵ�.
   �Ű�����: -
   ��ȯ��: id

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
string Client::getId()
{
    return this->id;
}


/*
   �Լ��̸�: Client::getPw
   ���: �ش� ȸ���� password�� ��ȯ�Ѵ�.
   �Ű�����: -
   ��ȯ��: pw

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
string Client::getPw()
{
    return this->pw;
}


/*
   �Լ��̸�: Client::getTyoe
   ���: �ش� ȸ���� ȸ�� Ÿ���� ��ȯ�Ѵ�.
   �Ű�����: -
   ��ȯ��: type 1:ȸ��ȸ�� 2: �Ϲ�ȸ��

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
int Client::getType()
{
    return this->type;
}


/*
   �Լ��̸�: Client::getLogInStatus
   ���: �ش� ȸ���� �α��� ���¸� ��ȯ�Ѵ�.
   �Ű�����: -
   ��ȯ��: isLogIn -> true: �α��� ���� / false: �α׾ƿ� ����

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
bool Client::getLogInStatus()
{
    return this->isLogIn;
}



// ä�� ���� ��� �� getName
string Client::getName()
{
    return this->name;
}



/*
   �Լ��̸�: Client::changeLogInStatus
   ���: �ش� ȸ���� �α��� ���¸� �ٲ��ش�. true->false / false->true
   �Ű�����: -
   ��ȯ��: ����

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
void Client::changeLogInStatus()
{
    if (this->isLogIn == false)
    {
        this->isLogIn = true;
    }

    else
    {
        this->isLogIn = false;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
   �Լ��̸�: ��ƼƼ Ŭ���� CompanyClient�� ������
   ���:  ȸ��ȸ���� �����ϱ� ���� Ŭ������ �����ڷμ� ����� -> type, name, id, pw�� �θ�Ŭ������ Client�� �����ڸ� ���� �����Ѵ�.
   �Ű�����:
            type: ȸ�� ���� / name: ȸ�� �̸� /id: ȸ�� id / pw: ȸ�� ��й�ȣ / num: ����� ��ȣ
   ��ȯ��: ����

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
CompanyClient::CompanyClient(int type, string name, string num, string id, string pw) :Client(type, name, id, pw)
{
    this->bn = num;
}




string CompanyClient::getbn()
{
    return this->bn;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
   �Լ��̸�: ��ƼƼ Ŭ���� GeneralClient�� ������
   ���:  �Ϲ�ȸ���� �����ϱ� ���� Ŭ������ �����ڷμ� ����� -> type, name, id, pw�� �θ�Ŭ������ Client�� �����ڸ� ���� �����Ѵ�.
   �Ű�����:
            type: ȸ�� ���� / name: ȸ�� �̸� /id: ȸ�� id / pw: ȸ�� ��й�ȣ / num: �ֹΤ���ȣ
   ��ȯ��: ����

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
GeneralClient::GeneralClient(int type, string name, string num, string id, string pw) :Client(type, name, id, pw)
{
    this->rrn = num;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
   �Լ��̸�: ClientList::addClient
   ���: �Ű������� ���� ȸ���� ȸ�� ����Ʈ�� �߰��Ѵ�.
   �Ű�����: Client* -> �߰��� ȸ�� ��ü
   ��ȯ��: ����

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
void ClientList::addClient(Client* c)
{
    this->cList.push_back(c);
}



/*
   �Լ��̸�: ClientList::size
   ���: ȸ�� ����Ʈ�� ũ�⸦ ��ȯ�Ѵ�.
   �Ű�����: ����
   ��ȯ��: size : ���� ȸ�� ����Ʈ�� ũ��

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
int ClientList::size()
{
    return this->cList.size();
}



/*
   �Լ��̸�: ClientList::getClientList
   ���: ȸ�� ����Ʈ ��ü�� ��ȯ�Ѵ�
   �Ű�����: ����
   ��ȯ��: vector<Client* > c1
   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
vector<Client*> ClientList::getClientList()
{
    vector<Client*> cl;
    for (int i = 0; i < this->size(); i++)
    {
        cl.push_back(this->cList[i]);
    }

    return cl;
}

/*
int ClientList::count()
{
    int c = 0;
    for (int i = 0; i < this->size(); i++)
    {
        if (this->cList[i]->getLogInStatus() == true)
        {
            c++;
        }
    }
    return c;
}
*/


/*
   �Լ��̸�: ClientList::destroy
   ���: �Է¹��� �ش� �ε����� ȸ�� ������ �����Ѵ�
   �Ű�����: idx -> ������ ȸ���� �ε�����
   ��ȯ��: ����

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
void ClientList::destroy(int idx)
{
    this->cList.erase(cList.begin() + idx); //�ش� �ε����� ȸ�� ���� ����
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
   �Լ��̸�: CompanyClientList::addCompanyClient
   ���: ���޹��� �ش� ȸ�� ȸ�� ������ ȸ��ȸ�� ����Ʈ�� �����Ѵ�
   �Ű�����: ����
   ��ȯ��: ����

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
void CompanyClientList::addCompanyClient(CompanyClient* c)
{
    this->cCList.push_back(c);
}



/*
   �Լ��̸�: CompanyClientList::destroy
   ���: �Է¹��� �ش� id���� ��ġ�ϴ� ȸ�� ȸ�� ������ �����Ѵ�
   �Ű�����: id -> ������ ȸ���� id��
   ��ȯ��: ����

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
void CompanyClientList::destroy(string id)
{
    for (int i = 0; i < this->cCList.size(); i++)
    {
        if (cCList[i]->getId() == id)
        {
            this->cCList.erase(cCList.begin() + i);
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
   �Լ��̸�: GeneralClientList::addGeneralClient
   ���: ���޹��� �ش� �Ϲ� ȸ�� ������ �Ϲ�ȸ������Ʈ�� �����Ѵ�
   �Ű�����: ����
   ��ȯ��: ����

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
void GeneralClientList::addGeneralClient(GeneralClient* c)
{
    this->gCList.push_back(c);
}


/*
�Լ��̸�: GeneralClientList::destroy
��� : �Է¹��� �ش� id���� ��ġ�ϴ� �Ϲ� ȸ�� ������ �����Ѵ�
�Ű����� : id->������ ȸ���� id��
��ȯ�� : ����

�ۼ���¥ : 2023 / 05 / 31
�ۼ��� : �ڽ�ȫ
*/
void GeneralClientList::destroy(string id)
{
    for (int i = 0; i < this->gCList.size(); i++)
    {
        if (gCList[i]->getId() == id)
        {
            this->gCList.erase(gCList.begin() + i);
        }
    }
}

string RecruitmentInfo::getBn() {
    return this->bn;
}

RecruitmentInfo* RecruitmentInfoList::findByName(string companyName) {
    int size = rCList.size();
    for (int i = 0; i < size; i++) {
        if (companyName == rCList[i]->getName()) {
            return rCList[i];
        }
    }
}

RecruitmentInfo* RecruitmentInfoList::findByNum(string bn) {
    int size = rCList.size();
    for (int i = 0; i < size; i++) {
        if (bn == rCList[i]->getBn()) {
            return rCList[i];
        }
    }
}

string RecruitmentInfo::getName()const {
    return this->companyName;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
/*
   �Լ��̸�: ��Ʈ�� Ŭ���� SignIn�� ������
   ���: ȸ������ ���� ����� �����ϱ� ���� ��Ʈ�� Ŭ������ �����ڷμ� �����
   �Ű�����:
            ClientList* list -> ȸ������ ������ ���� collection class�� instance
            GeneralClientList*gcList -> �Ϲ� ȸ������ ������ ���� collection class�� instance
            CompanyClientList*ccList -> ȸ�� ȸ������ ������ ���� collection class�� instance
   ��ȯ��: ����

   �ۼ���¥: 2023/05/31
   �ۼ���: �ڽ�ȫ
*/
SignIn::SignIn(ClientList* list, GeneralClientList* gcList, CompanyClientList* ccList)
{
    SignInUI* signInUI = new SignInUI(this); //�ٿ���� Ŭ������ ���۷��� ��ȯ�� ���� �ٿ���� Ŭ������ ������ ȣ��
    this->cList = list; //��Ʈ�� Ŭ������ ��� ������ ȸ������ �迭 ����
    this->gcList = gcList; //��Ʈ�� Ŭ������ ��� ������ �Ϲ�ȸ������ �迭 ����
    this->ccList = ccList; //��Ʈ�� Ŭ������ ��� ������ �Ϲ�ȸ������ �迭 ����
    this->pSignInUI = signInUI; //�ٿ���� Ŭ������ ���۷��� �� ����
    pSignInUI->startInterface(); //��Ʈ�� Ŭ������ ���� ���ÿ� startInterface ȣ���� �ٿ���� Ŭ�������� ���
}

/*
   �Լ��̸�: �ٿ���� Ŭ���� SignInUI�� ������
   ���: ȸ������ ���� ����� �����ϱ� ���� �ٿ���� Ŭ������ �����ڷμ� �����
   �Ű�����:
            SignIn* refSignIn -> ȸ�� ���԰� ���õ� ��Ʈ�� Ŭ������ ���۷����� attribute�� ����

   ��ȯ��: ����

   �ۼ���¥: 2023/05/31
   �ۼ���: �ڽ�ȫ
*/
SignInUI::SignInUI(SignIn* refSignIn)
{
    this->pSignIn = refSignIn;
    this->id = "";
    this->name = "";
    this->num = "";
    this->pw = "";
    this->type = 0;
}


/*
   �Լ��̸�: SignInUI::startInterface
   ���: ȸ�� ������ ������ �Է��϶�� ȭ���� �����ְ�, �ʿ� ������ �Է¹޾� ��Ʈ�� Ŭ�������� �Է¹��� ������ ���� ȸ�� ����� ��û�Ѵ�.
   �Ű�����: ����
   ��ȯ��: ����

   �ۼ���¥: 2023/05/31
   �ۼ���: �ڽ�ȫ
*/
void SignInUI::startInterface()
{
    cout << "ȸ�� ������ ������ �Է��ϼ���" << endl;
    this->fillInfo();



}


/*
   �Լ��̸�: SignInUI::fillInfo
   ���: ȸ�� ������ ���� �ʿ� ������ �Է¹޴� ����� �Ѵ�
   �Ű�����: ����
   ��ȯ��: ����

   �ۼ���¥: 2023/05/31
   �ۼ���: �ڽ�ȫ
*/
void SignInUI::fillInfo()
{
    fin >> this->type >> this->name >> this->num >> this->id >> this->pw;
    this->pSignIn->addNewClient(this->type, this->name, this->num, this->id, this->pw);
}



/*
   �Լ��̸�: SignIn::addNewClient
   ���: ȸ�� ������ ���� �Է¹��� ������ �̿��� ȸ�� ����Ʈ�� �����ϰ�, ȸ���� Ÿ�Կ� ���� �Ϲ�ȸ��/ȸ��ȸ���� ����Ʈ�� �����Ѵ�.
   �Ű�����: clientType -> �Է¹��� ȸ�� ����
            name -> �Է¹��� ȸ���� ȸ���̸�/�̸�
            num -> //ȸ���� �Է��� �ֹι�ȣ/����ڹ�ȣ
             id -> ȸ���� �Է��� id
             pw ->ȸ���� �Է��� pw
   ��ȯ��: ����

   �ۼ���¥: 2023/05/31
   �ۼ���: �ڽ�ȫ
*/
void SignIn::addNewClient(int clientType, string name, string num, string id, string pw)
{
    if (clientType == 1) //�Է¹��� ���� �� type���� ȸ��ȸ���� ���
    {
        CompanyClient* cClient = new CompanyClient(clientType, name, num, id, pw); //ȸ��ȸ�� ��ü ����
        Client* client = new Client(clientType, name, id, pw); //ȸ�� ��ü ����
        this->cList->addClient(client); //ȸ�� ����Ʈ�� ����
        this->ccList->addCompanyClient(cClient); //ȸ�� ȸ�� ����Ʈ�� ����



    }

    else //�Է¹��� ���� �� type���� �Ϲ�ȸ���� ���
    {
        GeneralClient* gClient = new GeneralClient(clientType, name, num, id, pw); //�Ϲ�ȸ�� ��ü ����
        Client* client = new Client(clientType, name, id, pw); //ȸ�� ��ü ����
        this->cList->addClient(client); //ȸ�� ����Ʈ�� ����
        this->gcList->addGeneralClient(gClient); //�Ϲ�ȸ�� ����Ʈ�� ����
    }

    fout << '>' << clientType << ' ' << name << ' ' << num << ' ' << id << ' ' << pw << endl << endl; //���Ͽ� ���� �޼��� ���
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////



/*
   �Լ��̸�: ��Ʈ�� Ŭ���� LogIn�� ������
   ���: �α��� ���� ����� �����ϱ� ���� ��Ʈ�� Ŭ������ �����ڷμ� �����
   �Ű�����:
            ClientList* list -> ȸ������ ������ ���� collection class�� instance
            GeneralClientList*gcList -> �Ϲ� ȸ������ ������ ���� collection class�� instance
            CompanyClientList*ccList -> ȸ�� ȸ������ ������ ���� collection class�� instance
   ��ȯ��: ����

   �ۼ���¥: 2023/05/31
   �ۼ���: �ڽ�ȫ
*/
LogIn::LogIn(ClientList* list, GeneralClientList* gcList, CompanyClientList* ccList)
{
    LogInUI* logInUI = new LogInUI(this); //�ٿ���� Ŭ������ ���۷��� ��ȯ�� ���� �ٿ���� Ŭ������ ������ ȣ��
    this->cList = list; //��Ʈ�� Ŭ������ ��� ������ ȸ������ �迭 ����
    this->gcList = gcList; //��Ʈ�� Ŭ������ ��� ������ �Ϲ�ȸ������ �迭 ����
    this->ccList = ccList; //��Ʈ�� Ŭ������ ��� ������ �Ϲ�ȸ������ �迭 ����
    this->pLogInUI = logInUI; //�ٿ���� Ŭ������ ���۷��� �� ����
    this->curLogInClient = nullptr;  //ó�� LogInŬ������ ������ �� �α��ε� ������ nullptr����
    pLogInUI->startInterface();  //��Ʈ�� Ŭ������ ���� ���ÿ� startInterface ȣ���� �ٿ���� Ŭ�������� ���
}



/*
   �Լ��̸�: LogIn::tryLogIn
   ���: �α����� �ϱ� ���� clientList�� ����� ��� ȸ���� ������ ������ ��, id, pw�� ��� ��ġ�ϰ� �α����� �ȵǾ��ִ� ��쿡�� �α��� ���·� �ٲ��ش�.
   �Ű�����:
             id -> ȸ���� �Է��� id
             pw ->ȸ���� �Է��� pw
   ��ȯ��: ����

   �ۼ���¥: 2023/05/31
   �ۼ���: �ڽ�ȫ
*/
void LogIn::tryLogIn(string id, string pw)
{

    vector<Client*> temp; //�ش� �Լ����� ����� �ӽ� client* ���͸� ����
    temp = this->cList->getClientList(); //�Ű������� ������ cList�� ��ü ȸ���� ������ temp �迭�� ����
    bool isMatched = false; //id pw�� ��� match�Ǵ��� Ȯ���� ���� isMatched�� �ʱ⿡ false�� �ʱ�ȭ

    for (int i = 0; i < temp.size(); i++) //temp�迭�� ũ��(����� ȸ���� ��)��ŭ �ݺ�
    {
        if (temp[i]->getId() == id && temp[i]->getPw() == pw) //�ش� �ε����� ȸ�� id,pw�� �Է¹��� id,pw�� ��ġ�Ѵٸ�
        {
            isMatched = true; //true������ ����
            if (temp[i]->getLogInStatus() == false) //�׸��� �ش� ȸ���� �α��� ���°� false���
            {

                temp[i]->changeLogInStatus(); //�ش� ȸ���� �α��� ���°��� true�� �ٲ���
                this->curLogInClient = temp[i]; //�α����� �Ǿ����Ƿ� LogIn ��Ʈ�� Ŭ������ ���� �α��ε� client�� ������ �����ִ´�
                fout << '>' << temp[i]->getId() << ' ' << temp[i]->getPw() << endl << endl; //�α����� �Ϸ�Ǹ� �Ϸ�Ǿ��ٴ� ������ ���Ͽ� �����
                break; //�α����� �������Ƿ� for�� Ż��
            }

            else //���� �α����� �̹� �Ǿ��ִ� ����� �� �α����� �õ��ϴ� ���
            {
                cout << "�̹� �α��ε� �����Դϴ�" << endl;
            }

            //break;
        }


    }

    if (isMatched == false) //���� ��� ������ match���� �ʾҴٸ� clientList�� ���� ������
    {
        cout << "���� �����Դϴ�." << endl;
    }
}

/*
   �Լ��̸�: LogInInUI::getLogInClient
   ���: �α��� ��ü�� ����Ǿ��ִ� ���� �α��ε� ȸ��(client)�� ���۷����� ��ȯ�Ѵ�
   �Ű�����: ����
   ��ȯ��: curLogInClient

   �ۼ���¥: 2023/05/31
   �ۼ���: �ڽ�ȫ
*/
Client* LogIn::getLogInClient()
{
    return this->curLogInClient;
}

/*
   �Լ��̸�: �ٿ���� Ŭ���� LogInUI�� ������
   ���: �α��� ���� ����� �����ϱ� ���� �ٿ���� Ŭ������ �����ڷμ� �����
   �Ű�����:
            LogIn* refLogIn -> �α��ΰ� ���õ� ��Ʈ�� Ŭ������ ���۷����� attribute�� ����

   ��ȯ��: ����

   �ۼ���¥: 2023/05/31
   �ۼ���: �ڽ�ȫ
*/
LogInUI::LogInUI(LogIn* refLogIn)
{
    this->pLogIn = refLogIn;
    this->id = "";
    this->pw = "";

}

/*
   �Լ��̸�: LogInInUI::startInterface
   ���: ȸ�� id�� pw�� �Է��϶�� ȭ���� �����ְ�, �ʿ� ������ �Է¹޾� ��Ʈ�� Ŭ�������� �Է¹��� ������ ���� �α����� ��û�Ѵ�.
   �Ű�����: ����
   ��ȯ��: ����

   �ۼ���¥: 2023/05/31
   �ۼ���: �ڽ�ȫ
*/
void LogInUI::startInterface()
{
    cout << "���̵�� �н����带 �Է��ϼ���" << endl;
    this->fillIDPW();
}



/*
   �Լ��̸�: LogInUI::fillIDPW
   ���: �α����� ���� �ʿ� ������ �Է¹޴� ����� �Ѵ�
   �Ű�����: ����
   ��ȯ��: ����

   �ۼ���¥: 2023/05/31
   �ۼ���: �ڽ�ȫ
*/
void LogInUI::fillIDPW()
{
    fin >> this->id >> this->pw;
    this->pLogIn->tryLogIn(this->id, this->pw);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*
   �Լ��̸�: ��Ʈ�� Ŭ���� LogOut�� ������
   ���: �α׾ƿ� ���� ����� �����ϱ� ���� ��Ʈ�� Ŭ������ �����ڷμ� �����
   �Ű�����:
            ClientList* list -> ȸ������ ������ ���� collection class�� instance
            GeneralClientList*gcList -> �Ϲ� ȸ������ ������ ���� collection class�� instance
            CompanyClientList*ccList -> ȸ�� ȸ������ ������ ���� collection class�� instance
            Client* client -> �α��ε� ������ ������ ���� Client ��ü
   ��ȯ��: ����

   �ۼ���¥: 2023/05/31
   �ۼ���: �ڽ�ȫ
*/
LogOut::LogOut(ClientList* list, GeneralClientList* gcList, CompanyClientList* ccList, Client* client)
{
    LogOutUI* logOutUI = new LogOutUI(this); //�ٿ���� Ŭ������ ���۷��� ��ȯ�� ���� �ٿ���� Ŭ������ ������ ȣ��
    this->cList = list; //��Ʈ�� Ŭ������ ��� ������ ȸ������ �迭 ����
    this->gcList = gcList; //��Ʈ�� Ŭ������ ��� ������ �Ϲ�ȸ������ �迭 ����
    this->ccList = ccList; //��Ʈ�� Ŭ������ ��� ������ �Ϲ�ȸ������ �迭 ����
    this->curLogInClient = client; //�α��ε� Client��ü�� ����
    this->pLogOutUI = logOutUI;   //�ٿ���� Ŭ������ ���۷��� �� ����
    this->changeLogInStatus(curLogInClient); //���� �α��ε� ������ ������ �������� �α׾ƿ� ��� ���� ���

}


/*
   �Լ��̸�: �ٿ���� Ŭ���� LogOutUI�� ������
   ���: �α׾ƿ� ���� ����� �����ϱ� ���� �ٿ���� Ŭ������ �����ڷμ� �����
   �Ű�����:
            LogOut* refLogOut -> �α׾ƿ��� ���õ� ��Ʈ�� Ŭ������ ���۷����� attribute�� ����

   ��ȯ��: ����

   �ۼ���¥: 2023/05/31
   �ۼ���: �ڽ�ȫ
*/
LogOutUI::LogOutUI(LogOut* refLogOut)
{
    this->pLogOut = refLogOut;

}

/*
   �Լ��̸�: LogOut::changeLogInStatus
   ���: �α׾ƿ��� �ϱ� ���� clientList�� ����� ��� ȸ���� ������ ������ ��, �α��ε� Client�� id�� pw�� ��ġ�ϴ� �� Ȯ��
        �� ��, match�� ������ login���°� true��� �α��� ���¸� false�� �ٲ��ش�.
   �Ű�����:
             Client* client -> �α��ε� ����
   ��ȯ��: ����

   �ۼ���¥: 2023/05/31
   �ۼ���: �ڽ�ȫ
*/
void LogOut::changeLogInStatus(Client* client)
{
    vector<Client*> temp; //�ش� �Լ����� ����� �ӽ� client* ���͸� ����
    temp = this->cList->getClientList(); //�Ű������� ������ cList�� ��ü ȸ���� ������ temp �迭�� ����
    string id; //�α׾ƿ��� ������ ���, �α׾ƿ��� ������ ��ȯ�ϱ� ���� ����
    bool isPossible = false; //�α׾ƿ��� �������� �˷��ִ� flag���� -> true�� ��쿡�� �α׾ƿ� ����, false�� ��� �α׾ƿ� �Ұ���

    for (int i = 0; i < temp.size(); i++) //temp�迭�� ũ��(����� ȸ���� ��)��ŭ �ݺ�
    {
        if (temp[i]->getId() == client->getId() && temp[i]->getPw() == client->getPw()) //�ش� �ε����� ȸ�� id,pw�� �α��� �� ȸ���� id,pw�� ��ġ�Ѵٸ�
        {
            if (temp[i]->getLogInStatus() == true) //�׸��� �� ȸ���� �α��� ���°� true���
            {
                temp[i]->changeLogInStatus(); //�ش� client�� �α��� ���°��� false�� �ٲ��ش�.
                id = temp[i]->getId(); //�������̽��� ��µ� �α׾ƿ��� ȸ���� id���� �޾ƿ´�.
                isPossible = true; //�α׾ƿ� flag������ true�� �ٲ��ش�
            }
        }
    }


    this->pLogOutUI->startInterface(id, isPossible); //�ٿ���� Ŭ������ �α׾ƿ� �������� �α׾ƿ��� ������ id���� �Ű������� �����ش�


}

/*
   �Լ��̸�: LogOutUI::startInterface
   ���: �α׾ƿ��� ������ ���, �α׾ƿ��� ������ id���� ���Ͽ� ����.
   �Ű�����: string id ->�α׾ƿ��� ȸ���� id��
            flag -> �α׾ƿ� ��: true / �α׾ƿ� �Ұ��� -> false
   ��ȯ��: ����

   �ۼ���¥: 2023/05/31
   �ۼ���: �ڽ�ȫ
*/
void LogOutUI::startInterface(string id, bool flag)
{
    if (flag == true) //�α׾ƿ��� �� ���
    {
        fout << '>' << id << endl << endl;
        cout << "�α׾ƿ� �Ǿ����ϴ�." << endl;
    }

    else //�α׾ƿ��� �Ұ����� ���
    {
        cout << "�α׾ƿ��� �� �����ϴ�." << endl;
    }

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
   �Լ��̸�: ��Ʈ�� Ŭ���� SignOut�� ������
   ���: ȸ��Ż�� ���� ����� �����ϱ� ���� ��Ʈ�� Ŭ������ �����ڷμ� �����
   �Ű�����:
            ClientList* list -> ȸ������ ������ ���� collection class�� instance
            GeneralClientList*gcList -> �Ϲ� ȸ������ ������ ���� collection class�� instance
            CompanyClientList*ccList -> ȸ�� ȸ������ ������ ���� collection class�� instance
            Client* client -> �α��ε� ������ ������ ���� Client ��ü
   ��ȯ��: ����

   �ۼ���¥: 2023/05/31
   �ۼ���: �ڽ�ȫ
*/
SignOut::SignOut(ClientList* list, GeneralClientList* gcList, CompanyClientList* ccList, Client* client)
{
    SignOutUI* signOutUI = new SignOutUI(this); //�ٿ���� Ŭ������ ���۷��� ��ȯ�� ���� �ٿ���� Ŭ������ ������ ȣ��
    this->cList = list; //��Ʈ�� Ŭ������ ��� ������ ȸ������ �迭 ����
    this->gcList = gcList; //��Ʈ�� Ŭ������ ��� ������ �Ϲ�ȸ������ �迭 ����
    this->ccList = ccList; //��Ʈ�� Ŭ������ ��� ������ �Ϲ�ȸ������ �迭 ����
    this->curLogInClient = client; //�α��ε� Client��ü�� ����
    this->pSignOutUI = signOutUI; //�ٿ���� Ŭ������ ���۷��� �� ����
    this->destroy(curLogInClient); //���� �α��ε� ���� ������ �������� ȸ��Ż�� ��� ����

}


/*
   �Լ��̸�: �ٿ���� Ŭ���� SignOutUI�� ������
   ���: ȸ��Ż�� ���� ����� �����ϱ� ���� �ٿ���� Ŭ������ �����ڷμ� �����
   �Ű�����:
            SignOut* refSignOut -> �α׾ƿ��� ���õ� ��Ʈ�� Ŭ������ ���۷����� attribute�� ����

   ��ȯ��: ����

   �ۼ���¥: 2023/05/31
   �ۼ���: �ڽ�ȫ
*/
SignOutUI::SignOutUI(SignOut* refSignOut)
{
    this->pSignOut = refSignOut;

}


/*
   �Լ��̸�: SignOut::destroy
   ���: ȸ��Ż��� �ϱ� ���� clientList�� ����� ��� ȸ���� ������ ������ ��, �α��ε� Client�� id�� pw�� ��ġ�ϴ� �� Ȯ��
        �� ��, match�� ������ login���°� true��� ȸ�������� �����ϰ�, �ش� ������ �Ϲ�/ȸ��ȸ�� ������ ���� ������ �� ������ ��û�Ѵ�.
   �Ű�����:
             Client* client -> �α��� �� ����
   ��ȯ��: ����

   �ۼ���¥: 2023/05/31
   �ۼ���: �ڽ�ȫ
*/
void SignOut::destroy(Client* client)
{
    vector<Client*> temp; //�ش� �Լ����� ����� �ӽ� client* ���͸� ����
    temp = this->cList->getClientList(); //�Ű������� ������ cList�� ��ü ȸ���� ������ temp �迭�� ����
    string id; //ȸ��Ż�� ������ ���, ȸ��Ż��� ������ id�� ��ȯ�ϱ� ���� ����
    bool isPossible = false; //ȸ�q���� �������� Ȯ���� flag����

    for (int i = 0; i < temp.size(); i++) //temp�迭�� ũ��(����� ȸ���� ��)��ŭ �ݺ�
    {
        if (temp[i]->getId() == client->getId() && temp[i]->getPw() == client->getPw()) //�ش� �ε����� ȸ�� id,pw�� �α��� �� ȸ���� id,pw�� ��ġ�Ѵٸ�
        {
            if (temp[i]->getLogInStatus() == true) //�׸��� �� ȸ���� �α��� �Ǿ��ִٸ�
            {
                if (temp[i]->getType() == 1) //�� ȸ���� type�� ȸ��ȸ���� ���
                {
                    this->ccList->destroy(temp[i]->getId()); //ȸ��ȸ�� �迭���� �ش� ȸ�� ����(id���� ��ġ�ϴ� �ε������� ȸ��ȸ�� ����)
                }

                else //�� ȸ���� type�� �Ϲ�ȸ���� ���
                {
                    this->gcList->destroy(temp[i]->getId()); //�Ϲ�ȸ�� �迭���� �ش� ȸ�� ����(id���� ��ġ�ϴ� �ε������� �Ϲ�ȸ�� ����)
                }

                this->cList->destroy(i); //ȸ��ȸ��, �Ϲ�ȸ�� ���� ���� client�迭���� �ش� ȸ�� ����
                isPossible = true; //ȸ��Ż�� ���� ����: true�� ����
                id = temp[i]->getId(); //�������̽��� ��µ� �α׾ƿ��� ȸ���� id���� �޾ƿ´�.
            }
        }
    }


    this->pSignOutUI->startInterface(id, isPossible); //�ٿ���� Ŭ������ ȸ��Ż�� �������� ȸ��Ż���� ������ id���� �Ű������� �����ش�
}


/*
   �Լ��̸�: SignOutUI::startInterface
   ���: ȸ��Ż�� ������ ���, ȸ��Ż���� ������ id���� ���Ͽ� ����.
   �Ű�����: string id ->ȸ��Ż���� ȸ���� id��
            flag -> ȸ��Ż�� ��: true / ȸ��Ż�� �Ұ��� -> false
   ��ȯ��: ����

   �ۼ���¥: 2023/05/31
   �ۼ���: �ڽ�ȫ
*/
void SignOutUI::startInterface(string id, bool flag)
{
    if (flag == true)
    {
        fout << '>' << id << endl << endl;
        cout << "ȸ��Ż�� �Ǿ����ϴ�." << endl;
    }

    else
    {
        cout << "ȸ��Ż�� �� �� �����ϴ�" << endl;
    }


}

/*
 �Լ��̸�: RegisterRecruitmentInfo::RegisterRecruitmentInfo
 ���: RegisterRecruitmentInfo control Ŭ������ �������Դϴ�
 �ۼ���¥: 2023/05/22
 �ۼ���: �����
*/
RegisterRecruitmentInfo::RegisterRecruitmentInfo(CompanyClient* companyClient, RecruitmentInfoList* recruitmentInfoList)
{
    this->recruitmentInfoList = recruitmentInfoList;
    this->companyClient = companyClient;
    RegisterRecruitmentInfoUI* registerRecruitmentUI = new RegisterRecruitmentInfoUI(this, this->companyClient);
    registerRecruitmentUI->startInterface();
}

/*
 �Լ��̸�: RegisterRecruitmentInfoUI::RegisterRecruitmentInfoUI
 ���: RegisterRecruitmentInfo  boundary Ŭ������ �������Դϴ�
 �ۼ���¥: 2023/05/22
 �ۼ���: �����
*/
RegisterRecruitmentInfoUI::RegisterRecruitmentInfoUI(RegisterRecruitmentInfo* registerRecruitmentInfo, CompanyClient* companyClient)
{
    this->registerRecruitmentInfo = registerRecruitmentInfo;
    this->companyClient = companyClient;

}

/*
 �Լ��̸�: RegisterRecruitmentInfoUI::startInterface
 ���: RegisterRecruitmentInfoUI���� �Է°��� �о���̰� RecruitmentInfo�� ������ �߰�, ����� ǥ���ϵ��� �մϴ�.
 �ۼ���¥: 2023/05/22
 �ۼ���: �����
*/
void RegisterRecruitmentInfoUI::startInterface()
{
    cout << "ä�� ���� ����� ���� �ʵ带 �Է��ϼ���" << endl;
    //string task;
    //int numOfApplicant;
    //string finishDate;

    //fin >> task >> numOfApplicant >> finishDate;
    //registerRecruitmentInfo->addNewRecruitmentInfo(task, numOfApplicant, finishDate);
    //result(task, numOfApplicant, finishDate);

    this->registerInput();
}

void RegisterRecruitmentInfoUI::registerInput()
{
    string task;
    int expectedApplicantNum;
    string finishDate;
    fin >> task >> expectedApplicantNum >> finishDate;
    registerRecruitmentInfo->addNewRecruitmentInfo(task, expectedApplicantNum, finishDate);
    result(task, expectedApplicantNum, finishDate);
}

/*
 �Լ��̸�: RegisterRecruitmentInfoUI::result
 ���: ����ڿ��� �Է��� ������ ǥ���մϴ�.
 �ۼ���¥: 2023/05/22
 �ۼ���: �����
*/
void RegisterRecruitmentInfoUI::result(string task, int expectedApplicantNum, string finishDate)
{
    fout << "> ";
    fout << task;
    fout << " ";
    fout << expectedApplicantNum;
    fout << " " << finishDate << endl<<endl;

}

/*
 �Լ��̸�: RegisterRecruitmentInfoUI::addNewRecruitmentInfo
 ���: companyClient���� RecruitmentInfo�� �߰��ϵ��� �մϴ�.
 �ۼ���¥: 2023/05/22
 �ۼ���: �����
*/
void RegisterRecruitmentInfo::addNewRecruitmentInfo(string task, int expectedApplicantNum, string finishDate)
{
    RecruitmentInfo *tmp = companyClient->addNewRecruitInfo(task, expectedApplicantNum, finishDate);
    this->recruitmentInfoList->addNewRecruitmentInfoList(tmp);
}

void RecruitmentInfoList::addNewRecruitmentInfoList(RecruitmentInfo* ri) {
    this->rCList.push_back(ri);
}
/*
 �Լ��̸�: CompanyClient::addNewRecruitInfo
 ���: company client�� �����Ͱ� RecruitmentInfo�� �߰��մϴ�
 �ۼ���¥: 2023/05/22
 �ۼ���: �����
*/
RecruitmentInfo* CompanyClient::addNewRecruitInfo(string task, int expectedApplicantNum, string finishDate)
{
    string name;
    string bn;

    name = this->getName();
    bn = this->getbn();
    RecruitmentInfo* newRecruitmentInfo = new RecruitmentInfo(name, bn, task, expectedApplicantNum, finishDate);
    this->registeredList.push_back(newRecruitmentInfo);
    return newRecruitmentInfo;

}

/*
 �Լ��̸�: RecruitmentInfo::RecruitmentInfo
 ���: ���ο� RecruitmentInfo ��ü�� �����մϴ�.
 �ۼ���¥: 2023/05/22
 �ۼ���: �����
*/
RecruitmentInfo::RecruitmentInfo(string companyName, string bn, string task, int expectedApplicantNum, string finishDate)
{
    this->companyName = companyName;
    this->bn = bn;
    this->task = task;
    this->expectedApplicantNum = expectedApplicantNum;
    this->finishDate = finishDate;
}

/*
 �Լ��̸�: InquireRecruitmentInfo::InquireRecruitmentInfo
 ���: InquireRecruitmentInfo control Ŭ������ �������Դϴ�
 �ۼ���¥: 2023/05/22
 �ۼ���: �����
*/
InquireRecruitmentInfo::InquireRecruitmentInfo(CompanyClient* companyClient)
{
    this->companyClient = companyClient;
    vector<RecruitmentInfo*> tmp = this->companyClient->getListRegisteredInfo();
    int size = tmp.size();
    
    InquireRecruitmentInfoUI* inquireRecruitmentInfoUI = new InquireRecruitmentInfoUI(this);
    inquireRecruitmentInfoUI->startInterface(tmp);
}

/*
 �Լ��̸�: InquireRecruitmentInfoUI::InquireRecruitmentInfo
 ���: InquireRecruitmentInfoUI boundary Ŭ������ �������Դϴ�
 �ۼ���¥: 2023/05/22
 �ۼ���: �����
*/
InquireRecruitmentInfoUI::InquireRecruitmentInfoUI(InquireRecruitmentInfo* inquireRecruitmentInfo)
{
    this->inquireRecruitmentInfo = inquireRecruitmentInfo;
}

/*
 �Լ��̸�: InquireRecruitmentInfoUI::startInterface
 ���: ������� ȸ�� ȸ���� RecruitmentInfo�� ����մϴ�.
 �ۼ���¥: 2023/05/22
 �ۼ���: �����
*/
void InquireRecruitmentInfoUI::startInterface(vector<RecruitmentInfo*> riList)
{
    int size = riList.size();
    for (int i = 0; i < size; i++) {
        fout <<"> "<< riList[i]->getTask() << " " << riList[i]->getExpectedApplicantNum() << " " << riList[i]->getFinishDate() << "\n\n";
    }
}
////////////////////////////////////////////////////////////////////////////////////////


CompanyClient* CompanyClientList::findById(string id) {
    int size = cCList.size();

    for (int i = 0; i < size; i++) {
        if (id == cCList[i]->getId()) {
            return cCList[i];
        }
    }
}

GeneralClient* GeneralClientList::findById(string id) {
    int size = gCList.size();

    for (int i = 0; i < size; i++) {
        if (id == gCList[i]->getId()) {
            return gCList[i];
        }
    }
}

vector<RecruitmentInfo*> CompanyClient::getListRegisteredInfo() {
    return registeredList;
}


string RecruitmentInfo::getTask() {
    return this->task;
}
int RecruitmentInfo::getApplicantNum() {
    return this->numOfApplicant;
}
string RecruitmentInfo::getFinishDate() {
    return this->finishDate;
}

RecruitmentInfoList* RegisterRecruitmentInfo::getRecruitmentInfoList() {
    return this->recruitmentInfoList;
}

RecruitmentInfo* RegisterRecruitmentInfo::getRegisteredList() {
    return this->registeredList;
}


vector<RecruitmentInfo*> RecruitmentInfoList::getRIList() {
    return this->rCList;
}


void GeneralClient::addApplication(RecruitmentInfo* ri) {
    this->appliedList.push_back(ri);
}

//�����ڼ� �Ѹ� �߰�
void RecruitmentInfo::addApplicantToRecruitment() {
    this->numOfApplicant += 1;
}

//�����ڼ� �Ѹ� ����
void RecruitmentInfo::subApplicantToRecruitment() {
    this->numOfApplicant -= 1;
}

int RecruitmentInfo::getExpectedApplicantNum() {
    return this->expectedApplicantNum;
}

void RecruitmentInfoList::setRecruitmentInfo(vector<RecruitmentInfo*> riList) {
    this->rCList = riList;
}

//-----------------------------------------------

SearchRecruitmentInfoUI::SearchRecruitmentInfoUI(SearchRecruitmentInfo* searchRecruitmentInfo) {
    this->searchRecruitmentInfo = searchRecruitmentInfo;
}


void SearchRecruitmentInfoUI::startInterface() {
    //�Է�â�� ���� 

    string companyName;
    fin >> companyName;


    this->searchRecruitmentInfo->searchRecruitmentInfoListByComName(companyName);

    fout << "> " << this->searchRecruitmentInfo->getResult()->getName() << " " <<
        this->searchRecruitmentInfo->getResult()->getBn() << " " << this->searchRecruitmentInfo->getResult()->getTask() << " " <<
        this->searchRecruitmentInfo->getResult()->getExpectedApplicantNum()<<" " << this->searchRecruitmentInfo->getResult()->getFinishDate() << "\n\n";




}
RecruitmentInfo* SearchRecruitmentInfo::getResult() {
    return this->result;
}

SearchRecruitmentInfo::SearchRecruitmentInfo(RecruitmentInfoList* riList) {
    this->riList = riList;
    this->companyName = "";

    SearchRecruitmentInfoUI* searchRecruitmentInfoUI = new SearchRecruitmentInfoUI(this);
    searchRecruitmentInfoUI->startInterface();
}

void SearchRecruitmentInfo::searchRecruitmentInfoListByComName(string companyName) {
    this->companyName = companyName;
    this->result = this->riList->findByName(companyName);

}


//ä�� ����

ApplyForRecruitmentInfoUI::ApplyForRecruitmentInfoUI(ApplyForRecruitmentInfo* applyForRecruitmentInfo) {
    this->applyForRecruitmentInfo = applyForRecruitmentInfo;
}

void ApplyForRecruitmentInfoUI::applyForRecruitmentInfoByNum(string bn) {
    this->applyForRecruitmentInfo->addApplicant(bn);
}


void ApplyForRecruitmentInfoUI::startInterface(RecruitmentInfoList* riList) {

    vector<RecruitmentInfo*> tmp;
    tmp = riList->getRIList();
    int size = tmp.size();
    for (int i = 0; i < size; i++) {
        fout << "> " << tmp[i]->getName() << " " << tmp[i]->getBn() << " " << tmp[i]->getTask() << "\n\n";
    }

    string tmpBn;
    fin >> tmpBn;
    this->applyForRecruitmentInfoByNum(tmpBn);

}



ApplyForRecruitmentInfo::ApplyForRecruitmentInfo(GeneralClient* gClient, RecruitmentInfoList* riList) {
    this->gClient = gClient;
    this->riList = riList;//���� ��ϵ� ä������ ����Ʈ
    vector<RecruitmentInfo*> tmp = riList->getRIList();

    sort(tmp.begin(), tmp.end(), CompareRecruitmentInfo());

    RecruitmentInfoList* tmpRiList = new RecruitmentInfoList(); \
    tmpRiList->setRecruitmentInfo(tmp);

    ApplyForRecruitmentInfoUI* applyForRecruitmentInfoUI = new ApplyForRecruitmentInfoUI(this);

    applyForRecruitmentInfoUI->startInterface(tmpRiList);
}


//
void ApplyForRecruitmentInfo::addApplicant(string bn) {
    appliedRecruitmentInfo = this->riList->findByNum(bn);
    this->gClient->addApplication(appliedRecruitmentInfo);
    this->appliedRecruitmentInfo->addApplicantToRecruitment();//�� ä�������� �����ڼ� �ϳ� �߰��ؾ���
    fout << endl << "> " << "�����Ϸ�: " << this->appliedRecruitmentInfo->getName() << ' ' << this->appliedRecruitmentInfo->getBn() << ' ' << this->appliedRecruitmentInfo->getTask() << endl << endl;
}

// ä������

// ����������ȸ
InquireApplicationInfo::InquireApplicationInfo(GeneralClient* gClient) {
    this->gClient = gClient;
    this->gcAppliedList = gClient->getListAppliedInfo();

    vector<RecruitmentInfo*> tmp = gcAppliedList;//�ش� ȸ���� ������ ȸ������ ����Ʈ

    sort(tmp.begin(), tmp.end(), CompareRecruitmentInfo());

    InquireApplicationInfoUI* inquireApplicationInfoUI = new InquireApplicationInfoUI();
    inquireApplicationInfoUI->startInterface(tmp);
}




void InquireApplicationInfoUI::startInterface(vector<RecruitmentInfo*> gcAppliedList) {
    int size = gcAppliedList.size();

    for (int i = 0; i < size; i++) {
        fout << "> " << gcAppliedList[i]->getName() << " " << gcAppliedList[i]->getTask() << " " << gcAppliedList[i]->getExpectedApplicantNum()
            << " " << gcAppliedList[i]->getFinishDate() << "\n\n";
    }
}


bool CompareRecruitmentInfo::operator()(const RecruitmentInfo* a, const RecruitmentInfo* b) {
    string aName = a->getName();
    string bName = b->getName();
    if (aName != bName) {
        return aName < bName;
    }
    else {//��� ȸ���̸��� ���� ���� ������ compile�� ���� ���� ó��
        return aName > bName;

    }
}

//

CancelApplicationInfo::CancelApplicationInfo(GeneralClient* gClient, RecruitmentInfoList* riList)
{    
    this->gClient = gClient;
    this->riList = riList;

    
    vector<RecruitmentInfo*> tmp = riList->getRIList();

    sort(tmp.begin(), tmp.end(), CompareRecruitmentInfo());

    RecruitmentInfoList* tmpRiList = new RecruitmentInfoList();
    tmpRiList->setRecruitmentInfo(tmp);

    CancelApplicationInfoUI* cancelApplicationInfoUI = new CancelApplicationInfoUI(this);

    cancelApplicationInfoUI->startInterface(tmpRiList);
}



CancelApplicationInfoUI::CancelApplicationInfoUI(CancelApplicationInfo* cancelApplicationInfo)
{
    this->cancelApplicationInfo = cancelApplicationInfo;
    this->bn = "";
}

bool compare(RecruitmentInfo* a, RecruitmentInfo* b) {
    return a->getName() < b->getName(); 
}

void CancelApplicationInfoUI::startInterface(RecruitmentInfoList* riList)
{
    vector<RecruitmentInfo*> tmp;
    tmp = riList->getRIList();
    int size = tmp.size();
    for (int i = 0; i < size; i++) {
        fout << "> " << tmp[i]->getName() << " " << tmp[i]->getBn() << " " << tmp[i]->getTask() << "\n\n";
    }

    this->bnInput();
    //int size = this->cancelApplicationInfo->gcRiList.size();

    
    
}

void CancelApplicationInfoUI::bnInput()
{
    fin >> this->bn;
    this->cancelApplicationInfo->cancelApplication(this->bn); 
}

vector<RecruitmentInfo*> GeneralClient::getListAppliedInfo() {
    return this->appliedList;
}


void CancelApplicationInfo::cancelApplication(string bn)
{
    //��Ʈ���� ���� �ִ� �Ϲ�ȸ���� ���� ���� ����Ʈ���� bn���� ��ġ�ϴ� ä�� ������ ����Ʈ���� �����Ѵ�
    for (int i = 0; i < this->gcRiList.size(); i++)
    {
        if (gcRiList[i]->getBn() == bn)
        {
            //this->cCList.erase(cCList.begin() + i);
            this->gcRiList.erase(gcRiList.begin() + i);
        }
    }
    //��Ʈ���� ���� �ִ� ��ü ä�� ��������Ʈ���� bn���� ��ġ�ϴ� ä�� ������ ������ ���� ���ҽ�Ų��.

    int tmpSize = this->riList->getRIList().size();

    for (int i = 0; i < tmpSize; i++)
    {
        if (riList[i].getRIList()[i]->getBn() == bn)
        {
            riList[i].getRIList()[i]->subApplicantToRecruitment();
        }
    }

    cout << "���������� �����Ǿ����ϴ�" << endl;
    
   

}