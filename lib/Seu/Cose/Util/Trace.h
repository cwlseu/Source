#ifndef __SEU_COSE_TRACE_H_
#define __SEU_COSE_TRACE_H_
/**
 * 目标：用于记录运行记录信息，相当于一个log类，可以输出log，也可以向日志文件中输出日志
 * 日志文件可以自定义或者默认
 * @author Charles<cwlseu@qq.com>
 * @version 1.0 
 */
#include <stdio.h>
#include <time.h>
namespace Seu{
	namespace Cose{
		class Trace{
			private:
				//日志文件
				FILE* file;
				//是否开启日志的开关
				int noisy;
			public:
				//缺省构造函数
				Trace():noisy(0){file= fopen("run.log","a+");}
				//构造函数
				Trace(FILE* _file):noisy(0){file=_file;}
				//开启日志开关
				void on(){noisy=1;}
				//关闭日志开关
				void off(){noisy=0;}
				//记录日志
				void log(char* s)
				{	
					if(noisy)
					{
						time_t rawtime;
						struct tm * timeinfo;
						time ( &rawtime );
						timeinfo = localtime ( &rawtime );
						fprintf(file, "%s:%s\n",asctime (timeinfo),s);
					}
				}
				//打印输出日志
				void print(char* s)
				{
					if(noisy)
					{
					   printf("Trace log:%s",s);
					   log(s);
					}
				}
		};
	}
}

#endif