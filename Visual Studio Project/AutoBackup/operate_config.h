#include <string>
#define COMMENT_CHAR '#'//ע�ͷ�
using namespace std;

class operate_config
{
private:
	ifstream* infile;
public:
	operate_config(void);
	//����filename�������ļ�������
	operate_config(const string& filename);
	//operate_config(void);
	//����name�������������
	//����ֵ����Ӧ������name��valueֵ
	string getValue(const string& name);
};
