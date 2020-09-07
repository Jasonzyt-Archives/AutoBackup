#include <string>
#define COMMENT_CHAR '#'//注释符
using namespace std;

class operate_config
{
private:
	ifstream* infile;
public:
	operate_config(void);
	//参数filename，配置文件的名字
	operate_config(const string& filename);
	//operate_config(void);
	//参数name，配置项的名字
	//返回值，对应配置项name的value值
	string getValue(const string& name);
};
