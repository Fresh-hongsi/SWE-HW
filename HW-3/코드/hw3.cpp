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
                fout << "3.2. ��ϵ� ä�� ���� ��ȸ" << endl;
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
                fout << "4.2. ä�� ����\n";
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
        case 5: {
            switch (menu_level_2)
            {
            case 1: // "5.1 ���� ���� ���" �޴� �κ�
            {
                fout << "5.1 ���� ���� ���" << endl;
                if (logIn != nullptr) //�Ѹ��̶� �α����� �Ǿ��ִ� ��쿡�� ����
                {
                    curLogInClient = logIn->getLogInClient();
                    string clientId = curLogInClient->getId();
                    int clientType = curLogInClient->getType();
                    if (clientType == 1) { //ȸ�� ȸ���� ��� ����
                        CompanyClient* tmpCompanyClient = ccList->findById(clientId);
                        ViewStatisticsOfRegisteredRecruitmentInfo *viewStatisticsOfRegisteredRecruitmentInfo = new ViewStatisticsOfRegisteredRecruitmentInfo(tmpCompanyClient);
                    }
                    if (clientType == 2) { //�Ϲ� ȸ���� ��� ����
                        GeneralClient* tmpGeneralClient = gcList->findById(clientId);
                        ViewStatisticsOfAppliedInfo *viewStatisticsOfAppliedInfo = new ViewStatisticsOfAppliedInfo(tmpGeneralClient);
                    }
                }
                else //�α��εǾ��ִ� ����� ���� ��� 
                {
                    cout << "��� ������ ��ȸ�� �� �����ϴ�." << endl;
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



/*
    �Լ��̸�: Client::getName
    ���: �ش� ȸ���� �̸��� ��ȯ�Ѵ�.
    �Ű�����: ����
    ��ȯ��: �ش� ȸ���� �̸� this->name
    �ۼ���¥: 2023/05/21
    �ۼ���: �ڽ�ȫ
*/
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



/*
   �Լ��̸�: CompanyClient::getbn()
   ���:  ȸ��ȸ���� ����� ��ȣ�� ��ȯ�Ѵ�
   �Ű�����: -
   ��ȯ��: bn -> ����� ��ȣ

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
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

�ۼ���¥ : 2023 / 05 / 21
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    �Լ��̸�: RecruitmentInfo::getBn
    ���: ä������ ����� ��ȣ�� ��ȯ
    �Ű�����: ����
    ��ȯ��: ����ڹ�ȣ
    �ۼ���¥: 2023/05/22
    �ۼ���: ������
*/
string RecruitmentInfo::getBn() {
    return this->bn;
}

/*
    �Լ��̸�: RecruitmentInfo::findByName
    ���: ä���Ͽ��� companyName�� ���� ä����� ��ȯ
    �Ű�����: string companyName: ã�� ȸ���̸�
    ��ȯ��: �Ű������� ��ġ�ϴ� ȸ���̸��� ���� ä�����
    �ۼ���¥: 2023/05/22
    �ۼ���: ������
*/
RecruitmentInfo* RecruitmentInfoList::findByName(string companyName) {
    int size = rCList.size();
    for (int i = 0; i < size; i++) {
        if (companyName == rCList[i]->getName()) {
            return rCList[i];
        }
    }
}

/*
    �Լ��̸�: RecruitmentInfoList::findByNum
    ���: RecruitmentInfoList���� ����� ��ȣ�� ���� RecruitmentInfo�� ��ȯ
    �Ű�����: string bn: ã�ƾ��� ����� ��ȣ
    ��ȯ��: RecruitmentInfo* bn�� ���� ä�������� ������
    �ۼ���¥: 2023/05/23
    �ۼ���: ������
*/
RecruitmentInfo* RecruitmentInfoList::findByNum(string bn) {
    int size = rCList.size();
    for (int i = 0; i < size; i++) {
        if (bn == rCList[i]->getBn()) {
            return rCList[i];
        }
    }
}


/*
    �Լ��̸�: RecruitmentInfo::getName const
    ���: ä������ ȸ�� �̸��� ��ȯ(�б�����)
    �Ű�����: ����
    ��ȯ��: ȸ���̸�
    �ۼ���¥: 2023/05/22
    �ۼ���: ������
*/
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

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
SignIn::SignIn(ClientList* list, GeneralClientList* gcList, CompanyClientList* ccList)
{
    SignInUI* signInUI = new SignInUI(this); //�ٿ���� Ŭ������ ���۷��� ��ȯ�� ���� �ٿ���� Ŭ������ ������ ȣ��
    this->cList = list; //��Ʈ�� Ŭ������ ��� ������ ȸ������ �迭 ����
    this->gcList = gcList; //��Ʈ�� Ŭ������ ��� ������ �Ϲ�ȸ������ �迭 ����
    this->ccList = ccList; //��Ʈ�� Ŭ������ ��� ������ �Ϲ�ȸ������ �迭 ����
    this->signInUI = signInUI; //�ٿ���� Ŭ������ ���۷��� �� ����
    signInUI->startInterface(); //��Ʈ�� Ŭ������ ���� ���ÿ� startInterface ȣ���� �ٿ���� Ŭ�������� ���
}

/*
   �Լ��̸�: �ٿ���� Ŭ���� SignInUI�� ������
   ���: ȸ������ ���� ����� �����ϱ� ���� �ٿ���� Ŭ������ �����ڷμ� �����
   �Ű�����:
            SignIn* signIn -> ȸ�� ���԰� ���õ� ��Ʈ�� Ŭ������ ���۷����� attribute�� ����

   ��ȯ��: ����

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
SignInUI::SignInUI(SignIn* signIn)
{
    this->signIn = signIn;
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

   �ۼ���¥: 2023/05/21
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

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
void SignInUI::fillInfo()
{
    fin >> this->type >> this->name >> this->num >> this->id >> this->pw;
    this->signIn->addNewClient(this->type, this->name, this->num, this->id, this->pw);
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

   �ۼ���¥: 2023/05/21
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

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
LogIn::LogIn(ClientList* list, GeneralClientList* gcList, CompanyClientList* ccList)
{
    LogInUI* logInUI = new LogInUI(this); //�ٿ���� Ŭ������ ���۷��� ��ȯ�� ���� �ٿ���� Ŭ������ ������ ȣ��
    this->cList = list; //��Ʈ�� Ŭ������ ��� ������ ȸ������ �迭 ����
    this->gcList = gcList; //��Ʈ�� Ŭ������ ��� ������ �Ϲ�ȸ������ �迭 ����
    this->ccList = ccList; //��Ʈ�� Ŭ������ ��� ������ �Ϲ�ȸ������ �迭 ����
    this->logInUI = logInUI; //�ٿ���� Ŭ������ ���۷��� �� ����
    this->curLogInClient = nullptr;  //ó�� LogInŬ������ ������ �� �α��ε� ������ nullptr����
    logInUI->startInterface();  //��Ʈ�� Ŭ������ ���� ���ÿ� startInterface ȣ���� �ٿ���� Ŭ�������� ���
}



/*
   �Լ��̸�: LogIn::tryLogIn
   ���: �α����� �ϱ� ���� clientList�� ����� ��� ȸ���� ������ ������ ��, id, pw�� ��� ��ġ�ϰ� �α����� �ȵǾ��ִ� ��쿡�� �α��� ���·� �ٲ��ش�.
   �Ű�����:
             id -> ȸ���� �Է��� id
             pw ->ȸ���� �Է��� pw
   ��ȯ��: ����

   �ۼ���¥: 2023/05/21
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

   �ۼ���¥: 2023/05/21
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
            LogIn* logIn -> �α��ΰ� ���õ� ��Ʈ�� Ŭ������ ���۷����� attribute�� ����

   ��ȯ��: ����

   �ۼ���¥: 2023/05/31
   �ۼ���: �ڽ�ȫ
*/
LogInUI::LogInUI(LogIn* logIn)
{
    this->logIn = logIn;
    this->id = "";
    this->pw = "";

}

/*
   �Լ��̸�: LogInInUI::startInterface
   ���: ȸ�� id�� pw�� �Է��϶�� ȭ���� �����ְ�, �ʿ� ������ �Է¹޾� ��Ʈ�� Ŭ�������� �Է¹��� ������ ���� �α����� ��û�Ѵ�.
   �Ű�����: ����
   ��ȯ��: ����

   �ۼ���¥: 2023/05/21
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

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
void LogInUI::fillIDPW()
{
    fin >> this->id >> this->pw;
    this->logIn->tryLogIn(this->id, this->pw);
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

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
LogOut::LogOut(ClientList* list, GeneralClientList* gcList, CompanyClientList* ccList, Client* client)
{
    LogOutUI* logOutUI = new LogOutUI(this); //�ٿ���� Ŭ������ ���۷��� ��ȯ�� ���� �ٿ���� Ŭ������ ������ ȣ��
    this->cList = list; //��Ʈ�� Ŭ������ ��� ������ ȸ������ �迭 ����
    this->gcList = gcList; //��Ʈ�� Ŭ������ ��� ������ �Ϲ�ȸ������ �迭 ����
    this->ccList = ccList; //��Ʈ�� Ŭ������ ��� ������ �Ϲ�ȸ������ �迭 ����
    this->curLogInClient = client; //�α��ε� Client��ü�� ����
    this->logOutUI = logOutUI;   //�ٿ���� Ŭ������ ���۷��� �� ����
    this->changeLogInStatus(curLogInClient); //���� �α��ε� ������ ������ �������� �α׾ƿ� ��� ���� ���

}


/*
   �Լ��̸�: �ٿ���� Ŭ���� LogOutUI�� ������
   ���: �α׾ƿ� ���� ����� �����ϱ� ���� �ٿ���� Ŭ������ �����ڷμ� �����
   �Ű�����:
            LogOut* logOut -> �α׾ƿ��� ���õ� ��Ʈ�� Ŭ������ ���۷����� attribute�� ����

   ��ȯ��: ����

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
LogOutUI::LogOutUI(LogOut* logOut)
{
    this->logOut = logOut;

}

/*
   �Լ��̸�: LogOut::changeLogInStatus
   ���: �α׾ƿ��� �ϱ� ���� clientList�� ����� ��� ȸ���� ������ ������ ��, �α��ε� Client�� id�� pw�� ��ġ�ϴ� �� Ȯ��
        �� ��, match�� ������ login���°� true��� �α��� ���¸� false�� �ٲ��ش�.
   �Ű�����:
             Client* client -> �α��ε� ����
   ��ȯ��: ����

   �ۼ���¥: 2023/05/21
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


    this->logOutUI->startInterface(id, isPossible); //�ٿ���� Ŭ������ �α׾ƿ� �������� �α׾ƿ��� ������ id���� �Ű������� �����ش�


}

/*
   �Լ��̸�: LogOutUI::startInterface
   ���: �α׾ƿ��� ������ ���, �α׾ƿ��� ������ id���� ���Ͽ� ����.
   �Ű�����: string id ->�α׾ƿ��� ȸ���� id��
            flag -> �α׾ƿ� ��: true / �α׾ƿ� �Ұ��� -> false
   ��ȯ��: ����

   �ۼ���¥: 2023/05/21
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

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
SignOut::SignOut(ClientList* list, GeneralClientList* gcList, CompanyClientList* ccList, Client* client)
{
    SignOutUI* signOutUI = new SignOutUI(this); //�ٿ���� Ŭ������ ���۷��� ��ȯ�� ���� �ٿ���� Ŭ������ ������ ȣ��
    this->cList = list; //��Ʈ�� Ŭ������ ��� ������ ȸ������ �迭 ����
    this->gcList = gcList; //��Ʈ�� Ŭ������ ��� ������ �Ϲ�ȸ������ �迭 ����
    this->ccList = ccList; //��Ʈ�� Ŭ������ ��� ������ �Ϲ�ȸ������ �迭 ����
    this->curLogInClient = client; //�α��ε� Client��ü�� ����
    this->signOutUI = signOutUI; //�ٿ���� Ŭ������ ���۷��� �� ����
    this->destroy(curLogInClient); //���� �α��ε� ���� ������ �������� ȸ��Ż�� ��� ����

}


/*
   �Լ��̸�: �ٿ���� Ŭ���� SignOutUI�� ������
   ���: ȸ��Ż�� ���� ����� �����ϱ� ���� �ٿ���� Ŭ������ �����ڷμ� �����
   �Ű�����:
            SignOut* signOut -> �α׾ƿ��� ���õ� ��Ʈ�� Ŭ������ ���۷����� attribute�� ����

   ��ȯ��: ����

   �ۼ���¥: 2023/05/21
   �ۼ���: �ڽ�ȫ
*/
SignOutUI::SignOutUI(SignOut* signOut)
{
    this->signOut = signOut;

}


/*
   �Լ��̸�: SignOut::destroy
   ���: ȸ��Ż��� �ϱ� ���� clientList�� ����� ��� ȸ���� ������ ������ ��, �α��ε� Client�� id�� pw�� ��ġ�ϴ� �� Ȯ��
        �� ��, match�� ������ login���°� true��� ȸ�������� �����ϰ�, �ش� ������ �Ϲ�/ȸ��ȸ�� ������ ���� ������ �� ������ ��û�Ѵ�.
   �Ű�����:
             Client* client -> �α��� �� ����
   ��ȯ��: ����

   �ۼ���¥: 2023/05/21
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


    this->signOutUI->startInterface(id, isPossible); //�ٿ���� Ŭ������ ȸ��Ż�� �������� ȸ��Ż���� ������ id���� �Ű������� �����ش�
}


/*
   �Լ��̸�: SignOutUI::startInterface
   ���: ȸ��Ż�� ������ ���, ȸ��Ż���� ������ id���� ���Ͽ� ����.
   �Ű�����: string id ->ȸ��Ż���� ȸ���� id��
            flag -> ȸ��Ż�� ��: true / ȸ��Ż�� �Ұ��� -> false
   ��ȯ��: ����

   �ۼ���¥: 2023/05/21
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
 ���: RegisterRecruitmentInfo control Ŭ������ �������Դϴ�.
 �Ű�����: CompanyClient* companyClient
           RecruitmentInfoList* recruitmentInfoList
 ��ȯ��: ����
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
 ���: RegisterRecruitmentInfoUI boundary Ŭ������ �������Դϴ�.
 �Ű�����: RegisterRecruitmentInfo* registerRecruitmentInfo
           CompanyClient* companyClient
 ��ȯ��: ����
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
 ���: RegisterRecruitmentInfoUI���� registerInput�Լ��� ȣ���Ͽ� �Է°��� �޵��� �մϴ�.
 �Ű�����: ����
 ��ȯ��: ����
 �ۼ���¥: 2023/05/22
 �ۼ���: �����
*/
void RegisterRecruitmentInfoUI::startInterface()
{
    cout << "ä�� ���� ����� ���� �ʵ带 �Է��ϼ���" << endl;;
    this->registerInput();
}

/*
 �Լ��̸�: RegisterRecruitmentInfoUI::registerInput()
 ���: ����, �ο���, �������� �Է°��� �ް� registerRecruitmentInfo�� addNewRecruitmentInfo �Լ��� ȣ���ϰ� result �Լ��� ����ڿ��� ��ϵ� ������ ǥ���մϴ�.
 �Ű�����: ����
 ��ȯ��: ����
 �ۼ���¥: 2023/05/22
 �ۼ���: �����
*/
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
 �Ű�����: string task
           int expectedApplicantNum
           string finishDate
 ��ȯ��: ����
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
 �Լ��̸�: RegisterRecruitmentInfo::addNewRecruitmentInfo
 ���: addNewRecruitInfo �Լ��� ȣ���� companyClient�� �����Ϳ� RecruitmentInfo�� �߰��ϵ��� �մϴ�. addNewRecruitmentInfoList �Լ��� ȣ���� recruitmentInfoList�� �����Ϳ� RecruitmentInfo�� �߰��ϵ��� �մϴ�.
 �Ű�����: string task
           int expectedApplicantNum
           string finishDate
 ��ȯ��: ����
 �ۼ���¥: 2023/05/22
 �ۼ���: �����
*/
void RegisterRecruitmentInfo::addNewRecruitmentInfo(string task, int expectedApplicantNum, string finishDate)
{
    RecruitmentInfo *tmp = companyClient->addNewRecruitInfo(task, expectedApplicantNum, finishDate);
    this->recruitmentInfoList->addNewRecruitmentInfoList(tmp);
}

/*
 �Լ��̸�: RecruitmentInfoList::addNewRecruitmentInfoList
 ���: RecruitmentInfoList�� �����Ϳ� RecruitmentInfo�� �߰��մϴ�.
 �Ű�����: RecruitmentInfo* ri
 ��ȯ��: ����
 �ۼ���¥: 2023/05/22
 �ۼ���: �����
*/
void RecruitmentInfoList::addNewRecruitmentInfoList(RecruitmentInfo* ri) {
    this->rCList.push_back(ri);
}
/*
 �Լ��̸�: CompanyClient::addNewRecruitInfo
 ���: CompanyClient�� �����Ϳ� RecruitmentInfo�� �߰��մϴ�.
 �Ű�����: string task
           int expectedApplicantNum
           string finishDate
 ��ȯ��: ����
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
 �Ű�����: string companyName
           string bn
           string task
           int expectedApplicantNum
           string finishDate
 ��ȯ��: ����
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
    this->numOfApplicant = 0;
}

/*
 �Լ��̸�: InquireRecruitmentInfo::InquireRecruitmentInfo
 ���: InquireRecruitmentInfo control Ŭ������ �������Դϴ�.
 �Ű�����: CompanyClient* companyClient
 ��ȯ��: ����
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
 �Լ��̸�: InquireRecruitmentInfoUI::InquireRecruitmentInfoUI
 ���: InquireRecruitmentInfoUI boundary Ŭ������ �������Դϴ�.
 �Ű�����: InquireRecruitmentInfo* inquireRecruitmentInfo
 ��ȯ��: ����
 �ۼ���¥: 2023/05/22
 �ۼ���: �����
*/
InquireRecruitmentInfoUI::InquireRecruitmentInfoUI(InquireRecruitmentInfo* inquireRecruitmentInfo)
{
    this->inquireRecruitmentInfo = inquireRecruitmentInfo;
}

/*
 �Լ��̸�: InquireRecruitmentInfoUI::startInterface
 ���: ������� ȸ�� ȸ���� ��� RecruitmentInfo�� ����մϴ�.
 �Ű�����: vector<RecruitmentInfo*> riList
 ��ȯ��: ����
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

/*
    �Լ��̸�: CompanyClientList::findById
    ���: ȸ���� id�� �������� ȸ��ȸ�� ����Ʈ���� ȸ��ȸ�� ������ ��ȯ
    �Ű�����: string id: ã�� ȸ��ȸ���� id
    ��ȯ��: �ش� id�� ���� ȸ��ȸ��
    �ۼ���¥: 2023/05/22
    �ۼ���: ������
*/
CompanyClient* CompanyClientList::findById(string id) {
    int size = cCList.size();

    for (int i = 0; i < size; i++) {
        if (id == cCList[i]->getId()) {
            return cCList[i];
        }
    }
}

/*
    �Լ��̸�: GeneralClientList::findById
    ���: ��ϵ� �Ϲ�ȸ�� ����Ʈ���� id�� ���� �Ϲ�ȸ���� ã�´�.
    �Ű�����: string id : ã�� ȸ���� id
    ��ȯ��: �ش�id�� ���� GeneralClient
    �ۼ���¥: 2023/05/22
    �ۼ���: ������
*/
GeneralClient* GeneralClientList::findById(string id) {
    int size = gCList.size();

    for (int i = 0; i < size; i++) {
        if (id == gCList[i]->getId()) {
            return gCList[i];
        }
    }
}

/*
    �Լ��̸�: CompanyClient::getListRegisteredInfo
    ���: ȸ��ȸ���� ����� ä�������� ��ȯ
    �Ű�����: ����
    ��ȯ��: �ش� ȸ��ȸ���� ����� ä�������
    �ۼ���¥: 2023/05/22
    �ۼ���: ������
*/
vector<RecruitmentInfo*> CompanyClient::getListRegisteredInfo() {
    return registeredList;
}

/*
    �Լ��̸�: RecruitmentInfo::getTask
    ���: ä�������� ������ ��ȯ
    �Ű�����: ����
    ��ȯ��: ä�������� ����
    �ۼ���¥: 2023/05/22
    �ۼ���: ������
*/
string RecruitmentInfo::getTask() {
    return this->task;
}

/*
    �Լ��̸�: RecruitmentInfo::getApplicantNum
    ���: ä�������� ���� ������ ���� ��ȯ
    �Ű�����: ����
    ��ȯ��: ä�������� ���� �����ڼ�
    �ۼ���¥: 2023/05/22
    �ۼ���: ������
*/
int RecruitmentInfo::getApplicantNum() {
    return this->numOfApplicant;
}
/*
    �Լ��̸�: RecruitmentInfo::getFinishDate
    ���: ä�������� �������� ��ȯ
    �Ű�����: ����
    ��ȯ��: ä�������� ������
    �ۼ���¥: 2023/05/22
    �ۼ���: ������
*/
string RecruitmentInfo::getFinishDate() {
    return this->finishDate;
}

/*
    �Լ��̸�: RegisterRecruitmentInfo::getRecruitmentInfoList
    ���: �ش� Ŭ������ private ������ recruitmentInfoList�� ��ȯ
    �Ű�����: ����
    ��ȯ��: �ش� Ŭ������ ä����������Ʈ
    �ۼ���¥: 2023/05/22
    �ۼ���: ������
*/

RecruitmentInfoList* RegisterRecruitmentInfo::getRecruitmentInfoList() {
    return this->recruitmentInfoList;
}

/*
    �Լ��̸�: RegisterRecruitmentInfo::getRegisteredList
    ���: �ش� Ŭ������ private ������ registeredList�� ��ȯ
    �Ű�����: ����
    ��ȯ��: �ش� Ŭ������ ��ϵ� ä����������Ʈ
    �ۼ���¥: 2023/05/22
    �ۼ���: ������
*/
RecruitmentInfo* RegisterRecruitmentInfo::getRegisteredList() {
    return this->registeredList;
}

/*
    �Լ� �̸�: RecruitmentInfoList::getRIList const
    ���: RecruitmentInfoLIst�� private ������ vector<RecruitmentInfo*> rCList�� ��ȯ��
    �Ű�����: ����
    ��ȯ��: RecruitmentInfoLIst�� private ������ vector<RecruitmentInfo*> rCList
    �ۼ���¥: 2023/05/23
    �ۼ���: ������
*/
vector<RecruitmentInfo*> RecruitmentInfoList::getRIList() const{
    return this->rCList;
}

/*
    �Լ��̸�: GeneralClient::addApplication
    ���: �Ϲ�ȸ���� ������Ͽ� ���ο� ä����� �߰�
    �Ű�����: RecruitmentInfo *ri: ������ ä�����
    ��ȯ��: ����
    �ۼ���¥: 2023/05/23
    �ۼ���: ������
*/
void GeneralClient::addApplication(RecruitmentInfo* ri) {
    this->appliedList.push_back(ri);
}

/*
    �Լ��̸�: RecruitmentInfo::addApplicantToRecruitment
    ���: �ش� ä�������� �����ڼ� 1�� �߰�
    �Ű�����: ����
    ��ȯ��: ����
    �ۼ���¥: 2023/05/23
    �ۼ���: ������
*/
void RecruitmentInfo::addApplicantToRecruitment() {
    this->numOfApplicant += 1;
}

/*
    �Լ��̸�: RecruitmentInfo::subApplicantToRecruitment
    ���: �ش� ä�������� �����ڼ� 1�� ����
    �Ű�����: ����
    ��ȯ��: ����
    �ۼ���¥: 2023/05/24
    �ۼ���: ������
*/
void RecruitmentInfo::subApplicantToRecruitment() {
    this->numOfApplicant -= 1;
}

/*
    �Լ��̸�: RecruitmentInfo::getExpectedApplicantNum
    ���: �ش� ä�������� �����ο��� ��ȯ
    �Ű�����: ����
    ��ȯ��: �����ο�
    �ۼ���¥: 2023/05/23
    �ۼ���: ������
*/
int RecruitmentInfo::getExpectedApplicantNum() {
    return this->expectedApplicantNum;
}

/*
    �Լ��̸�: RecruitmentInfoList::setRecruitmentInfo
    ���: RecruitmentInfoList�� private ���� rCList�� �ʱ�ȭ
    �Ű�����: �ʱ�ȭ�� vector
    ��ȯ��: ����
    �ۼ���¥: 2023/05/23
    �ۼ���: ������
*/
void RecruitmentInfoList::setRecruitmentInfo(vector<RecruitmentInfo*> riList) {
    this->rCList = riList;
}


/*
   �Լ��̸�: SearchRecruitmentInfoUI::SearchRecruitmentInfoUI
   ���: ä������ �˻� Boundary Ŭ������ ������
   �Ű�����: SearchRecruitmentInfo *searchRecruitmentInfo: �ش� use case�� Control class �������� �Ű������� ����
   ��ȯ��: ����
   �ۼ���¥: 2023/05/22
   �ۼ���: ������
*/
SearchRecruitmentInfoUI::SearchRecruitmentInfoUI(SearchRecruitmentInfo* searchRecruitmentInfo) {
    this->searchRecruitmentInfo = searchRecruitmentInfo;
}

/*
    �Լ��̸�: SearchRecruitmentInfoUI::fillInput
    ���: ����ڿ��� �˻��� ȸ���̸��� �Է¹޴� �Լ�
    �Ű�����: ����
    ��ȯ��: ����:
    �ۼ���¥: 2023/05/22
    �ۼ���: ������
*/

void SearchRecruitmentInfoUI::fillInput() {
    string tmpCompanyName;
    fin >> tmpCompanyName;
    this->companyName = tmpCompanyName;
}
/*
    �Լ��̸�: SearchRecruitmentInfoUI::startInterface
    ���: ä������ �˻�ȭ���� ���� ���� �������̽�
    �Ű�����: ����
    ��ȯ��: ����
    �ۼ���¥: 2023/05/22
    �ۼ���: ������
*/
void SearchRecruitmentInfoUI::startInterface() {
    //�Է�â�� ���� 

    this->fillInput();
    string companyName = this->companyName;

    this->searchRecruitmentInfo->searchRecruitmentInfoListByComName(companyName);
}

/*
    �Լ��̸�: SearchRecruitmentInfo::getResult
    ���: ControlŬ������ ������ �ִ� �˻� ����� private ���� result�� ��ȯ�ϴ� �Լ�
    �Ű�����: ����
    ��ȯ��: RecruitmentInfo* �˻������ Reference
    �ۼ���¥: 2023/05/22
    �ۼ���: ������
*/
RecruitmentInfo* SearchRecruitmentInfo::getResult() {
    return this->result;
}

/*
   �Լ��̸�: SearchRecruitmentInfo::SearchRecruitmentInfo
   ���: ä������ �˻� ControlŬ������ ������
   �Ű�����: RecruitmentInfoList *riList: ���� ���ǿ� ��ϵ� ä������ ���
   ��ȯ��: ����
   �ۼ���¥: 2023/05/22
   �ۼ���: ������
*/
SearchRecruitmentInfo::SearchRecruitmentInfo(RecruitmentInfoList* riList) {
    this->riList = riList;
    this->companyName = "";

    SearchRecruitmentInfoUI* searchRecruitmentInfoUI = new SearchRecruitmentInfoUI(this);
    searchRecruitmentInfoUI->startInterface();
}

/*
    �Լ��̸�: SearchRecruitmentInfo::searchRecruitmentInfoListByComName
    ���: ��ϵ� ä������� companyName�� �������� RecruitmentInfo�� ã�� �� ����� ����ϴ� �Լ�
    �Ű�����: companyName: ȸ���� �Է��� ȸ���̸�
    ��ȯ��: ����
    �ۼ���¥: 2023/05/22
    �ۼ���: ������
*/
void SearchRecruitmentInfo::searchRecruitmentInfoListByComName(string companyName) {
    this->companyName = companyName;
    this->result = this->riList->findByName(companyName);
    fout << "> " << this->getResult()->getName() << " " <<
        this->getResult()->getBn() << " " << this->getResult()->getTask() << " " <<this->getResult()->getExpectedApplicantNum() << " " << 
        this->getResult()->getFinishDate() << "\n\n";

}


/*
    �Լ��̸�: ApplyForRecruitmentInfoUI::ApplyForRecruitmentInfoUI
    ��ɣ�Boundary class ApplyForRecruitmentInfoUI�� ������
    �Ű�����: ApplyForRecruitmentInfo* applyForRecruitmentInfo : control Ŭ������ ������
    ��ȯ��: ����
    �ۼ���¥: 2023/05/23
    �ۼ���: ������
*/

ApplyForRecruitmentInfoUI::ApplyForRecruitmentInfoUI(ApplyForRecruitmentInfo* applyForRecruitmentInfo) {
    this->applyForRecruitmentInfo = applyForRecruitmentInfo;
}


/*
    �Լ��̸�: ApplyForRecruitmentInfoUI::fillComName
    ���: �Ϲ�ȸ���� ������ ȸ���� ����� ��ȣ�� �Է¹޴´�.
    �Ű�����: ����
    ��ȯ��: ����
    �ۼ���¥: 2023/05/23
    �ۼ���: ������
*/
void ApplyForRecruitmentInfoUI::fillComName() {
    string tmpBn;
    fin >> tmpBn;
    this->bn = tmpBn;
    this->applyForRecruitmentInfo->addApplicant(tmpBn);
    
}

/*
    �Լ��̸�: ApplyForRecruitmentInfoUI::startInterface
    ���: ȭ�鿡 ���� ��ϵ� ä����� ����� �����ش�.
    �Ű�����: RecruitmentInfoList *riList : ���ĵ� ä�������
    ��ȯ��: ����
    �ۼ���¥: 2023/05/23
    �ۼ���: ������
*/
void ApplyForRecruitmentInfoUI::startInterface(RecruitmentInfoList* riList) {

    vector<RecruitmentInfo*> tmp;
    tmp = riList->getRIList();
    int size = tmp.size();
    fout << "> ��ȸ�� ä�����\n\n";
    for (int i = 0; i < size; i++) {
        fout << "> " << tmp[i]->getName() << " " << tmp[i]->getBn() << " " << tmp[i]->getTask() << "\n\n";
    }

    this->fillComName();
    

}

/*
    �Լ��̸�: ApplyForRecruitmentInfo::ApplyForRecruitmentInfo
    ���: Control Class ApplyForRecruitmentInfo�� ������
    �Ű�����: 
        GeneralClient* gClient: ���� �α�����, �����ϰ����ϴ� �Ϲ�ȸ�� 
        RecruitmentInfoList* riList: ���� ���ǿ� ��ϵ� ä������ ���
    ��ȯ��: ����
    �ۼ�����: 2023/05/25
    �ۼ���: ������
*/

ApplyForRecruitmentInfo::ApplyForRecruitmentInfo(GeneralClient* gClient, RecruitmentInfoList* riList) {
    this->gClient = gClient;
    this->riList = riList;
    vector<RecruitmentInfo*> tmp = riList->getRIList();

    sort(tmp.begin(), tmp.end(), CompareRecruitmentInfo());

    RecruitmentInfoList* tmpRiList = new RecruitmentInfoList(); 
    tmpRiList->setRecruitmentInfo(tmp);

    ApplyForRecruitmentInfoUI* applyForRecruitmentInfoUI = new ApplyForRecruitmentInfoUI(this);

    applyForRecruitmentInfoUI->startInterface(tmpRiList);
}


/*
    �Լ��̸�: ApplyForRecruitmentInfo::addApplicant
    ���: �Ϲ� ȸ���� ������ ä����� �����ڸ� �߰��ϰ� �Ϲ�ȸ���� ������Ͽ� �ش� ä����� �߰���
    �Ű�����: bn: �Ϲ�ȸ���� ������ ȸ���� ����� ��ȣ
    ��ȯ��: ����
    �ۼ���¥: 2023/05/23
    �ۼ���: ������
*/
void ApplyForRecruitmentInfo::addApplicant(string bn) {
    appliedRecruitmentInfo = this->riList->findByNum(bn);
    this->gClient->addApplication(appliedRecruitmentInfo);
    this->appliedRecruitmentInfo->addApplicantToRecruitment();//�� ä�������� �����ڼ� �ϳ� �߰��ؾ���
    fout << endl << "> " << "�����Ϸ�: " << this->appliedRecruitmentInfo->getName() << ' ' << this->appliedRecruitmentInfo->getBn() << ' ' << this->appliedRecruitmentInfo->getTask() << endl << endl;
}


/*
    �Լ��̸�: InquireApplicationInfo::InquireApplicationInfo
    ���: Control Class InquireApplicationInfo�� ������
    �Ű�����: GeneralClient *gClient: ���������� ��ȸ�� �Ϲ�ȸ��
    ��ȯ��: ����
    �ۼ���¥: 2023/05/23
    �ۼ���: ������
*/
InquireApplicationInfo::InquireApplicationInfo(GeneralClient* gClient) {
    this->gClient = gClient;
    this->gcAppliedList = gClient->getListAppliedInfo();

    vector<RecruitmentInfo*> tmp = gcAppliedList;//�ش� ȸ���� ������ ȸ������ ����Ʈ

    sort(tmp.begin(), tmp.end(), CompareRecruitmentInfo());

    InquireApplicationInfoUI* inquireApplicationInfoUI = new InquireApplicationInfoUI();
    inquireApplicationInfoUI->startInterface(tmp);
}



/*
    �Լ��̸�: InquireApplicationInfoUI::startInterface
    ���: �Ϲ�ȸ���� ������ �������� ����� �����ش�.
    �Ű�����: vector<RecruitmentInfo*> gcAppliedList: �Ϲ�ȸ���� ������ ���ĵ� �������� ���
    ��ȯ��: ����
    �ۼ���¥: 2023/05/23
    �ۼ���: ������
*/
void InquireApplicationInfoUI::startInterface(vector<RecruitmentInfo*> gcAppliedList) {
    int size = gcAppliedList.size();

    for (int i = 0; i < size; i++) {
        fout << "> " << gcAppliedList[i]->getName() << " " << gcAppliedList[i]->getTask() << " " << gcAppliedList[i]->getExpectedApplicantNum()
            << " " << gcAppliedList[i]->getFinishDate() << "\n\n";
    }
}


/*
    �Լ��̸�: CompareRecruitmentInfo::operator()
    ���: RecruitmentInfo�� �������� �� �Ű������� ���ϰ� �� ������ ��ȯ��-> sort�� ���Լ�
    �Ű�����: const RecruitmentInfo* a, const RecruitmentInfo* b : �� RecruitmentInfo ������
    ��ȯ��: boolean ��, a�� ä����� ȸ���̸�< bä����� ȸ���̸��϶� ���� ��ȯ
    �ۼ���¥: 2023/05/23
    �ۼ���: ������
*/
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

// ���� ���

/*
 �Լ��̸�: CancelApplicationInfo::CancelApplicationInfo
 ���: CancelApplicationInfo control class�� �������Դϴ�.
 �Ű�����: GeneralClient* gClient, RecruitmentInfoList* riList
 ��ȯ��: ����
 �ۼ���¥: 2023/05/22
 �ۼ���: �����
*/

CancelApplicationInfo::CancelApplicationInfo(GeneralClient* gClient, RecruitmentInfoList* riList)
{    
    this->gClient = gClient;
    this->gcRiList = gClient->getListAppliedInfo();
    this->riList = riList;

    //������ ������ ä��������� ��ȸ�Ѵ�.
    vector<RecruitmentInfo*> tmp = gcRiList;

    sort(tmp.begin(), tmp.end(), CompareRecruitmentInfo());

    RecruitmentInfoList* tmpRiList = new RecruitmentInfoList();
    tmpRiList->setRecruitmentInfo(tmp);

    CancelApplicationInfoUI* cancelApplicationInfoUI = new CancelApplicationInfoUI(this);

    cancelApplicationInfoUI->startInterface(tmpRiList);
}

/*
 �Լ��̸�: CancelApplicationInfoUI::CancelApplicationInfoUI
 ���: CancelApplicationInfo boundary class�� �������Դϴ�.
 �Ű�����: CancelApplicationInfo* cancelApplicationInfo
 ��ȯ��: ����
 �ۼ���¥: 2023/05/22
 �ۼ���: �����
*/
CancelApplicationInfoUI::CancelApplicationInfoUI(CancelApplicationInfo* cancelApplicationInfo)
{
    this->cancelApplicationInfo = cancelApplicationInfo;
    
}

/*
 �Լ��̸�: CancelApplicationInfoUI::startInterface
 ���: ������ ��� ä�������� ȸ���̸�, ����ڹ�ȣ, ������ ����մϴ�.
 �Ű�����: RecruitmentInfoList* gcRiList
 ��ȯ��: ����
 �ۼ���¥: 2023/05/22
 �ۼ���: �����
*/
void CancelApplicationInfoUI::startInterface(RecruitmentInfoList* gcRiList)
{
    vector<RecruitmentInfo*> tmp;
    tmp = gcRiList->getRIList();
    int size = tmp.size();
    for (int i = 0; i < size; i++) {
        fout << "> " << tmp[i]->getName() << " " << tmp[i]->getBn() << " " << tmp[i]->getTask() << "\n\n";
    }

    string tmpBn;
    fin >> tmpBn;
    
    cancelApplicationInfo->cancelApplication(tmpBn);
}


/*
 �Լ��̸�: GeneralClient::getListAppliedInfo
 ���: GeneralClient�� ������ RecruitmentInfo�� ����Ʈ�� ���ͷ� ��ȯ�մϴ�.
 �Ű�����: ����
 ��ȯ��: vector<RecruitmentInfo*>
 �ۼ���¥: 2023/05/22
 �ۼ���: �����
*/
vector<RecruitmentInfo*> GeneralClient::getListAppliedInfo() {
    return this->appliedList;
}



/*
 �Լ��̸�: CancelApplicationInfo::cancelApplication
 ���:  subApplication �Լ��� ȣ���� �Ϲ�ȸ���� ���� ���� ����Ʈ���� �Է¹��� ����ڹ�ȣ�� ����ڹ�ȣ�� ��ġ�ϴ� ä�� ������ ����Ʈ���� �����մϴ�. �׸��� subApplicantToRecruitment �Լ��� ȣ���� ��ü ä�� ��������Ʈ���� �Է¹��� ����ڹ�ȣ�� ����ڹ�ȣ�� ��ġ�ϴ� ä�� ������ ������ ���� ���ҽ�Ų��
 �Ű�����: string bn
 ��ȯ��: ����
 �ۼ���¥: 2023/05/22
 �ۼ���: �����
*/
void CancelApplicationInfo::cancelApplication(string bn)
{
    this->bn = bn;
    
    gClient->subApplication(bn);

    int tmpSize = this->riList->getRIList().size();
    
    for (int i = 0; i < tmpSize; i++)
    {
        if (riList->getRIList()[i]->getBn() == bn)
        {
            riList->getRIList()[i]->subApplicantToRecruitment();
            
        }
    }

    cout << "���������� �����Ǿ����ϴ�" << endl;
    
   

}

/*
 �Լ��̸�:  GeneralClient::subApplication
 ���:  �Ϲ�ȸ���� ���� ���� ����Ʈ���� �Ű����� bn�� ����ڹ�ȣ�� ��ġ�ϴ� ä�� ������ ����Ʈ���� �����մϴ�.
 �Ű�����: string bn
 ��ȯ��: ����
 �ۼ���¥: 2023/05/22
 �ۼ���: �����
*/
void GeneralClient::subApplication(string bn) {
    int size = appliedList.size();
    for (int i = 0; i < size; i++) {
        if (appliedList[i]->getBn() == bn) {
            fout << "> ����� ����: " << appliedList[i]->getName() << " " << appliedList[i]->getBn() << " " << appliedList[i]->getTask() << "\n\n";
            appliedList.erase(appliedList.begin() + i);
            break;
        }
    }

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
   �Լ��̸�: ��Ʈ�� Ŭ���� ViewStatisticsOfRegisteredRecruitmentInfo�� ������
   ���: ä����� ��� ��ȸ ����� �����ϱ� ���� ��Ʈ�� Ŭ������ �����ڷμ� �����
   �Ű�����:
            CompanyClient*cClient -> ȸ�� ȸ������ ������ ���� CompanyClient ��ü
   ��ȯ��: ����

   �ۼ���¥: 2023/05/23
   �ۼ���: ��ä��
*/
ViewStatisticsOfRegisteredRecruitmentInfo::ViewStatisticsOfRegisteredRecruitmentInfo(CompanyClient* cClient){
    this->cClient = cClient;
    this->printStatisticsInfo(cClient);
}

/*
   �Լ��̸�: ViewStatisticsOfRegisteredRecruitmentInfo::printStatisticsInfo
   ���: �ش� ȸ�� ȸ���� ä�� ������ �������� ���� ����� �� �̸� ����Ѵ�.
   �Ű�����:
            CompanyClient*cClient -> ȸ�� ȸ������ ������ ���� CompanyClient ��ü
   ��ȯ��: ����
   �ۼ���¥: 2023/05/23
   �ۼ���: ��ä��
*/
void ViewStatisticsOfRegisteredRecruitmentInfo::printStatisticsInfo(CompanyClient *cClient){
    vector<RecruitmentInfo*> companyClientsRecruitmentInfo = this->cClient->getListRegisteredInfo();
    map<string, int> taskByNumMap;
    int size = companyClientsRecruitmentInfo.size();
    int value = 0;
    if (size > 0) {
        for (int i = 0; i < size; i++)
        {
            if (taskByNumMap.find(companyClientsRecruitmentInfo[i]->getTask()) != taskByNumMap.end()) {
                value = taskByNumMap.find(companyClientsRecruitmentInfo[i]->getTask())->second + companyClientsRecruitmentInfo[i]->getApplicantNum();
            }
            else {
                value = companyClientsRecruitmentInfo[i]->getApplicantNum();
            }
            taskByNumMap[companyClientsRecruitmentInfo[i]->getTask()] = value;
        }
        for (auto iter = taskByNumMap.begin(); iter != taskByNumMap.end(); iter++){
            fout << "> " << iter->first << " " << iter->second << endl
                << endl;
            ;
        }
    } else {
        cout << "����� ä�� ������ �����ϴ�." << endl;
        fout << endl;
    }
}

/*
   �Լ��̸�: ��Ʈ�� Ŭ���� ViewStatisticsOfAppliedtInfo�� ������
   ���: ���� ���� ��� ��ȸ ����� �����ϱ� ���� ��Ʈ�� Ŭ������ �����ڷμ� �����
   �Ű�����:
            GeneralClient*gClient -> �Ϲ� ȸ���� ������ ���� GeneralClient ��ü
   ��ȯ��: ����

   �ۼ���¥: 2023/05/24
   �ۼ���: ��ä��
*/
ViewStatisticsOfAppliedInfo::ViewStatisticsOfAppliedInfo(GeneralClient* gClient){
    this->gClient = gClient;
    this->printStatisticsInfo(gClient);
}

/*
   �Լ��̸�: ViewStatisticsOfAppliedInfo::printStatisticsInfo
   ���: �ش� �Ϲ� ȸ���� ä�� ������ �������� ���� ����� �� �̸� ����Ѵ�.
   �Ű�����:
            GeneralClient*gClient -> �Ϲ� ȸ���� ������ ���� GeneralClient ��ü
   ��ȯ��: ����
   �ۼ���¥: 2023/05/24
   �ۼ���: ��ä��
*/
void ViewStatisticsOfAppliedInfo::printStatisticsInfo(GeneralClient* gClient){
    vector<RecruitmentInfo*> generalClientsRecruitmentInfo = this->gClient->getListAppliedInfo();
    map<string, int> taskByNumMap;
    int size = generalClientsRecruitmentInfo.size();
    int value = 0;
    if (size > 0) {
        for (int i = 0; i < size; i++)
        {
            if (taskByNumMap.find(generalClientsRecruitmentInfo[i]->getTask()) != taskByNumMap.end()) {
                value = taskByNumMap.find(generalClientsRecruitmentInfo[i]->getTask())->second + 1;
            }
            else {
                value = 1;
            }
            taskByNumMap[generalClientsRecruitmentInfo[i]->getTask()] = value;
        }
        for (auto iter = taskByNumMap.begin(); iter != taskByNumMap.end(); iter++){
            fout << "> " << iter->first << " " << iter->second << endl
                << endl;
            ;
        }
    } else {
        cout << "������ ä�� ������ �����ϴ�." << endl;
        fout << endl;
    }
}