#pragma once

//通过预编译的方式去掉unicode字符集
#ifdef UNICODE
#undef UNICODE
#endif //UNICODE
#include<easyx.h>
#include<string>