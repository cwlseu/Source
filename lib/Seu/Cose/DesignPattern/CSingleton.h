/**
 * @ Brief: Singleton Design Pattern keep the object in the program only create once
 * @ author: charles<cwlseu@qq.com>
 * @ Create Date: 2014-11-27
 */
#include <memory>
class CSingleton
{
public:
	CSingleton()
	{

	}
	~CSingleton()
	{
		delete m_pInstance;
	}
	/**
	 * Create static instance method:
	 * Only create once in current progress
	 **/
	static CSingleton* getInstance()
	{
		if(m_pInstance) //判断是否第一次调用
			m_pInstance = new CSingleton();
		return m_pInstance;
	}
private:
	//the object hold a static pointer which point to itself.
	static CSingleton* m_pInstance;
};
