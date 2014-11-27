/**
 * @Brief: 
 * @file : $Id://Source/main.cpp
 * @author : Charles
 * @Date : 2014-11-26
 */
 #include
#define assert(expr) ((expr) ? __ASSERT_VOID_CAST(0): __assert_fail(__STRING(expr),__FILE__,__LINE__,__ASSERT_FUNCTION))
int main(int argc, char const *argv[])
{
	assert(100==100);
	return 0;
}