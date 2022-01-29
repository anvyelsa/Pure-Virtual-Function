#include<string>
#include<iostream>

using namespace std;
class CPerson
{
public:
	string m_sName;
	string m_sAddress;
	long int m_lnPhoneNumber;
	long int m_lnAdharNumber;

	CPerson()
	{
		 m_sName="";
		 m_sAddress="";
		 m_lnPhoneNumber=0;
		 m_lnAdharNumber=0;
	}
	virtual ~CPerson()
	{

	}
	void GetPersonData();
	void DisplayPerson();
	//virtual void GetStudentData() = 0;
	//virtual void GetTeacherData() = 0;
	virtual void GetDoctorData() = 0;
	//virtual void DisplayStudent() = 0;
	//virtual void DisplayTeacher() = 0;
	virtual void DisplayDoctor() = 0;
};

void CPerson::GetPersonData()
{
	cout << "Enter Name : ";
	cin.ignore();
	getline(cin, m_sName);
	cout << "Enter Address : ";
	getline(cin, m_sAddress);
	cout << "Enter Phone Number : ";
	cin >> m_lnPhoneNumber;
	cout << "Enter Adhar Number : ";
	cin >> m_lnAdharNumber;
}

void CPerson::DisplayPerson()
{
	cout << "Name : " << m_sName << endl;
	cout << "Address : " << m_sAddress << endl;
	cout << "Phone Number : " << m_lnPhoneNumber << endl;
	cout << "Adhar Number : " << m_lnAdharNumber << endl;
}

class CDoctor : public CPerson
{
private:
	int m_nDoctorId;
	int m_nExperience;
	string m_sSpecialisation;
public:
	CDoctor()
	{
		m_nDoctorId = 0;
		m_nExperience = 0;
		m_sSpecialisation = "";
	}
	~CDoctor()
	{

	}
	void GetDoctorData()
	{
	    GetPersonData();
	cout << "Enter the Doctor ID : ";
	cin >> m_nDoctorId;
	cout << "Enter the Experience : ";
	cin >> m_nExperience;
	cout << "Enter Specialization : ";
	cin.ignore();
	getline(cin, m_sSpecialisation);
	}
	void DisplayDoctor();
};

/*void CDoctor::GetDoctorData()
{

}*/

void CDoctor::DisplayDoctor()
{
	DisplayPerson();
	cout << "Doctor ID : "<<m_nDoctorId<<endl;
	cout << "Experience : " << m_nExperience << endl;
	cout << "Specialization : "<<m_sSpecialisation;
}


//using namespace std;
int main()
{
    CPerson *pPerson ;

	CDoctor oDoctor;
	pPerson = &oDoctor;
	pPerson->GetDoctorData();
	//CTeacher oTeacher;
    return 0;
}
